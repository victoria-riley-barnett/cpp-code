These questions are presented for your practice. You are not required to post an answer.  If you're stuck, or unsure about an answer, or have any questions about the midterm at all, please use this module's ungraded discussion board!

1. Consider the recursive function first() below.  What is a problem with it?

```cpp
//prints out the first element of an array recursively
void first(int theArray[], int size)
{
  if (size == 1)
    cout << theArray[0];
  else {
    first(theArray, size);
  }
}
```

1. Answer: The array will not usually be size 1, and if the array passed is not size one this function will segfault because it run's over and over, doing nothing. Also, I'm not sure there is a need to recursively print out the first element of an array - it doesn't really make sense.

2.  Write a recursive C++ function that returns the maximum value in an integer array of length size.  You may assume the array passed in and its size are valid, and size is at least 1.  It should have the following signature:

```cpp
int max(int array[], int size)
```

3.  Trace through one iteration of the quick sort partition algorithm for the following array.  Write out the values in the array after each swap and indicate the swaps which occurred.  Assume you are using the first element as the pivot.  

`5 1 8 2 9 3 1`

```cpp output
array is currently: 1 2 3 4 5
i = 0
i = 1
array[i] = 2
swapped: 5 and 2
array is now: 1 5 3 4 2
i = 2
i = 3
array[i] = 4
swapped: 2 and 4
array is now: 1 5 3 2 4
i = 4
array[i] = 4
swapped: 4 and 4
array is now: 1 5 3 2 4
1 5 3 2 4
The number of swaps is: 3
```

```cpp

#include <iostream>
#include <string>

using namespace std;

// Prototyping
int quickswap(int array[], int size);


int main(){
  //vars
  int size = 5;
  int theArray[size] = {1,2,3,4,5};
  int count = 0;

  count = quickswap(theArray, size);
  for (int i = 0; i < size; i++)
    cout << theArray[i] << " ";
  cout << endl;

  cout << "The number of swaps is: " << count << endl;

  return 0;
}

int quickswap(int array[], int size){
  int count = 0;
  int temp = 0;

  cout << "array is currently: ";
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;

  for (int i = 0; i < size; i++){
    cout << "i = " << i << endl;
    if (array[i] % 2 == 0){
      temp = array[i];
      cout << "array[i] = " << array[i] << endl;
      array[i] = array[size-1];
      array[size-1] = temp;
      cout << "swapped: " << array[i] << " and " << array[size-1] << endl;
      cout << "array is now: ";
      for (int i = 0; i < size; i++)
        cout << array[i] << " ";
      cout << endl;
      count++;
    }
  }
  return count;
}
```


4.  What is an advantage of an array-based list over a linked list?
4a. An array based list can be more efficient in that each of it's items don't require additonal structures, like a pointer in a linked list. This is an advantage in memory efficiency and speed that needs to be considered. You can also use better alogrithms like merge sort on an array based list.


5.  Assume you have an ADT list which currently has 10 entries.  You would like to add an element with new entry x to the beginning of the list.  Which of the following insert operations does it:

a) insert(0,x)

b) insert(1,x)

c) insert(10,x)

d) none of these

5a. a) insert(0,x) will inset entry x at the beginning of the list. 


6.  You have the same list as question 5.

True/False: the command remove(5) is issued.  After this, the element which was previously at position 7 will be at position 6. 

6a. False. The element which was previously at position 7 will be at position 7. Remove(5) only removes the first occurrence of the element at position 5 and does not shift the rest of the list.

7a.  The ADT list method remove removes from the list the entry at a given position.  We'd like a new method removeEntry which removes the first (or only) occurrence of a given entry from the list.  Write a pseudocode function which does this.  You may use the standard ADT list functions we discussed in the videos/pdfs -- insert(), remove(), getEntry(), setEntry(), getLength().  It should have the following signature:

```cpp
removeEntry(theList: List, entry: ItemType)

void removeEntry(theList: List, entry: ItemType){
  //vars
  int index = 0;
  int size = 0;

  //get size of list
  size = theList.getLength();

  //find index of entry
  for (int i = 0; i < size; i++){
    if (theList.getEntry(i) == entry)
      index = i;
  }

  //remove entry
  theList.remove(index);
}
```

7b. Specify what happens if there are multiple entries with the value to be removed. 
7ba. Only the first occurrence of the entry will be removed from the list.

8.  True/False: In the general case, a linked list provides a faster setEntry() time than an array based list.
8a. A linked list provides a slower setEntry() time than an array based list - it's time complexity is O(n) while an array based list is O(1), meaning it's constant while linked lists scale up exponentially with the size of the list.

9.  You have an integer array of length n.  What is the worst-case complexity of sorting it using a quick sort?  A bubble sort?  State your answers in big-O notation.
9a. Both Quick sort's worst case complexity and bubble sort's worst case complexity are O(n^2).

10.  You have an integer array of length 5.  What is the best-case number of comparisons a bubble sort needs to make?
10a. Best case for bubble sort is O(n) - meaning with an array of length 5, it would only need to make 5 comparisons.

11.  You have an integer array of length 5.  What is the worst-case number of swaps a selection sort needs to make? 
11a. Worst case for selection sort is O(n^2) - meaning with an array of length 5, it would need to make 25 swaps. 

12.  What is the worst-case complexity of a linear search on a sorted array of length n?  State your answer using big-O notation.
12a. The worst case complexity of a linear search on a sorted array of length n is O(n).

13.  Consider the doubly-linked list we discussed in the videos/pdfs in which each node points both to the next node, and to the previous node.  The list contains integer entries.

Write a C++ function printReverse() that prints out all elements in the list in reverse order.  It must take one parameter: a pointer the last node in the list.  You may assume that the parameter passed in points to a valid doubly-linked list. It should have the following signature:

```cpp
void printReverse(Node* tail);

You may use the Node class defined below for your nodes, or design your own.

class Node {
  public:
    int data;
    Node* next;
    Node* prev;
};   
``` 

void printReverse(Node* tail){
  Node* current = new Node;
  current = tail;

  while (current != NULL){
    cout << current->data << " ";
    current = current->prev;
  }
  cout << endl;
}