#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

struct AVLNode {
    int data;
    AVLNode *left, *right;
    int height;
};

struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;

    AVLNode* _avl_createNode(int value) {
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height =1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    AVLNode* _search(AVLNode *root, int value) {
        while (root != NULL) {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode* node){
        if(node==NULL)
            return 0; 
        return node->height;
    }

    int _max(int a,int b){
        return (a > b)? a : b;
    }

    AVLNode* _rightRotate(AVLNode* pivotNode){
        AVLNode* newParrent=pivotNode->left;
        pivotNode->left=newParrent->right;
        newParrent->right=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftRotate(AVLNode* pivotNode) {
        AVLNode* newParrent=pivotNode->right;
        pivotNode->right=newParrent->left;
        newParrent->left=pivotNode;

        pivotNode->height=_max(_getHeight(pivotNode->left),
                        _getHeight(pivotNode->right))+1;
        newParrent->height=_max(_getHeight(newParrent->left),
                        _getHeight(newParrent->right))+1;
        
        return newParrent;
    }

    AVLNode* _leftCaseRotate(AVLNode* node){
        return _rightRotate(node);
    }

    AVLNode* _rightCaseRotate(AVLNode* node){
        return _leftRotate(node);
    }

    AVLNode* _leftRightCaseRotate(AVLNode* node){
        node->left=_leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode* _rightLeftCaseRotate(AVLNode* node){
        node->right=_rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode* node){
        if(node==NULL)
            return 0;
        return _getHeight(node->left)-_getHeight(node->right);
    }

    AVLNode* _insert_AVL(AVLNode* node,int value) {
        
        if(node==NULL)
            return _avl_createNode(value);
        if(value < node->data)
            node->left = _insert_AVL(node->left,value);
        else if(value > node->data)
            node->right = _insert_AVL(node->right,value);
        
        node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

        int balanceFactor=_getBalanceFactor(node);
        
        if(balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if(balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if(balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if(balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    AVLNode* _findMinNode(AVLNode *node) {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode* _remove_AVL(AVLNode* node,int value){
        if(node==NULL)
            return node;
        if(value > node->data)
            node->right=_remove_AVL(node->right,value);
        else if(value < node->data)
            node->left=_remove_AVL(node->left,value);
        else{
            AVLNode *temp;
            if((node->left==NULL)||(node->right==NULL)){
                temp=NULL;
                if(node->left==NULL) temp=node->right;  
                else if(node->right==NULL) temp=node->left;
                
                if(temp==NULL){
                    temp=node;
                    node=NULL;
                }
                else
                    *node=*temp;   
                
                free(temp);
            }
            else{
                temp = _findMinNode(node->right);
                node->data=temp->data;
                node->right=_remove_AVL(node->right,temp->data);
            }    
        }

        if(node==NULL) return node;
        
        node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

        int balanceFactor= _getBalanceFactor(node);
        
        if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
            return _leftCaseRotate(node);

        if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
            return _leftRightCaseRotate(node);
    
        if(balanceFactor<-1 && _getBalanceFactor(node->right)<=0) 
            return _rightCaseRotate(node);

        if(balanceFactor<-1 && _getBalanceFactor(node->right)>0) 
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    void _inorder(AVLNode *node) {
        if (node) {
            _inorder(node->left);
            printf("%d ", node->data);
            _inorder(node->right);
        }
    }

public:
    void init() {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;
        
        if (temp->data == value) return true;
        else return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = _insert_AVL(_root, value);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }

    void inorder() {
        this->_inorder(_root);
    }

    AVLNode* get_root()
    {
        return _root;
    }
};

void nyariParent(AVLNode *root, int val, int parent,int *hasil){
    if(!root)
        return;
    if(root->data==val){
        *hasil = parent; }
    else{
    nyariParent(root->left,val, root->data,hasil);
    nyariParent(root->right,val,root->data,hasil); }
}

void avl_nyariParent(AVL *avl, int val, int parent,int *hasil){
    nyariParent(avl->get_root(), val, parent, hasil);
}

void nyariSibling(AVLNode *root,int val,AVLNode *parent, int *sibling){
    if(!root)
        return;
    if(root->data==val){
        if(parent->data > val){
            if(parent->right!=NULL){
                *sibling = parent->right->data; }
            else
            *sibling = 0;
        }
        else if(parent->data < val){
            if(parent->left!=NULL){ *sibling = parent->left->data; }else *sibling = 0;
        }
        else
            *sibling = 0;
        }
    else {
        nyariSibling(root->left,val, root,sibling);
        nyariSibling(root->right,val,root,sibling);
    }
}

void avl_nyariSibling(AVL *avl, int val, int *sibling){
    nyariSibling(avl->get_root(), val,avl->get_root(), sibling);
}

int main(){
    int n, x, t, b;
    AVL tree;
    tree.init();

    scanf("%d", &n);
    scanf("%d", &t);

    while (n != 0){
        scanf("%d", &x);
        tree.insert(x);
        n--;
    }

    while (t != 0){
        {
       int data = 0;
       int parent = 0, sibling =0;
       scanf("%d", &b);
       avl_nyariParent(&tree, b, data, &parent);
       avl_nyariSibling(&tree, parent, &sibling);
       int total = abs(parent + sibling);
       printf("%d\n", total);
        t--;
    }

}
}