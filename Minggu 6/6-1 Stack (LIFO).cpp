#include <iostream>
#include <vector>

using namespace std;

// Implementasi Stack (LIFO) sederhana berbasis vector
class Stack {
private:
    vector<int> data; // elemen paling akhir adalah TOP

public:
    void push(int value) { 
        data.push_back(value); 
    }

    void pop() { 
        if (!data.empty()) data.pop_back(); 
    }

    int top() const { 
        return data.back(); 
    }

    bool empty() const { 
        return data.empty(); 
    }

    int size() const { 
        return static_cast<int>(data.size()); 
    }
};

int main() {
    cout << "=== Stack (LIFO) ===\n";

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "size: " << st.size() << " top: " << st.top() << '\n';
    st.pop();
    cout << "after pop -> size: " << st.size() << " top: " << st.top() << '\n';

    while (!st.empty()) { 
        cout << st.top() << (st.size()>1?' ':'\n'); 
        st.pop(); 
    }

    return 0;
}
