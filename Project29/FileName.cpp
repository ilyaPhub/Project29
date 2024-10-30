#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* head; 
    Node<T>* tail; 
    size_t size;  

public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty! Cannot dequeue." << endl;
            return T(); 
        }
        Node<T>* temp = head;
        T value = temp->data;

        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr; 
        }
        delete temp;
        size--;
        return value;
    }

    T front() const {
        if (isEmpty()) {
            cout << "Error: Queue is empty!" << endl;
            return T();
        }
        return head->data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;

    q.dequeue();
    cout << "Front element after dequeue: " << q.front() << endl;

    q.enqueue(40);
    cout << "Queue size: " << q.getSize() << endl;

    while (!q.isEmpty()) {
        cout << "Dequeue: " << q.dequeue() << endl;
    }

    q.dequeue();
    return 0;
}
