#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head; // Pointer (head)
public:
    LinkedList() {
        head = nullptr;
    }

    // Menambahkan data di awal
    void addToFront(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Menambahkan data di tengah
    void insertAfter(int value, int afterValue) {
        Node* newNode = new Node;
        newNode->data = value;

        Node* current = head;
        while (current != nullptr && current->data != afterValue) {
            current = current->next;
        }

        if (current != nullptr) {
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Menambahkan data di akhir
    void addToEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Menghapus data dengan nilai tertentu
    void remove(int value) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current != nullptr) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList myList;

    myList.addToFront(10);
    myList.addToFront(20);
    myList.addToEnd(30);
    myList.insertAfter(25, 20);

    std::cout << "Linked list contents: ";
    myList.display();

    myList.remove(20);
    std::cout << "After removing 20: ";
    myList.display();

    return 0;
}