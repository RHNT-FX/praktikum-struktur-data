#include <iostream>

// File ini menjelaskan tentang "using namespace std;"
// Standar library C++ berada di dalam namespace bernama std.
// Ada 3 cara umum untuk mengaksesnya:
// 1) Menulis nama lengkap (qualified name): std::cout, std::endl, std::string, dll.
// 2) Menggunakan using declaration (spesifik simbol): using std::cout; using std::endl;
// 3) Menggunakan using directive (semua simbol): using namespace std;

int main() {
    // === 1) Tanpa using: menggunakan qualified name ===
    std::cout << "[Qualified] Halo memakai std::cout" << std::endl;

    // === 2) Using declaration: hanya ambil simbol yang dibutuhkan ===
    using std::cout;   // hanya cout
    using std::endl;   // hanya endl
    cout << "[Using declaration] Halo memakai cout dan endl" << endl;

    // === 3) Using directive: ambil semua dari std ===
    using namespace std; // memudahkan untuk pemula, tapi bisa menimbulkan konflik nama pada proyek besar
    string nama = "Alice"; // langsung pakai string tanpa std::
    cout << "[Using directive] Nama: " << nama << endl;

    // Catatan penting:
    // - Untuk pemula dan tugas kecil, using namespace std; sering dipakai agar kode lebih ringkas.
    // - Untuk proyek besar/serius, lebih disarankan:
    //   a) Tetap memakai std:: secara eksplisit, atau
    //   b) Gunakan using declaration hanya untuk simbol yang dibutuhkan.

    // --- Contoh masalah pada proyek besar ---
    // 1) Tabarakan nama fungsi
    //    Misal ada fungsi distance() milik proyek:
    //    namespace geometry { double distance(Point a, Point b); }
    //    Dengan "using namespace std;" dan juga memanggil distance(v.begin(), v.end()),
    //    kompiler bisa bingung memilih antara std::distance dan geometry::distance
    //    (terutama jika ADL ikut bermain). Tanpa using directive, Anda tulis jelas std::distance(...).

    // 2) Konflik begin/end ADL
    //    Beberapa tipe custom mendefinisikan begin(obj)/end(obj) agar bisa dipakai di range-based for.
    //    Dengan "using namespace std;", panggilan begin(obj) dapat menjadi ambigu antara std::begin
    //    dan begin milik namespace lain. Menulis std::begin(obj) menghindari ambiguitas.

    // 3) Nama umum seperti count, size, swap
    //    Proyek besar sering punya utilitas bernama count/size/swap.
    //    "using namespace std;" bisa membuat panggilan swap(x,y) memilih std::swap yang kurang tepat
    //    untuk tipe custom (bukan specialized swap Anda). Lebih aman panggil ::swap atau ns::swap.

    // 4) Literals dan chrono
    //    Jika membawa banyak namespace sekaligus, literal atau nama seperti duration, count, time_point
    //    dapat bentrok/ambigu. Menulis std::chrono::duration, std::chrono::milliseconds, dsb, lebih jelas.

    return 0;
}
