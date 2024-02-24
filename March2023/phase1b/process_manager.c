#include "phase1.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "kernel.h"

/* ------------------------- Prototypes ----------------------------------- */
int sentinel (char *);
extern int start1 (char *);
void dispatcher(void);
void launch();
static void checkDeadlock();
void enableInterrupts(void);
void requireKernelMode(char *);
void clockHandler();
int readtime();
void emptyProc(int);
int block(int);
void initProcQueue(procQueue*, int);
void enq(procQueue*, procPtr);
procPtr deq(procQueue*);
procPtr peek(procQueue*);
void removeChild(procQueue*, procPtr);

/* -------------------------- Globals ------------------------------------- */

// Patrick's debugging global variable...
int debugflag = 1;

// the process table
procStruct ProcTable[MAXPROC];

// Process lists
procQueue ReadyList[SENTINELPRIORITY];

// The number of process table spots taken
int numProcs;

// current process ID
procPtr Current;

// the next pid to be assigned
unsigned int nextPid = SENTINELPID;


/* -------------------------- Functions ----------------------------------- */
/* ------------------------------------------------------------------------
   Name - startup
   Purpose - Initializes process lists and clock interrupt vector.
             Start up sentinel process and the test process.
   Parameters - none, called by USLOSS
   Returns - nothing
   Side Effects - lots, starts the whole thing
   ----------------------------------------------------------------------- */
void startup()
{
    // test if in kernel mode; halt if in user mode
    requireKernelMode("startup()"); 

    int result; // value returned by call to fork1()

    // initialize the process table
    if (DEBUG && debugflag)
        USLOSS_Console("startup(): initializing process table, ProcTable[]\n");
    int i; 
    // init the fields of each process
    for (i = 0; i < MAXPROC; i++) {
        emptyProc(i);
    }

    numProcs = 0;
    Current = &ProcTable[MAXPROC-1];

    // Initialize the ReadyList, etc.
    if (DEBUG && debugflag)
        USLOSS_Console("startup(): initializing the Ready list\n");
    for (i = 0; i < SENTINELPRIORITY; i++) {
        initProcQueue(&ReadyList[i], READYLIST);
    }

    // Initialize the clock interrupt handler
    USLOSS_IntVec[USLOSS_CLOCK_INT] = clockHandler;

    // startup a sentinel process
    if (DEBUG && debugflag)
        USLOSS_Console("startup(): calling fork1() for sentinel\n");
    result = fork1("sentinel", sentinel, NULL, USLOSS_MIN_STACK,
                    SENTINELPRIORITY);
    if (result < 0) {
        if (DEBUG && debugflag) {
            USLOSS_Console("startup(): fork1 of sentinel returned error, ");
            USLOSS_Console("halting...\n");
        }
        USLOSS_Halt(1);
    }
  
    // start the test process
    if (DEBUG && debugflag)
        USLOSS_Console("startup(): calling fork1() for start1\n");
    result = fork1("start1", start1, NULL, 2 * USLOSS_MIN_STACK, 1);
    if (result < 0) {
        USLOSS_Console("startup(): fork1 for start1 returned an error, ");
        USLOSS_Console("halting...\n");
        USLOSS_Halt(1);
    }

    USLOSS_Console("startup(): Should not see this message! ");
    USLOSS_Console("Returned from fork1 call that created start1\n");

    return;
} /* startup */


/* ------------------------------------------------------------------------
   Name - finish
   Purpose - Required by USLOSS
   Parameters - none
   Returns - nothing
   Side Effects - none
   ----------------------------------------------------------------------- */
void finish()
{
    // test if in kernel mode; halt if in user mode
    requireKernelMode("finish()"); 

    if (DEBUG && debugflag)
        USLOSS_Console("in finish...\n");
} /* finish */


/* ------------------------------------------------------------------------
   Name - fork1
   Purpose - Gets a new process from the process table and initializes
             information of the process.  Updates information in the
             parent process to reflect this child process creation.
   Parameters - the process procedure address, the size of the stack and
                the priority to be assigned to the child process.
   Returns - the process id of the created child or -1 if no child could
             be created or if priority is not between max and min priority.
   Side Effects - ReadyList is changed, ProcTable is changed, Current
                  process information changed
   ------------------------------------------------------------------------ */
int fork1(char *name, int (*startFunc)(char *), char *arg,
          int stacksize, int priority)
{
    int procSlot = -1;

    if (DEBUG && debugflag)
        USLOSS_Console("fork1(): creating process %s\n", name);

    // test if in kernel mode; halt if in user mode
    requireKernelMode("fork1()"); 
    disableInterrupts(); 

    // Return if stack size is too small
    if (stacksize < USLOSS_MIN_STACK) { // found in usloss.h
        if (DEBUG && debugflag)
            USLOSS_Console("fork1(): Stack size too small.\n");
        return -2; // from the phase1 pdf
    }

    // Return if startFunc is null
    if (startFunc == NULL) { 
        if (DEBUG && debugflag)
            USLOSS_Console("fork1(): Start function is null.\n");
        return -1; // from the phase1 pdf
    }

    // Return if name is null
    if (name == NULL) { 
        if (DEBUG && debugflag)
            USLOSS_Console("fork1(): Process name is null.\n");
        return -1; // from the phase1 pdf
    }

    // Return if priority is out of range (except sentinel, which is below the min)
    if ((priority > MINPRIORITY || priority < MAXPRIORITY) && startFunc != sentinel) { 
        if (DEBUG && debugflag)
            USLOSS_Console("fork1(): Priority is out of range.\n");
        return -1; // from the phase1 pdf
    }

    // handle case where there is no empty spot
    if (numProcs >= MAXPROC) {
        if (DEBUG && debugflag)
            USLOSS_Console("fork1(): No empty slot on the process table.\n");
        return -1;
    }

    // find an empty slot in the process table
    procSlot = nextPid % MAXPROC;
     while (ProcTable[procSlot].status != EMPTY) {
        nextPid++;
        procSlot = nextPid % MAXPROC;
     }

    if (DEBUG && debugflag)
        USLOSS_Console("fork1(): creating process pid %d in slot %d, slot status %d\n", nextPid, procSlot, ProcTable[procSlot].status);

    // fill-in entry in process table */
    if ( strlen(name) >= (MAXNAME - 1) ) {
        if (DEBUG && debugflag)
            USLOSS_Console("fork1(): Process name is too long.  Halting...\n");
        USLOSS_Halt(1);
    }
    strcpy(ProcTable[procSlot].name, name);
    ProcTable[procSlot].startFunc = startFunc;
    if ( arg == NULL )
        ProcTable[procSlot].startArg[0] = '\0';
    else if ( strlen(arg) >= (MAXARG - 1) ) {
        if (DEBUG && debugflag)
            USLOSS_Console("fork1(): argument too long.  Halting...\n");
        USLOSS_Halt(1);
    }
    else
        strcpy(ProcTable[procSlot].startArg, arg);

    // allocate the stack
    ProcTable[procSlot].stack = (char *) malloc(stacksize);
    ProcTable[procSlot].stackSize = stacksize;

    // make sure malloc worked, halt otherwise
    if (ProcTable[procSlot].stack == NULL) {
        if (DEBUG && debugflag)
            USLOSS_Console("fork1(): Malloc failed.  Halting...\n");
        USLOSS_Halt(1);
    }

    // set the process id
    ProcTable[procSlot].pid = nextPid++;
    
    // set the process priority
    ProcTable[procSlot].priority = priority;

    // increment number of processes
    numProcs++;

    // Initialize context for this process, but use launch function pointer for
    // the initial value of the process's program counter (PC)
    USLOSS_ContextInit(&(ProcTable[procSlot].state), USLOSS_PsrGet(),
                       ProcTable[procSlot].stack,
                       ProcTable[procSlot].stackSize,
                       launch);

    // for future phase(s)
    p1_fork(ProcTable[procSlot].pid);

    // More stuff to do here...
    // add process to parent's (current's) list of children, iff parent exists 
    if (Current->pid > -1) {
        enq(&Current->childrenQueue, &ProcTable[procSlot]);
        ProcTable[procSlot].parentPtr = Current; // set parent pointer
    }

    // add process to the approriate ready list
    enq(&ReadyList[priority-1], &ProcTable[procSlot]);
    ProcTable[procSlot].status = READY; // set status to READY

    // let dispatcher decide which process runs next
    if (startFunc != sentinel) { // don't dispatch sentinel!
        dispatcher(); 
    }

    // enable interrupts for the parent
    enableInterrupts();

    return ProcTable[procSlot].pid;  // return child's pid
} /* fork1 */


/* ------------------------------------------------------------------------
   Name - launch
   Purpose - Dummy function to enable interrupts and launch a given process
             upon startup.
   Parameters - none
   Returns - nothing
   Side Effects - enable interrupts
   ------------------------------------------------------------------------ */
void launch()
{
    // test if in kernel mode; halt if in user mode
    requireKernelMode("launch()"); 
    disableInterrupts(); 

    int result;

    if (DEBUG && debugflag)
        USLOSS_Console("launch(): starting current process: %d\n\n", Current->pid);

    // Enable interrupts
    enableInterrupts();

    // Call the function passed to fork1, and capture its return value
    result = Current->startFunc(Current->startArg);

    if (DEBUG && debugflag)
        USLOSS_Console("Process %d returned to launch\n", Current->pid);

    quit(result);
} /* launch */


/* ------------------------------------------------------------------------
   Name - dispatcher
   Purpose - dispatches ready processes.  The process with the highest
             priority (the first on the ready list) is scheduled to
             run.  The old process is swapped out and the new process
             swapped in.
   Parameters - none
   Returns - nothing
   Side Effects - the context of the machine is changed
   ----------------------------------------------------------------------- */
void dispatcher(void)
{
    // test if in kernel mode; halt if in user mode
    requireKernelMode("dispatcher()"); 
    disableInterrupts(); 

    procPtr nextProcess = NULL;

    // if current is still running, remove it from ready list and put it back on the end 
    if (Current->status == RUNNING) {
        Current->status = READY;
        deq(&ReadyList[Current->priority-1]);
        enq(&ReadyList[Current->priority-1], Current);
    }

    // Find the highest priority non-empty process queue
    int i;
    for (i = 0; i < SENTINELPRIORITY; i++) {
        if (ReadyList[i].size > 0) {
            nextProcess = peek(&ReadyList[i]);
            break;
        }
    }

    // Print message and return if the ready list is empty
    if (nextProcess == NULL) {
        if (DEBUG && debugflag)
            USLOSS_Console("dispatcher(): ready list is empty!\n");
        return;
    }

    if (DEBUG && debugflag)
        USLOSS_Console("dispatcher(): next process is %s\n\n", nextProcess->name);

    // update current
    procPtr old = Current;
    Current = nextProcess;
    Current->status = RUNNING; // set status to RUNNING

    // set slice time and time started 
    if (old != Current) {
        if (old->pid > -1)
            old->cpuTime += USLOSS_Clock() - old->timeStarted; // update cpu time for previous process
        Current->sliceTime = 0;
        Current->timeStarted = USLOSS_Clock(); // set time started
    }

    // your dispatcher should call p1_switch(int old, int new) with the 
    // PID’s of the process that was previously running and the next process to run. 
    // You will enable interrupts before you call USLOSS_ContextSwitch. 
    // The call to p1_switch should be called just before you enable interrupts
    p1_switch(old->pid, Current->pid);
    enableInterrupts();
    USLOSS_ContextSwitch(&old->state, &Current->state);
} /* dispatcher */


/* ------------------------------------------------------------------------
   Name - join
   Purpose - Wait for a child process (if one has been forked) to quit.  If 
             one has already quit, don't wait.
   Parameters - a pointer to an int where the termination code of the 
                quitting process is to be stored.
   Returns - the process id of the quitting child joined on.
             -1 if the process was zapped in the join
             -2 if the process has no children
   Side Effects - If no child process has quit before join is called, the 
                  parent is removed from the ready list and blocked.
   ------------------------------------------------------------------------ */
int join(int *status)
{
    // test if in kernel mode; halt if in user mode
    requireKernelMode("join()"); 
    disableInterrupts(); 
  
    if (DEBUG && debugflag)
        USLOSS_Console("join(): In join, pid = %d\n", Current->pid);

    // check if has children
    if (Current->childrenQueue.size == 0 && Current->deadChildrenQueue.size == 0) {
        if (DEBUG && debugflag)
            USLOSS_Console("join(): No children\n");
        return -2;
    }

    // if current has no dead children, block self and wait.
    if (Current->deadChildrenQueue.size == 0) {
        if (DEBUG && debugflag)
            USLOSS_Console("join(): pid %d blocked at priority %d \n\n" , Current->pid, Current->priority - 1);
        block(JBLOCKED);
    }

    if (DEBUG && debugflag)
        USLOSS_Console("join(): pid %d unblocked, dead child queue size = %d \n" , Current->pid, Current->deadChildrenQueue.size);

    // get the earliest dead child
    procPtr child = deq(&Current->deadChildrenQueue);
    int childPid = child->pid;
    *status = child->quitStatus;

    if (DEBUG && debugflag)
        USLOSS_Console("join(): got child pid = %d, quit status = %d\n\n" , childPid, *status);

    // put child to rest
    emptyProc(childPid);

    if (Current->zapQueue.size != 0 ) {
        childPid = -1;
    }
    
    enableInterrupts(); // enable interrupts for the parent
    return childPid;
} /* join */


/* ------------------------------------------------------------------------
   Name - quit
   Purpose - Stops the child process and notifies the parent of the death by
             putting child quit info on the parents child completion code
             list.
   Parameters - the code to return to the grieving parent
   Returns - nothing
   Side Effects - changes the parent of pid child completion status list.
   ------------------------------------------------------------------------ */
void quit(int status)
{
    // test if in kernel mode; halt if in user mode
    requireKernelMode("quit()"); 
    disableInterrupts(); 

    if (DEBUG && debugflag)
        USLOSS_Console("quit(): quitting process pid = %d, parent is %d\n", Current->pid, Current->parentPtr->pid);

    // print error message and halt if process with active children calls quit
    // loop though children to find if any are active
    procPtr childPtr = peek(&Current->childrenQueue);
    while (childPtr != NULL) {
        if (childPtr->status != QUIT) {
            USLOSS_Console("quit(): process %d, '%s', has active children. Halting...\n", Current->pid, Current->name);
            USLOSS_Halt(1);
        }
        childPtr = childPtr->nextSiblingPtr;
    }

    Current->status = QUIT; // change status to QUIT
    Current->quitStatus = status; // store the given status
    deq(&ReadyList[Current->priority-1]); // remove self from ready list
    if (Current->parentPtr != NULL) {
        removeChild(&Current->parentPtr->childrenQueue, Current); // remove self from parent's list of children
        enq(&Current->parentPtr->deadChildrenQueue, Current); // add self to parent's dead children list

        if (Current->parentPtr->status == JBLOCKED) { // unblock parent
            Current->parentPtr->status = READY;
            enq(&ReadyList[Current->parentPtr->priority-1], Current->parentPtr);
        }
    }

    // unblock processes that zap'd this process
    while (Current->zapQueue.size > 0) {
        procPtr zapper = deq(&Current->zapQueue);
        zapper->status = READY;
        enq(&ReadyList[zapper->priority-1], zapper);
    }

    // remove any dead children current has form the process table
    while (Current->deadChildrenQueue.size > 0) {
        procPtr child = deq(&Current->deadChildrenQueue);
        emptyProc(child->pid);
    }

    // delete current if it has no parent
    if (Current->parentPtr == NULL)
        emptyProc(Current->pid);

    p1_quit(Current->pid);

    dispatcher(); // call dispatcher to run next process
} /* quit */


/* ------------------------------------------------------------------------
   Name - zap
   Purpose - 
   Parameters - 
   Returns -  -1: the calling process itself was zapped while in zap.
               0: the zapped process has called quit.
   Side Effects - 
   ----------------------------------------------------------------------- */
int zap(int pid) {
    if (DEBUG && debugflag)
        USLOSS_Console("zap(): called\n");

    // test if in kernel mode; halt if in user mode
    requireKernelMode("zap()"); 
    disableInterrupts();

    procPtr process; 
    if (Current->pid == pid) {
        USLOSS_Console("zap(): process %d tried to zap itself.  Halting...\n", pid);
        USLOSS_Halt(1);
    }
  
    process = &ProcTable[pid % MAXPROC];

    if (process->status == EMPTY || process->pid != pid) {
        USLOSS_Console("zap(): process being zapped does not exist.  Halting...\n");
        USLOSS_Halt(1);
    }

    if (process->status == QUIT) { // CHECK
        enableInterrupts();
        if (Current->zapQueue.size > 0) 
            return -1;
        else
            return 0;
    }

    enq(&process->zapQueue, Current);
    block(ZBLOCKED);

    enableInterrupts();
    if (Current->zapQueue.size > 0) {
        return -1;  
    }
    return 0; 
} 
