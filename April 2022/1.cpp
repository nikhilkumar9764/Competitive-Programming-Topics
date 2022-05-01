/* Find median in a stream of running integers 
GFG Hard Question*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD (ll) (1e9+7)

int main() {
    
    ll n;
    cin>>n;
    ll ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    priority_queue<ll> max_heap;
    priority_queue<ll,vector<ll>,greater<ll>> min_heap;

    for(int i=0;i<n;i++)
    {
        double av;
        if(max_heap.empty() || max_heap.top()>ar[i])
        {
            max_heap.push(ar[i]);
        }
        else{
            min_heap.push(ar[i]);
        }

        if(max_heap.size()>min_heap.size()+1)
        {
             av = (double)(max_heap.top());
             max_heap.pop();
             min_heap.push(av);
        }
        else if(min_heap.size()>max_heap.size()+1)
        {
             av = (double)(min_heap.top());
             min_heap.pop();
             max_heap.push(av);
        }
        
        if(max_heap.size()>min_heap.size())
        {
            cout<<(double)(max_heap.top())<<" ";
        }
        else if(min_heap.size()>max_heap.size())
        {
            cout<<(double)(min_heap.top())<<" ";
        }
        else if(min_heap.size() == max_heap.size())
        {
            double tot = ((double)(max_heap.top()) + (double)(min_heap.top()))/2;
            cout<<tot<<" ";
        }
    }
    cout<<"\n";
}

/* GFG Medium  
Given a linked list of numbers sorted in order of absolute values sort them in order of actual values 
 */

// C++ program to sort a linked list, already
// sorted by absolute values
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " -> ";
		head = head->next;
	}
	cout<<endl;
}

// To sort a linked list by actual values.
// The list is assumed to be sorted by absolute
// values.
void sortList(Node** head)
{
	// Initialize previous and current nodes
	Node* prev = (*head);
	Node* curr = (*head)->next;

	// Traverse list
	while (curr != NULL)
	{
		// If curr is smaller than prev, then
		// it must be moved to head
		if (curr->data < prev->data)
		{
			// Detach curr from linked list
			prev->next = curr->next;

			// Move current node to beginning
			curr->next = (*head);
			(*head) = curr;

			// Update current
			curr = prev;
		}

		// Nothing to do if current element
		// is at right place
		else
			prev = curr;

		// Move current
		curr = curr->next;
	}
}

// Driver code
int main()
{
	Node* head = NULL;
	push(&head, -5);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, -2);
	push(&head, 1);
	push(&head, 0);

	cout << "Original list :\n";
	printList(head);

	sortList(&head);

	cout << "\nSorted list :\n";
	printList(head);

	return 0;
}
