/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *merge(Node *head, Node *temp)
{
    Node *dummy = new Node(-1);
    Node *res = dummy;
    while (head != NULL and temp != NULL)
    {
        if (head->data < temp->data)
        {
            dummy->child = head;
            head = head->child;
        }
        else
        {
            dummy->child = temp;
            temp = temp->child;
        }
        dummy = dummy->child;
    }

    if (head == NULL)
        dummy->child = temp;
    else
        dummy->child = head;

    return res->child;
}

Node *flattenLinkedList(Node *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL)
        return head;

    Node *root = head->next;
    head->next = NULL;
    root = flattenLinkedList(root);
    head = merge(head, root);
    return head;
}
