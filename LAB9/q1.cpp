#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

class BinarySearchTree
{
    struct Node *root;
    struct Node *insert(struct Node *root, int data)
    {
        if (root == NULL)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }

public:
    BinarySearchTree()
    {
        root = NULL;
    }

    void preOrder(struct Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(struct Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
    void inOrder(struct Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }

    void deleteElement(struct Node *parent, struct Node *current, int data)
    {
        if (current == NULL)
        {
            return;
        }

        if (current->data == data)
        {
            // Case 1: Leaf Node (No children)
            if (current->left == NULL && current->right == NULL)
            {
                // checks are used to handle the case where the node to be deleted is the root of the tree.
                if (parent == NULL)
                {
                    root = NULL;
                }
                else if (parent->right == current)
                {
                    parent->right = NULL;
                }
                else
                {
                    parent->left = NULL;
                }
                free(current);
                return;
            }
            // Case 2: Child on right
            if (current->left == NULL)
            {
                // checks are used to handle the case where the node to be deleted is the root of the tree.
                if (parent == NULL)
                {
                    root = current->right;
                }
                else if (parent->right == current)
                {
                    parent->right = current->right;
                }
                else
                {
                    parent->left = current->right;
                }
                free(current);
                return;
            }
            // Case 3: Child on left
            if (current->right == NULL)
            {
                // checks are used to handle the case where the node to be deleted is the root of the tree.
                if (parent == NULL)
                {
                    root = current->left;
                }
                else if (parent->right == current)
                {
                    parent->right = current->left;
                }
                else
                {
                    parent->left = current->left;
                }
                free(current);
                return;
            }
            // Case 4: Two children
            // Go to leftmost of right subtree
            // Delete
            struct Node *temp = current->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            current->data = temp->data;
            deleteElement(current, current->right, temp->data);
            return;
        }

        if (current->data > data)
        {
            deleteElement(current, current->left, data);
        }
        else
        {
            deleteElement(current, current->right, data);
        }
    }

    void insert(int data)
    {
        root = insert(root, data);
    }

    struct Node *getRoot()
    {
        return root;
    }

    int search(struct Node *root, int data)
    {
        if (root == NULL)
        {
            printf("Element not found\n");
            return 0;
        }
        if (root->data == data)
        {
            printf("Element found\n");
            return 1;
        }
        if (data < root->data)
        {
            return search(root->left, data);
        }
        return search(root->right, data);
    }

    int findMax()
    {
        if (root == NULL)
        {
            return -1;
        }
        else
        {
            struct Node *temp = root;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            return temp->data;
        }
    }

    int findMin()
    {
        if (root == NULL)
        {
            return -1;
        }
        else
        {
            struct Node *temp = root;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            return temp->data;
        }
    }
};

int main()
{
    BinarySearchTree bst;
    int choice;
    int num;
    while (1)
    {
        printf("\n1. Insert\n2. Preorder\n3. Postorder\n4. Inorder\n5. Search\n6.Delete\n7.Exit\n8.Max Element\n9.Min Element\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            bst.insert(num);
            break;
        case 2:
            printf("Preorder: ");
            bst.preOrder(bst.getRoot());
            break;
        case 3:
            printf("Postorder: ");
            bst.postOrder(bst.getRoot());
            break;
        case 4:
            printf("Inorder: ");
            bst.inOrder(bst.getRoot());
            break;
        case 5:
            int found;
            printf("Enter the number to search: ");
            scanf("%d", &num);
            found = bst.search(bst.getRoot(), num);
            if (found == 1)
            {
                printf("Element %d found in the tree.", num);
            }
            else
            {
                printf("Element not found in the tree.");
            }
            break;
        case 6:
            printf("Enter the number to delete: ");
            scanf("%d", &num);
            bst.deleteElement(NULL, bst.getRoot(), num);
            break;
        case 8:
            printf("Max: %d\n", bst.findMax());
            break;
        case 9:
            printf("Min: %d\n", bst.findMin());
            break;
        case 7:
            printf("Exit successful");
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    printf("\n");
    return 0;
}
