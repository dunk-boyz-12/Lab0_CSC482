//
//  searches.cpp
//  Lab0_Buras_SearchSortTime
//
//  Created by Nicholas Buras on 9/1/21.
//

#include "searches.hpp"

bool c_mySearches::linearSearch(int* list, int listSize, int desiredNumber) {
    for (int ctr = 0; ctr < listSize; ctr++) {
        if(list[ctr] == desiredNumber){
            this->isNumberInList = true;
            break;
        }
    }
    return this->isNumberInList;
}

bool c_mySearches::binarySearch(int* list, int listSize, int desiredNumber) {
    this->bsHelper(list, 0, listSize-1, desiredNumber);
    return this->isNumberInList;
}

void c_mySearches::bsHelper(int* list, int left, int right, int num) {
    int middle = floor((right+left)/2);
    if(left > right){
        return;
    } else if(num < list[middle]) {
        this->bsHelper(list, left, middle-1, num);
    } else if(num > list[middle]) {
        this->bsHelper(list, middle+1, right, num);
    } else {
        this->isNumberInList = true;
    }
}

//overhead functions
void c_mySearches::linearSearchOverhead(int* list, int listSize, int desiredNumber) {
    
}

void c_mySearches::binarySearchOverhead(int* list, int listSize, int desiredNumber) {
    
}
