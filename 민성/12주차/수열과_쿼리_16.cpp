#include <iostream>
#include <algorithm>

using namespace std;

int A[100001];                        // 수열 저장 배열
int tree[400004];                     // 세그먼트 트리 구현 배열
void maketree(int s, int e, int idx); // 세그먼트 트리 생성 함수 정의
// 세그먼트 트리 업데이트 함수 정의
void updatetree(int s, int e, int idx, int i, int v);
// 구간 내 최소값 탐색 함수 정의
int query(int s, int e, int idx, int i, int j);
int comp(int l, int r); // 최소값 비교 함수 정의

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> A[i];   // 수열 저장
    maketree(1, n, 1); // 세그먼트 트리 생성
    cin >> m;
    for (int k = 0; k < m; k++)
    {
        int num, i, j;
        cin >> num >> i >> j;
        if (num == 1)
            updatetree(1, n, 1, i, j);
        else
            cout << query(1, n, 1, i, j) << "\n";
    }
    return 0;
}

void maketree(int s, int e, int idx)
{
    if (s == e)
    {
        tree[idx] = s; // 트리 제일 하단에 도달 시 인덱스 저장
        return;
    }
    int mid = (s + e) / 2;
    // 자식 노드 탐색
    maketree(s, mid, idx * 2);
    maketree(mid + 1, e, idx * 2 + 1);
    // 부모 노드 값 할당
    tree[idx] = comp(tree[idx * 2], tree[idx * 2 + 1]);
}

void updatetree(int s, int e, int idx, int i, int v)
{
    if (i < s || i > e)
        return; // 수정할 노드가 범위에 포함되지 않으면 스킵
    if (s == e)
    {
        A[i] = v;
        return; // 트리 끝에 도달 시 값 갱신
    }
    int mid = (s + e) / 2;
    // 자식 노드 탐색
    updatetree(s, mid, idx * 2, i, v);
    updatetree(mid + 1, e, idx * 2 + 1, i, v);
    // 부모 노드 값 갱신
    tree[idx] = comp(tree[idx * 2], tree[idx * 2 + 1]);
}

int query(int s, int e, int idx, int i, int j)
{
    if (j < s || i > e)
        return -1; // 탐색 범위에 포함되지 않으면 제외
    if (i <= s && j >= e)
        return tree[idx]; // 범위 내 값 할당
    int mid = (s + e) / 2;
    // 자식 노드 탐색
    int l = query(s, mid, idx * 2, i, j);
    int r = query(mid + 1, e, idx * 2 + 1, i, j);
    if (l == -1)
        return r;
    else if (r == -1)
        return l;
    else
        return comp(l, r);
}

int comp(int l, int r)
{
    if (A[l] <= A[r])
        return l;
    else // 값이 작은 쪽 인덱스 할당(같을 시 작은 인덱스 할당)
        return r;
}