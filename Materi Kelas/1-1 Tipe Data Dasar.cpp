#include <iostream>

using namespace std;

int main() {
    cout << "=== Tipe Data Dasar (C++) ===" << endl;

    // Bilangan bulat
    short s = -12;          // 2 byte (umumnya)
    int i = 123;            // 4 byte (umumnya)
    long l = 123456L;       // >= 4 byte
    long long ll = 1234567890123LL; // 8 byte (umumnya)

    // Bilangan pecahan
    float f = 3.14f;        // 4 byte, ~6-7 digit presisi
    double d = 2.718281828; // 8 byte, ~15-16 digit presisi

    // Karakter dan boolean
    char c = 'A';           // 1 byte
    bool b = true;          // true/false

    // Menampilkan nilai
    cout << "short: " << s << endl;
    cout << "int: " << i << endl;
    cout << "long: " << l << endl;
    cout << "long long: " << ll << endl;
    cout << "float: " << f << endl;
    cout << "double: " << d << endl;
    cout << "char: " << c << " (ASCII: " << static_cast<int>(c) << ")" << endl; // static_cast adalah contoh fungsi cast yang berguna untuk mengkonversi tipe data
    cout << boolalpha << "bool: " << b << endl;

    // Konversi tipe (casting)
    cout << "\n=== Konversi (Casting) ===" << endl;
    double toDouble = static_cast<double>(i);
    int toInt = static_cast<int>(f);
    cout << "int -> double: " << toDouble << endl;
    cout << "float -> int: " << toInt << endl;

    // Ukuran memori
    cout << "\n=== sizeof ===" << endl;
    cout << "sizeof(short): " << sizeof(short) << " byte" << endl;
    cout << "sizeof(int): " << sizeof(int) << " byte" << endl;
    cout << "sizeof(long): " << sizeof(long) << " byte" << endl;
    cout << "sizeof(long long): " << sizeof(long long) << " byte" << endl;
    cout << "sizeof(float): " << sizeof(float) << " byte" << endl;
    cout << "sizeof(double): " << sizeof(double) << " byte" << endl;
    cout << "sizeof(char): " << sizeof(char) << " byte" << endl;
    cout << "sizeof(bool): " << sizeof(bool) << " byte" << endl;

    return 0;
}
