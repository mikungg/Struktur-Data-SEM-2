#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode {
    int key;
    struct bstnode *left, *right;
} BSTNode;

typedef struct bst {
    BSTNode *_root;
    unsigned int _size;
} BST;

// util functions

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

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

BSTNode* bst_lowestanc(BST bst, int a, int b) {
    if(bst_find(&bst, a) == false)
    {
        printf("%d is not found within the tree", a);
    }
    else if(bst_find(&bst, b) == false)
    {
        printf("%d is not found within the tree", b);
    }

    while(1)
    {   
        if(a == bst._root->key || b == bst._root->key)
        {
            return bst._root;
        }
        else if(a > bst._root->key && b < bst._root->key)
        {
            return bst._root;
        }
        else if(a < bst._root->key && b > bst._root->key)
        {
            return bst._root;
        }
        else if(a < bst._root->key && b < bst._root->key)
        {
            bst._root = bst._root->left;
        }
        else if(a > bst._root->key && b > bst._root->key)
        {
            bst._root = bst._root->right;
        }
    }
}

int bst_finddist(BST bst, int a, int b) {
    int sum = 0;
    BSTNode *lca;

    lca = bst_lowestanc(bst, a, b);

    while (lca->key != a) {
        if (a < lca->key)
        {
            lca = lca->left;
            sum++;
        }
        else if (a > lca->key)
        {
            lca = lca->right;
            sum++;
        }
    }

    lca = bst_lowestanc(bst, a, b);

    while (lca->key != b) {
        if (b < lca->key)
        {
            lca = lca->left;
            sum++;
        }
        else if (b > lca->key)
        {
            lca = lca->right;
            sum++;
        }
    }
    
    return sum;
}

int main()
{
    int n, capy, testc, a, b;
    BST bloodline;

    scanf("%d", &n);
    bst_init(&bloodline);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &capy);
        bst_insert(&bloodline, capy);
    }

    scanf("%d", &testc);

    for(int i = 0; i < testc; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", bst_finddist(bloodline, a, b));
    }   
}