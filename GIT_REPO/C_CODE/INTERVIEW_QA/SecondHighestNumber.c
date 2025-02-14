#include <stdio.h>
#include <limits.h>

//12,32,43,89,89,45,56,67,78,89,89,89
int getSecondHighestElement(int a[], int n)
{
    int firstHighest = INT_MIN;
    int secondHighest = INT_MIN;
    
    for(int i = 0; i < n; i++)
    {
        if(a[i] > firstHighest) {
            secondHighest = firstHighest;
            firstHighest = a[i];
        }
        else if(a[i] > secondHighest && a[i] < firstHighest) {
            secondHighest = a[i];
        }
    }
    return secondHighest;
}

int main()
{
    int arr[] = {1,1,1,1,-1,1,2,2,-2,2,2,3};
    int second_highest = getSecondHighestElement(arr, sizeof(arr) / sizeof(arr[0]));
    
    printf("Second Highest :: %d\n", second_highest);
    
    return 0;
}