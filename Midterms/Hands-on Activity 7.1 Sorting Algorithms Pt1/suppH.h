#ifndef VOTECOUNTING_H
#define VOTECOUNTING_H

//insertion sort, used to group equal votes together before counting
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

void countVotes(int arr[], int size, std::string candidates[]){
    int i = 0;
    int winnerVote = -1, winnerCount = 0;

    std::cout << "Vote Count Result:\n";
    while(i < size){
        int currentVote = arr[i];
        int count = 0;

        while(i < size && arr[i] == currentVote){
            count++;
            i++;
        }

        std::cout << candidates[currentVote - 1] << ": " << count << " votes\n";

        if(count > winnerCount){
            winnerCount = count;
            winnerVote = currentVote;
        }
    }

    std::cout << "\nWinner: " << candidates[winnerVote - 1] << " with " << winnerCount << " votes.\n";
}

#endif