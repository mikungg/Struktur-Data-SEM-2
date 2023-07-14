#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

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

int minim[25], maxim[25];
int height = 0;     // global

void findMinimumMax(BSTNode *root, int value, int lvl)
{
    if (root == NULL)   //basecase
    {
        return;
    }
        
    if (value != root->key)
    {
        if (minim[lvl] == 0 || root->key < minim[lvl])
        {
            minim[lvl] = root->key;
        }
        if (root->key > maxim[lvl])
        {
            maxim[lvl] = root->key;
        }
        findMinimumMax(root->left, value, lvl + 1);
        findMinimumMax(root->right, value, lvl + 1);
    }
    else
    {
        if (root->left || root ->right){  // ngecheck punya child apa ga
            height = lvl;              
        }   // kenapa kondisi if nya ngecheck child karena dan baru ngubah height nya setelah masuk if itu karena
    }       // sesuai soal kalo supplynya harus aman dari segala arah
}

void bst_findminmax(BST *bst, int value)
{
    findMinimumMax(bst->_root, value, 0);
}

int main(){
    int n, x, m;
    BST team;
    team.init();

    scanf("%d", &n);

    while(n != 0){
        scanf("%d", &x);
        team.insert(x);
        n--;
    }

    scanf("%d", &m);
    bst_findminmax(&team, m);

    if (height != 0 && minim[height]<m && maxim[height]>m){
        printf("Supply aman");
    }
    else{
        printf("Ga aman, ganti lokasi!");
    }
}