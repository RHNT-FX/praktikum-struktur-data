#include <iostream>
#include <vector>

using namespace std;

// === PENJELASAN MENGAPA MAIN() BERUBAH DARI VOID KE INT ===
// 1. Standar C++ mengharuskan main() mengembalikan int
// 2. Return value menunjukkan status program: 0 = sukses, non-zero = error
// 3. void main() tidak standar dan bisa menyebabkan masalah kompatibilitas

// === PENJELASAN PARAMETER FUNGSI: PASS-BY-VALUE vs PASS-BY-REFERENCE ===

// Fungsi dengan pass-by-value (tanpa &)
// - Membuat salinan data asli
// - Perubahan di dalam fungsi TIDAK mempengaruhi data asli
// - Lebih aman tapi bisa lambat untuk data besar
int fungsiPassByValue(int x, vector<int> arr) {
    cout << "=== Pass-by-Value ===" << endl;
    cout << "Nilai x di dalam fungsi: " << x << endl;
    cout << "Array di dalam fungsi: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
    
    // Modifikasi di dalam fungsi
    x = 999;
    arr[0] = 999;
    
    cout << "Setelah modifikasi - x: " << x << ", arr[0]: " << arr[0] << endl;
    return x;
}

// Fungsi dengan pass-by-reference (dengan &)
// - Menggunakan alamat memori yang sama dengan data asli
// - Perubahan di dalam fungsi AKAN mempengaruhi data asli
// - Lebih efisien untuk data besar, tapi berbahaya jika tidak hati-hati
int fungsiPassByReference(int& x, vector<int>& arr) {
    cout << "\n=== Pass-by-Reference ===" << endl;
    cout << "Nilai x di dalam fungsi: " << x << endl;
    cout << "Array di dalam fungsi: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
    
    // Modifikasi di dalam fungsi
    x = 888;
    arr[0] = 888;
    
    cout << "Setelah modifikasi - x: " << x << ", arr[0]: " << arr[0] << endl;
    return x;
}

// Fungsi dengan const reference (const &)
// - Menggunakan alamat memori yang sama tapi TIDAK bisa diubah
// - Efisien untuk data besar dan aman (read-only)
void fungsiConstReference(const vector<int>& arr) {
    cout << "\n=== Const Reference (Read-Only) ===" << endl;
    cout << "Array (tidak bisa diubah): ";
    for (int val : arr) cout << val << " ";
    cout << endl;
    
    // arr[0] = 777; // ERROR: tidak bisa mengubah const reference
}

int main() {
    cout << "=== Penjelasan Parameter Fungsi ===" << endl;
    
    // Data untuk testing
    int angka = 100;
    vector<int> data = {1, 2, 3, 4, 5};
    
    cout << "Data awal - angka: " << angka << ", data[0]: " << data[0] << endl;
    
    // Test pass-by-value
    int hasil1 = fungsiPassByValue(angka, data);
    cout << "Setelah pass-by-value - angka: " << angka << ", data[0]: " << data[0] << endl;
    cout << "Return value: " << hasil1 << endl;
    
    // Test pass-by-reference
    int hasil2 = fungsiPassByReference(angka, data);
    cout << "Setelah pass-by-reference - angka: " << angka << ", data[0]: " << data[0] << endl;
    cout << "Return value: " << hasil2 << endl;
    
    // Test const reference
    fungsiConstReference(data);
    
    // === KESIMPULAN ===
    cout << "\n=== KESIMPULAN ===" << endl;
    cout << "1. main() harus int untuk kompatibilitas standar C++" << endl;
    cout << "2. Pass-by-value (&): salinan data, aman, lambat untuk data besar" << endl;
    cout << "3. Pass-by-reference (&): alamat asli, efisien, berbahaya jika tidak hati-hati" << endl;
    cout << "4. Const reference (const &): alamat asli tapi read-only, efisien dan aman" << endl;
    
    return 0; // 0 = program berhasil
}
