#include <iostream>

using namespace std;

// Node untuk Singly Linked List
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Fungsi untuk membuat linked list dari array
Node* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* cur = head;
    for (int i = 1; i < n; ++i) {
        cur->next = new Node(arr[i]);
        cur = cur->next;
    }
    return head;
}

// Tampilkan linked list
void printList(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->data;
        if (cur->next != nullptr) cout << " -> ";
        cur = cur->next;
    }
    cout << '\n';
}

// Reverse linked list (iteratif)
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    Node* next = nullptr;

    while (cur != nullptr) {
        next = cur->next;  // simpan node berikutnya
        cur->next = prev;  // balik pointer
        prev = cur;        // maju ke depan
        cur = next;        // maju ke node berikutnya
    }
    return prev; // prev sekarang menjadi head baru
}

// Hapus node dengan nilai tertentu (hapus semua kemunculan)
Node* deleteNode(Node* head, int value) {
    // Hapus node di depan jika perlu
    while (head != nullptr && head->data == value) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    if (head == nullptr) return nullptr;

    // Hapus node di tengah/belakang
    Node* cur = head;
    while (cur->next != nullptr) {
        if (cur->next->data == value) {
            Node* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

// Cari nilai di linked list
bool search(Node* head, int value) {
    Node* cur = head;
    while (cur != nullptr) {
        if (cur->data == value) return true;
        cur = cur->next;
    }
    return false;
}

// Hitung panjang linked list
int getLength(Node* head) {
    int count = 0;
    Node* cur = head;
    while (cur != nullptr) {
        ++count;
        cur = cur->next;
    }
    return count;
}

// Hapus semua node (cleanup memori)
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    cout << "=== Linked List Applications ===\n\n";

    int arr[] = {1, 2, 3, 4, 5};
    Node* head = createList(arr, 5);
    cout << "List awal: ";
    printList(head);

    cout << "\nPanjang list: " << getLength(head) << '\n';

    cout << "\nCari nilai 3: " << (search(head, 3) ? "ditemukan" : "tidak ditemukan") << '\n';
    cout << "Cari nilai 10: " << (search(head, 10) ? "ditemukan" : "tidak ditemukan") << '\n';

    cout << "\nReverse list: ";
    head = reverseList(head);
    printList(head);

    cout << "\nHapus nilai 3: ";
    head = deleteNode(head, 3);
    printList(head);

    cout << "\nHapus nilai 1: ";
    head = deleteNode(head, 1);
    printList(head);

    deleteList(head);
    return 0;
}

