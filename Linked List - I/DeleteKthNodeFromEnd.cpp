/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *removeKthNode(Node *head, int K)
{
    // Write your code here.
    Node *slower = NULL, *slow = head, *fast = head;
    while (fast != NULL and K--)
    {
        fast = fast->next;
    }

    while (fast != NULL)
    {
        slower = slow;
        slow = slow->next;
        fast = fast->next;
    }
    if (slower == NULL)
        return head->next;
    slower->next = slow->next;
    return head;
}
