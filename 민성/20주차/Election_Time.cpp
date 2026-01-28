#include <iostream>
#include <algorithm>

using namespace std;

// 소 정보 저장 구조체 할당
struct cow
{
    int f, s, idx;
};

// 소 투표 결과 저장 배열
cow vote[50000];
// 정렬 방식 지정 함수 정의
bool comp1(cow a, cow b);
bool comp2(cow a, cow b);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    // 투표 결과 저장
    for (int i = 0; i < n; i++)
    {
        cin >> vote[i].f >> vote[i].s;
        vote[i].idx = i;
    }
    // 1차 투표 결과 내림차순 정렬
    sort(vote, vote + n, comp1);
    // 1차 투표 수가 많은 k마리 소 중 2차 투표 결과 내림차순 정렬
    sort(vote, vote + k, comp2);
    cout << vote[0].idx + 1;
    return 0;
}

bool comp1(cow a, cow b)
{
    return a.f > b.f;
}

bool comp2(cow a, cow b)
{
    return a.s > b.s;
}