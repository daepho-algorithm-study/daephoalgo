#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 이분 탐색 함수 정의
int bs(const vector<int> &v, int s, int e, int num);
int parent(int x);        // 루트 노드 탐색 함수 정의
void merge(int x, int y); // 병합 함수 정의
int root[4000001];        // 루트 노드 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> card(m, 0); // 카드 번호 저장 배열
    vector<int> cs(k, 0);   // 철수 카드 번호 저장 배열
    for (int i = 0; i < m; i++)
        cin >> card[i]; // 카드 번호 저장
    for (int i = 0; i < k; i++)
        cin >> cs[i];               // 철수 카드 번호 저장
    sort(card.begin(), card.end()); // 카드 번호 오름차순 정렬
    for (int i = 0; i <= m; i++)
        root[i] = i; // 루트 노드 초기화
    for (int i = 0; i < k; i++)
    {
        // 조건 만족하는 카드 인덱스 추출
        int idx = bs(card, 0, m, cs[i]);
        idx = parent(idx);         // 해당 노드의 루트 노드 호출
        cout << card[idx] << "\n"; // 해당 카드 출력
        merge(idx, idx + 1);       // 사용한 카드 인덱스는 바로 윗 인덱스와 병합
    }
    return 0;
}

int bs(const vector<int> &v, int s, int e, int num)
{
    if (s == e)
        return s; // 해당 인덱스 출력
    int mid = (s + e) / 2;
    if (v[mid] > num)
        return bs(v, s, mid, num); // 목표값 초과면 아래 탐색
    else
        return bs(v, mid + 1, e, num); // 목표값 이하면 위 탐색
}

int parent(int x)
{
    if (root[x] == x)
        return root[x];               // 루트 노드 탐색 완료 시 리턴
    return root[x] = parent(root[x]); // 루트 노드 탐색
}

void merge(int x, int y)
{
    x = parent(x), y = parent(y); // 각 노드의 루트 노드 할당
    if (x == y)
        return; // 루트 노드가 같으면 스킵
    if (x > y)
        swap(x, y); // x가 y보다 작도록 노드 할당
    root[x] = y;    // 더 큰 수 쪽으로 병합
}