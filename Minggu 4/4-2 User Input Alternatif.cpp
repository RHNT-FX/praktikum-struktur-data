#include <iostream>
#include <vector>

using namespace std;

// Mengurutkan vector secara ascending dengan Bubble Sort (in-place)
void bubbleSort(vector<int>& array) {
    int n = static_cast<int>(array.size());
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

// Mencetak isi vector dalam satu baris dengan pesan pembuka
void tampilkanArray(const vector<int>& array, const char* pesan) {
    cout << pesan;
    for (int i = 0; i < static_cast<int>(array.size()); ++i) {
        cout << array[i];
        if (i + 1 < static_cast<int>(array.size())) cout << ' ';
    }
    cout << '\n';
}

int main() {
    cout << "=== Program Bubble Sort (Alternatif Input) ===\n";

    char lanjut = 'y';
    while (lanjut == 'y' || lanjut == 'Y') {
        cout << "\n--- Input Array Baru ---\n";
        cout << "Masukkan elemen array (pisahkan dengan spasi), akhiri dengan Enter:\n";

        vector<int> array;

        // Strategi tanpa <string> / <sstream>:
        // - Baca integer berulang kali dengan operator>> (melewati spasi otomatis)
        // - Setelah setiap pembacaan angka, cek karakter berikutnya:
        //   - Lewati spasi berturut-turut
        //   - Jika ketemu '\n' (newline), berhenti
        //   - Jika bukan '\n', lanjut baca angka berikutnya
        // Catatan: gunakan cin.peek() untuk melihat karakter berikutnya tanpa mengkonsumsi,
        //          dan cin.get() untuk mengkonsumsi satu karakter.
        while (true) {
            int value;

            // Coba baca satu integer; jika gagal (misal user langsung Enter), keluar dari loop input baris
            if (!(cin >> value)) {
                // Bersihkan state error dan buang sisa baris agar loop berikutnya tetap bersih
                cin.clear();
                // Buang sampai newline
                int ch;
                while ((ch = cin.get()) != '\n' && ch != EOF) {}
                break;
            }

            array.push_back(value);

            // Lewati spasi setelah angka
            while (cin.peek() == ' ' || cin.peek() == '\t') {
                cin.get();
            }

            // Jika next char adalah newline, konsumsi dan hentikan input baris ini
            if (cin.peek() == '\n') {
                cin.get();
                break;
            }

            // Jika bukan newline (misal ada angka lagi), loop lanjut dan operator>> akan skip spasi
        }

        if (array.empty()) {
            cout << "Input kosong. Silakan masukkan setidaknya satu angka." << '\n';
            continue;
        }

        tampilkanArray(array, "Array sebelum diurutkan: ");
        bubbleSort(array);
        tampilkanArray(array, "Array setelah diurutkan: ");

        cout << "\nApakah ingin mengurutkan array lain? (y/n): ";
        cin >> lanjut;
        // Buang satu newline agar pembacaan berikutnya bersih
        if (cin.peek() == '\n') cin.get();
    }

    cout << "\nTerima kasih!" << '\n';
    return 0;
}
