#include <iostream>
#include <string>

using namespace std;

// 알파벳 인덱스 변환 함수 정의
int chnum(char c);
// 조건 체크 함수 정의
void check();

// 문자열에 포함된 알파벳 수와 최소 필요 수 저장 배열
int cnt[4], acgt[4];
int s, p, ans = 0;
string dna;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> p >> dna >> acgt[0] >> acgt[1] >> acgt[2] >> acgt[3];
    // 제일 왼쪽 부분 문자열부터 체크
    for (int i = 0; i < p; i++)
    {
        // 해당 알파벳 인덱스 변환
        int idx = chnum(dna[i]);
        cnt[idx]++;
    }
    check();
    for (int i = 0; i < s - p; i++)
    {
        // 부분 문자열에서 빠질 부분과 다음 탐색 문자 할당
        int l = chnum(dna[i]), r = chnum(dna[i + p]);
        cnt[l]--;
        cnt[r]++;
        check();
    }
    cout << ans;
    return 0;
}

int chnum(char c)
{
    if (c == 'A')
        return 0;
    else if (c == 'C')
        return 1;
    else if (c == 'G')
        return 2;
    else
        return 3;
}

void check()
{
    // 조건 미충족 시 스킵
    for (int i = 0; i < 4; i++)
        if (cnt[i] < acgt[i])
            return;
    // 조건 충족 시 카운팅
    ans++;
    return;
}