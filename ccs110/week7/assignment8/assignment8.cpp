// Victoria Barnett - CS 110C - Assignment 8 - 04/18/2023
#include <iostream>
#include <string>

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
    front = 0;
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
bool isPalindrome(Stack s, Queue q, int length);

int main(){
    string input;
    int length;

    cout << "Enter a string: ";
    getline(cin, input);

    length = input.length();

    Stack s(length);
    Queue q(length);

    for (int i = 0; i < length; i++) {
        char c = input[i] - '0';
        s.push(input[i]);
        q.enqueue(input[i]);
    }

    if (isPalindrome(s, q, length)) {
        cout << "The string is a palindrome" << endl;
    }
    else {
        cout << "The string is not a palindrome" << endl;
    }

    
    return 0;
}

bool isPalindrome(Stack s, Queue q, int length) {
    while (!q.isEmpty()) {
        if (q.peekFront() == s.peek()) {
            q.dequeue();
            s.pop();
        }
        else {
            return false;
        }
    }

    return true;
}

