#include <iostream>
using namespace std;

class Stack {
private:
    int capacity;
    int number;
    int count = 0;
    int *mas;

public:
    void set_size(int);

    void push(int);

    void pop();

    void print();
};

void Stack::set_size(int value) {
    capacity = value;
    mas = new int[capacity];

    for (int i = 0; i < capacity; i++) {
        mas[i] = -1;
    }
}

void Stack::push(int value) {
    number = value;
    mas[count] = number;
    count++;
}

void Stack::pop() {
    mas[count] = NULL;
    count--;
}

void Stack::print() {
    for (int i = 0; i < capacity; i++) {
        cout << mas[i] << " ";
    }
}

int definition(string str) {
    int n;

    if (str == "set_size") {
        n = 1;
    } else if (str == "pop") {
        n = 2;
    } else if (str == "push") {
        n = 3;
    } else if (str == "print") {
        n = 4;
    }

    return n;
}

int main() {
    string s;
    string command, str_value;
    int value, n = 0;
    Stack st;

    for (;;) {
        cin >> s;

        for (int i = 0; i <= s.length(); i++) {
            while (s[i] != ' ') {
                command += s[i];
            }
            if ((s[i] >= '0') && (s[i] <= '9')) {
                str_value += s[i];
            } else {
                value = stoi(str_value);
            }
        }

        cout << s << " " << command << " " << value;

        definition(command);

        switch (n) {
            case 1: {
                st.set_size(value);
                break;
            }
            case 2: {
                st.pop();
            }
            case 3: {
                st.push(value);
            }
            case 4: {
                st.print();
                break;
            }
            default: {
                cout << "Error";
            }
        }
    }
}
