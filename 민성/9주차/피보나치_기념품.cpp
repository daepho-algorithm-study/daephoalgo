#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a, b;
    int n;
    cin >> n;
    int k = 1;
    if (n % 3 == 1)
        k = 2; // 이 경우, 수 하나는 무조건 빠져야 하므로 제일 앞 수 제외
    else if (n % 3 == 2)
    {
        a.push_back(1); // 피보나치 시작점을 미리 삽입(1, 1)
        b.push_back(2);
        k = 3;
    }
    while (k < n)
    {
        // 앞의 두 수 합이 뒤의 한 수와 같으므로 2개, 1개씩 삽입
        a.push_back(k);
        a.push_back(k + 1);
        b.push_back(k + 2);
        k += 3;
    }
    int as = a.size(), bs = b.size();
    cout << as << "\n";
    for (int i = 0; i < as; i++)
        cout << a[i] << " ";
    cout << "\n";
    cout << bs << "\n";
    for (int i = 0; i < bs; i++)
        cout << b[i] << " ";
    return 0;
}