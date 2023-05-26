#include <iostream>
using namespace std;

// The basic function of sorting problem.
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// HEAPIFY(max heap)
// A perfect binary tree is :
//  + Leafs are same level.
//  + leafs turn to the left

// Node i have 2 leafs that is (2*i + 1) and (2*i + 2).
// Right leafs have even index, the other side is the opposite(odd index).
void heapify(int *arr, int n, int node){
    // Index of parent point and child points.
    int largest = node;
    int right = 2*node + 2;
    int left = 2*node + 1;
    // Find the max of family(triangle in geometric space).
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (largest != node) swap(arr[node], arr[largest]);
    // Recursion until put the point having max value of binary tree on the top(index 0).
    if (node > 0) heapify(arr, n, node - 1);
}
void heap_sort(int *arr, int n){
    while (n > 1){
        // Initial step to start with the lowest node in binary tree.
        int node = (n-1) / 2;
        // Swap point which has max value with the lowest point.
        heapify(arr, n, node);
        swap(arr[0], arr[n-1]);
        // Ignore the end point of array(binary tree) each iteration.
        n = n - 1;
    }
}

// Function to print an array
void output(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main(){
    int arr[] = {1, 6, 5, 2, 9, 4, 7, 110, 10, 3, 8};
    heap_sort(arr, 10);
    output(arr, 10);
    return 0;
}
// complexity O(nlog(n))