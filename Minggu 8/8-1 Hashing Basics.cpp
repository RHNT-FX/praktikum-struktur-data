#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Fungsi hash sederhana untuk integer: h(x) = x % kapasitas
int hashInt(int key, int kapasitas) {
    if (kapasitas == 0) return 0;
    int h = key % kapasitas;
    if (h < 0) h += kapasitas;
    return h;
}

// Fungsi hash sederhana untuk string: jumlah ASCII % kapasitas
int hashString(const string& key, int kapasitas) {
    if (kapasitas == 0) return 0;
    long long sum = 0;
    for (char c : key) sum += static_cast<unsigned char>(c);
    return static_cast<int>(sum % kapasitas);
}

int main() {
    cout << "=== Hashing Basics ===\n\n";

    int kapasitas = 10;

    cout << "Hash integer (kapasitas " << kapasitas << "):\n";
    vector<int> ints = {15, 26, 37, -4, 123};
    for (int x : ints) {
        cout << "  key " << x << " -> slot " << hashInt(x, kapasitas) << '\n';
    }

    cout << "\nHash string (kapasitas " << kapasitas << "):\n";
    vector<string> names = {"alice", "bob", "carol", "dave"};
    for (const string& s : names) {
        cout << "  key \"" << s << "\" -> slot " << hashString(s, kapasitas) << '\n';
    }

    return 0;
}

// Catatan:
    // - Fungsi hash harus cepat, deterministik, dan menyebar merata.
    // - Collision terjadi saat dua key berbeda jatuh ke slot sama.
    // - Penanganan collision dibahas di file berikutnya.
