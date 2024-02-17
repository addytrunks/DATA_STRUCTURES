// Linked List Implementation
#include <stdio.h>
#include <stdlib.h>

// Datatype of a node
struct Node
{
    int data;
    struct Node *next;
};

class Linked_List
{
    struct Node *head;

public:
    Linked_List()
    {
        head = NULL;
    }
    // Method to count the number of elements in the list : O(n)
    int count_nodes()
    {
        int count = 0;
        struct Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Method to display the contents of the list: O(n)
    void display()
    {
        struct Node *temp;
        temp = head;

        if (head == NULL)
        {
            printf("Empty list.");
        }
        else
        {

            while (temp != NULL)
            {
                printf("%d->", temp->data);
                temp = temp->next;
            }
        }
    }

    // Method to insert a number in beginning of the list: O(1)
    void insert_beg(int data)
    {
        struct Node *new_node;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = head;
        head = new_node;
        printf("Element has been inserted at the beginning.\n");
    }

    // Method to insert a number in end of the list: O(n)
    void insert_end(int data)
    {
        struct Node *temp, *new_node;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        printf("Element has been inserted at the end.\n");
    }

    // Method to insert a number in given position of the list: O(n)
    void insert_pos(int data, int pos)
    {
        struct Node *temp, *new_node;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        temp = head;

        if (pos == 0)
        {
            insert_beg(data);
        }
        else if (pos == count_nodes())
        {
            insert_end(data);
        }
        else if(pos < 0 || pos >= count_nodes()){
            printf("Invalid position.");
        }else
        {
            int index = 0;
            while (index != pos - 1)
            {
                temp = temp->next;
                index++;
            }
            new_node->next = temp->next;
            temp->next = new_node;
            printf("Element has been inserted at position %d.\n", pos);
        }
    }

    // Method to delete the first element in the list: O(1)
    int delete_beg()
    {
        if (head == NULL)
        {
            printf("Empty List. Nothing to be deleted.");
            return -1; // Return a default value to indicate failure
        }
        else
        {
            struct Node *temp;
            int deleted_value;
            temp = head;
            head = head->next;
            deleted_value = temp->data;
            free(temp);
            printf("First element (%d) has been deleted.\n", deleted_value);
            return deleted_value;
        }
    }

    // Method to delete the last element in the list and return the deleted element : O(1)
    int delete_end()
    {
        if (head == NULL)
        {
            printf("Empty List. Nothing to be deleted.");
            return -1; // Return a default value to indicate failure
        }
        else
        {
            int deleted_value;
            if (count_nodes() == 1)
            {
                return delete_beg(); // If there's only one node, call delete_beg()
            }
            else
            {
                struct Node *p, *q;
                p = head;
                q = head->next;
                while (q->next != NULL)
                {
                    p = p->next;
                    q = q->next;
                }
                p->next = NULL;
                deleted_value = q->data;
                free(q);
                printf("Last element (%d) has been deleted.\n", deleted_value);
                return deleted_value;
            }
        }
    }

    // Method to delete the element at a specified position in the list and return the deleted element : O(1)
    int delete_pos(int pos)
    {
        if (head == NULL)
        {
            printf("Empty List. Nothing to be deleted.");
            return -1; // Return a default value to indicate failure
        }
        else
        {
            int deleted_value;
            if (pos == 0)
            {
                return delete_beg(); // If position is 0, call delete_beg()
            }
            else if (pos == count_nodes() - 1)
            {
                return delete_end(); // If position is last, call delete_end()
            }
            else
            {
                struct Node *p, *q;
                p = head;
                q = head->next;
                for (int i = 0; i < pos - 1; i++)
                {
                    p = p->next;
                    q = q->next;
                }
                p->next = q->next;
                deleted_value = q->data;
                free(q);
                printf("Element at position %d (%d) has been deleted.\n", pos, deleted_value);
                return deleted_value;
            }
        }
    }

    // Method to delete the iTH element in the list : O(n)
    void search(int data)
    {
        struct Node *temp;
        temp = head;
        int found, index;
        found = 0;
        index = 0;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                found = 1;
                break;
            }
            else
            {
                temp = temp->next;
                index += 1;
            }
        }
        if (found == 1)
        {
            printf("The element %d has been found at index %d", data, index);
        }
        else
        {
            printf("The given element does not exist in the list.");
        }
    }

    // Method to display the contents of the list reversed : O(n)
    void display_reverse()
    {
        int arr[count_nodes()];
        struct Node *temp;
        temp = head;
        int index = 0;
        while (temp != NULL)
        {
            arr[index] = temp->data;
            temp = temp->next;
            index += 1;
        }
        printf("Displaying the list in reverse order:\n");
        for (int i = count_nodes() - 1; i >= 0; i--)
        {
            printf("%d->", arr[i]);
        }
    }

    // Method to reverse the list: O(n)
    void reverse()
    {
        if (head == NULL)
        {
            printf("Empty list.");
        }
        else
        {
            struct Node *curr, *prev, *next;
            curr = head;
            prev = NULL;
            next = NULL;

            while (curr != NULL)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
            printf("The list has been reversed.");
        }
    }
};

int main()
{

    Linked_List l1;
    int choice, num, pos;

    while (1)
    {
        printf("\nEnter \n1. Insert Begin\n2. Insert End\n3. Insert Position");
        printf("\n4. Delete Begin\n5. Delete End\n6. Delete Position");
        printf("\n7. Search\n8. Display\n9. Display Reverse\n10.Reverse Link\n11.Exit");
        printf("\n Enter a choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number:");
            scanf("%d", &num);
            l1.insert_beg(num);
            break;
        case 2:
            printf("Enter the number:");
            scanf("%d", &num);
            l1.insert_end(num);
            break;
        case 3:
            printf("\n Enter the number insert:");
            scanf("%d", &num);
            printf("\n Enter the position at which you want to insert:");
            scanf("%d", &pos);
            l1.insert_pos(num, pos);
            break;
        case 4:
            l1.delete_beg();
            break;
        case 5:
            l1.delete_end();
            break;
        case 6:
            printf("\n Enter the position at which you want to delete:");
            scanf("%d", &pos);
            l1.delete_pos(pos);
            break;
        case 7:
            printf("\n Enter the number  which you want to search:");
            scanf("%d", &num);
            l1.search(num);
            break;
        case 8:
            l1.display();
            break;
        case 9:
            l1.display_reverse();
            break;
        case 10:
            l1.reverse();
            break;
        case 11:
            exit(1);
            break;
        default:
            printf("\n Enter a valid choice\n");
            break;
        }
    }
}
