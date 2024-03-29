/* Tests blockMe and unblockProc.
 * XXp1 starts 3 children at a higher priority, passing each child a different
 * argument containing an integer.  Each child executes the XXp2 function,
 * calling blockMe() using the status passed to XXp2 by its parent.
 * XXp1 then calls dumpProcesses(); should see the 3 processes blocked
 * on different statuses.
 * XXp1 then unblocks each of the three.
 */

#include <stdio.h>
#include <stdlib.h>
#include <usloss.h>
#include <phase1.h>

int XXp1(char *);
int XXp2(char *);

int testcase_main()
{
    int pid1, kid_status;

    USLOSS_Console("testcase_main(): started\n");
// TODO    USLOSS_Console("EXPECTATION: TBD\n");
    USLOSS_Console("QUICK SUMMARY: Tests blockMe() and unblockProc().\n");

    pid1 = spork("XXp1", XXp1, "XXp1", USLOSS_MIN_STACK, 5);
    pid1 = join(&kid_status);
    USLOSS_Console("testcase_main(): XXp1, pid %d, done; returning...\n", pid1);

    return 0;
}

int XXp1(char *arg)
{
    int  i, pid[10], result[10];
    char buf[20];

    USLOSS_Console("XXp1(): creating children\n");
    for (i = 0; i < 3; i++) {
        sprintf(buf, "%d", 13 + i); // different blockMe status
        pid[i] = spork("XXp2", XXp2, buf, USLOSS_MIN_STACK, 2);
    }

    dumpProcesses();

    USLOSS_Console("XXp1(): unblocking children\n");
    for (i = 0; i < 3; i++)
        result[i] = unblockProc(pid[i]);

    for (i = 0; i < 3; i++)
        USLOSS_Console("XXp1(): after unblocking %d, result = %d\n", pid[i], result[i]);

    USLOSS_Console("XXp1(): joining with children\n");
    for (i = 0; i < 3; i++)
    {
        int status_ignored;
        join(&status_ignored);
    }

    quit(0);
}


int XXp2(char *arg)
{
    int status = atoi(arg);

    USLOSS_Console("XXp2(): started, pid = %d, calling blockMe with status %d\n", getpid(),status);

    blockMe(status);
    USLOSS_Console("XXp2(): pid = %d, after blockMe\n", getpid());

    quit(0);
}

