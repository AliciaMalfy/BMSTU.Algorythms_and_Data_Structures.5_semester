#include <iostream>
#include <sstream>
#include <string>
#include <array>
using namespace std;

class Stack {
private:
    int capacity{};
    int number{};
    int count = 0;
    int *mas{};

public:
    void set_size(int);

    void push(int);

    void pop();

    void print();

    ~Stack() {
        delete[] mas;
    }
};

void Stack::set_size(int value) {
    capacity = value;
    mas = new int[capacity];
}

void Stack::push(int value) {
    number = value;

    if (count == capacity) {
        cout << "overflow" << endl;
    } else {
        mas[count] = number;
        count++;
    }
}

void Stack::pop() {
    if (count == 0) {
        cout << "underflow" << endl;
    } else {
        count--;
        cout << mas[count] << endl;
    }
}

void Stack::print() {
    if (count == 0) {
        cout << "empty" << endl;
    } else {
        for (int i = 0; i < count; i++) {
            if (i < count - 1) {
                cout << mas[i] << " ";
            } else {
                cout << mas[i];
            }
        }
        cout << endl;
    }
}

int definition(string str) {
    string field = move(str);
    int n = 0;

    if (field == "set_size") {
        n = 1;
    } else if (field == "pop") {
        n = 2;
    } else if (field == "push") {
        n = 3;
    } else if (field == "print") {
        n = 4;
    }

    return n;
}

int main() {
    string s, command, tf = "1";
    int value, a;
    Stack st;
    stringstream ss;

    while (getline(cin, s)) {
        if (s.empty()) {
            continue;
        }

        ss << s;
        ss >> command;
        ss >> value;
        ss >> tf;

        if (tf == "1") {
            a = definition(command);

            switch (a) {
                case 1: {
                    st.set_size(value);
                    break;
                }
                case 2: {
                    if (value == 1) {
                        cout << "error" << endl;
                    } else {
                        st.pop();
                    }
                    break;
                }
                case 3: {
                    st.push(value);
                    break;
                }
                case 4: {
                    st.print();
                    break;
                }
                default: {
                    cin.ignore();
                    break;
                };
            }
        }

        if (tf != "1") {
            cout << "error" << endl;
            tf = "1";
        }
        ss.clear();
    }
}
