#include<stdio.h>
int main()
{
    int size;
    printf("Array size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter array elements: ");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    int LIS[size];
    for(int i=0; i<size; i++)
    {
        LIS[i] = 1;
    }
    for(int i=1; i<size; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i] > arr[j] && LIS[i] < LIS[j] + 1)
            {
                LIS[i] = LIS[j] + 1;
            }
        }
    }   
    int max = 0;
    for(int i=0; i<size; i++)
    {
        if(LIS[i] > max)
        {
            max = LIS[i];
        }
    }
    printf("LIS is: %d\n", max);   
    return 0;
}