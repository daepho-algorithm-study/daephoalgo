#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    double a, b, c;
    cin >> n;
    cout.precision(3);
    cout << fixed;
    while (n--)
    {
        // b^2 - 4ac 값 저장 변수
        double root;
        cin >> a >> b >> c;
        // b^2 - 4ac 값 저장
        root = sqrt(b * b - 4 * a * c);
        cout << (root - b) / (a * 2) << ", " << (-root - b) / (a * 2) << "\n";
    }
    return 0;
}