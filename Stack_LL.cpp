    #include<iostream>
    using namespace std;

    class StackNode{
        public:
        int info;
        StackNode* next;

        StackNode(int i, StackNode* t){
            info = i;
            next = t;
        }
    };

    class StackLL{
        private:
        StackNode* top;
        public:
        StackLL(){
            top = 0;
        }
        ~StackLL(){
            StackNode* t1;
            while(top != 0){
                t1 = top->next;
                delete top;
                top = t1;
            }
        }
        bool push(int);
        bool pop(int&);
        void display();
    };

    bool StackLL::push(int v){
        top = new StackNode(v, top);
        return true;
    }
    bool StackLL::pop(int &v){
        if(top != 0){
            StackNode* tmp = top;
            v = tmp->info;
            top = tmp->next;
            delete tmp;
            tmp = 0;
            return true;
        }
        else return false;
    }
    void StackLL::display(){
        StackNode* tmp = top;
        while(tmp != 0){
            cout<<tmp->info<<" ";
            tmp = tmp->next;
        }
    }
    
    int main(){
        StackLL s1;
        s1.push(3);
        s1.push(4);
        s1.push(5);
        s1.push(6);
        /* int x;
        s1.pop(x);
        cout<<x<<endl; */
        s1.display();
    }