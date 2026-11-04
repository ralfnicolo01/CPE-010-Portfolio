#ifndef SORTING_H
#define SORTING_H


template <typename T>
void insertionSort(T arr[], int arrSize){
    int k = 1, j;
    T temp;

    while(k < arrSize){
        temp = arr[k];
        j = k - 1;

        while(j >= 0 && temp < arr[j]){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        k++;
    }
}

template <typename T>
void shellSort(T arr[], int arrSize){
    for(int gap = arrSize / 2; gap > 0; gap /= 2){
        for(int i = gap; i < arrSize; i++){
            T temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

template <typename T>
void merge(T arr[], int left, int middle, int right){
    int n1 = middle - left + 1;
    int n2 = right - middle;

    T* leftArr = new T[n1];
    T* rightArr = new T[n2];

    for(int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for(int j = 0; j < n2; j++) rightArr[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(i < n1){ arr[k] = leftArr[i]; i++; k++; }
    while(j < n2){ arr[k] = rightArr[j]; j++; k++; }

    delete[] leftArr;
    delete[] rightArr;
}

template <typename T>
void mergeSort(T arr[], int left, int right){
    if(left < right){
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

template <typename T>
int partition(T arr[], int low, int high){
    T pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quickSort(T arr[], int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

#endif