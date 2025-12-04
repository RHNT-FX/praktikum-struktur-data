#include <iostream>

using namespace std;

int main() {
    cout << "=== Dasar string ===" << endl;

    // Deklarasi dan inisiasi string
    string s1;                        // Inisiasi string kosong
    string s2 = "hello";              // Inisiasi string dan nilainya
    string s3("world");              // Cara alternatif untuk inisiasi string
    string s4(3, '!');                // Inisiasi string dengan karakter yang sama sebanyak 3 kali output: !!!
    string s5 = s2 + " " + s3 + s4;   // Penggabungan string

    // Menampilkan nilai string
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5 (gabungan): " << s5 << endl;

    // Fungsi - fungsi pada string
    cout << "\n=== Akses dan Ubah ===" << endl;
    cout << "panjang: " << s5.size() << endl; // Menampilkan jumlah karakter pada string
    cout << "kosong? " << (s1.empty() ? "ya" : "tidak") << endl; // Menampilkan apakah string kosong
    cout << "awal (front): " << s5.front() << endl; // Menampilkan karakter pertama pada string
    cout << "akhir (back): " << s5.back() << endl; // Menampilkan karakter terakhir pada string
    s5[0] = 'H';                     // Merubah nilai pada string menggunakan index seperti array
    s5.at(6) = 'W';                  // Merubah nilai pada string menggunakan fungsi at()
    cout << "setelah diubah: " << s5 << endl; // Menampilkan string setelah diubah

    cout << "\n=== Tambah (append), Sisip (insert), Hapus (erase), Ganti (replace) ===" << endl;
    string name = "Alice";
    name.append(" Bob");             // Menambahkan nilai pada string pada bagian paling belakang menggunakan fungsi
    name += " Charlie";               // Menambahkan nilai pada string pada bagian paling belakang menggunakan operator
    name.insert(0, "Names: ");       // Menambahkan nilai pada string pada index tertentu
    name.erase(6, 1);                 // Menghapus 1 karakter pada index 6
    name.replace(6, 0, ": ");        // Menambahkan nilai pada string pada index 6
    cout << name << endl; // Menampilkan string setelah diubah

    cout << "\n=== Cari (find) dan Potong (substr) ===" << endl;
    string text = "bananas";
    auto pos = text.find("ana");      // Mencari nilai pada string, jika ditemukan maka akan menampilkan index dari nilai yang ditemukan tetapi hanya yang pertama kali yang ditemukan
    cout << "find 'ana' -> index: " << pos << endl;
    auto rpos = text.rfind('a');       // Mencari nilai pada string, jika ditemukan maka akan menampilkan index dari nilai yang ditemukan tetapi hanya yang terakhir yang ditemukan
    cout << "rfind 'a' -> index: " << rpos << endl;
    cout << "substr(1, 3): " << text.substr(1, 3) << endl; // Menampilkan substring dari string, index dimulai dari 1 dan jumlah karakter yang akan ditampilkan adalah 3

    cout << "\n=== Bandingkan (compare) ===" << endl;
    cout << std::boolalpha;
    cout << (string("abc") == string("abc")) << endl; // Mengecek apakah string sama
    cout << (string("Abc") < string("abc")) << endl; // Disini hasil menjadi true karena membandingkan nilai ASCII dari karakter pertama (A = 65 dan a = 97)

    cout << "\n=== Konversi (conversion) ===" << endl;
    string numStr = "12345";
    int value = std::stoi(numStr); // Mengubah string menjadi integer
    cout << "stoi('12345') -> angka: " << value << endl;
    string fromNum = std::to_string(6789); // Mengubah integer menjadi string
    cout << "to_string(6789) -> string: " << fromNum << endl;

    // Membaca nilai pada string menggunakan for loop seperti array
    // Cara Standar
    for (int i = 0; i < s3.size(); ++i) { 
        cout << s3[i] << ' '; 
    } 
    cout << endl;
    
    // Cara Alternatif
    cout << "\n=== Iterasi (looping) ===" << endl;
    for (char ch : s2) { 
        cout << ch << ' '; 
    } 
    cout << endl;

    return 0;
}
