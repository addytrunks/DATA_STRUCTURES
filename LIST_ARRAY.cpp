// Array implementation of List ADT
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
class List
{
    int arr[SIZE];
    int end, beg;

public:
    List()
    {
        end = -1;
        beg = 0;
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
        printf("Enter \n1. Insert Begin\n2. Append\n3. Insert Position");
        printf("\n4. Delete Begin\n5. Pop\n6. Delete Position");
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
            if (l1.delpos(pos)){
                printf("Element successfully deleted.");
                l1.display();
            }else{
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
    if (end == SIZE - 1)
    {
        return 0;
    }
    else if (end == -1)
    {
        end = 0;
        arr[0] = num;
        return 1;
    }
    else
    {
        for (int i = end; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        end = end + 1;
        arr[0] = num;
        return 1;
    }
}

// Method to insert a number in end of the list
int List::insend(int num)
{
    if (end == SIZE - 1)
    {
        return 0;
    }
    else
    {
        end += 1;
        arr[end] = num;
        return 1;
    }
}

// Method to insert a number in given position of the list
int List::insposition(int num, int pos)
{
    if (end == SIZE - 1)
    {
        return 0;
    }
    else if (pos == 0)
    {
        insbeg(num);
        return 1;
    }
    else if (pos == end + 1)
    {
        insend(num);
        return 1;
    }
    else
    {
        for (int i = end; i >= pos; i--)
        {
            arr[i + 1] = arr[i];
        }
        end += 1;
        arr[pos] = num;
        return 1;
    }
}

// Method to delete the last number in the list
int List::delend(){
    if (end == -1 || (beg == end))
    {
        return 0;
    }
    else
    {
        end--;
        return 1;
    }
}

// Method to delete the first number in the list
int List::delbegin()
{
    if (end == -1 || (beg == end))
    {
        return 0;
    }
    else
    {
        beg += 1;
        return 1;
    }
}

// Method to search for an element
int List::search(int num)
{
    int found = 0;
    for (int i = 0; i <= end; i++)
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
    if (end == -1 || (beg == end))
    {
        printf("\nEmpty List.");
    }
    else
    {
        printf("\nThe contents of the list are:");
        for (int i = beg; i <= end; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}
