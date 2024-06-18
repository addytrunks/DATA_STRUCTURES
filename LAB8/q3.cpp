#include <stdio.h>
#include "q3.h"

int main() {
    BinarySearchTree tree;
    int n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        tree.insert(num);
    }
    printf("Enter the number to find: ");
    scanf("%d", &target);
    tree.findPreviousAndNext(target);

    return 0;
}
