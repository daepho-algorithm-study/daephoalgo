#include <iostream>
using namespace std;

long long dist[100001];
long long cost[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) cin >> dist[i];
    for (int i = 0; i < N; i++) cin >> cost[i];

    long long mn = cost[0];   // 지금까지의 최소 기름값
    long long total = 0;      // 총 비용

    for (int i = 0; i < N - 1; i++) {
        if (cost[i] < mn) mn = cost[i];
        total += mn * dist[i];
    }

    cout << total << "\n";
    return 0;
}
