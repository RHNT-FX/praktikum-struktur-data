#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Stack char sederhana berbasis vector
class CharStack {
private:
    vector<char> data;

public:
    void push(char c) { 
        data.push_back(c); 
    }

    void pop() { 
        if (!data.empty()) data.pop_back(); 
    }

    char top() const { 
        return data.back(); 
    }

    bool empty() const { 
        return data.empty(); 
    }
};

// Cek keseimbangan tanda kurung (), {}, []
// Algoritma:
// - Baca string dari kiri ke kanan.
// - Jika ketemu pembuka '(', '{', '[' -> push ke stack.
// - Jika ketemu penutup ')', '}', ']' ->
//   * Stack tidak boleh kosong (kalau kosong -> tidak seimbang).
//   * Pop satu dari stack, pastikan pasangannya cocok:
//       ')' berpasangan dengan '(', '}' dengan '{', ']' dengan '['.
//   * Jika tidak cocok -> tidak seimbang.
// - Setelah selesai, stack harus kosong (semua pembuka sudah punya penutup).
// - Jika masih ada sisa di stack -> tidak seimbang.
bool isMatching(const string& s) {
    CharStack st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') st.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) return false;
            char t = st.top(); 
            st.pop();

            if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

// Balik string menggunakan stack
string reverseString(const string& s) {
    CharStack st;
    for (char c : s) st.push(c);
    string out;
    out.reserve(s.size()); //optimisasi agar tidak terjadi realokasi memori

    while (!st.empty()) { 
        out.push_back(st.top()); 
        st.pop(); 
    }

    return out;
}

int main() {
    cout << "=== Stack Applications ===\n";
    string a = "(a+[b*c]-{d/e})";
    string b = "(a+[b*c}-{d/e})";
    cout << a << " -> balanced? " << (isMatching(a) ? "yes" : "no") << '\n';
    cout << b << " -> balanced? " << (isMatching(b) ? "yes" : "no") << '\n';

    string s = "stack";
    cout << "reverse '" << s << "' -> '" << reverseString(s) << "'\n";

    return 0;
}
