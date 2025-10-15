#include <iostream>
#include <string>

using namespace std;

int main() {

    double result = 0;
    double z = 0;

    for (int tc = 0; tc < 20; tc++) {
        string name, grade;
        double credit;
        cin >> name >> credit >> grade;

        double y = 0;

        if (grade == "A+") {
            y = 4.5;
        }
        else if (grade == "A0") {
            y = 4.0;
        }
        else if (grade == "B+") {
            y = 3.5;
        }
        else if (grade == "B0") {
            y = 3.0;
        }
        else if (grade == "C+") {
            y = 2.5;
        }
        else if (grade == "C0") {
            y = 2.0;
        }
        else if (grade == "D+") {
            y = 1.5;
        }
        else if (grade == "D0") {
            y = 1.0;
        }
        else if (grade == "F") {
            y = 0.0;
        }
        else {
            continue;
        }

        result += credit * y;
        z += credit;
    }

    cout << result/z << endl;
    
    return 0;
}
