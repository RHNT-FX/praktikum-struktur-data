#include <iostream>

using namespace std;

// Node untuk Doubly Linked List: punya pointer ke node sebelumnya dan berikutnya
struct Node {
    int data;
    Node* prev; // pointer ke node sebelumnya
    Node* next; // pointer ke node berikutnya

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Kelas Doubly Linked List
class DoublyLinkedList {
private:
    Node* head; // pointer ke node pertama
    Node* tail; // pointer ke node terakhir
    int length;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    // Tambah di depan
    void push_front(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++length;
    }

    // Tambah di belakang
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++length;
    }

    // Hapus dari depan
    void pop_front() {
        if (head == nullptr) return;
        Node* tmp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // list menjadi kosong
        }
        delete tmp;
        --length;
    }

    // Hapus dari belakang
    void pop_back() {
        if (tail == nullptr) return;
        Node* tmp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr; // list menjadi kosong
        }
        delete tmp;
        --length;
    }

    // Cari node dengan nilai tertentu, kembalikan pointer ke node tersebut
    Node* find(int value) const {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data == value) return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    // Hapus node dengan nilai tertentu (hapus pertama yang ditemukan)
    bool erase_value(int value) {
        Node* target = find(value);
        if (target == nullptr) return false;

        // Update pointer node tetangga
        if (target->prev != nullptr) {
            target->prev->next = target->next;
        } else {
            head = target->next; // target adalah head
        }

        if (target->next != nullptr) {
            target->next->prev = target->prev;
        } else {
            tail = target->prev; // target adalah tail
        }

        delete target;
        --length;
        return true;
    }

    // Hapus semua elemen
    void clear() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* nextNode = cur->next;
            delete cur;
            cur = nextNode;
        }
        head = tail = nullptr;
        length = 0;
    }

    // Tampilkan dari depan ke belakang
    void print_forward() const {
        cout << "Forward: ";
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->data;
            if (cur->next != nullptr) cout << " <-> ";
            cur = cur->next;
        }
        cout << '\n';
    }

    // Tampilkan dari belakang ke depan (keuntungan doubly linked list)
    void print_backward() const {
        cout << "Backward: ";
        Node* cur = tail;
        while (cur != nullptr) {
            cout << cur->data;
            if (cur->prev != nullptr) cout << " <-> ";
            cur = cur->prev;
        }
        cout << '\n';
    }

    int size() const { return length; }
    bool empty() const { return head == nullptr; }
};

int main() {
    cout << "=== Doubly Linked List ===\n";
    DoublyLinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.push_back(30);
    list.print_forward();
    list.print_backward();

    cout << "\nHapus 20:\n";
    list.erase_value(20);
    list.print_forward();

    cout << "\nHapus dari depan dan belakang:\n";
    list.pop_front();
    list.pop_back();
    list.print_forward();

    cout << "\nSize: " << list.size() << '\n';
    return 0;
}

