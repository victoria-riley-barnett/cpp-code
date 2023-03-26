/* CS110C - Victoria Barnett - Discussion 6 - 03/25/2023

Write pseudocode that combines two sorted lists into a new third sorted list by
using only the ADT sorted list operations discussed in the videos/pdfs:

+isEmpty(): boolean
+getLength(): integer
+insertSorted(newEntry: ItemType): void
+removeSorted(entry: ItemType): void
+remove(position:integer): boolean
+getEntry(position: integer): ItemType
+getPosition(entry: ItemType): integer              
+clear(): void

You can assume that the two existing sorted lists are called listOne and listTwo, 
and each has at least 1 element.  The new sorted list should be called combinedList.*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

// ADT sorted list operations
+isEmpty(): boolean
+getLength(): integer
+insertSorted(newEntry: ItemType): void
+removeSorted(entry: ItemType): void
+remove(position:integer): boolean
+getEntry(position: integer): ItemType
+getPosition(entry: ItemType): integer
+clear(): void

function combineLists() {
    int length = listOne.getLength();
    int length2 = listTwo.getLength();
    SortedListInterface<ItemType>* combinedList = new SortedList<ItemType>();
    int i = 1;
    int j = 1;
    while (i <= length && j <= length2) {
        if (listOne.getEntry(i) < listTwo.getEntry(j)) {
            combinedList.insertSorted(listOne.getEntry(i));
            i++;
        }
        else {
            combinedList.insertSorted(listTwo.getEntry(j));
            j++;
        }
    }
    while (i <= length) {
        combinedList.insertSorted(listOne.getEntry(i));
        i++;
    }
    while (j <= length2) {
        combinedList.insertSorted(listTwo.getEntry(j));
        j++;
    }
    return combinedList;
}

program start
initialize new SortedListInterface variable combinedList
function int combineLists(){
    initialize two length integers using getLength
    initialize an i and j variable to iterate on over both length ints
    start while i & j are less than length ints {
        compare values of entry i and j in listone and listtwo
        insert i into combinedList if it's smaller, otherwise insert j, then iterate both counters }
    return combinedList
}