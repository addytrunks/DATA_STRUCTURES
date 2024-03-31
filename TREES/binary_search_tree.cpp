#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node *left;
    struct Node *right;
};

class BinarySearchTree{
    struct Node *root;
    struct Node *insert(struct Node *root, char data){
        if(root == NULL){
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }
        if(data < root->data){
            root->left = insert(root->left, data);
        }else{
            root->right = insert(root->right, data);
        }
        return root;
    }
    void preOrder(struct Node *root){
        if(root == NULL){
            return;
        }
        printf("%c ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(struct Node *root){
        if(root == NULL){
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", root->data);
    }
    void inOrder(struct Node *root){
        if(root == NULL){
            return;
        }
        inOrder(root->left);
        printf("%c ", root->data);
        inOrder(root->right);
    }

    void deleteElement(struct Node *root, char data){
        if(root == NULL){
            return;
        }
        if(root->data == data){
            if(root->left == NULL && root->right == NULL){
                free(root);
                return;
            }
            if(root->left == NULL){
                struct Node *temp = root;
                root = root->right;
                free(temp);
                return;
            }
            if(root->right == NULL){
                struct Node *temp = root;
                root = root->left;
                free(temp);
                return;
            }
            struct Node *temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            deleteElement(root->right, temp->data);
            return;
        }
        if(data < root->data){
            deleteElement(root->left, data);
        }else{
            deleteElement(root->right, data);
        }
    }
}