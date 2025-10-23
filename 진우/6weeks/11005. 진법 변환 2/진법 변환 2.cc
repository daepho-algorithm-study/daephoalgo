#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, B;
    cin >> N >> B;

    string result = "";

    while (N > 0) {
       char num;
       if (10 <= N % B) { 
           num = (N % B) + 55;
       }
       else {
           num = (N % B) + '0';
       }       
       result += num;
       
       N /= B;
    }

    reverse(result.begin(), result.end());
    
    cout << result << "\n";

    return 0;
}
