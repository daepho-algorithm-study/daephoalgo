class Solution {
    int[] parent;
    
    public int solution(int n, int[][] computers) {
        parent = new int[n];
        int cnt = 0;
        
        // 부모 노드 초기화(간선 없는 상태)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        // 간선 정보대로 연결
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (computers[i][j] == 1) {
                    union(i, j);
                }
            }
        }
        
        // 집합 갯수 세기
        for (int i = 0; i < n; i++) {
            if (i == parent[i]) {
                cnt++;
            }
        }
        
        return cnt;
    }
    
    public int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            return parent[x] = find(parent[x]);
        }
    }
    
    public void union(int x, int y) {
        x = find(x);
        y = find(y);
        // 부모가 다르면 이어주기
        if (x != y) {
            parent[y] = x;
        }
    }
}