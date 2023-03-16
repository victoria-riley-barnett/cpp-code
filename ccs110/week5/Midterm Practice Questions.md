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

4.  What is an advantage of an array-based list over a linked list?

5.  Assume you have an ADT list which currently has 10 entries.  You would like to add an element with new entry x to the beginning of the list.  Which of the following insert operations does it:

a) insert(0,x)

b) insert(1,x)

c) insert(10,x)

d) none of these

6.  You have the same list as question 5.

True/False: the command remove(5) is issued.  After this, the element which was previously at position 7 will be at position 6. 

7a.  The ADT list method remove removes from the list the entry at a given position.  We'd like a new method removeEntry which removes the first (or only) occurrence of a given entry from the list.  Write a pseudocode function which does this.  You may use the standard ADT list functions we discussed in the videos/pdfs -- insert(), remove(), getEntry(), setEntry(), getLength().  It should have the following signature:

```cpp
removeEntry(theList: List, entry: ItemType)
```

7b. Specify what happens if there are multiple entries with the value to be removed. 

8.  True/False: In the general case, a linked list provides a faster setEntry() time than an array based list.

9.  You have an integer array of length n.  What is the worst-case complexity of sorting it using a quick sort?  A bubble sort?  State your answers in big-O notation.

10.  You have an integer array of length 5.  What is the best-case number of comparisons a bubble sort needs to make?

11.  You have an integer array of length 5.  What is the worst-case number of swaps a selection sort needs to make?  

12.  What is the worst-case complexity of a linear search on a sorted array of length n?  State your answer using big-O notation.

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