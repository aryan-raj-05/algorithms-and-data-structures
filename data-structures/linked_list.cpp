#include <iostream>

// Doubly Linked List
template <typename T>
class LinkedList {
    struct Node {
        T item;
        Node* next;
        Node* prev;

        Node() : item(T()), next(nullptr), prev(nullptr) {}
        Node(T val) : item(val), next(nullptr), prev(nullptr) {}
        Node(T val, Node* nxt, Node* prv): item(val), next(nxt), prev(prv) {}
    };

    Node* head;
    Node* tail;
    int length;
public:
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    LinkedList(T item) {
        head = tail = new Node(item);
        length = 1;
    }

    void addLast(T item) {
        if (length == 0) {
            head = tail = new Node(item);
            length++;
            return;
        }

        Node* tmp = new Node(item, nullptr, tail);
        tail->next = tmp;
        tail = tmp;
        length++;
    }

    void removeLast() {
        if (length == 0) {
            std::cerr << "Remove Operation Called on Empty List\n";
            return;
        } else if (length == 1) {
            delete head;
            head = tail = nullptr;
            length = 0;
            return;
        }

        Node* nodeToDelete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete nodeToDelete;
        length--;
    }

    void addFirst(T item) {
        if (length == 0) {
            head = tail = new Node(item);
            length++;
            return;
        }

        Node* tmp = new Node(item, head, nullptr);
        head->prev = tmp;
        head = tmp;
        length++;
    }

    void removeFirst() {
        if (length == 0) {
            std::cerr << "Remove Operation called on empty list\n";
            return;
        } else if (length == 1) {
            delete head;
            head = tail = nullptr;
            length = 0;
            return;
        }

        Node* nodeToDelete = head;
        head = head->next;
        head->prev = nullptr;
        delete nodeToDelete;
        length--;
    }

    int size() const {
        return length;
    }

    ~LinkedList() {
        Node *tmp = head;

        while (tmp != nullptr) {
            Node* prev = tmp;
            tmp = tmp->next;
            delete prev;
        }

        head = tail = nullptr;
        length = 0;
    }
};