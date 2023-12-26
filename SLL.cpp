#include <iostream>
using namespace std;

class IntSLLNode
{
public:
    int info;
    IntSLLNode *next;

    IntSLLNode(int i, IntSLLNode *in = 0)
    {
        info = i;
        next = in;
    }
};

class IntSLList
{
private:
    IntSLLNode *head, *tail;

public:
    IntSLList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void sort()
    {
        sortLinkedList(head, tail);
    }
    void swapNodes(IntSLLNode *&head, IntSLLNode *&tail, IntSLLNode *node1, IntSLLNode *node2)
    {
        if (node1 == node2)
        {
            return;
        }

        IntSLLNode *prevNode1 = nullptr;
        IntSLLNode *prevNode2 = nullptr;
        IntSLLNode *current = head;

        while (current != nullptr)
        {
            if (current->next == node1)
            {
                prevNode1 = current;
            }
            else if (current->next == node2)
            {
                prevNode2 = current;
            }

            current = current->next;
        }

        if (prevNode1 != nullptr)
        {
            prevNode1->next = node2;
        }
        else
        {
            head = node2;
        }

        if (prevNode2 != nullptr)
        {
            prevNode2->next = node1;
        }
        else
        {
            head = node1;
        }

        IntSLLNode *temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        // Update tail if necessary
        if (node2->next == nullptr)
        {
            tail = node2;
        }
        else if (node1->next == nullptr)
        {
            tail = node1;
        }
    }

    void sortLinkedList(IntSLLNode *&head, IntSLLNode *&tail)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return; // Already sorted or empty list
        }

        IntSLLNode *current = head;

        while (current != nullptr)
        {
            IntSLLNode *minNode = current;
            IntSLLNode *temp = current->next;

            while (temp != nullptr)
            {
                if (temp->info < minNode->info)
                {
                    minNode = temp;
                }

                temp = temp->next;
            }

            swapNodes(head, tail, current, minNode);
            current = minNode->next;
        }
    }

    void addtohead(int t)
    {
        if (head == nullptr)
        {
            head = new IntSLLNode(t);
            tail = head;
        }
        else
            head = new IntSLLNode(t, head);
    }
    void addtotail(int r)
    {
        if (tail == nullptr)
        {
            tail = new IntSLLNode(r);
            head = tail;
        }
        else
        {
            tail->next = new IntSLLNode(r);
            tail = tail->next;
        }
    }
    int deletefromhead()
    {
        int s = head->info;
        IntSLLNode *temp = head;
        if (head == tail)
        {
            head = tail = 0;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        return s;
    }
    int deletefromtail()
    {
        int s = tail->info;
        if (head == tail)
        {
            delete head;
            head = tail = 0;
        }
        else
        {
            IntSLLNode *tmp;
            for (tmp = head; tmp->next != tail; tmp = tmp->next)
                ;
            delete tail;
            tail = tmp;
            tail->next = 0;
        }
        return s;
    }
    void deletenode(int i)
    {
        if (head != 0)      //if there is only one node
            if (head == tail && i == head->info)
            {
                delete head;
                head = tail = 0;
            }
            else if (i == head->info)
            {
                IntSLLNode *tmp = head;
                head = head->next;
                delete tmp;
            }
            else
            {
                IntSLLNode *pred, *tmp;
                for (pred = head, tmp = head->next; tmp != 0 && !(tmp->info == i); pred = pred->next, tmp = tmp->next)
                    ;
                if (tmp != 0)
                {
                    pred->next = tmp->next;
                    delete tmp;
                }
            }
    }
    // traversing
    bool isinList(int i){
        IntSLLNode* tmp = head;
        while(tmp){
            if(i == head->info){
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }
    void view()
    {
        IntSLLNode *s = head;
        while (s)
        {
            cout << s->info << " ";
            s = s->next;
        }
    }
    ~IntSLList()
    {
        for (IntSLLNode *s; head;)
        {
            s = head->next;
            delete head;
            head = s;
        }
    }
};

int main()
{
    IntSLList list, list1;
    list.addtotail(5);
    list.addtotail(9);
    list.addtotail(6);
    list.addtotail(50);
    list.addtotail(4);
    list.addtotail(10);
    list.addtotail(20);
    list.sort();
    list.view();
}