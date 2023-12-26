        #include<iostream>
        using namespace std;

        class MaxHeap{
            private:
            int currSize, maxSize;
            int* heap;
            public:
            MaxHeap(int size){
                currSize = 0;
                maxSize = size;
                heap = new int[size + 1];
            }
            ~MaxHeap(){
                delete []heap;
            }
            bool isEmpty(){
                return currSize == 0;
            }
            bool isFull(){
                return currSize == maxSize;
            }
            void swapp (int& a, int& b){
            int temp = a;
                a = b;
                b = temp;
            }
            //Insertion
            bool insert(int);
            /*Also say that deletion from 1st node*/
            bool extractMax(int&);
            void maxHeapify(int s);
            void display();
        };
        /*complexity of build MAX-HEAP is O(n)*/
        bool MaxHeap::insert(int value){
            if(isFull()){
                return false;
            }
            else{
                currSize++;
                int i = currSize;
                while(i > 1 && value > heap[i/2]){
                    heap[i] = heap[i/2];
                    i = i/2;
                }
                heap[i] = value;
                return true;
            }
        }

        bool MaxHeap::extractMax(int& maxValue){
            if(isEmpty()){
                return false;
            }
            else{
                maxValue = heap[1];
                heap[1] = heap[currSize];
                currSize--;
                //HEAPIFY
                int i = 1, largest, left, right;
                bool flag = true;
                while(flag == true){
                    largest = i;
                    left = 2 * i;
                    right = 2 * i + 1;
                    if(i <= currSize && heap[i] < heap[left]){
                        largest = left;
                    }
                    if(i <= currSize && heap[largest] < heap[right]){
                        largest = right;
                    }
                    if(largest != i){
                        swap(heap[i], heap[largest]);
                        i = largest;
                    }
                    else{
                        flag = false;
                    }
                }
                return true;
            }
        }
        
        void MaxHeap:: display(){
            for(int i = 1; i <= currSize; i++){
                cout<<heap[i]<<" ";
            }
        }

        int main(){
            MaxHeap m(8);
            m.insert(4);
            m.insert(8);
            m.insert(6);
            m.insert(11);
            m.insert(7);
            m.insert(15);
            int x;
            //m.extractMax(x);
            //cout<<x<<endl;
            m.display();
            return 0;
        }
