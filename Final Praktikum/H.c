#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct bstnode {
    int key, level;
    struct bstnode *left, *right;
} BSTNode;

typedef struct bst {
    BSTNode *_root;
    int _size;
} BST;

typedef struct node{
    int data;
    struct node *next;

} Node, *NodePtr;

/* Stack */
typedef struct stack{
    NodePtr head;
    int size;

} Stack;


// util functions

BSTNode* __bst__createNode(int value, int level) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->level = level;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int level) {
    if (root == NULL) 
        return __bst__createNode(value, level);

    if (value < root->key)
        root->left = __bst__insert(root->left, value, level+1);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value, level+1);
    
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
        bst->_root = __bst__insert(bst->_root, value, 1);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}


void initStack(Stack *stack)
{
    stack->size = 0;
    stack->head = (NodePtr) malloc(sizeof(Node));               //allocate memory for head node
    stack->head->next = NULL;                                   //assign NULL to head's link 
}

void pushElem(Stack *stack, int elem)
{
    NodePtr curr;                                               //declare a new node pointer, curr

    if(stack->size == 0)                                        //if stack doesn't have an element yet
    {
        stack->head->data = elem;                               //assign element to head's data
        stack->head->next = NULL;                               
        stack->size++;                                          //increment size to track the number of elements in a stack
    }
    else                                                        //if stack already has an element
    {
        NodePtr curr = (NodePtr) malloc(sizeof(Node));          //allocate memory for a new node(curr)
        curr->data = elem;                                      //assign element to curr's data
        curr->next = stack->head;                               //assign curr's link to head pointer
        stack->head = curr;                                     //pointer curr is now the head of stack
        stack->size++;                                          //increment size to track the number of elements in a stack
    }
}

void popElem(Stack *stack)
{
    NodePtr curr;                                               //declare a new node pointer, curr

    if(stack->size == 1)                                        //if there is only 1 element at a stack
    {
        stack->head->data = 0;                                  //head's data become 0
        stack->size--;                                          //decrement size to track the number of elements in a stack
    }
    else                                                        //if stack elements is > 1
    {
        curr = stack->head->next;                               //curr is pointing at the node after head
        free(stack->head);                                      //free the head node
        stack->head = curr;                                     //pointer curr is now the head of stack
        stack->size--;                                          //decrement size to track the number of elements in a stack
    }
}


void bst_FD (BST bst, int value)
{
    BSTNode *temp = __bst__search(bst._root, value);

    if (temp == NULL){
        printf("no %d\n", value);
    }
    else{
        printf("on level %d\n", temp->level);
    }
}

void __bst__inorderRK(BSTNode *, int, Stack *);

void bst_RK (BST bst, int value)
{
    int temp = bst._size;

    Stack counter;
    initStack(&counter);

    while(temp != 0){
        pushElem(&counter, temp);
        temp--;
    }

    if(value > bst._size){
        printf("-1\n");
    }
    else{
        __bst__inorderRK(bst._root, value, &counter);
    }
}

void __bst__inorderRK(BSTNode *root, int value, Stack *counter) {
     if (root) {
        __bst__inorderRK(root->left, value, counter);

        if(counter->head->data == value){
            printf("%d\n", root->key);
        }
        popElem(counter);

        __bst__inorderRK(root->right, value, counter);
    }
}

void bst_PH(int value, BST bst){
    if (!bst_find(&bst, value))
    {
        printf("no %d\n", value);
    }
    else
    {
        while(1) 
        {
            if (value < bst._root->key){
                bst._root = bst._root->left;
                printf("L");
            }
            else if (value > bst._root->key){
                bst._root = bst._root->right;
                printf("R");
            }
            else if (value == bst._root->key){
                printf("S\n");
                break;
            }
        }
    }
}

int main()
{
    int x;
    char comms[10];
    BST bst;

    bst_init(&bst);

    while(1){
        scanf("%s", comms);

        if (strcmp(comms, "STOP") == 0){
            printf("done"); 
            break;
        }
        else if (strcmp(comms, "IN") == 0){
            scanf(" %d", &x);
            bst_insert(&bst, x);
        }
        else if (strcmp(comms, "FD") == 0){
            scanf(" %d", &x);
            bst_FD(bst, x);
        }
        else if (strcmp(comms, "RK") == 0){
            scanf(" %d", &x);
            bst_RK(bst, x);
        }
        else if (strcmp(comms, "PH") == 0){
            scanf(" %d", &x);
            bst_PH(x, bst);
        }
    }
}