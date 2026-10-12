
#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value)
{
    int parent, i;

    if (size == MAX)
    {
        printf("Heap is full!\n");
        return;
    }

    heap[size] = value;
    i = size;
    size++;

    while (i > 0)
    {
        parent = (i - 1) / 2;

        if (heap[parent] >= heap[i])
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

void deleteRoot()
{
    int deleted, left, right, largest, i;

    if (size == 0)
    {
        printf("Heap is empty!\n");
        return;
    }

    deleted = heap[0];
    heap[0] = heap[size - 1];
    size--;

    i = 0;

    while (1)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&heap[i], &heap[largest]);
        i = largest;
    }

    printf("Deleted element: %d\n", deleted);
}

void display()
{
    int i;

    if (size == 0)
    {
        printf("Heap is empty!\n");
        return;
    }

    printf("Max Heap: ");

    for (i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- MAX HEAP MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete Root\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteRoot();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

