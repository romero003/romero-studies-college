using namespace std;
#include <iostream>

struct AVLtree{
    
    

    struct Node{
        int value;
        int height;
        Node* right;
        Node* left;

        Node(int v){
            value = v;
            left = nullptr;
            right = nullptr;
            height = -1;
        };
    };

    Node* root;

    AVLtree(){
        root = nullptr;
    }
    ~AVLtree(    ){
        //postfix delete
    }

    Node* insert(int &number, Node* rt){
        if(rt == nullptr){
            rt = new Node(number);
        }else if(rt->value > number){
            rt -> left = insert(number, rt->left);
        }else{
            rt -> right = insert(number, rt->right);
        }
        rt -> height = 1 + max(h(rt->left), h(rt -> right));
        int balance = getBalance(rt);
        if(balance < -1 && number >= rt->right->value){
            return lRotation(rt);
        }
        if(balance > 1 && number < rt->left->value){
            return lRotation(rt);
        }
        if(balance > 1 && number >= rt->left->value){
            rt = lRotation(rt->left);
            return(rRotation(rt));
        }
        if(balance < -1 && number < rt->right->value){
            rt = rRotation(rt->right);
            return(lRotation(rt));
        }

        return rt;
    }

    int getBalance(Node* rt){
        if (rt = nullptr){
            return 0;
        }
        return (rt->left->height - rt->right->height);
    }

    int h(Node* rt){
        if(rt == nullptr){
            return -1;
        }
        return(h(rt->left)- h(rt->right));
    }

    void printPreOrder(){

    }

    void printInOrder(){

    }

    void printPostOrder(){

    }

    Node* rRotation(Node* rt){
        Node* l = rt->left;
        Node* lr = l ->right;
        l -> right = rt;
        rt->height = max(h(rt->right), h(rt->left)) + 1;
        l->height = max(h(l->left), h(l->right)) + 1;
        return l; 
    }

    Node* lRotation(Node* rt){

    }

    
};