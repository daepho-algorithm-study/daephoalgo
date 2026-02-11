#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// 수량 저장 배열
int cnt[101];
// 할인가 저장 배열
double dis[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, n, m;
    string p, c, s;
    cout << fixed;
    cout.precision(2);
    cin >> k;
    for (int t = 1; t <= k; t++)
    {
        // 품목 위치 저장 해시
        unordered_map<string, int> food;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> cnt[i] >> p >> c;
            cin.ignore();
            // 공백 포함 품목 이름 입력 받기
            getline(cin, s);
            // 품목 이름 소문자 변환 저장 변수
            string lower = "";
            for (int i = 0; i < s.size(); i++)
            {
                // 대문자는 소문자로 변환 후 저장
                if (s[i] >= 65 && s[i] <= 90)
                    lower += s[i] + 32;
                else
                    lower += s[i];
            }
            // 품목 위치 저장
            food[lower] = i;
            // 금액 문자열에서 달러 표시 제외
            string p1 = p.substr(1), c1 = c.substr(1);
            // 할인가 저장
            dis[i] = stod(p1) - stod(c1);
        }
        // 필요 품목 수량과 할인가 총합 저장 변수
        int num;
        double sm = 0;
        // 필요 품목 재고 탐색
        for (int i = 0; i < m; i++)
        {
            cin >> num;
            cin.ignore();
            getline(cin, s);
            string lower = "";
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] >= 65 && s[i] <= 90)
                    lower += s[i] + 32;
                else
                    lower += s[i];
            }
            // 품목 위치 할당
            int idx = food[lower];
            // 재고 없는 품목은 스킵
            if (!idx)
                continue;
            // 재고보다 더 많이 필요하면 재고만큼만 차감
            if (num > cnt[idx])
                num = cnt[idx];
            // 재고만큼 할인가 적용
            sm += dis[idx] * num;
        }
        cout << "Data Set " << t << ":\n$" << sm << "\n\n";
    }
    return 0;
}