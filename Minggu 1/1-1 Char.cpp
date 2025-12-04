#include <iostream>

using namespace std;

int main() {

    // Cara Inisiasi Variabel Char
    // Size dari Char adalah 1 byte
    cout << "=== Dasar Char ===" << std::endl;
    char letter = 'A';
    char digitChar = '7';
    char symbol = '#';

    // Print Kode ASCII dari Karakter Char
    // Standar pengodean karakter yang memberikan nilai numerik pada huruf, angka, simbol, dan karakter kontrol lainnya
    // Sehingga komputer dan perangkat lain dapat bertukar dan menginterpretasikan data teks
    cout << "huruf: " << letter << ", ASCII: " << static_cast<int>(letter) << std::endl;
    cout << "digitChar: " << digitChar << ", ASCII: " << static_cast<int>(digitChar) << std::endl;
    cout << "simbol: " << symbol << ", ASCII: " << static_cast<int>(symbol) << std::endl;

    // Konversi Huruf Kapital ke Huruf Kecil dan Sebaliknya pada Char
    cout << "\n=== Konversi Huruf (dasar) ===" << std::endl;
    char lower = 'm';
    char upper = 'Q';
    char toUpper = (lower >= 'a' && lower <= 'z') ? static_cast<char>(lower - ('a' - 'A')) : lower;
    char toLower = (upper >= 'A' && upper <= 'Z') ? static_cast<char>(upper + ('a' - 'A')) : upper;
    cout << lower << " -> ke huruf besar -> " << toUpper << std::endl;
    cout << upper << " -> ke huruf kecil -> " << toLower << std::endl;

    // Operasi ASCII pada Char
    // Bisa melakukan operasi aritmatika pada nilai ASCII dari Char
    cout << "\n=== Aritmatika Char (ASCII) ===" << std::endl;
    char nextLetter = letter + 1; // 'B'
    cout << "'" << letter << "' + 1 -> '" << nextLetter << "' (ASCII: " << static_cast<int>(nextLetter) << ")" << std::endl;

    return 0;
}
