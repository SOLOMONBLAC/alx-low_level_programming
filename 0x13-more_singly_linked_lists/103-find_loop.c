/* Function prototype */
int addNumbers(int a, int b);

/* Function definition */
int addNumbers(int a, int b) {
    return a + b;
}

/* Main program */
#include <stdio.h>
/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */

int main() {
    int num1 = 5;
    int num2 = 10;
    int sum = addNumbers(num1, num2);
    
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    
    return 0;
}

