// C program to solve the Tower of Hanoi problem using recursion.
// The Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective is to move the entire stack of disks from the source rod to the destination rod, following these rules:
// 1. Only one disk can be moved at a time.
// 2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
// 3. No disk may be placed on top of a smaller disk.

// Logic is to move n-1 disks from source to auxiliary, then move the nth disk from source to destination, and finally move the n-1 disks from auxiliary to destination.
#include <stdio.h>
void towersOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towersOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towersOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int source, destination, auxiliary, n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towersOfHanoi(n, 'A', 'B', 'C');
    return 0;
}