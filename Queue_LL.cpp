#include<iostream>
using namespace std;

class QueueNode{
        public:
        int info;
        QueueNode* next;

        QueueNode(int i, QueueNode* t = 0){
            info = i;
            next = t;
        }
    };

    class QueueLL{
        private:
        QueueNode* front, *back;
        public:
        QueueLL(){
            front = 0;
            back = 0;
        }
        //Destructor
        bool enQueue(int);
        bool deQueue(int&);
        void display();
    };

    bool QueueLL::enQueue(int val){
        if(back == 0){
            front = new QueueNode(val);
            back = front;
        }
        else{
            back->next = new QueueNode(val);
            back = back->next;
        }
        return true;
    }
    bool QueueLL::deQueue(int& val){
        if(front != 0){     //if there is no node in LL
            QueueNode* tmp = front;
            val = tmp->info;
            front = tmp->next;
            delete tmp;
            tmp = 0;
            return true;
        }
        else{
            return false;
        }
    }
    void QueueLL::display(){
        QueueNode* tmp = front;
        while(tmp != 0){
            cout<<tmp->info<<" ";
            tmp = tmp->next;
        }
    }

    int main(){
        QueueLL q1;
        q1.enQueue(67);
        q1.enQueue(34);
        q1.enQueue(45);
        int x,y;
        //q1.deQueue(x);
       /*  cout<<x<<endl;
        cout<<q1.deQueue(y); */
        q1.display();
    }
