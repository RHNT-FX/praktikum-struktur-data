#include <iostream>

using namespace std;

int main() {
    cout << "=== Dasar Array ===" << endl;
    int a[5]; // Deklarasi Array dengan ukuran yang sudah ditentukan
    int b[5] = {1, 2, 3, 4, 5}; // Deklarasi Array dengan ukuran yang sudah ditentukan dan inisialisasi dengan nilai yang sudah ditentukan
    int c[5] = {10, 20}; // Inisialisasi Parsial, elemen yang tidak diisi dianggap 0
    int d[] = {7, 8, 9}; // Size dapat dideklarasikan dari list inisialisasi
    // Beda dengan syntax dibawah, karena tidak ada ukuran yang ditentukan dan tidak ada nilai yang diberikan maka akan menjadi error
    // int d[];

    // Memasukkan nilai pada array menggunakan index
    a[0] = 42;
    a[1] = 11;
    a[2] = -3;
    a[3] = 0;
    a[4] = 5;

    // Jika print array secara langsung maka akan menampilkan alamat memory dari array
    cout << "alamat memori array a: " << a << endl;

    // Cara - cara membaca nilai pada array menggunakan for loop

    // Cara Standar
    cout << "a: ";
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << (i < 4 ? ' ' : '\n');
    }

    // Cara Alternatif
    cout << "b: ";
    for (int i : b) {
        cout << i << ' ';
    }
    cout << endl << endl;

    // Catatan: untuk array yang dinamis gunakan std::vector atau std::string
    return 0;
}
