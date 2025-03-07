//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}

// } Driver Code Ends

/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to merge two sorted linked list.
class Solution
{
public:
    Node *sortedMerge(Node *head1, Node *head2)
    {
        if (head1 == NULL)
            return head2;
        else if (head2 == NULL)
            return head1;

        Node *p = head1;
        Node *q = head2;
        Node *head = new Node(-1);
        Node *dummy = head;

        while (p != NULL && q != NULL)
        {
            if (p->data > q->data)
            {
                head->next = q;
                head = q;
                q = q->next;
            }
            else
            {
                head->next = p;
                head = p;
                p = p->next;
            }
        }

        while (p != NULL)
        {
            head->next = p;
            head = p;
            p = p->next;
        }

        while (q != NULL)
        {
            head->next = q;
            head = q;
            q = q->next;
        }

        return dummy->next;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int T;
    cin >> T;
    cin.ignore();
    while (T--)
    {
        int n1, n2, tmp;
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp)
        {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr)
            {
                head1 = new_node;
                tail1 = new_node;
            }
            else
            {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp)
        {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr)
            {
                head2 = new_node;
                tail2 = new_node;
            }
            else
            {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends