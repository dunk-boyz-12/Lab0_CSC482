//
//  sorts.hpp
//  Lab0_Buras_SearchSortTime
//
//  Created by Nicholas Buras on 9/1/21.
//

#ifndef sorts_hpp
#define sorts_hpp

#include <stdio.h>
#include <cmath>

class c_mySorts {
public:
    //sorts
    void selectionSort(int*,int);
    void mergeSortHandler(int*,int*,int);
    //helper functions
    void mergeSort(int*,int*,int,int);
    void merge(int*,int*,int,int,int);
    //overhead
    void selectionSortOverhead(int*,int);
    void mergeSortHandlerOverhead(int*,int*,int);
};

#endif /* sorts_hpp */
