#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 100;  
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack penuh! Tidak dapat menambahkan elemen." << std::endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack kosong! Tidak dapat menghapus elemen." << std::endl;
            return;
        }
        --top;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack kosong!" << std::endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Elemen teratas: " << myStack.peek() << std::endl;

    myStack.pop();
    std::cout << "Elemen teratas setelah pop: " << myStack.peek() << std::endl;

    return 0;
}