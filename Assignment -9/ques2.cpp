#include <stdio.h>

#define MAX 100

int heap[MAX];
int heapSize = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int x) {
    if (heapSize >= MAX) {
        printf("Heap overflow!\n");
        return;
    }

    heap[heapSize] = x;
    int i = heapSize;
    heapSize++;
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int getMax() {
    if (heapSize == 0) {
        printf("Heap empty!\n");
        return -1;
    }
    return heap[0];
}

void maxHeapifyPQ(int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < heapSize && heap[l] > heap[largest])
        largest = l;

    if (r < heapSize && heap[r] > heap[largest])
        largest = r;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapifyPQ(largest);
    }
}

int extractMax() {
    if (heapSize == 0) {
        printf("Heap empty!\n");
        return -1;
    }

    int max = heap[0];
    heap[0] = heap[--heapSize];
    maxHeapifyPQ(0);

    return max;
}

void display() {
    for (int i = 0; i < heapSize; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(10);
    insert(40);
    insert(20);
    insert(30);
    insert(50);

    printf("Priority Queue: ");
    display();

    printf("Max element = %d\n", getMax());
    printf("Extracted max = %d\n", extractMax());

    printf("After extraction: ");
    display();

    return 0;
}