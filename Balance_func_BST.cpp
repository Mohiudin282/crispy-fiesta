/* #include<iostream>
using namespace std; */
/* int main(){
    int b = 10;
    int *t = &b;
    int *&c = t;
    int s = 20;
    c = &s;
    *c = 21;
    cout<<*t;
} */
    #include <iostream>
    #include<queue>
    using namespace std;

    class BSTNode{
    public:
        int info;
        BSTNode *left, *right;
        BSTNode(int i, BSTNode *l = 0, BSTNode *r = 0){
            info = i;
            left = l;
            right = r;
        }
    };

    class BST{
    private:
        BSTNode *root;
    public:
        BST(){
            root = 0;
        }
        ~BST(){
            clear(root);
            root = 0;
        }
        bool isEmpty(){
            return root == 0;
        }
        int* search(int &el){
            return search(root, el);
        }
        void preOrder(){
            preOrder(root);
        }
        void inOrder(){
            inOrder(root);
        }
        void postOrder(){
            postOrder(root);
        }
        void visit(BSTNode *p){
            cout<<p->info<<" ";
        }
        int* search(BSTNode*, const int&);
        void insert(const int &);
        void preOrder(BSTNode*);
        void inOrder(BSTNode*);
        void postOrder(BSTNode*);
        void breadthFirst();
        void clear(BSTNode*);
        void deleteByMerging(BSTNode*&);
        void findAndDeleteByMerging(const int&);
        void balance(int*, int, int);
        void mergeSort(int*, int, int);
    };
        //Finding an element in a tree.
        int* BST::search(BSTNode *p, const int& el){
                while(p != 0)
                if(el == p->info)
                return &p->info;
                else if(el < p->info)
                p = p->left;
                else
                p = p->right;
            return 0;
        }
        //Insert a node in a tree.
        void BST::insert(const int& el){
            BSTNode *p = root, *prev = 0;
            while(p != 0){      //Find a place to insert a new node in BST.
                prev = p;
                if(el > p->info){
                    p = p->right;
                }
                else if(el < p->info){
                    p = p->left;
                }
            }
            if(root == 0){
                root = new BSTNode(el);
            }
            else if(el > prev->info){
                prev->right = new BSTNode(el);
            }
            else
            prev->left = new BSTNode(el);
        }
        /*Preorder traversal using recursion*/
        void BST::preOrder(BSTNode* p){
            if(p != 0){
                visit(p);
                preOrder(p->left);
                preOrder(p->right);
            }
        }
        /*Inorder traversal using recursion*/
        void BST::inOrder(BSTNode* p){
            if(p != 0){
                inOrder(p->left);
                visit(p);
                inOrder(p->right);
            }
        }
        /*Postorder traversal using recursion*/
        void BST::postOrder(BSTNode* p){
            if(p != 0){
                postOrder(p->left);
                postOrder(p->right);
                visit(p);
            }
        }
        //Breadth first traversal.
        void BST::breadthFirst(){
            queue<BSTNode*> queue;
            BSTNode *p = root;
            if(p != 0){
                queue.push(p);
                while(!queue.empty()){
                    p = queue.front();
                    queue.pop();
                    visit(p);
                    if(p->left != 0)
                    queue.push(p->left);
                    if(p->right != 0)
                    queue.push(p->right);
                }
            }
        }
        //Delete a node from a binary search tree.
        /*Node is attached to a parent node because
        this function takes argument as a refrence*/
        void BST::deleteByMerging(BSTNode*& node){
            BSTNode* tmp = node;
            if(node != 0){
                if(node->left == 0){
                    node = node->right;
                }
                else if(node->right == 0){
                    node = node->left;
                }
                else{
                    tmp = node->left;
                    while(tmp->right != 0){
                        tmp = tmp->right;
                    }
                    tmp->right = node->right;
                    tmp = node;
                    node = node->left;
                }
                delete tmp;
            }
        }
        //Find node and use deleteByMerge function to delete it.
        void BST::findAndDeleteByMerging(const int& el){
            BSTNode* node = root, *prev = 0;
            /*search a node and take a record of previous node
            by using prev variable*/
            while(node != 0){
                if(node->info == el){
                    break;
                }
                prev = node;
                if(el > node->info){
                    node = node->right;
                }
                else{
                    node = node->left;
                }
            }
            /*When node is find then pass the address of node to
            delete by merge function by using the prev(parent) node*/
            if(node != 0 && node->info == el){
                if(node == root){
                    deleteByMerging(root);
                }
                else if(prev->left == node){
                    deleteByMerging(prev->left);
                }
                else{
                    deleteByMerging(prev->right);
                }
            }
            else if(root != 0){
                cout<<"Element "<<el<<"cannot be found in a tree\n";
            }
            else{
                cout<<"the tree is Empty"<<endl;
            }
        }
        /*used binary search algo to input a nodes in a tree*/
        void BST::balance(int *arr, int low, int high){
            if(low<=high){
                int mid = (low + high)/2;
                insert(arr[mid]);
                balance(arr, low, mid - 1);
                balance(arr, mid + 1, high);
            }
        }
        //Sorting for balencing
        void merge(int *arr, int low, int mid, int high){
            int left=low;
            int right=mid+1;
            vector<int> temp;

            while(left<=mid && right<=high){
                if(arr[left]<=arr[right]){
                    temp.push_back(arr[left]);
                    left++;
                }
                else{
                    temp.push_back(arr[right]);
                    right++;
                }
            }

            while(left<=mid){
                temp.push_back(arr[left]);
                left++;
            }
            while(right<=high){
                temp.push_back(arr[right]);
                right++;
            }

            for(int i=low; i<=high; i++){
                arr[i]=temp[i-low];
            }
        }
        //Recursion
        void BST::mergeSort(int *arr, int low, int high){
            if(low>=high){
                return;
            }
            int mid=(low+high)/2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
        //Function to clear memory resources.
        void BST::clear(BSTNode *p){
            if(p){
                clear(p->left);
                clear(p->right);
                delete p;
            }
        }

        int main(){
             BST b;
            /* b.insert(40);
            b.insert(50);
            b.insert(25);
            b.insert(30);
            b.insert(35);
            b.insert(60);
            b.insert(45);
            //b.findAndDeleteByMerging(40);
            b.inOrder(); */
            int arr[] = {23,56,21,32,67,41};
            b.mergeSort(arr, 0, 5);
            b.balance(arr, 0, 5);
            b.inOrder();


        }