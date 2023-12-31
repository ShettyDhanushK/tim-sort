#include <stdio.h>                                      //Header files
#include <stdlib.h>
#include <time.h>

#define MIN_SIZE 32                                     //Minimum size of each run

int min (int a, int b);                                 //Minimum of a and b
void insertionSort (int arr[], int left, int right);    //Insertion sort
void merge (int arr[], int l, int m, int r);            //merge sort
void printArray (int arr[], int n);
void randomizeArray (int arr[], int n);

void timSort(int arr[], int n)
{   
    //Divide the array into runs and apply insertion sort
    for(int i = 0; i < n; i += MIN_SIZE)
    {
        insertionSort(arr, i, min((i + MIN_SIZE - 1), (n-1)));
    }

    //Merge the sorted runs
    for(int size = MIN_SIZE; size < n; size = 2 * size)
    {
        for(int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            if (mid < right)
            {
                merge(arr, left, mid, right);
            }
        }
    }
}


int main()
{
    int n = 10;
    int arr[n];
    
    randomizeArray (arr, n);

    printf ("Input Array --> ");
    printArray (arr, n);

    timSort (arr, n);

    printf ("Output Array --> ");
    printArray (arr, n);

    return 0;

}










int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else if (b < a)
    {
        return b;
    }
}

void insertionSort(int arr[], int left, int right)
{
    for(int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int len1 = m - l + 1;
    int len2 = r - m;
    int left[len1] , right[len2];

    for(int i = 0; i < len1; i++)
    {
        left[i] = arr[l+i];
    }

    for(int i = 0; i < len2; i++)
    {
        right[i] = arr[m+1+i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i < len1 && j < len2)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    while(j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void randomizeArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = (rand() % 151) - 50;
    }
}