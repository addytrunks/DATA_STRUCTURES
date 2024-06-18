// Header file for the BinarySearchTree 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

class BinarySearchTree {
    struct Node* root;

    struct Node* newNode(int data);
    struct Node* insertNode(struct Node* root, int data);
    struct Node* findPrevSmaller(struct Node* root, int target);
    struct Node* findNextGreater(struct Node* root, int target);

public:
    BinarySearchTree() {
        root = NULL;
    }

    void insert(int data);
    void findPreviousAndNext(int target);
};

struct Node* BinarySearchTree::newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* BinarySearchTree::insertNode(struct Node* root, int data) {
    if (root == NULL) return newNode(data);

    if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void BinarySearchTree::insert(int data) {
    root = insertNode(root, data);
}

// Method to find the previous smaller element and the next greater element from the target element in the BST.
void BinarySearchTree::findPreviousAndNext(int target) {
    struct Node* prev = findPrevSmaller(root, target);
    struct Node* next = findNextGreater(root, target);

    printf("Target: %d\n", target);
    printf("Previous smaller element: ");
    if (prev != NULL) {
        printf("%d\n", prev->data);
    } else {
        printf("None\n");
    }
    printf("Next greater element: ");
    if (next != NULL) {
        printf("%d\n", next->data);
    } else {
        printf("None\n");
    }
}

// Method to find the previous smaller element from the target element in the BST using iterative approach.
struct Node* BinarySearchTree::findPrevSmaller(struct Node* root, int target) {
    struct Node* prev = NULL;
    while (root != NULL) {
        if (root->data >= target) {
            root = root->left;
        } else {
            prev = root;
            root = root->right;
        }
    }
    return prev;
}


// Method to find the next greater element from the target element in the BST using iterative approach.
struct Node* BinarySearchTree::findNextGreater(struct Node* root, int target) {
    struct Node* next = NULL;
    while (root != NULL) {
        if (root->data <= target) {
            root = root->right;
        } else {
            next = root;
            root = root->left;
        }
    }
    return next;
}
