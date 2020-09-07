#include <iostream>
#include <vector>
#include <stdlib.h>  // for std::rand
#include <algorithm> // for std::sort
#include "sorter.h"
#include "mytimer.h"

using namespace std;


template <typename T>
void print_vector(vector<T> arr, int N)
{
    for (size_t i = 0; i < arr.size() && i < N; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    // generate a random vector array of float
    int count = 10000;
    cout << "ARRAY SIZE: " << count << endl;
    vector<float> arr_f;
    for (size_t i = 0; i < count; i++)
    {
        arr_f.push_back((float)rand() / RAND_MAX);
    }
    vector<float> arr_s(arr_f);
    vector<float> arr_b(arr_f);
    vector<float> arr_i(arr_f);
    vector<float> arr_m(arr_f);

    // create instance of SelectionSort
    DECLARE_TIMING(t);
    START_TIMING(t);
    SelectionSort<float> selsort;
    selsort.sort(arr_f);
    STOP_TIMING(t);
    SHOW_TIMING(t, "SelectionSort");

    // create instance of BubbleSort
    DECLARE_TIMING(t2);
    START_TIMING(t2);
    BubbleSort<float> bblsort;
    bblsort.sort(arr_b);
    STOP_TIMING(t2);
    SHOW_TIMING(t2, "BubbleSort");

    // create instance of InsertionSort
    DECLARE_TIMING(t3);
    START_TIMING(t3);
    InsertionSort<float> inssort;
    inssort.sort(arr_i);
    STOP_TIMING(t3);
    SHOW_TIMING(t3, "InsertionSort");

    // create instance of MergeSort
    DECLARE_TIMING(t4);
    START_TIMING(t4);
    MergeSort<float> mrgsort;
    mrgsort.sort(arr_m);
    STOP_TIMING(t4);
    SHOW_TIMING(t4, "MergeSort");


    // use std::sort
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    std::sort(arr_s.begin(), arr_s.end());
    STOP_TIMING(t1);
    SHOW_TIMING(t1, "std::sort");

    // check if selectionsort is equal
    if (arr_f == arr_s)
        cout << "The implementation of selection sort is correct!" << endl;
    else
        cout <<"The implementation of selection sort is incorrect."<<endl;

    // check if bubblesort is equal
    if (arr_b == arr_s)
        cout << "The implementation of bubble sort is correct!" << endl;
    else
        cout <<"The implementation of bubble sort is incorrect."<<endl;

    // check if insertionsort is equal
    if (arr_i == arr_s)
        cout << "The implementation of insertion sort is correct!" << endl;
    else
        cout <<"The implementation of insertion sort is incorrect."<<endl;

    // check if mergesort is equal
    if (arr_m == arr_s)
        cout << "The implementation of merge sort is correct!" << endl;
    else
        cout <<"The implementation of merge sort is incorrect."<<endl;

    return 0;
}