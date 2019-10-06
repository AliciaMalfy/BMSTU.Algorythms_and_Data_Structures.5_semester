#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;



class Queue {
private:
    int capacity{};
    bool set_size_exist = true;
    string number{};
    int count = 0;
    string *mas{};

public:
    void set_size(string);

    void push(string, char);

    void pop();

    void print();
};


void Queue::set_size(string value) {
    if (set_size_exist) {
        capacity = stoi(value);
        mas = new string[capacity];
        set_size_exist = false;
    } else {
        cout << "error" << endl;
    }
}

void Queue::push(string value, char output) {
    string out(output, sizeof(output));
    ofstream file;
    //out.open(output);
    number = value;

    if (count == capacity) {
        file.write("overflow");
        //cout << "overflow" << endl;
    } else {
        mas[count] = value;
        file.write(mas[count], sizeof(mas[]));
        file.write(" ", );
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


int main(int argc, char *argv[]) {
    ifstream input;
    ofstream output;
    Queue que;
    stringstream ss;
    string command, value;
    int a;

    if (argc >= 2) {
        cout << "error" << endl;
    } else {
        input.open(argv[1]);
        output.open(argv[2]);

        while (! input.eof()) {
            string str;
            getline(input, str);
            ss << str;
            ss >> command;
            ss >> value;

            a = definition(command);

            switch (a) {
                case 1: {
                    que.set_size(value);
                    break;
                }
                case 2: {
                    que.pop();
                    break;
                }
                case 3: {
                    que.push(value, *argv[2]);
                    break;
                }
                case 4: {
                    que.print();
                    break;
                }
                default: {
                    break;
                };
            }
            ss.clear();
        }
    }
}
