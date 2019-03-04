/*
 * NAME: JOÃO PEDRO VELOSO
 * PROGRAM 3
 *
 * EXTRA CREDIT: IN ADDITION TO INSERT (N^2) AND MERGE SORT (NlogN):
 *                              – BUBBLE SORT
 *                              – QUICK SORT
 *             : DID IMPLEMENT ALGORITHM TO CALCULATE AVG RUNTIME, BC I WAS CURIOUS ON THE AVG TIMES THESE SORTS TAKE,
 *                  DON'T KNOW IF IT COUNTS AS EXTRA CREDIT THOUGH.
 *                  THE ALGORITHM RUNS AT THE END OF MAIN, AND IF WANTING TO RUN MAIN WITHOUT IT, JUST COMMENT OUT LINES 83-84.
 */

#include <iostream>
#include <vector>
#include "SortAlgs.h"

using namespace std;

template<class T> void printvec(const vector<T> vec);
template<class T> void populate(vector<T> &a, unsigned count);
template<class T> void average_time(SortAlgs v, vector<T> &a);

int main() {
    SortAlgs v; //ghost variable that is here just to call functions from SortAlgs
    srand((unsigned)time(NULL)); //seeding time
    //creating two vectors
    vector<int> vec1;
    populate(vec1, 1000);
    vector<int> vec2;
    populate(vec2, 1000);
    vector<int> vec3;
    populate(vec3, 1000);
    vector<int> vec4;
    populate(vec4, 1000);

    cout << "Before Merge Sort:" << endl;
    printvec(vec1);
    auto startmerge = chrono::high_resolution_clock::now(); //gets start time of operation
    v.nLgNSort(vec1, 1000);
    auto donemerge = chrono::high_resolution_clock::now(); //gets end time of operation
    std::chrono::duration<double, std::milli> frac_ms = donemerge - startmerge; //calculates difference in fraction ms
    std::cout << "Merge Sort took " << frac_ms.count() << " ms." << endl;
    cout << "Final state of list after running Merge Sort: " << endl;
    printvec(vec1);

    cout << endl; //to look pretty :)

    cout << "Before Insert Sort:" << endl;
    printvec(vec2);
    auto startinsert = chrono::high_resolution_clock::now();
    v.nSqSort(vec2, 1000);
    auto doneinsert = chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> frac_ms2 = doneinsert - startinsert; //calculates difference in fraction ms
    std::cout << "Insert Sort took " << frac_ms2.count() << " ms." << endl;
    cout << "Final state of list after running Insert Sort: " << endl;
    printvec(vec2);

    cout << endl;

    cout << "Before Quicksort:" << endl;
    printvec(vec3);
    auto startquick = chrono::high_resolution_clock::now();
    v.quickSort(vec3, 0, 999);
    auto donequick = chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> frac_ms3 = donequick - startquick; //calculates difference in fraction ms
    std::cout << "Quick Sort took " << frac_ms3.count() << " ms." << endl;
    cout << "Final state of list after running Quick Sort: " << endl;
    printvec(vec3);

    cout << endl;

    cout << "Before Bubble Sort:" << endl;
    printvec(vec4);
    auto startbubble = chrono::high_resolution_clock::now();
    v.bubbleSort(vec4, 1000);
    auto donebubble = chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> frac_ms4 = donebubble - startbubble; //calculates difference in fraction ms
    std::cout << "Bubble Sort took " << frac_ms4.count() << " ms." << endl;
    cout << "Final state of list after running Bubble Sort: " << endl;
    printvec(vec4);

    cout << endl;

    vector<int> a;
    average_time(v, a); //was bored so I wrote this function to calculate average run-time based on some user inputs

    return 0;
}

template <class T>
void populate(vector<T> &a, unsigned count) {
    int x;
    for (unsigned i = 0; i < count; i++) {
        x = rand() % count + 1;
        a.push_back(x);
    }
}

template <class T>
void printvec(const vector<T> vec) {
    for (unsigned i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

//precision will be the amount of times a function runs in order to figure out average run-time
//count will simply be the size of the vector or "n" when referring to number of operations
//the a vector is initialized before hand, and is cleared
template <class T>
void average_time(SortAlgs v, vector<T> &a) {
    long double total = 0;
    string y;
    unsigned int count, precision;
    cout << "Would you like to calculate average run-time for one of the sorts available?" << endl;
    cout << "If yes, press 1, if not press any other key. ";
    string x;
    cin >> x;

    if (x == "1") {
        cout << "Ok! Which sort would you like to calculate? " << endl;
        cout << "1. Merge Sort\n"
                "2. Insert Sort\n"
                "3. Bubble Sort\n"
                "4. Quick Sort" << endl;
        cin >> y;
        //checking for bad inputs
        while (y != "1" && y != "2" && y != "3" && y != "4"){
            cout << "Mistake! Try entering a valid input. ";
            cin >> y;
        }
        cout << "What value of n (size of vector would you like)? ";
        cin >> count;
        cout << "How many trials would you like to run to compute the average? ";
        cin >> precision;
    }
    else {
        cout << "Thank you for running me!" << endl;
        return;
    }


    if (y == "1") {
        for (int i = 0; i < precision; i++) {
            populate(a, count);
            auto startmerge = chrono::high_resolution_clock::now(); //gets start time of operation
            v.nLgNSort(a, count);
            auto donemerge = chrono::high_resolution_clock::now(); //gets end time of operation
            a.clear();
            std::chrono::duration<double, std::milli> frac_ms = donemerge - startmerge; //calculates difference in fraction ms
            total += frac_ms.count(); //sums frac_ms value to total
        }
    }
    else if (y == "2") {
        for (int i = 0; i < precision; i++) {
            populate(a, count);
            auto startmerge = chrono::high_resolution_clock::now();
            v.nSqSort(a, count);
            auto donemerge = chrono::high_resolution_clock::now();
            a.clear();
            std::chrono::duration<double, std::milli> frac_ms = donemerge - startmerge;
            total += frac_ms.count();
        }
    }
    else if (y == "3") {
        for (int i = 0; i < precision; i++) {
            populate(a, count);
            auto startmerge = chrono::high_resolution_clock::now(); //gets start time of operation
            v.bubbleSort(a, count);
            auto donemerge = chrono::high_resolution_clock::now(); //gets end time of operation
            a.clear();
            std::chrono::duration<double, std::milli> frac_ms = donemerge - startmerge; //calculates difference in fraction ms
            total += frac_ms.count(); //sums frac_ms value to total
        }
    }
    else if (y == "4") {
        for (int i = 0; i < precision; i++) {
            populate(a, count);
            auto startmerge = chrono::high_resolution_clock::now(); //gets start time of operation
            v.quickSort(a, 0, count-1);
            auto donemerge = chrono::high_resolution_clock::now(); //gets end time of operation
            a.clear();
            std::chrono::duration<double, std::milli> frac_ms = donemerge - startmerge; //calculates difference in fraction ms
            total += frac_ms.count(); //sums frac_ms value to total
        }
    }

    long double avg = total / precision; //calculates avg
    cout << "Average time to run the required sort is: " << avg << "ms." << endl; //prints avg to user

    string replay;
    cout << "Enter 1 to calculate another average runtime? Or anything else to quit. ";
    cin >> replay;
    if (replay == "1")
        average_time(v, a);
    else {
        cout << "Thank you for running me!" << endl;
    }
}