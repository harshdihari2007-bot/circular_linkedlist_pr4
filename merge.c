#include <stdio.h>

/* ---------- Bubble Sort ---------- */

void bubbleSort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

/* ---------- Merge Sort ---------- */

void combine(int a[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}

void divide(int a[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        divide(a, low, mid);
        divide(a, mid + 1, high);

        combine(a, low, mid, high);
    }
}

void mergeSort(int a[], int n)
{
    divide(a, 0, n - 1);
}

/* ---------- Main Function ---------- */

int main()
{
    int a[100];
    int n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    /* Menu */
    printf("\nChoose Sorting Method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Merge Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    /* Perform selected sorting method */
    if (choice == 1)
    {
        bubbleSort(a, n);

        printf("\nSorted using Bubble Sort: ");
    }
    else if (choice == 2)
    {
        mergeSort(a, n);

        printf("\nSorted using Merge Sort: ");
    }
    else
    {
        printf("\nInvalid choice!");
        return 0;
    }

    /* Display sorted array */
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
