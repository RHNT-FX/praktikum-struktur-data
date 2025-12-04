#include <iostream>

using namespace std;

// Struktur node untuk Singly Linked List
// Setiap node menyimpan data (int) dan pointer ke node berikutnya
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Kelas Singly Linked List sederhana
class SinglyLinkedList {
private:
    Node* head; // pointer ke node pertama (kepala)
    int length; // menyimpan jumlah elemen agar size() O(1)

public:
    SinglyLinkedList() : head(nullptr), length(0) {}

    ~SinglyLinkedList() {
        clear(); // pastikan semua node dibebaskan saat objek dihancurkan
    }

    // Tambah elemen di depan (O(1))
    void push_front(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        ++length;
    }

    // Tambah elemen di belakang (O(n) karena perlu traversal ke akhir)
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = newNode;
        }
        ++length;
    }

    // Sisipkan pada indeks ke-pos (0-based). Jika pos == 0, sama seperti push_front
    // Mengembalikan true jika berhasil, false jika pos di luar [0, length]
    bool insert_at(int pos, int value) {
        if (pos < 0 || pos > length) return false;
        if (pos == 0) { push_front(value); return true; }
        Node* newNode = new Node(value);
        Node* cur = head;
        for (int i = 0; i < pos - 1; ++i) {
            cur = cur->next; // bergerak ke node sebelum posisi sisip
        }
        newNode->next = cur->next;
        cur->next = newNode;
        ++length;
        return true;
    }

    // Hapus elemen pertama yang bernilai 'value'. Mengembalikan true jika ketemu dan dihapus
    bool erase_value(int value) {
        if (head == nullptr) return false;
        // Jika yang dihapus adalah head
        if (head->data == value) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            --length;
            return true;
        }
        // Cari node sebelum target
        Node* cur = head;
        while (cur->next != nullptr && cur->next->data != value) {
            cur = cur->next;
        }
        if (cur->next == nullptr) return false; // tidak ketemu
        Node* victim = cur->next;
        cur->next = victim->next;
        delete victim;
        --length;
        return true;
    }

    // Hapus elemen pada indeks pos (0-based). Mengembalikan true jika berhasil
    bool erase_at(int pos) {
        if (pos < 0 || pos >= length || head == nullptr) return false;
        if (pos == 0) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            --length;
            return true;
        }
        Node* cur = head;
        for (int i = 0; i < pos - 1; ++i) {
            cur = cur->next; // node sebelum yang akan dihapus
        }
        Node* victim = cur->next;
        cur->next = victim->next;
        delete victim;
        --length;
        return true;
    }

    // Mencari nilai. Mengembalikan indeks pertama jika ketemu, atau -1 jika tidak ada
    // Ditandai const karena tidak mengubah state list (aman dipanggil pada objek const)
    int find_first(int value) const {
        Node* cur = head;
        int idx = 0;
        while (cur != nullptr) {
            if (cur->data == value) return idx;
            cur = cur->next;
            ++idx;
        }
        return -1;
    }

    // Menghapus semua elemen dan membebaskan memori
    void clear() {
        Node* cur = head;
        while (cur != nullptr) {
            Node* nextNode = cur->next;
            delete cur;
            cur = nextNode;
        }
        head = nullptr;
        length = 0;
    }

    // size() tidak mengubah state, maka dibuat const agar bisa dipanggil pada objek const
    int size() const { return length; }

    // print() tidak memodifikasi list: tandai const untuk menjamin tidak ada perubahan state
    // Parameter prefix bertipe const char* karena hanya dibaca, bukan diubah
    void print(const char* prefix = "List: ") const {
        cout << prefix;
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->data;
            if (cur->next != nullptr) cout << ' ';
            cur = cur->next;
        }
        cout << '\n';
    }
};

int main() {
    cout << "=== Singly Linked List (Sederhana) ===\n";

    SinglyLinkedList list;

    // Tambah di depan dan belakang
    list.push_front(30);  // List: 30
    list.push_front(20);  // List: 20 30
    list.push_back(40);   // List: 20 30 40
    list.push_front(10);  // List: 10 20 30 40
    list.print("Setelah push_front/back: ");

    // Sisipkan pada indeks tertentu
    list.insert_at(2, 25); // List: 10 20 25 30 40  (disisip di index 2)
    list.print("Setelah insert_at(2,25): ");

    // Cari elemen
    int idx = list.find_first(30);
    cout << "Index nilai 30: " << idx << '\n';

    // Hapus berdasarkan nilai
    bool erased = list.erase_value(25); // hapus nilai 25
    cout << "Hapus nilai 25: " << (erased ? "berhasil" : "gagal") << '\n';
    list.print("Setelah erase_value(25): ");

    // Hapus berdasarkan posisi
    list.erase_at(0); // hapus head (10)
    list.print("Setelah erase_at(0): ");

    cout << "Ukuran list: " << list.size() << '\n';

    // clear akan otomatis dipanggil di destructor, namun kita bisa panggil manual
    list.clear();
    list.print("Setelah clear(): ");

    return 0;
}
