#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int R;
        string word;

        cin >> R >> word;

        for (int i = 0; i < (int)word.size(); i++) {
            for (int j = 0; j < R; j++) {
                cout << word[i];
            }
        }
        cout << endl;


    }
    
    return 0;
  }

