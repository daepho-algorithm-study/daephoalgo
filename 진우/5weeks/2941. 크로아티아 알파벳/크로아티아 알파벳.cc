#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    cin >> word;

    int count = 0;
    for (int i = 0; i < (int)word.size(); i++) {
        // "dz=" 확인 (3글자)
        if (i + 2 < word.size() && word.substr(i, 3) == "dz=") {
            count++;
            i += 2;
        }
        // 나머지 2글자 조합 확인
        else if (i + 1 < word.size()) {
            string two = word.substr(i, 2);
            if (two == "c=" || two == "c-" || two == "d-" ||
                two == "lj" || two == "nj" || two == "s=" || two == "z=") {
                count++;
                i++;
                continue;
            }
            count++;
        } 
        else {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
