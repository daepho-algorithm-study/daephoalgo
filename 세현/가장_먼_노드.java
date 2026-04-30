import java.util.*;

// class Solution {
//        public int solution(int n, int[][] edge) {
        
//         Deque<Integer> q = new ArrayDeque<>();      // 큐
//         int[] visited = new int[n+1];           // 방문 노드
        
//         int c_c = 1;        // 현재 레벨 자식 수
//         int n_c = 0;        // 다음 레벨 자식 수
//         int cur_lv = 1;     // 현재 레벨 
           
//         q.offer(1);
//         visited[1] = cur_lv;
//         while (!q.isEmpty()) {
            
//             int current = q.poll();
            
//             if (c_c == 0) {
//                 cur_lv++;
//                 c_c = n_c;
//                 n_c = 0;
//             }
            
//             for (int i = 0; i < edge.length; i++) {
//                 // 양방향 그래프 처리(두 방향 다 봐야 함)
//                 // 현재 노드의 자식을 방문 안했으면 큐에 집어넣고 다음 자식 개수 증가
//                 if (edge[i][0] == current && visited[edge[i][1]] == 0) {
//                     visited[edge[i][1]] = cur_lv+1;
//                     q.offer(edge[i][1]);
//                     n_c++;
//                 } else if (edge[i][1] == current && visited[edge[i][0]] == 0){
//                     visited[edge[i][0]] = cur_lv+1;
//                     q.offer(edge[i][0]);
//                     n_c++;
//                 }
//             }
//             // 현재 자식 개수 감소
//             c_c--;
//         }
        
//         int leaf_cnt = 0;
//         for (int i = 1; i <= n; i++) {
//             if(visited[i] == cur_lv) leaf_cnt++;
//         }
           
//         System.out.println(Arrays.toString(visited));
           
//         return leaf_cnt;
//     }
// }

// 다른 풀이
class Solution {
    public int solution(int n, int[][] edge) {
        // 인접 리스트 만들고 이걸로 순회 돌기
        List<Integer>[] adjL = new ArrayList[n+1];
        
        for (int i = 0; i <= n; i++) {
            adjL[i] = new ArrayList<>();
        }
        
        for (int[] e: edge) {
            adjL[e[0]].add(e[1]);
            adjL[e[1]].add(e[0]);
        }
        
        // 거리 배열(visited 역할 겸용)
        int[] dist = new int[n+1];
        for (int i = 0; i <= n; i++) dist[i] = -1;  // 거리 -1로 초기화
        
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(1);
        dist[1] = 0;
        
        while(!q.isEmpty()) {
            int current = q.poll();
            
            // 현재 노드의 인접한 노드들 다 꺼내기
            for(int next: adjL[current]) {
                if(dist[next] == -1) {
                    // 거리는 현재 노드의 거리에서 + 1
                    dist[next] = dist[current] + 1;
                    q.offer(next);
                }
            }
        }
        
        int leaf_cnt = 0;

        // 최대 레벨 구하기
        int mx_dist = 0;
        for (int d : dist) {
            if(d > mx_dist) {
                mx_dist = d;
            }
        }
        
        // 리프 노드 개수 세기
        for (int d : dist) {
            if (d == mx_dist) {
                leaf_cnt++;
            }
        }
        
    return leaf_cnt; 
    }
}