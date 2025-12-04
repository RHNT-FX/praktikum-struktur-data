#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum SlotState { EMPTY, OCCUPIED, DELETED };

struct Slot {
    int key = 0;
    string value;
    SlotState state = EMPTY;
};

class HashTableLinearProbing {
private:
    vector<Slot> table;
    int count = 0;

    int hash(int key) const {
        int cap = static_cast<int>(table.size());
        if (cap == 0) return 0;
        int h = key % cap;
        if (h < 0) h += cap;
        return h;
    }

    double loadFactor() const {
        if (table.empty()) return 1.0;
        return static_cast<double>(count) / table.size();
    }

    void rehash() {
        vector<Slot> old = table;
        table.assign(old.size() * 2 + 1, Slot());
        count = 0;
        for (const Slot& s : old) {
            if (s.state == OCCUPIED) {
                insert(s.key, s.value);
            }
        }
    }

public:
    explicit HashTableLinearProbing(int capacity = 7) : table(capacity) {}

    void insert(int key, const string& value) {
        if (loadFactor() > 0.6) {
            rehash();
        }
        int idx = hash(key);
        int cap = static_cast<int>(table.size());
        for (int i = 0; i < cap; ++i) {
            int probe = (idx + i) % cap;
            if (table[probe].state != OCCUPIED || table[probe].key == key) {
                if (table[probe].state != OCCUPIED) ++count;
                table[probe].key = key;
                table[probe].value = value;
                table[probe].state = OCCUPIED;
                return;
            }
        }
        cout << "Tabel penuh, gagal insert key " << key << '\n';
    }

    string* find(int key) {
        int idx = hash(key);
        int cap = static_cast<int>(table.size());
        for (int i = 0; i < cap; ++i) {
            int probe = (idx + i) % cap;
            if (table[probe].state == EMPTY) break;
            if (table[probe].state == OCCUPIED && table[probe].key == key) {
                return &table[probe].value;
            }
        }
        return nullptr;
    }

    bool erase(int key) {
        int idx = hash(key);
        int cap = static_cast<int>(table.size());
        for (int i = 0; i < cap; ++i) {
            int probe = (idx + i) % cap;
            if (table[probe].state == EMPTY) break;
            if (table[probe].state == OCCUPIED && table[probe].key == key) {
                table[probe].state = DELETED;
                --count;
                return true;
            }
        }
        return false;
    }

    void print() const {
        cout << "Hash table (linear probing):\n";
        for (size_t i = 0; i < table.size(); ++i) {
            cout << "  [" << i << "]: ";
            if (table[i].state == OCCUPIED) {
                cout << table[i].key << ":" << table[i].value;
            } else if (table[i].state == DELETED) {
                cout << "<deleted>";
            } else {
                cout << "(empty)";
            }
            cout << '\n';
        }
    }
};

int main() {
    cout << "=== Hash Table: Linear Probing ===\n";
    HashTableLinearProbing ht(5);

    ht.insert(10, "ten");
    ht.insert(15, "fifteen"); // collision -> probing
    ht.insert(7, "seven");
    ht.insert(22, "twenty-two"); // collision -> probing
    ht.insert(32, "thirty-two");

    ht.print();

    if (string* val = ht.find(22)) {
        cout << "\nfind(22) -> " << *val << '\n';
    }

    cout << "\nHapus key 15.\n";
    ht.erase(15);
    ht.print();

    cout << "\nTambah key 40 (rehash jika load factor tinggi).\n";
    ht.insert(40, "forty");
    ht.print();

    return 0;
}



