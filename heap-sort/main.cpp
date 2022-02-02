#include <iostream>

using namespace std;

int maxChildIndex(int arr[], int size, int index){
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    if(rightChildIndex >= size && leftChildIndex >= size) //No child exists
        return -1;

    if(rightChildIndex >= size) //right child does not exits
        return leftChildIndex;

    //return index of the child which is greater of the two
    return (arr[leftChildIndex] > arr[rightChildIndex]) ? leftChildIndex : rightChildIndex;
}

//heapify down to ensure max heap property
void heapifyDown(int arr[], int size, int index){
    int maxChild = maxChildIndex(arr, size, index);
    if(maxChild == -1) //no child exists. index is a leaf node
        return;
    //swap element at the index maxChild
    if(arr[index] < arr[maxChild]){ //swap maxChild if it is greater
        swap(arr[index], arr[maxChild]);
        heapifyDown(arr, size, maxChild); //ensure heap property within subtree
    }
}



//heapify entire array
void heapifyArray(int arr[], int size){
    //create a max heap
    for(int i = size/2 - 1; i >= 0; i--){
        heapifyDown(arr, size, i); // heapifyDown all elements starting from mid of array to the start of array
    }    
}

void heapSort(int arr[], int size){
    //first we create a max heap by heapifying our array
    heapifyArray(arr, size);
    //now 0th index has maximum element
    //we move this maximum element at the end of our heap
    for(int i = size - 1; i > 0; i--){ //loop through our heap backwards
        swap(arr[0], arr[i]); //move maximum element to the end
        heapifyDown(arr, i, 0); //decrement size of heap (i == --size) and heapifyDown from first index to ensure max heap property
    }

}

int main(){
    int arr[] = {7, 2, 99, 22, -1, 0, 3};
    int size = sizeof(arr)/sizeof(*arr);
    heapSort(arr, size);

    for(int item : arr){
        cout << item << "  ";
    }
    return 0;
}