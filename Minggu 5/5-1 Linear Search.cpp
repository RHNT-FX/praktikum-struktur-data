#include <iostream>
#include <vector>

using namespace std;

// Linear Search: cek satu per satu dari kiri ke kanan
// Mengembalikan indeks pertama yang cocok, atau -1 jika tidak ditemukan
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// Versi yang mengembalikan semua indeks kemunculan target
vector<int> linearSearchAll(const vector<int>& arr, int target) {
    vector<int> idxs;
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        if (arr[i] == target) idxs.push_back(i);
    }
    return idxs;
}

int main() {
    cout << "=== Linear Search ===\n";
    vector<int> data = {4, 2, 7, 2, 9, 2};

    int target = 2;
    int firstIdx = linearSearch(data, target);
    cout << "Indeks kemunculan pertama angka " << target << ": " << firstIdx << '\n';

    vector<int> allIdx = linearSearchAll(data, target);
    cout << "Semua indeks kemunculan angka " << target << ": ";
    for (int i = 0; i < static_cast<int>(allIdx.size()); ++i) {
        cout << allIdx[i] << (i + 1 < static_cast<int>(allIdx.size()) ? ' ' : '\n');
    }

    // Kasus tidak ditemukan
    cout << "Indeks kemunculan pertama angka 5: " << linearSearch(data, 5) << '\n';

    return 0;
}


