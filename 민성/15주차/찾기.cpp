#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 부분 문자열 최장 접두사이자 접미사(LPS) 길이 저장 배열
int pi[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string t, p;
    // 공백 포함 문자열 입력
    getline(cin, t);
    getline(cin, p);
    // 문자열 길이 저장
    int ts = t.size(), ps = p.size();
    // pi 배열 구성
    int j = 0;
    for (int i = 1; i < ps; i++)
    {
        // 문자가 일치할 때까지 이전 LPS의 LPS 길이를 대입
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        // LPS 길이 갱신
        if (p[i] == p[j])
        {
            j += 1;
            pi[i] = j;
        }
    }
    // P 문자열 개수 저장 변수
    int cnt = 0;
    // P 문자열 위치 저장 배열
    vector<int> pos;
    // 문자열 T와 P 비교
    j = 0;
    for (int i = 0; i < ts; i++)
    {
        // pi 배열을 이용하여 불필요 연산 스킵
        while (j > 0 && t[i] != p[j])
            j = pi[j - 1];
        // 일치하는 문자열 길이 측정
        if (t[i] == p[j])
            j += 1;
        // 문자열 P 탐색 시 카운팅 및 위치 저장
        if (j == ps)
        {
            cnt++;
            pos.push_back(i - ps + 2);
            j = pi[j - 1];
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < pos.size(); i++)
        cout << pos[i] << " ";
    return 0;
}