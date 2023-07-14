#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode {
    int key;
    struct bstnode *left, *right, *prev;
} BSTNode;

typedef struct bst {
    BSTNode *_root;
    unsigned int _size;
} BST;

// util functions

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = newNode->prev = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
    {
        return __bst__createNode(value);
    }

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
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

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
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

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

// primary functions

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

int bst_sumriteleaf(BSTNode* root, bool isrightleaf) {
    // base case
    if (!root)
    {
        return 0;
    }
    // if it is a leaf node and right node, the return root's data.
    if (!root->left && !root->right && isrightleaf)
    {
        return root->key;
    }
    // recur of left subtree and right subtree and do the summation simultaniously.
    return bst_sumriteleaf(root->left, false) + bst_sumriteleaf(root->right, true);
}


int bst_sumleftleaf(BSTNode *root, bool isleftleaf) {
    // base case
    if (!root)
    {
        return 0;
    }
    // if it is a leaf node and left node, the return root's data.
    if (!root->right && !root->left && isleftleaf)
    {
        return root->key;
    }
    // recur of right subtree and left subtree and do the summation simultaniously.
    return bst_sumleftleaf(root->right, false) + bst_sumleftleaf(root->left, true);
}

int main()
{
    int n, sum;
    char comm;
    BST tree;

    bst_init(&tree);

    while(1)
    {
        scanf("%d", &n);
        if(n == -1)
        {
            break;
        }
        bst_insert(&tree, n);
    }

    scanf("%s", &comm);

    if(tree._size == 1 || tree._size == 0)
    {
        printf("gaada pak!");
    }

    else if(comm == 'L')
    {
        sum = bst_sumleftleaf(tree._root, false);
        
        if(sum > 0)
        {
            printf("%d", sum);
        }
        else
        {
            printf("gaada pak!");
        }
    }
    else if(comm == 'R')
    {
        sum = bst_sumriteleaf(tree._root, false);
        
        if(sum > 0)
        {
            printf("%d", sum);
        }
        else
        {
            printf("gaada pak!");
        }
    }
}