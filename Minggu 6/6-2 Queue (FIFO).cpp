#include <iostream>
#include <vector>

using namespace std;

// Implementasi Queue (FIFO) sederhana tanpa <queue>
// Menggunakan vector dan indeks head untuk O(1) amortized pop
class Queue {
private:
    vector<int> data;
    int head = 0; // posisi elemen terdepan

    // Rapatkan memori bila head terlalu maju untuk menghindari pertumbuhan memori
    // Contoh alur (data awal {1,2,3}, head=0):
    // - pop() -> head=1, elemen aktif {2,3} berada di indeks [1..)
    // - pop() -> head=2, elemen aktif {3} berada di indeks [2..)
    // - Saat head cukup besar (>= size/2), compactIfNeeded() menyalin elemen aktif
    //   ke vector baru: tmp = {3}, lalu swap -> data={3}, head=0.
    //   Tujuan: membebaskan ruang yang tidak terpakai di depan dan menjaga efisiensi.
    void compactIfNeeded() {
        if (head > 0 && head * 2 >= static_cast<int>(data.size())) {
            vector<int> tmp(data.begin() + head, data.end());
            data.swap(tmp); // swap untuk menukar isi data dengan tmp tanpa copy elemen
            head = 0;
        }
    }

public:
    void push(int value) {
        data.push_back(value);
    }

    void pop() {
        if (!empty()) { 
            ++head; 
            compactIfNeeded(); 
        }
    }

    int front() const { 
        return data[head]; 
    }

    bool empty() const { 
        return head >= static_cast<int>(data.size()); 
    }

    int size() const { 
        return static_cast<int>(data.size()) - head; 
    }
};

int main() {
    cout << "=== Queue (FIFO) ===\n";
    Queue q;

    q.push(10); 
    q.push(20); 
    q.push(30);

    cout << "size: " << q.size() << " front: " << q.front() << '\n';
    q.pop();
    cout << "after pop -> size: " << q.size() << " front: " << q.front() << '\n';

    while (!q.empty()) { 
        cout << q.front() << (q.size()>1?' ':'\n'); 
        q.pop(); 
    }

    return 0;
}
