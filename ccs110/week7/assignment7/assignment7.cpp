// Victoria Barnett - CS 110C - Assignment 7 - 04/09/2023
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//defs
class Stack {
private:
    char top;
    int size;
    int *stackArray;
public:
    Stack(int size);
    ~Stack();
    void push(int value);
    int pop();
    bool isEmpty();
    bool isFull();
    void showStack();
    char peek();
};

Stack::Stack(int size) {
    this->size = size;
    stackArray = new int[size];
    top = -1;
}

Stack::~Stack() {
    delete[] stackArray;
}

void Stack::push(int value) {
    if (isFull()) {
        cout << "Stack is full" << endl;
    }
    else {
        top++;
        stackArray[top] = value;
    }
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else {
        int temp = stackArray[top];
        top--;
        return temp;
    }
}

bool Stack::isEmpty() {
    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}

bool Stack::isFull() {
    if (top == size - 1) {
        return true;
    }
    else {
        return false;
    }
}

void Stack::showStack() {
    for (int i = top; i >= 0; i--) {
        cout << stackArray[i] << " ";
    }
    cout << endl;
}

char Stack::peek() {
    return stackArray[top];
}

class Queue {
private:
    char front;
    char rear;
    int size;
    int *queueArray;
public:
    Queue(int size);
    ~Queue();
    void enqueue(int value);
    int dequeue();
    bool isEmpty();
    bool isFull();
    void showQueue();
    char peekFront();
    char peekRear();
};

Queue::Queue(int size) {
    this->size = size;
    queueArray = new int[size];
    front = -1;
    rear = -1;
}

Queue::~Queue() {
    delete[] queueArray;
}

void Queue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full" << endl;
    }
    else {
        rear++;
        queueArray[rear] = value;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else {
        int temp = queueArray[front];
        front++;
        return temp;
    }
}

bool Queue::isEmpty() {
    if (front == rear) {
        return true;
    }
    else {
        return false;
    }
}

bool Queue::isFull() {
    if (rear == size - 1) {
        return true;
    }
    else {
        return false;
    }
}

void Queue::showQueue() {
    for (int i = front; i <= rear; i++) {
        cout << queueArray[i] << " ";
    }
    cout << endl;
}

char Queue::peekFront() {
    return queueArray[front];
}

char Queue::peekRear() {
    return queueArray[rear];
}

//prototypes
bool isPalindrome(string palindrome, Stack &stack, Queue &queue);
bool QueueEqualsStack(Queue &queue, Stack &stack);

int main(){
    //vars
    string palindrome;
    Stack stack(100);
    Queue queue(100);
    bool isPalindromeBool;

    //get input
    cout << "Enter a string: ";
    getline(cin, palindrome);

    //check if palindrome
    isPalindromeBool = isPalindrome(palindrome, stack, queue);

    //output
    if (isPalindromeBool) {
        cout << "The string is a palindrome" << endl;
    }
    else {
        cout << "The string is not a palindrome" << endl;
    }

    return 0;
}

bool isPalindrome(string palindrome, Stack &stack, Queue &queue) {
    //vars
    int i = 0;
    int j = palindrome.length() - 1;
    bool isPalindromeBool = true;

    //loop through string
    while (i < j) {
        //push to stack
        stack.push(palindrome[i]);
        //enqueue to queue
        queue.enqueue(palindrome[j]);
        //increment i
        i++;
        //decrement j
        j--;
    }

    //check if palindrome
    isPalindromeBool = QueueEqualsStack(queue, stack);

    return isPalindromeBool;
}

bool QueueEqualsStack(Queue &queue, Stack &stack) {
    //vars
    bool isPalindromeBool = true;

    //loop through queue and stack
    while (!queue.isEmpty() && !stack.isEmpty()) {
        //check if equal
        if (queue.peekFront() != stack.peek()) {
            isPalindromeBool = false;
        }
        //dequeue from queue
        queue.dequeue();
        //pop from stack
        stack.pop();
    }

    return isPalindromeBool;
}
