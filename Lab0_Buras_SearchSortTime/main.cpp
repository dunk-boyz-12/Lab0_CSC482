//
//  main.cpp
//  Lab0_Buras_SearchSortTime
//
//  Created by Nicholas Buras on 9/1/21.
//

//sort and search classes
#include "Utils/sorts.hpp"
#include "Utils/searches.hpp"
//libs
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <chrono>
#include <iomanip>

#define MIN_N 1000
#define MAX_N 6400000

using Clock = std::chrono::steady_clock;
using TimePoint = std::chrono::steady_clock::time_point;
using Microeconds = std::chrono::microseconds;
using Milliseconds = std::chrono::milliseconds;
using Seconds = std::chrono::seconds;
using Minutes = std::chrono::minutes;

struct Timer {
    TimePoint start, end;
};

int* createList(int N);
void printTableRow();

/* ############################ Start of Main ############################ */

int main(int argc, const char * argv[]) {

    Timer T;
    int* numberList;
    bool inList;
    std::srand(std::time(0));

    //get number of trials per input size from command line
    int trials = std::stoi(argv[1]);
    
    //linear search
    c_mySearches linearSearchTest;
    std::cout << "Linear Search Test" << std::endl;
    for (int N = MIN_N; N < MAX_N; N *= 2) {
        numberList = createList(N);
        //calculate function overhead
        T.start = Clock::now();
        //dummy loop
        for (int i = 0; i < trials; i++) {
            linearSearchTest.linearSearchOverhead(numberList, N, -1);
        }
        T.end = Clock::now();
        Milliseconds avgOverheadRuntime = std::chrono::duration_cast<Milliseconds>((T.end - T.start)/trials);

        //real test loop
        T.start = Clock::now();
        for (int i = 0; i < trials; i++) {
            inList = linearSearchTest.linearSearch(numberList, N, -1);
        }
        T.end = Clock::now();
        Milliseconds avgRuntime = std::chrono::duration_cast<Milliseconds>((T.end - T.start)/trials);
        //actual runtime
        Milliseconds avgActualRuntime = avgRuntime - avgOverheadRuntime;
        //print table row
        std::cout << std::endl;
        std::cout << std::left << std::setw(5) << "N Value: " << std::left << std::setw(10) << N << std::setw(5) << "Runtime Avg: " << std::setw(8) << avgActualRuntime.count() << "ms" << std::endl;
        //deallocate memory
        delete []numberList;
    }
    
    //binary search
    c_mySearches binarySearchTest;
    std::cout << std::endl;
    std::cout << "Binary search Test" << std::endl;
    for (int N = MIN_N; N < MAX_N; N *= 2) {
        numberList = createList(N);
        //calculate function overhead
        T.start = Clock::now();
        //dummy loop
        for (int i = 0; i < trials; i++) {
            binarySearchTest.binarySearchOverhead(numberList, N, -1);
        }
        T.end = Clock::now();
        //Milliseconds avgOverheadRuntime = std::chrono::duration_cast<Milliseconds>((T.end - T.start)/trials);
        Milliseconds avgOverheadRuntime = std::chrono::duration_cast<Milliseconds>((T.end - T.start)/trials);

        //real test loop
        T.start = Clock::now();
        for (int i = 0; i < trials; i++) {
            inList = binarySearchTest.binarySearch(numberList, N, -1);
        }
        T.end = Clock::now();
        
        //Milliseconds avgRuntime = std::chrono::duration_cast<Milliseconds>((T.end - T.start)/trials);
        Milliseconds avgRuntime = std::chrono::duration_cast<Milliseconds>((T.end - T.start)/trials);
        //actual runtime
        //Milliseconds avgActualRuntime = avgRuntime - avgOverheadRuntime;
        Milliseconds avgActualRuntime = avgRuntime - avgOverheadRuntime;
        //print table row
        std::cout << std::endl;
        std::cout << std::left << std::setw(5) << "N Value: " << std::left << std::setw(10) << N << std::setw(5) << "Runtime Avg: " << std::setw(8) << avgActualRuntime.count() << "ms" << std::endl;
        delete []numberList;
    }
    
    /* ############################ Sorts ############################ */
    
    //selection sort
    c_mySorts selectionSortTest;
    std::cout << std::endl;
    std::cout << "Selection Sort Test" << std::endl;
    for (int N = MIN_N; N <= MAX_N; N *= 2) {
        numberList = createList(N);
        //calculate function overhead
        T.start = Clock::now();
        //dummy loop
        for (int i = 0; i < trials; i++) {
            selectionSortTest.selectionSortOverhead(numberList, N);
        }
        T.end = Clock::now();
        Milliseconds avgOverheadRuntime = std::chrono::duration_cast<Milliseconds>((T.end - T.start)/trials);

        //real test loop
        T.start = Clock::now();
        for (int i = 0; i < trials; i++) {
            selectionSortTest.selectionSort(numberList, N);
        }
        T.end = Clock::now();
        
        Milliseconds avgRuntime = std::chrono::duration_cast<Milliseconds>((T.end - T.start)/trials);
        //actual runtime
        Milliseconds avgActualRuntime = avgRuntime - avgOverheadRuntime;
        //print table row
        std::cout << std::endl;
        std::cout << std::left << std::setw(5) << "N Value: " << std::left << std::setw(10) << N << std::setw(5) << "Runtime Avg: " << std::setw(8) << avgActualRuntime.count() << "ms" << std::endl;
        delete []numberList;
    }
    
    //merge sort
    c_mySorts mergeSortTest;
    std::cout << std::endl;
    std::cout << "Merge Sort Test" << std::endl;
    for (int N = MIN_N; N <= MAX_N; N *= 2) {
        numberList = createList(N);
        int* temp = new int[N];
        //calculate function overhead
        T.start = Clock::now();
        //dummy loop
        for (int i = 0; i < trials; i++) {
            mergeSortTest.mergeSortHandlerOverhead(numberList, temp, N);
        }
        T.end = Clock::now();
        Milliseconds avgOverheadRuntime = std::chrono::duration_cast<Milliseconds>((T.end - T.start)/trials);

        //real test loop
        T.start = Clock::now();
        for (int i = 0; i < trials; i++) {
            mergeSortTest.mergeSortHandler(numberList, temp, N);
        }
        T.end = Clock::now();
        
        Milliseconds avgRuntime = std::chrono::duration_cast<Milliseconds>((T.end - T.start)/trials);
        //actual runtime
        Milliseconds avgActualRuntime = avgRuntime - avgOverheadRuntime;
        //print table row
        std::cout << std::endl;
        std::cout << std::left << std::setw(5) << "N Value: " << std::left << std::setw(10) << N << std::setw(5) << "Runtime Avg: " << std::setw(8) << avgActualRuntime.count() << "ms" << std::endl;
        /*for (int i = 0; i < N; i++) {
            std::cout << numberList[i] << std::endl;
        }*/
        delete []numberList;
        delete []temp;
    }
}

/* ############################ Function Definitions ############################ */

int* createList(int N) {
    int* myList = new int[N];
    for (int i = 0; i < N; i++) {
        myList[i] = rand() % 10000;
    }
    return myList;
}
