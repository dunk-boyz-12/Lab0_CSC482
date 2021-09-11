//
//  searches.hpp
//  Lab0_Buras_SearchSortTime
//
//  Created by Nicholas Buras on 9/1/21.
//

#ifndef searches_hpp
#define searches_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>

class c_mySearches {
public:
    bool isNumberInList;
    c_mySearches() : isNumberInList(false) {};

    bool linearSearch(int*,int,int);
    bool binarySearch(int*,int,int);
    void bsHelper(int*,int,int,int);
    //overhead test functions
    void linearSearchOverhead(int*,int,int);
    void binarySearchOverhead(int*,int,int);
};

#endif /* searches_hpp */
