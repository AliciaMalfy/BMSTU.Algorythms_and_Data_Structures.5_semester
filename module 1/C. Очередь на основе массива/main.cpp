#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Queue {
private:
    int capacity{};
    //bool set_size_exist = true;
    //int number{};
    //int count = 0;
    int *mas{};

public:
    void set_size(int);

    void push(int);

    void pop();

    void print();

    /*~Queue() {
        delete[] mas;
    }
     */
};

/*
void Queue::set_size(int value) {
    if (set_size_exist) {
        capacity = value;
        mas = new int[capacity];
        set_size_exist = false;
    } else {
        cout << "error" << endl;
    }
}

void Queue::push(int value) {
    number = value;

    if (count == capacity) {
        cout << "overflow" << endl;
    } else {
        mas[count] = number;
        count++;
    }
}

void Queue::pop() {
    if (count == 0) {
        cout << "underflow" << endl;
    } else {
        count--;
        cout << mas[count] << endl;
    }
}

void Queue::print() {
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
 */

int main(int argc, char *argv[]) {
    ifstream input;
    ofstream output;
    Queue que;

    if (argc != 1) {
        cout << "error" << endl;
    } else {
        input.open(argv[1]);
        output.open(argv[2]);
/*
        while () {

        }
        */
    }
}



/*
    string s, command, tf = "1";
    int value, a;

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
 */
