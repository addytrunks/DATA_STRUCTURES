#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class BinaryTree {
    struct Node* root;
public:
    BinaryTree() {
        root = NULL;
    }
    
    void insert(int);
    void preOrder(struct Node *);
    void postOrder(struct Node *);
    void inOrder(struct Node *);
    int search(struct Node *,int);
    struct Node* getRoot() {
        return root;
    };
};

int main() {
    BinaryTree tree;
    int choice, num;
    Node *root = tree.getRoot();
    while (1) {
        printf("\n1. Insert\n2. Preorder\n3. Postorder\n4. Inorder\n5. Search\n6.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &num);
                tree.insert(num);
                break;
            case 2:
                printf("Preorder: ");
                tree.preOrder(tree.getRoot());
                break;
            case 3:
                printf("Postorder: ");
                tree.postOrder(tree.getRoot());
                break;
            case 4:
                printf("Inorder: ");
                tree.inOrder(tree.getRoot());
                break;
            case 5:
                printf("Enter the number to insert: ");
                scanf("%d", &num);
                tree.search(tree.getRoot(), num);
            default:
                printf("Invalid choice\n");
        }
    }
    printf("\n");
    return 0;
}

void BinaryTree::insert(int num){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL) {
        root = newNode;
        return;
    }else{
        struct Node *temp = root;  
        while(1){
            char choice;
            printf("Enter the direction to insert (l/r) of %d: ", root->data);
            scanf(" %c", &choice);
            if(choice == 'l' || choice == 'L'){
                if(temp->left == NULL){
                    temp->left = newNode;
                    break;
                }else{
                    temp = temp->left;
                }
            }else{
                if(temp->right == NULL){
                    temp->right = newNode;
                    break;
                }else{
                    temp = temp->right;
                }
        }
    }
    }
}

void BinaryTree::preOrder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void BinaryTree::postOrder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void BinaryTree::inOrder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
