/****************************************************************

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


*****************************************************************/

Node *firstNode(Node *head)
{
    if (head == NULL or head->next == NULL)
        return NULL;
    //    Write your code here.
    Node *slow = head, *fast = head;
    while (fast->next != NULL and fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            Node *temp = head;
            while (temp != slow)
            {
                temp = temp->next;
                slow = slow->next;
            }
            return temp;
        }
    }

    return NULL;
}