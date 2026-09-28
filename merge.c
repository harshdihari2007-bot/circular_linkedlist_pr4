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

    /* Compare and combine */
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

    /* Copy remaining left elements */
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    /* Copy remaining right elements */
    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    /* Copy back to original array */
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
    int n, i;
    int a[100];
    int b[100];

    /* Take input from user */
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);

        /* Copy same input for Merge Sort */
        b[i] = a[i];
    }

    /* Bubble Sort */
    bubbleSort(a, n);

    printf("\nBubble Sort: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    /* Merge Sort */
    mergeSort(b, n);

    printf("\nMerge Sort:  ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }

    return 0;
}
