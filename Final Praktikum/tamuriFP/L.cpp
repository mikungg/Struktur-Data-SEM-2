#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Node structure */

struct BSTNode {
    BSTNode *left, *right;
    int key, level;
};

/* uniqueBST */

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;
    int maxVal[100000] = {0};

    // Function
    void init() {
        _root = NULL;
        _size = 0u;
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
            _root = __insert(_root, value, 1);
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

    void maxInLvl(){
        maxUtil(_root, 1);

        int i = 1;
        while(1)
        {
            if (maxVal[i] == 0){
                break;
            }
            else{
                printf("%d\n", maxVal[i]);
                i++;
            }
        }
    }
private:
    // Utility Function
    BSTNode* __createNode(int value, int level) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->level = level;
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

    BSTNode* __insert(BSTNode *root, int value, int level) {
        if (root == NULL)
            return __createNode(value, level);
        
        if (value < root->key)
            root->left = __insert(root->left, value, level+1);
        else if (value > root->key)
            root->right = __insert(root->right, value, level+1);
        
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

    void maxUtil(BSTNode *root, int lvl){
        if (root == NULL){
            return;
        }
        else if (root->key > maxVal[lvl]){
            maxVal[lvl] = root->key;
        }

        maxUtil(root->left, lvl+1);
        maxUtil(root->right, lvl+1);
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



int main(){
    int x;
    BST atf;
    
    atf.init();

    while(cin >> x){
        atf.insert(x);
    }

    atf.maxInLvl();
}