#include <stdio.h>

//  SELECTION SORT 
void selectionSort(int a[], int n){
    int i, j, min, temp;
    for(i=0; i<n-1; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

//  INSERTION SORT 
void insertionSort(int a[], int n){
    int i, j, key;
    for(i=1; i<n; i++){
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

// BUBBLE SORT 
void bubbleSort(int a[], int n){
    int i, j, temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// MERGE SORT
void merge(int a[], int l, int m, int r){
    int i = l, j = m+1, k = 0;
    int temp[1000];

    while(i <= m && j <= r){
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i <= m)
        temp[k++] = a[i++];
    while(j <= r)
        temp[k++] = a[j++];

    for(i=0; i<k; i++)
        a[l + i] = temp[i];
}

void mergeSort(int a[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

// QUICK SORT
int partition(int a[], int l, int r){
    int pivot = a[l];
    int i = l, j = r, temp;

    while(i < j){
        while(a[i] <= pivot) i++;
        while(a[j] > pivot) j--;
        if(i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[], int l, int r){
    if(l < r){
        int p = partition(a, l, r);
        quickSort(a, l, p-1);
        quickSort(a, p+1, r);
    }
}
void printArr(int a[], int n){
    int i;
    for(i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int arr[] = {50, 20, 40, 10, 60};
    int n = 5;

    printf("Original: ");
    printArr(arr, n);
    quickSort(arr, 0, n-1);

    printf("Sorted: ");
    printArr(arr, n);

    return 0;
}