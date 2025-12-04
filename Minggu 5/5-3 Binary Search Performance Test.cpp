#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Binary Search Iteratif
int binarySearchIteratif(const vector<int>& arr, int target) {
    int l = 0, r = static_cast<int>(arr.size()) - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// Binary Search Rekursif
int binarySearchRekursifHelper(const vector<int>& arr, int l, int r, int target) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return binarySearchRekursifHelper(arr, mid + 1, r, target);
    return binarySearchRekursifHelper(arr, l, mid - 1, target);
}

int binarySearchRekursif(const vector<int>& arr, int target) {
    return binarySearchRekursifHelper(arr, 0, static_cast<int>(arr.size()) - 1, target);
}

int main() {
    cout << "=== Binary Search Performance Test ===\n";
    
    // Buat array besar untuk testing
    vector<int> data;
    for (int i = 0; i < 1000000; ++i) {
        data.push_back(i * 2); // Array terurut: 0, 2, 4, 6, 8, ...
    }
    
    const int ITERATIONS = 100000; // Jumlah pencarian
    vector<int> targets;
    
    // Buat target yang bervariasi untuk mencegah over-optimization
    for (int i = 0; i < ITERATIONS; ++i) {
        targets.push_back((i * 7) % 2000000); // Target yang tersebar
    }
    
    cout << "Array size: " << data.size() << " elements\n";
    cout << "Iterations: " << ITERATIONS << " searches\n\n";
    
    // Test Iteratif
    auto start = chrono::high_resolution_clock::now();
    volatile int result_iter = 0; // volatile untuk mencegah optimisasi
    for (int i = 0; i < ITERATIONS; ++i) {
        result_iter += binarySearchIteratif(data, targets[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration_iter = chrono::duration_cast<chrono::milliseconds>(end - start);
    
    // Test Rekursif
    start = chrono::high_resolution_clock::now();
    volatile int result_rec = 0; // volatile untuk mencegah optimisasi
    for (int i = 0; i < ITERATIONS; ++i) {
        result_rec += binarySearchRekursif(data, targets[i]);
    }
    end = chrono::high_resolution_clock::now();
    auto duration_rec = chrono::duration_cast<chrono::milliseconds>(end - start);
    
    cout << "Iteratif: " << duration_iter.count() << " ms\n";
    cout << "Rekursif: " << duration_rec.count() << " ms\n";
    
    // Hitung perbedaan
    if (duration_iter.count() > 0) {
        double ratio = static_cast<double>(duration_rec.count()) / duration_iter.count();
        cout << "Rekursif " << (ratio > 1.0 ? "lebih lambat" : "lebih cepat") 
             << " " << ratio << "x\n";
    }
    
    return 0;
}
