// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            Node *newnode = new Node(node->val);
            newnode->next = node->next;
            node->next = newnode;
        }
        for (Node *node = head; node != nullptr; node = node->next->next)
        {
            node->next->random = node->random != nullptr ? node->random->next : nullptr;
        }
        Node *newhead = head->next;
        for (Node *node = head; node != nullptr; node = node->next)
        {
            Node *newnode = node->next;
            node->next = newnode->next;
            newnode->next = node->next != nullptr ? node->next->next : nullptr;
        }
        return newhead;
    }
};