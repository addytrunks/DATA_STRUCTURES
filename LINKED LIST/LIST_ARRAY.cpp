// Array implementation of List ADT
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
class List
{
    int arr[SIZE];
    int curr;

public:
    List()
    {
        curr = -1;
    }
    int insbeg(int);
    int insend(int);
    int insposition(int, int);

    int search(int);

    int delend();
    int delbegin();
    int delpos(int);

    void display();
};

int main()
{
    List l1;
    int choice, num, pos;
    while (1)
    {
        printf("\nEnter \n1. Insert Begin\n2. Append\n3. Insert Position");
        printf("\n4. Pop\n5. Delete Begin\n6. Delete Position");
        printf("\n7. Search\n8. Display\n9. Exit");
        printf("\n Enter a choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the number insert:");
            scanf("%d", &num);
            if (l1.insbeg(num))
            {
                printf("\n %d successfully inserted.", num);
            }
            else
            {
                printf("\n Failed to insert %d. The list is full.", num);
            }
            break;
        case 2:
            printf("\n Enter the number insert:");
            scanf("%d", &num);

            if (l1.insend(num))
            {
                printf("\n %d successfully inserted.", num);
            }
            else
            {
                printf("\n Failed to insert %d. The list is full.", num);
            }
            break;
        case 3:
            printf("\n Enter the number insert:");
            scanf("%d", &num);
            printf("\n Enter the position at which you want to insert:");
            scanf("%d", &pos);
            if (l1.insposition(num, pos))
            {
                printf("\n %d successfully inserted.", num);
            }
            else
            {
                printf("\n Failed to insert %d. The list is full.", num);
            }
            break;
        case 4:
            if (l1.delend())
            {
                printf("Last element has been deleted.");
                l1.display();
            }
            else
            {
                printf("Empty list. No element to delete.");
            }
            break;
        case 5:
            if (l1.delbegin())
            {
                printf("First element has been deleted.");
                l1.display();
            }
            else
            {
                printf("Empty list. No element to delete.");
            }
            break;
        case 6:
            printf("\n Enter the position at which you want to delete:");
            scanf("%d", &pos);
            if (l1.delpos(pos))
            {
                printf("Element successfully deleted.");
                l1.display();
            }
            else
            {
                printf("List empty. Cannot delete.");
            }
            break;
        case 7:
            printf("\nEnter the number you want to search:");
            scanf("%d", &num);
            l1.search(num);
            break;
        case 8:
            l1.display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("\n Enter a valid choice\n");
            break;
        }
    }
    return 0;
}

// Method to insert a number in beginning of the list
int List::insbeg(int num)
{
    if (curr == SIZE - 1)
    {
        return 0;
    }
    else if (curr == -1)
    {
        curr = 0;
        arr[0] = num;
        return 1;
    }
    else
    {
        for (int i = curr; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        curr = curr + 1;
        arr[0] = num;
        return 1;
    }
}

// Method to insert a number in end of the list
int List::insend(int num)
{
    if (curr == SIZE - 1)
    {
        return 0;
    }
    else
    {
        curr += 1;
        arr[curr] = num;
        return 1;
    }
}

// Method to insert a number in given position of the list
int List::insposition(int num, int pos)
{
    if (curr == SIZE - 1)
    {
        return 0;
    }
    else if (pos == 0)
    {
        insbeg(num);
        return 1;
    }
    else if (pos == curr + 1)
    {
        insend(num);
        return 1;
    }
    else
    {
        for (int i = curr; i >= pos; i--)
        {
            arr[i + 1] = arr[i];
        }
        curr += 1;
        arr[pos] = num;
        return 1;
    }
}

// Method to search for an element
int List::search(int num)
{
    int found = 0;
    for (int i = 0; i <= curr; i++)
    {
        if (arr[i] == num)
        {
            printf("Element found at position %d", i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("The given element does not exist.");
    }

    return found;
}

// Method to display the contents of the list
void List::display()
{
    if (curr == -1)
    {
        printf("\nEmpty List.");
    }
    else
    {
        printf("\nThe contents of the list are:");
        for (int i = 0; i <= curr; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}

// Method to delete the first element in the list
int List::delbegin()
{
    if (curr == -1)
    {
        return 0; // Empty list
    }
    else
    {
        for (int i = 0; i < curr; i++)
        {
            arr[i] = arr[i + 1]; // Shift elements to the left to overwrite the first element
        }
        curr--;  
        return 1;
    }
}

// Method to delete the last element in the list
int List::delend()
{
    if (curr == -1)
    {
        return 0; // Empty list
    }
    else
    {
        curr--;   // Decrement the current size of the list
        return 1;
    }
}

// Method to delete the iTH element in the list
int List::delpos(int pos)
{
    if (curr == -1 || pos < 0 || pos > curr)
    {
        return 0; // Invalid position or empty list
    }
    else if (pos == 0)
    {
        return delbegin(); // Call delbegin() to delete the first element
    }
    else if (pos == curr)
    {
        return delend(); // Call delend() to delete the last element
    }
    else
    {
        for (int i = pos; i < curr; i++)
        {
            arr[i] = arr[i + 1]; // Shift elements to the left to overwrite the element at the given position
        }
        curr--; 
        return 1;
    }
}