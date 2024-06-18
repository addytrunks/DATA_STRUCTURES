void deleteElement(struct Node *parent, struct Node *current, int data)
    {
        if (current == NULL)
        {
            return;
        }

        if (current->data == data)
        {
            if (current->left == NULL && current->right == NULL)
            {
                if (parent == NULL)
                {
                    root = NULL; // Update root if deleting the root node
                }
                else if (parent->left == current)
                {
                    parent->left = NULL;
                }
                else
                {
                    parent->right = NULL;
                }
                free(current);
                return;
            }
            if (current->left == NULL)
            {
                if (parent == NULL)
                {
                    root = current->right; // Update root if deleting the root node
                }
                else if (parent->left == current)
                {
                    parent->left = current->right;
                }
                else
                {
                    parent->right = current->right;
                }
                free(current);
                return;
            }
            if (current->right == NULL)
            {
                if (parent == NULL)
                {
                    root = current->left; // Update root if deleting the root node
                }
                else if (parent->left == current)
                {
                    parent->left = current->left;
                }
                else
                {
                    parent->right = current->left;
                }
                free(current);
                return;
            }
            struct Node *temp = current->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            current->data = temp->data;
            deleteElement(current, current->right, temp->data);
            return;
        }

        if (data < current->data)
        {
            deleteElement(current, current->left, data);
        }
        else
        {
            deleteElement(current, current->right, data);
        }
    }