#include<iostream>
using namespace std;

void printarray(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int *arr, int low, int high){
    int i = low+1;
    int j = high;
    int pivot, temp;
    pivot = arr[low];
    do
    {
        while(arr[j] > pivot)
        {
            j--;
        }
        while (arr[i]<=pivot)
        {
            i++;
        }
        if (i<j)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    } while (i<j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quicksort(int *arr, int low, int high){
    int index;
    if(low<high){
    index = partition(arr,low,high);
    quicksort(arr,low,index-1);
    quicksort(arr,index+1,high);
    }
}

int main(){
    // int arr[] = {4,8,9,2,3,19};
    int arr[] = {99,88,77,6,2,3};
    int n = 6;
    int low = 0;
    int high = n-1;
    quicksort(arr,low,high);
    printarray(arr,n);
    return 0;
}
