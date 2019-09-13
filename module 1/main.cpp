#include <iostream>
#include <cstring>
using namespace std;

int main() {

    string number, dop_str;
    int sum = 0;
    string str = ",";

    while ((cin >> number)) {
        for (int i = 0; i <= number.length(); i++) {
            if (((number[i] >= '0') && (number[i] <= '9')) || number[i]=='-') {
                dop_str += number[i];
            } else {
                sum += stoi(dop_str);
                dop_str="";
            }
        }
    }

    cout << sum;

    return 0;
}
