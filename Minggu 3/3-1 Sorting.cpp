#include <iostream>
#include <vector>

using namespace std;

// Fungsi bubble sort untuk mengurutkan array dari kecil ke besar
// Algoritma: membandingkan elemen berdekatan dan menukar jika urutannya salah
// Kompleksitas waktu: O(n²) - tidak efisien untuk data besar
vector<int> bubbleSort(vector<int> array) {
    int arraySize = array.size();

    // Loop luar: menentukan berapa kali iterasi penuh diperlukan
    // Setiap iterasi akan memindahkan elemen terbesar ke posisi terakhir
    for (int i = 0; i < arraySize - 1; i++) {
        // Loop dalam: membandingkan elemen berdekatan
        // arraySize - i - 1: tidak perlu membandingkan elemen yang sudah di posisi akhir
        for (int j = 0; j < arraySize - i - 1; j++) {
            // Jika elemen saat ini lebih besar dari elemen berikutnya, tukar posisi
            if (array[j] > array[j + 1]) {
                int temp = array[j];        // Simpan nilai sementara
                array[j] = array[j + 1];    // Pindahkan elemen kanan ke kiri
                array[j + 1] = temp;        // Pindahkan elemen kiri ke kanan
            }
        }
    }

    return array; // Kembalikan array yang sudah terurut
}

int main() {
    // Array yang akan diurutkan
    vector<int> arrayUnsorted = {5, 3, 8, 4, 2};

    // Menampilkan array sebelum diurutkan
    cout << "Array sebelum diurutkan: ";
    for (int i = 0; i < arrayUnsorted.size(); i++) {
        cout << arrayUnsorted[i] << " ";
    }
    cout << endl;

    // Memanggil fungsi bubble sort dan menyimpan hasilnya
    vector<int> arraySorted = bubbleSort(arrayUnsorted);

    // Menampilkan array setelah diurutkan
    cout << "Array setelah diurutkan: ";
    for (int i = 0; i < arraySorted.size(); i++) {
        cout << arraySorted[i] << " ";
    }
    cout << endl;

    return 0;
}