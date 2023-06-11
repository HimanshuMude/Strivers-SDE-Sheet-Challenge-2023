/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k)
{
    // Write your code here.
    Node *last = head;
    int len = 0;
    Node *dummy = head;
    while (dummy != NULL)
    {
        dummy = dummy->next;
        len++;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = head;
    Node *newHead = last->next;
    int dist = len - k % len;
    while (dist > 1)
    {
        dist--;
        newHead = newHead->next;
    }
    last = newHead;
    newHead = newHead->next;
    last->next = NULL;
    return newHead;
}