#include <stdio.h>
#include <stdlib.h>

class btree
{
    struct node
    {
        char data;
        struct node *left;
        struct node *right;
    };
    struct node *root;

public:
    btree()
    {
        root = NULL;
    }
    int insert(char);
    int search(struct node *, char);
    void inorder(struct node *);
    void preorder(struct node *);
    void postorder(struct node *);
    void delnode(char);
    struct node *getroot()
    {
        return root;
    }
    struct node *deleteRecursive(struct node *, char);
    struct node *findRightmost(struct node *);
};

int main()
{
    int choice;
    char ch;
    btree b1;
    while (1)
    {
        printf("\n1.insert\n2.inorder\n3.preorder\n4.postorder\n5.search\n6.delete\n7.exit\nEnter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter character to be inserted:");
            scanf(" %c", &ch);
            if (b1.insert(ch))
            {
                printf("successful");
            }
            else
            {
                printf("unsuccessful");
            }
            break;
        case 2:
            b1.inorder(b1.getroot());
            break;
        case 3:
            b1.preorder(b1.getroot());
            break;
        case 4:
            b1.postorder(b1.getroot());
            break;
        case 5:
            printf("enter the character:");
            scanf(" %c", &ch);
            if (b1.search(b1.getroot(), ch))
            {
                printf("found");
            }
            else
            {
                printf("not found");
            }
            break;
        case 6:
            printf("enter character:");
            scanf(" %c", &ch);
            b1.delnode(ch);
            break;
        case 7:
            printf("exited");
            exit(0);
            break;
        default:
            printf("invalid");
            break;
        }
    }
}

int btree::insert(char ch)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = ch;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL)
    {
        root = newnode;
        return 1;
    }
    else
    {

        struct node *temp = root;
        while (1)
        {
            int side;
            printf("enter 1 for left,2 for right insertion:");
            scanf("%d", &side);
            if (side == 1)
            {
                if (temp->left == NULL)
                {
                    temp->left = newnode;
                    break;
                    return 1;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = newnode;
                    break;
                    return 1;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

void btree::inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf(" %c", root->data);
    inorder(root->right);
}

void btree::preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf(" %c", root->data);
    preorder(root->left);
    preorder(root->right);
}

void btree::postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf(" %c", root->data);
}

int btree::search(struct node *root, char ch)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == ch)
    {
        return 1;
    }
    int res1 = search(root->left, ch);
    if (res1 == 1)
    {
        return 1;
    }
    int res2 = search(root->right, ch);
    return res2;
}

void btree::delnode(char ch)
{
    root = deleteRecursive(root, ch);
}

struct btree::node *btree::deleteRecursive(struct node *root, char ch)
{
    // Base case: If the tree is empty, item not found
    if (root == NULL)
    {
        return root;
    }

    // If the node to be deleted is found
    if (ch == root->data)
    {
        // Case 1: Node to be deleted has no children
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2: Node to be deleted has one child
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Node to be deleted has two children
        else
        {
            struct node *temp = findRightmost(root);              // Find the rightmost node in the tree
            root->data = temp->data;                              // Replace data of the node to be deleted with the data of the rightmost node
            root->left = deleteRecursive(root->left, temp->data); // Delete the rightmost node
        }
    }
    // If the item is not found in the current node, recursively search in left and right subtrees
    else
    {
        root->left = deleteRecursive(root->left, ch);
        root->right = deleteRecursive(root->right, ch);
    }
    return root;
}

struct btree::node *btree::findRightmost(struct node *root)
{
    // Traverse to the rightmost node in the tree
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
