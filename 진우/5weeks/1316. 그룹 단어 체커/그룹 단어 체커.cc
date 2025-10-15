#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string word;
    cin >> N;
    int result = N;

    for (int tc = 0; tc < N; tc++) {
        cin >> word;

        int len = word.size();

        for (int i = 0; i < len - 1; i++) {
            if (word[i] == word[i + 1]) {
                continue;
            }
            if (word.find(word[i], i + 1) != string::npos) {
                result--;
                break;
            }
        }
    }
    cout << result << endl;
    
    return 0;
}
