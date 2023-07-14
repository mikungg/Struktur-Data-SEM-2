#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* Node structure */

struct BSTNode {
    BSTNode *left, *right;
    int key;
};

/* uniqueBST */

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;
    int singleChild;

    // Function
    void init() {
        _root = NULL;
        _size = 0u;
        singleChild = 0;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }

    void singleChildParent(){
        customInorder(_root);
    }

private:
    // Utility Function
    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->right = __remove(root->right, value);
        else if (value < root->key) 
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void customInorder(BSTNode *root) {
        if (root){
            customInorder(root->left);
            

            if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)){
                printf("%d ", root->key);
                singleChild++;
            }


            customInorder(root->right);
        }
    }

    void __postorder(BSTNode *root) {
        if (root) {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root) {
        if (root) {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }
};

int main()
{
    int n, comm, x;
    BST bst;
    bst.init();

    scanf("%d", &n);

    while(n != 0){
        scanf("%d", &comm);

        if(comm == 15){
            scanf("%d", &x);
            bst.insert(x);
        }

        else if(comm == 04){
            scanf("%d", &x);
            bst.remove(x);
        }
        
        else if(comm == 89){
            bst.singleChild = 0;
            bst.singleChildParent();

            if(bst.singleChild == 0){
                printf("Use whatever means you must to control our population. Just do it.\n");
            }
        }

        n--;
    }
}