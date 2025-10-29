#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int k;
    for (int i = 0; i < 3; i++)
    {
        cin >> s;
        if (s != "Fizz" && s != "Buzz" && s != "FizzBuzz")
            k = (3 - i) + stoi(s);
    }
    if (k % 3 == 0 && k % 5 == 0)
        cout << "FizzBuzz";
    else if (k % 3 == 0)
        cout << "Fizz";
    else if (k % 5 == 0)
        cout << "Buzz";
    else
        cout << k;
    return 0;
}