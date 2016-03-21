// File:        sorting.cpp
// Author:      Geoffrey Tien
//              (your name)
// Date:        2016-02-08
// Description: Skeleton file for CMPT 225 assignment #3 sorting functions and helpers
//              Function bodies to be completed by you!

// Complete your sorting algorithm function implementations here

// Selection Sort
// (your comments here)
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//is a O(n^2) algorithm (double for loop) it is actually (n^2+n)/2 algorithm
//but O notation only takes largest magnitude of variables
template <class T>
int SelectionSort(T arr[], int n)
{
  int count = 0; // counter for barometer operations
    int i, j;
    T value;
    
    for(i=0; i<n-1 ; i++) //chooses element to be compared with
    {
        for(j=i+1;j<n;j++)  //compares original element with all elements right of itself
        {
            if(arr[i]>arr[j]) //swaps elements if arr[i] is larger then arr[j]
            {
                value = arr[i];
                arr[i] = arr[j];
                arr[j] = value;
            }
             count++;

        }
    }
  return count;
}

// Quicksort
// (your comments here)

//is also a O(n^2) (n^+n)/2 but typically acts like an O(nlog(n)) algorithm where log is base 2
template <class T>
int Quicksort(T arr[], int n)
{
  int count = 0;
    QuicksortHelper(arr, 0, n-1, count);
  
    return count;
}


//
template <class T>
void QuicksortHelper(T arr[], int low, int high, int& counter)
{

    if(low<high)
    {

        
        int pivot = QSPartition(arr, low, high, counter); //partitions array and returns the index of the pivot

        
        QuicksortHelper(arr, low, pivot-1, counter); //takes first half array to be partitioned

        
        QuicksortHelper(arr, pivot+1, high, counter); //takes second half array to be partitioned

    }
    
  
}

template <class T>
int QSPartition(T arr[], int low, int high, int& counter)
{
    int pivotindex = low; //starts the pivotindex at the start of array so 
    T pivot = arr[high]; //sets the pivot to the last item of array
                        //high starts at the last index, not n
    T copy; //copy T item
    int i;
    
    for(i=low;i<high; i++)
    {
        counter++;
        
        if(arr[i]<=pivot) //if value is less then the pivot
        {
            //swaps last array element with first element that is larger then pivot in bigger-smaller portion of array
            copy = arr[i];
            arr[i] = arr[pivotindex];
            arr[pivotindex] = copy;
            pivotindex++;
        }

    }
    //this portion below switches the pivot so lower elements are less then pivot and higher elements are higher then pivot
    copy = arr[pivotindex];
    arr[pivotindex] = pivot;
    arr[high] = copy;
    
  
  return pivotindex; //returns the index of the pivot
}






// Randomized Quicksort
// (your comments here)

//is also a O(n^2) but typically acts like an O(nlog(n)) algorithm.
//The randomization to choose the pivot causes the the algorithm to more likely be a 0(nlog(n)) algorithm
//same as quicksort but with randomized pivot in partition
template <class T>
int RQuicksort(T arr[], int n)
{
    int count = 0;
    RQuicksortHelper(arr, 0, n-1, count);
  return count;
}

template <class T>
void RQuicksortHelper(T arr[], int low, int high, int& counter)
{
    if(low<high)
    {
        
        int pivot = RQSPartition(arr, low, high, counter);
        
        RQuicksortHelper(arr, low, pivot-1, counter);
        
        RQuicksortHelper(arr, pivot+1, high, counter);
    }
}

template <class T>
int RQSPartition(T arr[], int low, int high, int& counter)
{
    srand(static_cast <unsigned int> (time(0)));


    int randNum = rand()%(high-low + 1) + low;
    T pivot = arr[randNum]; //sets pivot as value at randNum, this is the only
                            //difference between randomized quicksort and the one above
    T copy = arr[high];
    arr[high] = arr[randNum];
    arr[randNum] = copy;
    
    
    int pivotindex = low;
    int i;
    
    for(i=low;i<high; i++)
    {
        counter++;
        
        if(arr[i]<=pivot)
        {
            //swaps array elements between
            copy = arr[i];
            arr[i] = arr[pivotindex];
            arr[pivotindex] = copy;
            pivotindex++;
        }
        
    }
    
    copy = arr[pivotindex];
    arr[pivotindex] = pivot;
    arr[high] = copy;
    
    
    return pivotindex;
}

// Mergesort
// (your comments here)

//Merge sort is a O(nlog(n)) algorithm where log is base 2
template <class T>
int Mergesort(T arr[], int n)
{
  int count = 0;
    MergesortHelper(arr, 0, n-1, n, count);
  
  return count;
}

template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)
{
    if(n<2) //when there is single element, return
        return;
    
    int mid = (high+low)/2 + 1; //mid point
    
    MergesortHelper(arr, low, mid-1, mid-low, counter); //seperates array by positions for first half
    MergesortHelper(arr, mid, high, high-mid+1, counter); //seperates array by position for second half
    Merge(arr, low, mid, high, n, counter); //merges arrays
    
}

template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{
    T* new_arr = new T[n]; //makes copy array
    int i = low, j= mid, k=0;


    
    while(i<mid && j<=high) //conditions so indices don't go past their legal terminal indices
    {
        counter++;
        if(arr[i]<=arr[j]) //statement puts array[i] into copy array if smaller then array[j]
        {
            new_arr[k] = arr[i];
            i++;
            k++;
        }
        
        else if(arr[j]<arr[i]) //statement puts array[j] into copy array if smaller then array[i]
        {
            new_arr[k] = arr[j];
            j++;
            k++;
        }
        
    }
    
    
    
    if(i>=mid) //checks if i goes past end of first part of array
    {
        for( ;k<n;k++) //if it does the fills array with the rest of j
        {
            new_arr[k] = arr[j];
            j++;
        }
    }
    
    if(j>high) //checks if j goes past end of first part of array
    {
        for( ;k<n;k++)//if it does the fills array with the rest of j
        {
            new_arr[k] = arr[i];
            i++;
        }
    }
    
    for(k=0;k<n;k++) //copies sorted array elements into original array
    {
        arr[low] = new_arr[k];
        low++;
    }
    
    delete[] new_arr; //frees up space of allocated array
        
        
        
        
        
}

// Shell Sort
// (your comments here)
//best case O(nlog(n)) and worst case O(n^2)
template <class T>
int ShellSort(T arr[], int n)
{
    int count = 0;
    
    int x, y, gap;
    T z;
    for (gap = n / 2; gap > 0; gap /= 2) {	//splits the array into the matrix shape; creating the gap and halving it in each iteration 
        
        for (x = gap; x < n; x++) {		//basically picks the first element you will compare to, and then in each iteration moves the beginning of the gap
            z = arr[x];
            
            for (y = x; y >= gap; y -= gap) {	//picks the second item you will compare to and in each iteration moves the end of the gap until the end of the gap is on the last element of the array
                count++;
                if (z < arr[y - gap]) //does comparison of the elements picked by the second and third forloops
                {
                    arr[y] = arr[y - gap];	//does a switch
                }
                else {
                    break;		
                }
            }
            arr[y] = z;			//does the second switch
        }
    }
    
    return count;
}