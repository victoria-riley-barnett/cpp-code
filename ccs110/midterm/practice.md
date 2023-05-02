Midterm 2 On-Your-Own Practice Questions

These questions are presented for your practice. You are not required to post an answer.  If you're stuck, or unsure about an answer, or have any questions about the midterm at all, please use this module's ungraded discussion board!

For questions 1-2, assume you have an ADT sorted list which currently has 10 integer entries.  All of the standard ADT sorted list operations discussed in class and textbook are available, including:

insertSorted(newEntry: ItemType): void 
remove(position: integer): boolean 
removeSorted(entry: ItemType): boolean

1. True/False: Command remove(5) is issued.  After this, the element previously at position 7 is guaranteed to be at position 6.
1a.) True - the int remove method shifts all elements after the removed element down one position, so the element previously at position 7 will be at position 6.

2.  True/False: insertSorted(100) will always insert 100 at the end of the list.
2a.) False, it will insert 100 into the correct position on the list depending on the key that is being used to sort the list.

3. You have an array of n unsorted integers.  In big-O notation, what's the worst case efficiency of using insertSorted() to insert them all into a sorted list?  Assume the sorted list is implemented using a link-based approach.
3a.) The worst case efficiency would be an O(n^2) because the insertSorted() method would have to iterate through the existing list to find the correct position to insert the new element. This would have to be done for each element in the array, so it would be n^2.

4. True/False: a stack is a FIFO (first in first out) system
4a.) False, a stack is a LIFO (last in first out) system.

5.  You have an algorithm which processes a string containing an algebraic expression.  Every time it sees open parenthesis ‘(‘ it pushes it on a stack.  Every time it sees close parenthesis ‘)’ it pops one element off the stack.  You process an expression using this algorithm and each push and pop operation returns true (success).  How would you test if the expression has balanced parenthesis?
5a.) Balanced expressions has the same number of open and closed parenthesis, so one test could be checking to see if the stack is empty after the expression string has been processed. Alternatively you could could the occurances of open and closed parenthesis being added to your stack and compare them. 

6.  Assume you have a stack implemented which supports the following operations discussed in the videos and the textbook:

+isEmpty(): boolean
+push(newEntry: ItemType): boolean                  
+pop(): boolean
+peek(): ItemType

What would peek() return after using push() to add these three items to it in order: 2 4 3? 

6a.) Peek would return 3 because it returns the top element of the stack, which is the last element that was added to the stack.

7. True/False: a queue is a FIFO (first in first out) system
7a.) True, a queue is a FIFO (first in first out) system.

8. You've implemented a queue for a concierge phone line for customers of a Las Vegas casino in which customers are served in the order they called in.  Your boss tells you that customers with higher VIP status levels should be served before customers of lower VIP status levels.  What ADT could you use to accomplish this?
8a.) Multiple ADTs could be used to accomplish this depending on how the VIP status levels are stored and could be keyed. A sorted list or priority queue could be used to compare VIP status levels and prioritize the higher VIP customers.


9. You enqueue the following items into a queue of integers: 5 2 3.  What will peekFront() return?
9a.) PeekFront() will return 5 because it returns the first element in the queue,  peekFront is a method that calls getEntry at the front of the queue.

10. True/False: each node in a binary tree has exactly two children.
10a.) False, each node in a binary tree can have 0, 1, or 2 children.

11.  What is the efficiency of traversal of a binary tree in big-O notation?  A binary search tree?
11a.) The efficiency of traversal of a binary tree is O(n) because it has to visit each node in the tree. The efficiency of traversal of a binary search tree is O(log n) because it only has to visit the nodes that are on the path to the node that is being searched for.

12. True/false: the following tree is a balanced binary search tree.  
    0060
    /  \
 0020 0070
  / \
0010 0030
      /\
    0025 0040 

12a.) False, this tree is not balanced as the height differs by greater than 1 between the left and right subtrees.

13. What's the minimum height of a binary tree with n nodes?
13a.) The minimum height of a binary tree with n nodes is floor(log2(n)) where floor is the greatest integer less than or equal to log2(n).


14. If I add the element 45 to this binary search tree, where could it go?  Make sure to specify if it is a right or left child of its parent.

    0060
    /  \
 0020 0070
  / \
0010 0040
      /\
    0030 0050

14a.) Inserting 45 would lead us to the right subtree of 40 because it is greater than 40, however that position is filled by 50, so it would go to the left subtree of 50 because it is less than 50.

15. Suppose I have an array-based queue which is implemented with a circular array in the state depicted below, with 2 being the front and 7 being the rear pointer.  Illustrate the circular array after the following two operations:

enqueue(9)
dequeue()

15a.) After enqueue(9) the array would look like this:

9 2 4 1 7

Then after dequeue() the array would look like this:

2 4 1 7 9, shifting the front pointer to the next element in the array and the front to the back of the array.

16. Write a C++ function sum() which returns the sum of all entries in a node-based binary search tree containing integers.  You may assume each node contains a valid integer.  You can assume the BinaryNode class supports the BinaryNode member functions discussed in class and the textbook: getItem(), getLeftChildPtr(), getRightChildPtr().

// nodePtr: pointer to the root of the tree we want to sum
int sum(BinaryNode* nodePtr)

17. Write a pseudocode function sumPositive() which adds up all of the positive elements in a queue containing integers.

sumPositive(aQueue: Queue): integer

For example, if aQueue contains, from front to back: 2, -3, 4, -10, 1

your function should return 7.  It is acceptable if you modify aQueue in the function.

You can assume that the queue supports the functions discussed in class and the textbook (and only these functions):

isEmpty(): boolean
enqueue(newEntry: integer): boolean 
dequeue(): boolean
peekFront(): integer