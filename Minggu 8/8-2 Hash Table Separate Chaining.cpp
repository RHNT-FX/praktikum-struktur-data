#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Entry {
    int key;
    string value;
    Entry(int k, const string& v) : key(k), value(v) {}
};

class HashTableChaining {
private:
    vector<vector<Entry>> buckets;

    int hash(int key) const {
        int cap = static_cast<int>(buckets.size());
        if (cap == 0) return 0;
        int h = key % cap;
        if (h < 0) h += cap;
        return h;
    }

public:
    explicit HashTableChaining(int capacity) : buckets(capacity) {}

    void insert(int key, const string& value) {
        int idx = hash(key);
        for (Entry& e : buckets[idx]) {
            if (e.key == key) {
                e.value = value; // update jika key sudah ada
                return;
            }
        }
        buckets[idx].push_back(Entry(key, value));
    }

    bool erase(int key) {
        int idx = hash(key);
        auto& chain = buckets[idx];
        for (size_t i = 0; i < chain.size(); ++i) {
            if (chain[i].key == key) {
                chain.erase(chain.begin() + static_cast<long long>(i));
                return true;
            }
        }
        return false;
    }

    string* find(int key) {
        int idx = hash(key);
        for (Entry& e : buckets[idx]) {
            if (e.key == key) return &e.value;
        }
        return nullptr;
    }

    void print() const {
        cout << "Hash table (separate chaining):\n";
        for (size_t i = 0; i < buckets.size(); ++i) {
            cout << "  [" << i << "]: ";
            if (buckets[i].empty()) {
                cout << "(empty)";
            } else {
                for (size_t j = 0; j < buckets[i].size(); ++j) {
                    cout << buckets[i][j].key << ":" << buckets[i][j].value;
                    if (j + 1 < buckets[i].size()) cout << " -> ";
                }
            }
            cout << '\n';
        }
    }
};

int main() {
    cout << "=== Hash Table: Separate Chaining ===\n";
    HashTableChaining ht(5);

    ht.insert(10, "ten");
    ht.insert(15, "fifteen"); // collision dengan 10 (15 % 5 == 0)
    ht.insert(7, "seven");
    ht.insert(12, "twelve");
    ht.insert(22, "twenty-two"); // collision dengan 7 (22 % 5 == 2)

    ht.print();

    if (string* val = ht.find(15)) {
        cout << "\nfind(15) -> " << *val << '\n';
    }

    cout << "\nHapus key 7.\n";
    ht.erase(7);
    ht.print();

    return 0;
}



