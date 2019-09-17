#include <iostream>
#include <sstream>
#include <string>
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

	if (count == capacity) {
		cout << "overflow";
	}
	else {
		mas[count] = number;
		count++;
	}
}

void Stack::pop() {
	if (count == 0) {
		cout << "underflow";
	}
	else {
		mas[count] = -1;
		count--;
	}
}

void Stack::print() {
	if (count == 0) {
		cout << "empty";
	}
	else {
		for (int i = 0; i < capacity; i++) {
			if (mas[i] >= -1) {
				cout << mas[i] << " ";
			}
		}
	}
}

int definition(string str) {
	string field = move(str);
	int n = 0;

	if (field == "set_size") {
		n = 1;
	}
	else if (field == "pop") {
		n = 2;
	}
	else if (field == "push") {
		n = 3;
	}
	else if (field == "print") {
		n = 4;
	}

	return n;
}

int main() {
	string s, command;
	int value, a;
	Stack st;
	stringstream ss;

	for (;;) {
		getline(cin, s);

		ss << s;
		ss >> command;
		ss >> value;

		a = definition(command);

		switch (a) {
		case 1: {
			st.set_size(value);
			break;
		}
		case 2: {
			st.pop();
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
			cout << "Error";
		}
		}

		ss.clear();

		system("pause");
	}
}
