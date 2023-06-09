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

int len(Node *head)
{
    int l = 0;
    while (head != NULL)
    {
        head = head->next;
        l++;
    }
    return l;
}

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    Node *ln, *sh;
    if (len(firstHead) < len(secondHead))
    {
        sh = firstHead;
        ln = secondHead;
    }
    else
    {
        ln = firstHead;
        sh = secondHead;
    }

    int diff = len(ln) - len(sh);

    while (diff--)
    {
        ln = ln->next;
    }

    while (ln != NULL and sh != NULL)
    {
        if (ln == sh)
        {
            return ln;
        }
        ln = ln->next;
        sh = sh->next;
    }

    return NULL;
}