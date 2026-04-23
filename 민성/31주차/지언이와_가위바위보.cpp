#include <iostream>

using namespace std;

// 가위바위보 함수 정의
char rps(bool lose, char c);

// 정답 저장 배열
char ans[601];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w, d, l;
    cin >> n;
    while (1)
    {
        cout << "? ";
        for (int i = 1; i <= n; i++)
        {
            // 정답을 모를 때는 바위를 기본으로 출력
            if (!ans[i])
                ans[i] = 'R';
            // 현재 정답 배열 출력
            cout << ans[i];
        }
        cout << "\n"
             << flush;
        cin >> w >> d >> l;
        // 모든 정답을 알아냈으면 정답 출력 후 종료
        if (w == n)
        {
            cout << "! ";
            for (int i = 1; i <= n; i++)
                cout << ans[i];
            return 0;
        }
        // 최초 비기거나 지는 지점에서 이기는 수로 뒤쪽을 모두 초기화
        if (d < l)
        {
            if (d != -1)
            {
                char win = rps(false, ans[d]);
                for (int i = d; i <= l - 1; i++)
                    ans[i] = win;
            }
            char win = rps(true, ans[l]);
            for (int i = l; i <= n; i++)
                ans[i] = win;
        }
        else
        {
            if (l != -1)
            {
                char win = rps(true, ans[l]);
                for (int i = l; i <= d - 1; i++)
                    ans[i] = win;
            }
            char win = rps(false, ans[d]);
            if (d != -1)
            {
                for (int i = d; i <= n; i++)
                    ans[i] = win;
            }
        }
    }
}

char rps(bool lose, char c)
{
    // 비겼을 때 이기기 위한 수
    if (lose == false)
    {
        if (c == 'R')
            return 'P';
        else if (c == 'P')
            return 'S';
        else
            return 'R';
    }
    // 졌을 때 이기기 위한 수
    else
    {
        if (c == 'R')
            return 'S';
        else if (c == 'P')
            return 'R';
        else
            return 'P';
    }
}