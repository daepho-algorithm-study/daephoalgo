#include <iostream>
#include <tuple>

using namespace std;

// 깊이에 따른 s,t 정보 저장 배열
tuple<int, int, int> v[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 깊이 변수 할당
    int n, depth = 0;
    string code;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> code;
        // s와 t 개수 카운팅 변수
        int s = 0, t = 0, cs = code.size();
        // s와 t 개수 카운팅
        for (int j = 0; j < cs - 1; j++)
        {
            if (code[j] == 's')
                s++;
            else if (code[j] == 't')
                t++;
        }
        // 깊이에 따른 s,t 저장
        if (code[cs - 1] == '{')
            v[i] = {s, t, depth++};
        else
            v[i] = {s, t, --depth};
    }
    // 정답 저장 변수
    int ans = -1;
    for (int x = 1; x < 100000; x++)
    {
        // 정답 체크 변수
        bool check = true;
        // 깊이 배수 할당 변수
        int i = -1;
        // 저장된 정보에 해당 i값 대입 후 정답 체크
        for (int j = 0; check && j < n; j++)
        {
            // s, t 개수와 깊이 할당 변수
            int s = get<0>(v[j]), t = get<1>(v[j]), k = get<2>(v[j]);
            // 깊이 배수 값이 정해지지 않았으면 계산
            if (i == -1 && k != 0)
                i = (s + t * x) / k;
            // 깊이 배수가 정해진 후 식이 맞지 않으면 정답 X
            else if (s + t * x != k * i)
            {
                check = false;
                break;
            }
        }
        // 정답 발견 시 반복 종료
        if (check)
        {
            ans = x;
            break;
        }
    }
    cout << ans;
    return 0;
}