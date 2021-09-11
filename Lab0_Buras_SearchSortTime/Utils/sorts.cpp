//
//  sorts.cpp
//  Lab0_Buras_SearchSortTime
//
//  Created by Nicholas Buras on 9/1/21.
//

#include "sorts.hpp"

void c_mySorts::selectionSort(int* list, int N) {
    int check, smallest;
    for (int i = 0; i < N-1; i++) {
        smallest = i;
        check = i+1;
        while (check < N) {
            if(list[check] < list[smallest]){
                int t = list[check];
                list[check] = list[smallest];
                list[smallest] = t;
            }
            check++;
        }
    }
}

void c_mySorts::mergeSortHandler(int* list, int* tempList, int N) {
    this->mergeSort(list, tempList,0, N-1);
}

void c_mySorts::mergeSort(int* list, int* tempList,int left, int right) {
    if(left >= right){
        return;
    }
    int middle = floor((right+left)/2);
    this->mergeSort(list, tempList,left, middle);
    this->mergeSort(list, tempList,middle+1, right);
    this->merge(list,tempList,left,middle,right);
}

void c_mySorts::merge(int* list, int* tempList, int left, int middle, int right) {
    int leftIndex = left;
    int rightIndex = middle+1;
    int tempSize = (right-left)+1;
    

    //copy into temp list
    for (int ctr = left; ctr <= right; ctr++) {
        tempList[ctr] = list[ctr];
    }
    
    //merge back to actual list
    for (int ctr = left; ctr <= right; ctr++) {
        if(leftIndex > middle){
            list[ctr] = tempList[rightIndex];
            rightIndex++;
        } else if(rightIndex > right) {
            list[ctr] = tempList[leftIndex];
            leftIndex++;
        } else if(tempList[leftIndex] <= tempList[rightIndex]) {
            list[ctr] = tempList[leftIndex];
            leftIndex++;
        } else {
            list[ctr] = tempList[rightIndex];
            rightIndex++;
        }
    }
}

/* ############################ Overhead Functions ############################ */

void c_mySorts::selectionSortOverhead(int* list, int N) {

}

void c_mySorts::mergeSortHandlerOverhead(int* list, int* tempList, int N) {
    
}
