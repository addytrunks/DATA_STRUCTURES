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
   void deleteNode(int);
   struct Node* deleteNodeRecursive(Node* root, int key) {
   if (root == NULL) {
       return root;
   }

   // If the current node is the node to be deleted
   if (root->data == key) {
       // Free memory for the current node
       free(root);
       return NULL; // Return NULL to indicate that this node has been deleted
   }

   // Recur for left subtree and right subtree
   root->left = deleteNodeRecursive(root->left, key);
   root->right = deleteNodeRecursive(root->right, key);

   return root; // Return the modified root (if not deleted)
}

};

int main() {
   BinaryTree tree;
   int choice, num;
   while (1) {
       printf("\n1. Insert\n2. Preorder\n3. Postorder\n4. Inorder\n5. Search\n6.Delete\n7.Exit\nEnter your choice: ");
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
               int found; 
               printf("Enter the number to search: ");
               scanf("%d", &num);
               found = tree.search(tree.getRoot(), num);
               if(found == 1){
                   printf("Element %d found in the tree.",num);
               }else{
                   printf("Element not found in the tree.");
               }
               break;
           case 6:
               printf("Enter the number to delete: ");
               scanf("%d", &num);
               tree.deleteNode(num);
           default:
               printf("Invalid choice\n");
               break;
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
           printf("Enter the direction to insert (l/r) of %d: ", temp->data);
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

int BinaryTree::search(struct Node *root,int key){
   if(root == NULL){
       return 0;
   }

   if(root->data == key){
       return 1;
   }

   int res1 = search(root->left,key);

   if(res1 == 1){
       return 1;
   }

   int res2 = search(root->right,key);

   return res2;
}

void BinaryTree::deleteNode(int key) {
   if(search(root,key) == 1){
       root = deleteNodeRecursive(root, key);
   }else{
       printf("No element found,nothing to be deleted.");
   }
}

