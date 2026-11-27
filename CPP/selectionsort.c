#include <stdio.h>
int main()
{
    int arr[] = {10, 3, 5, 1, -1};

    // Selection Sort
    // for (int i=0;i<5;i++){
    //     for(int j=i+1;j<5;j++){
    //         if(arr[i]>arr[j]){
    //             int temp=arr[j];
    //             arr[j]=arr[i];
    //             arr[i]=temp;
    //         }
    //     }
    // }

    // Bubble Sort
    int n=sizeof(arr)/sizeof(int);
    for (int i = 0; i <n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d,", arr[i]);
    }

    return 0;
}