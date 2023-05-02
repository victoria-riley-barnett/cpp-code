/*
Write a C++ function shortName which returns the number of nodes containing short names in a link-based binary tree containing strings at each node.  
A short name is defined as a string with 3 or fewer characters.  Hint: use the length() function to determine the length of a string.  
or example, if string s contains "Bob", s.length() will return 3.
You must use the BinaryNode class below for each node in the tree.  
You cannot assume any other classes or functions are available.
*/

class BinaryNode

{

public:

  string item;

  BinaryNode *leftChildPtr;

  BinaryNode *rightChildPtr;

};

 

//You can assume that your function is called with parameter nodePtr pointing to a valid binary tree with one or more nodes.

// nodePtr: pointer to the root of tree we need to search

int shortName(BinaryNode* nodePtr)

int shortName(BinaryNode* nodePtr) {
    if (nodePtr == NULL) {
        return 0;
    }
    int count = 0;
    if (nodePtr->item.length() <= 3) {
        count++;
    }
    count += shortName(nodePtr->leftChildPtr);
    count += shortName(nodePtr->rightChildPtr);
    return count;
}
/*
Write a pseudocode function which modifies a stack containing integers so that every element in the stack is doubled.  For example:

aStack before function: aStack after function:

top-> 3                         top-> 6                         

      2                               4                         

      1                               2                         

 

The stack implements the functions discussed in class and the textbook (and only these functions):

+isEmpty(): boolean

+push(newEntry: integer): boolean                  

+pop(): boolean

+peek(): integer

 

Hint: use temporary stack(s).  

*/
// doubles every element in aStack, which is passed in by reference

doubleStack(aStack: Stack)

doubleStack(aStack: Stack) {
    Stack tempStack;
    while (!aStack.isEmpty()) {
        tempStack.push(aStack.pop() * 2);
    }
    while (!tempStack.isEmpty()) {
        aStack.push(tempStack.pop());
    }
}