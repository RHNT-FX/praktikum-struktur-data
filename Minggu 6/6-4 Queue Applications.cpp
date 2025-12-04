#include <iostream>
#include <vector>

using namespace std;

// Queue sederhana berbasis vector + head index
class Queue {
private:
    vector<int> data; 
    int head = 0;

    // Meng-"compact" buffer ketika head sudah terlalu maju.
    // Tujuan:
    // - Mengembalikan elemen aktif ke awal vector agar tidak terus membuang memori di depan.
    // - Menjaga ukuran kapasitas agar tidak membesar tanpa perlu saat banyak pop() dilakukan.
    // Algoritma:
    // - Jika head sudah melewati setengah dari total elemen tersimpan, salin sisa elemen aktif
    //   [head..end) ke vector baru, lalu swap dan set head=0.
    void compactIfNeeded() {
        if (head > 0 && head * 2 >= static_cast<int>(data.size())) {
            vector<int> tmp(data.begin() + head, data.end());
            data.swap(tmp); 
            head = 0;
        }
    }

public:
    void push(int v) { 
        data.push_back(v); 
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
};

// BFS pada graf tidak berbobot, adjacency list
void bfs(const vector<vector<int>>& g, int start) {
    int n = static_cast<int>(g.size());
    vector<int> vis(n, 0); // contoh: n = 5 maka vis = {0, 0, 0, 0, 0}, fungsinya untuk menandai node yang sudah dikunjungi
    Queue q; 
    q.push(start); 
    vis[start] = 1;
    
    cout << "BFS order: ";

    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        cout << u << ' ';
        for (int v : g[u]) {
            if (!vis[v]) { 
                vis[v] = 1; 
                q.push(v); 
            }
        }
    }
    cout << '\n';
}

int main() {
    cout << "=== Queue Applications: BFS ===\n";
    // Graf contoh (0..5)
    vector<vector<int>> g = {
        {1, 2},    // 0 -> 1,2
        {0, 3, 4}, // 1 -> 0,3,4
        {0, 5},    // 2 -> 0,5
        {1},       // 3 -> 1
        {1, 5},    // 4 -> 1,5
        {2, 4}     // 5 -> 2,4
    };

    bfs(g, 0);
    bfs(g, 3);

    return 0;
}
