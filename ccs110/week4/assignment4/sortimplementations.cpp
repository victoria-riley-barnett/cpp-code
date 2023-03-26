/* CS 110C - Victoria Barnett - Sorting Algorithms assignment
3/13/2023
This program implements 3 sorting algorithms: bubble sort, merge sort, and counting sort 
for an array of ints representing basketball scores. Randomizes betweeen sort calls. */

#include <iostream>
#include <fstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Function prototypes
void initArray(int scores[], int size);
void printArray(int scores[], int size);
void printArrayToFile(int scores[], int size);
void readArrayFromFile(int scores[], int size);
void unsortArray(int scores[], int size);
int bubbleSort(int scores[], int size);
int mergeSort(int scores[], int first, int last, int size);
int merge(int scores[], int first, int middle, int last, int size);
int countingSort(int scores[], int size);

// Global vars
string fileName = "scores.txt";

int main(){
    // Vars
    
    ifstream inFile;
    ofstream outFile;
    int num;
    int n = 0;
    int bubbleavg = 0;
    int mergeavg = 0;
    int countingavg = 0;
    int size = 128;
    int accInt;
    int scores[size];


    // init random array
    initArray(scores, size);

    // Print array to file
    printArrayToFile(scores, size);

    // Read array from file
    readArrayFromFile(scores, size);

    // Using fstream send all couts to a file
    ofstream resultsFile;
    outFile.open("output.txt");
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(outFile.rdbuf());



    // Print array
    cout << "Original array: " << endl;
    printArray(scores, size);

    // Sort array - bubble sort
    cout << "Bubble sort: " << bubbleSort(scores, size) << " accesses" << endl;
    readArrayFromFile(scores, size);
    bubbleSort(scores, size);
    printArrayToFile(scores, size);
    printArray(scores, size);

    // Unsort array
    cout << "Now unsorted: " << endl;
    readArrayFromFile(scores, size);
    unsortArray(scores, size);
    printArrayToFile(scores, size);
    printArray(scores, size);

    // Sort array - merge sort
    cout << "Merge sort: " << mergeSort(scores, 0, 99, size) + merge(scores, 0, 49, 99, size) << " accesses" << endl;
    readArrayFromFile(scores, size);
    mergeSort(scores, 0, 99, size);
    printArrayToFile(scores, size);
    printArray(scores, size);

    // Unsort array
    cout << "Now unsorted: " << endl;
    readArrayFromFile(scores, size);
    unsortArray(scores, size);
    printArrayToFile(scores, size);
    printArray(scores, size);

    // Sort array - counting sort
    cout << "Counting sort: " << countingSort(scores, size) << " accesses" << endl;
    readArrayFromFile(scores, size);
    countingSort(scores, size);
    printArrayToFile(scores, size);
    printArray(scores, size);

    // Unsort array
    cout << "Now unsorted: " << endl;
    readArrayFromFile(scores, size);
    unsortArray(scores, size);
    printArrayToFile(scores, size);
    printArray(scores, size);

    cout << endl << "Begin efficiency test: " << endl;

    // Efficiency test - size 1 8 ints
    cout << "Size 1 tests: " << endl;
    size = 8;
    for (int i = 0; i < 3; i++){
        n++;
        initArray(scores, size);
        printArrayToFile(scores, size);
        readArrayFromFile(scores, size);
        bubbleSort(scores, size);
        cout << "Bubble sort " << n << ": " << bubbleSort(scores, size) << " accesses" << endl;
        printArray(scores, size);
        bubbleavg += bubbleSort(scores, size);
        unsortArray(scores, size);
        mergeSort(scores, 0, 7, size);
        cout << "Merge sort " << n << ": " << mergeSort(scores, 0, 7, size) + merge(scores, 0, 3, 7, size) << " accesses" << endl;
        printArray(scores, size);
        mergeavg += mergeSort(scores, 0, 7, size) + merge(scores, 0, 3, 7, size);
        unsortArray(scores, size);
        countingSort(scores, size);
        cout << "Counting sort " << n << ": " << countingSort(scores, size) << " accesses" << endl;
        printArray(scores, size);
        countingavg += countingSort(scores, size);
        unsortArray(scores, size);

    }

    cout << "Bubble sort average: " << bubbleavg / 3 << endl;
    cout << "Merge sort average: " << mergeavg / 3 << endl;
    cout << "Counting sort average: " << countingavg / 3 << endl;
    n = 0;

    // Reset averages
    bubbleavg = 0;
    mergeavg = 0;
    countingavg = 0;

    // Efficiency test - size 2 32 ints
    cout << "Size 2 tests: " << endl;
    size = 32;
    for (int i = 0; i < 3; i++){
        n++;
        initArray(scores, size);
        printArrayToFile(scores, size);
        readArrayFromFile(scores, size);
        bubbleSort(scores, size);
        cout << "Bubble sort " << n << ": " << bubbleSort(scores, size) << " accesses" << endl;
        printArray(scores, size);
        bubbleavg += bubbleSort(scores, size);
        unsortArray(scores, size);
        mergeSort(scores, 0, 31, size);
        cout << "Merge sort " << n << ": " << mergeSort(scores, 0, 31, size) + merge(scores, 0, 15, 31, size) << " accesses" << endl;
        printArray(scores, size);
        mergeavg += mergeSort(scores, 0, 31, size) + merge(scores, 0, 15, 31, size);
        unsortArray(scores, size);
        countingSort(scores, size);
        cout << "Counting sort " << n << ": " << countingSort(scores, size) << " accesses" << endl;
        printArray(scores, size);
        countingavg += countingSort(scores, size);
        unsortArray(scores, size);

    }
    
    cout << "Bubble sort average: " << bubbleavg / 3 << endl;
    cout << "Merge sort average: " << mergeavg / 3 << endl;
    cout << "Counting sort average: " << countingavg / 3 << endl;
    n = 0;
    // Reset averages
    bubbleavg = 0;
    mergeavg = 0;
    countingavg = 0;

    // Efficiency test - size 3 128 ints
    cout << "Size 3 tests: " << endl;
    size = 128;
    for (int i = 0; i < 3; i++){
        n++;
        initArray(scores, size);
        printArrayToFile(scores, size);
        readArrayFromFile(scores, size);
        bubbleSort(scores, size);
        cout << "Bubble sort " << n << ": " << bubbleSort(scores, size) << " accesses" << endl;
        printArray(scores, size);
        bubbleavg += bubbleSort(scores, size);
        unsortArray(scores, size);
        mergeSort(scores, 0, 127, size);
        cout << "Merge sort " << n << ": " << mergeSort(scores, 0, 127, size) + merge(scores, 0, 63, 127, size) << " accesses" << endl;
        printArray(scores, size);
        mergeavg += mergeSort(scores, 0, 127, size) + merge(scores, 0, 63, 127, size);
        unsortArray(scores, size);
        countingSort(scores, size);
        cout << "Counting sort " << n << ": " << countingSort(scores, size) << " accesses" << endl;
        printArray(scores, size);
        countingavg += countingSort(scores, size);
        unsortArray(scores, size);

    }

    cout << "Bubble sort average: " << bubbleavg / 3 << endl;
    cout << "Merge sort average: " << mergeavg / 3 << endl;
    cout << "Counting sort average: " << countingavg / 3 << endl;

    return 0;
}

// Function definitions
void initArray(int scores[], int size){
    // Seed random number generator
    srand(time(0));

    // Init array
    for (int i = 0; i < size; i++){
        scores[i] = rand() % 100;
    }
}

void printArray(int scores[], int size){
    // Print array
    for (int i = 0; i < size; i++){
        cout << scores[i] << " ";
    }
    cout << endl;
}

void printArrayToFile(int scores[], int size){
    // Print array to file
    ofstream outFile;
    outFile.open(fileName);
    for (int i = 0; i < size; i++){
        outFile << scores[i] << " ";
    }
    outFile.close();
}

void readArrayFromFile(int scores[], int size){
    // Read array from file
    ifstream inFile;
    inFile.open(fileName);
    for (int i = 0; i < size; i++){
        inFile >> scores[i];
    }
    inFile.close();
}

void unsortArray(int scores[], int size){
    // random shuffle array
    random_shuffle(&scores[0], &scores[size]);
}

int bubbleSort(int scores[], int size){
    // Vars
    int temp;
    bool swap;
    int count = 0;


    // Sort array + count accesses
    do{
        swap = false;
        for (int i = 0; i < size; i++){
            count++;
            if (scores[i] > scores[i + 1]){
                temp = scores[i];
                scores[i] = scores[i + 1];
                scores[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);

    return count;
}


int mergeSort(int scores[], int first, int last, int size){
    int count = 0;
    int temp[size];
    int middle;

    if (first < last){
        middle = (first + last) / 2;
        mergeSort(scores, first, middle, size);
        count++;
        mergeSort(scores, middle + 1, last, size);
        count++;
        merge(scores, first, middle, last, size);
    }
    return count;
}

int merge(int scores[], int first, int middle, int last, int size){
    int temp[size];
    int first1 = first;
    int last1 = middle;
    int first2 = middle + 1;
    int last2 = last;
    int index = first1;
    int count = 0;

    while ((first1 <= last1) && (first2 <= last2)){
        if (scores[first1] < scores[first2]){
            temp[index] = scores[first1];
            first1++;
            count++;
        }
        else{
            temp[index] = scores[first2];
            first2++;
            count++;
        }
        index++;
    }

    while (first1 <= last1){
        temp[index] = scores[first1];
        first1++;
        index++;
    }

    while (first2 <= last2){
        temp[index] = scores[first2];
        first2++;
        index++;
    }

    for (index = first; index <= last; index++){
        scores[index] = temp[index];
    }
    return count;
}


// Sort our array using a second array that counts the number of times each value appears while counting accesses
int countingSort(int scores[], int size){
    // Vars
    int count[100] = { 0 };
    int temp[size];
    int count2 = 0;

    // Count the number of times each value appears
    for (int i = 0; i < size; i++){
        count[scores[i]]++;
        count2++;
    }

    // Add the number of times each value appears to the next value
    for (int i = 1; i < 100; i++){
        count[i] += count[i - 1];
    }

    // Sort array
    for (int i = size - 1; i >= 0; i--){
        temp[count[scores[i]] - 1] = scores[i];
        count[scores[i]]--;
    }

    // Copy array
    for (int i = 0; i < size; i++){
        scores[i] = temp[i];
    }

    return count2;
}