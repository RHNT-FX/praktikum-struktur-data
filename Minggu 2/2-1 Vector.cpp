#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "=== std::vector - Dasar dan Penggunaan ===" << endl;

    // Deklarasi dan Inisialisasi
    vector<int> v1;                    // kosong
    vector<int> v2 = {1, 2, 3};        // dari initializer list
    vector<int> v3(5, 10);             // ukuran 5, semua elemen bernilai 10

    // Menampilkan nilai pada vector
    cout << "v2: ";
    for (int x : v2) cout << x << ' '; cout << endl;
    cout << "v3 (size=" << v3.size() << "): ";

    // Menampilkan nilai pada vector menggunakan for loop

    // Cara Standar.
    for (int i = 0; i < v3.size(); ++i) {
        cout << v3[i] << ' ';
    }
    cout << endl;
    
    // Cara Alternatif
    for (int x : v3) {
        cout << x << ' '; 
    } 
    cout << endl << endl;

    // Menambah dan Menghapus Elemen
    cout << "=== push_back, pop_back, emplace_back ===" << endl;
    v1.push_back(5); // Menambahkan nilai pada vector yang masih kosong
    v1.push_back(7); // Menambahkan nilai pada vector yang ada di bagian paling belakang
    v1.emplace_back(9); // Menambahkan nilai pada vector yang ada di bagian paling belakang
    cout << "v1: "; for (int x : v1) cout << x << ' '; cout << endl;

    v1.pop_back(); // Menghapus nilai pada vector yang ada di bagian paling belakang
    cout << "v1 setelah pop_back: "; for (int x : v1) cout << x << ' '; cout << endl << endl;

    // Akses Elemen
    cout << "=== Akses Elemen ===" << endl;
    cout << "front: " << v2.front() << endl; // Menampilkan nilai pada vector yang ada di bagian paling depan
    cout << "back: " << v2.back() << endl; // Menampilkan nilai pada vector yang ada di bagian paling belakang
    cout << "v2[1] (tanpa cek): " << v2[1] << endl;        // Menampilkan nilai dengan tidak melakukan pengecekan batas
    cout << "v2.at(1) (cek batas): " << v2.at(1) << endl;  // Menampilkan nilai dengan melakukan pengecekan batas dan jika di luar batas akan menampilkan error
    // Errornya adalah std::out_of_range
    cout << endl;

    // Ukuran dan Kapasitas
    cout << "=== Size, Capacity, Reserve, Resize ===" << endl;
    vector<int> cap;
    cout << "size: " << cap.size() << ", capacity: " << cap.capacity() << endl;
    cap.reserve(10); // set kapasitas minimal 10 (tidak mengubah size)
    cout << "setelah reserve(10) -> size: " << cap.size() << ", capacity: " << cap.capacity() << endl;
    cap.resize(5, 1); // ubah ukuran menjadi 5, isi elemen baru dengan 1
    cout << "setelah resize(5,1) -> size: " << cap.size() << ", capacity: " << cap.capacity() << "; isi: ";
    for (int x : cap) cout << x << ' '; cout << endl << endl;

    // Insert, Erase, Clear
    cout << "=== Insert, Erase, Clear ===" << endl;
    vector<int> e = {10, 20, 30};
    cout << "e: "; for (int x : e) cout << x << ' '; cout << endl;

    e.insert(e.begin() + 1, 15);           // sisip di index 1
    e.insert(e.end(), 2, 40);              // tambahkan 40 sebanyak 2 kali di akhir
    cout << "e setelah insert: "; for (int x : e) cout << x << ' '; cout << endl;

    e.erase(e.begin() + 2);                // hapus elemen index 2
    cout << "e setelah erase idx 2: "; for (int x : e) cout << x << ' '; cout << endl;
    
    e.clear();                              // kosongkan semua elemen
    cout << "e kosong? " << (e.empty() ? "ya" : "tidak") << endl << endl;

    // Find manual, remove manual
    cout << "=== find, remove ===" << endl;
    vector<int> a = {4, 1, 5, 2, 3, 2};

    // Find manual nilai 5
    bool found = false; int idx = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 5) { 
            found = true; idx = i; 
            break; 
        }
    }
    cout << "find 5 -> " << (found ? "ketemu di index " : "tidak ketemu") << (found ? to_string(idx) : "") << endl;

    // Remove semua nilai 2 (in-place: tulis ke depan nilai yang bukan 2, lalu resize)
    int write = 0;
    for (int read = 0; read < a.size(); ++read) {
        if (a[read] != 2) {
            a[write++] = a[read];
        }
    }
    a.resize(write);
    cout << "remove semua 2: "; for (int x : a) cout << x << ' '; cout << endl << endl;

    // assign, swap
    cout << "=== assign, swap ===" << endl;
    vector<int> b;
    b.assign(3, 7); // isi vektor dengan 3 elemen bernilai 7
    cout << "b: "; for (int x : b) cout << x << ' '; cout << endl;
    swap(a, b);
    cout << "a setelah swap: "; for (int x : a) cout << x << ' '; cout << endl;
    cout << "b setelah swap: "; for (int x : b) cout << x << ' '; cout << endl << endl;

    // Vector of vector (2D)
    cout << "=== vector<vector<int>> (2D) ===" << endl;
    //vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}}; // Cara Tradisional
    vector<vector<int>> grid(2, vector<int>(3, 0)); // 2 baris, 3 kolom, isi 0 (Cara Menggunakan Constructor Vector)
    grid[0][1] = 5;
    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[r].size(); c++) {
            cout << grid[r][c] << (c + 1 < grid[r].size() ? ' ' : '\n');
        }
    }

    // Tips: vector mengelola memori sendiri (dinamis) dan cocok untuk ukuran yang berubah-ubah.
    // Hindari mengakses di luar batas; gunakan at() jika butuh pengecekan. alasannya karena jika di luar batas akan menampilkan error std::out_of_range

    return 0;
}
