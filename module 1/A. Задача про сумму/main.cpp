#include <iostream>
#include <string>
using namespace std;

int main() {

    string number, dop_str;
    long long int sum = 0;

    while ((cin >> number)) {
        for (int i = 0; i <= number.length(); i++) {
            if (((number[i] >= '0') && (number[i] <= '9'))
                || ((number[i] == '-') && ((number[i+1] >= '0')
                && (number[i+1] <= '9')))) {
                dop_str += number[i];
                if (dop_str == "--") {
                    dop_str = "-";
                }
            } else if ((dop_str == "") || (dop_str == "-")) {
                sum += 0;
            } else {
                sum += stoi(dop_str);
                dop_str = "";
            }
        }
    }

    cout << sum;

    return 0;
}
