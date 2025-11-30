#include <stdio.h>

void improvedSelectionSort(int a[], int n){
    int left = 0, right = n - 1;

    while(left < right){
        int min = left, max = right;
        int i;

        for(i = left; i <= right; i++){
            if(a[i] < a[min]) min = i;
            if(a[i] > a[max]) max = i;
        }
        int temp = a[left];
        a[left] = a[min];
        a[min] = temp;
        if(max == left)
            max = min;
        temp = a[right];
        a[right] = a[max];
        a[max] = temp;

        left++;
        right--;
    }
}

void printArr(int a[], int n){
    int i;
    for(i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int arr[] = {30, 10, 50, 20, 60, 40};
    int n = 6;

    printf("Before: ");
    printArr(arr, n);

    improvedSelectionSort(arr, n);

    printf("After : ");
    printArr(arr, n);

    return 0;
}
