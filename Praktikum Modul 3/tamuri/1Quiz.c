/*
Tamara Jovanka - 5025221213
Struktur Data B
*/

// PreOrder
struct Node* preOrderSearch(struct Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == target) {
        return root;
    }
    struct Node* foundNode = preOrderSearch(root->left, target);
    if (foundNode != NULL) {
        return foundNode;
    }
    return preOrderSearch(root->right, target);
}

// Fungsi rekursif untuk pencarian menggunakan metode in-order
struct Node* inOrderSearch(struct Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }
    struct Node* foundNode = inOrderSearch(root->left, target);
    if (foundNode != NULL) {
        return foundNode;
    }
    if (root->data == target) {
        return root;
    }
    return inOrderSearch(root->right, target);
}

// Fungsi rekursif untuk pencarian menggunakan metode post-order
struct Node* postOrderSearch(struct Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }
    struct Node* foundNode = postOrderSearch(root->left, target);
    if (foundNode != NULL) {
        return foundNode;
    }
    foundNode = postOrderSearch(root->right, target);
    if (foundNode != NULL) {
        return foundNode;
    }
    if (root->data == target) {
        return root;
    }
    return NULL;
}