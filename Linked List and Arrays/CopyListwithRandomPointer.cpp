#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if (head == NULL)
        return NULL;

    LinkedListNode<int> *iter = head, *front = head;

    // creating dummy nodes
    while (iter != NULL)
    {
        front = iter->next;
        LinkedListNode<int> *copy = new LinkedListNode<int>(iter->data);
        iter->next = copy;
        copy->next = front;
        iter = front;
    }

    // copying random pointers

    iter = head;
    while (iter != NULL)
    {
        if (iter->random != NULL)
            iter->next->random = iter->random->next;
        else
            iter->next->random = NULL;
        iter = iter->next->next;
    }

    // segregating the lists

    LinkedListNode<int> *newHead = new LinkedListNode<int>(-1);
    LinkedListNode<int> *temp = newHead;
    iter = head, front = head;

    while (iter != NULL)
    {
        front = iter->next->next;
        temp->next = iter->next;
        iter->next = front;
        temp = temp->next;
        iter = front;
    }

    return newHead->next;
}
