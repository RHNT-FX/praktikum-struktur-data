#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// Mengurutkan vector secara ascending dengan Bubble Sort (in-place)
void bubbleSort(vector<int>& array) {
    int arraySize = array.size();

    // Setiap iterasi luar menempatkan elemen terbesar tersisa ke posisi akhir yang benar
    for (int i = 0; i < arraySize - 1; i++) {
        // Bandingkan pasangan elemen yang berdekatan dan tukar jika urutannya salah
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Mencetak isi vector dalam satu baris dengan pesan pembuka
void tampilkanArray(const vector<int>& array, const string& pesan) {
    cout << pesan;
    for (int i = 0; i < array.size(); i++) {
        cout << array[i];
        if (i < array.size() - 1) cout << " "; // spasi antar nilai, tidak di akhir
    }
    cout << endl;
}

int main() {
    cout << "=== Program Bubble Sort dengan Input User ===" << endl;
    
    char lanjut = 'y'; // kontrol loop untuk input berulang
    
    while (lanjut == 'y' || lanjut == 'Y') {
        cout << "\n--- Input Array Baru ---" << endl;
        
        // Baca satu baris berisi angka yang dipisahkan spasi, contoh: "5 4 3 2 1"
        cout << "Masukkan elemen array (pisahkan dengan spasi): ";
        string input;
        getline(cin, input);
        
        // Parsing string input menjadi angka-angka menggunakan stringstream
        // - stringstream adalah "aliran" (stream) yang membaca dari string
        // - Operator >> pada stringstream secara otomatis memisahkan token
        //   berdasarkan whitespace (spasi, tab, newline) dan mencoba mengubahnya
        //   ke tipe data yang diminta (di sini: int)
        // - Setiap keberhasilan pembacaan akan menggeser posisi pembacaan di dalam string
        //   ke depan, sehingga loop dapat mengambil angka berikutnya hingga habis
        vector<int> array;      // menampung semua angka hasil parsing
        stringstream ss(input); // sumber data parsing adalah string "input"
        int num;                // variabel sementara untuk menampung angka yang terbaca
        
        // Selama masih ada token angka yang bisa dibaca, push ke vector
        // Jika ada token non-angka, ss >> num akan gagal dan loop berhenti
        while (ss >> num) {
            array.push_back(num);
        }
        
        // Validasi: wajib ada setidaknya satu angka
        if (array.empty()) {
            cout << "Array kosong! Masukkan setidaknya satu elemen." << endl;
            continue; // kembali ke awal loop untuk mencoba lagi
        }
        
        // Tampilkan sebelum dan sesudah diurutkan
        tampilkanArray(array, "Array sebelum diurutkan: ");
        bubbleSort(array);
        tampilkanArray(array, "Array setelah diurutkan: ");
        
        // Tanyakan apakah ingin mengulang; ignore newline supaya getline selanjutnya aman
        cout << "\nApakah ingin mengurutkan array lain? (y/n): ";
        cin >> lanjut;
        cin.ignore(); // buang satu karakter newline yang tersisa dari input 'lanjut'
    }
    
    cout << "\nTerima kasih telah menggunakan program!" << endl;
    return 0;
}