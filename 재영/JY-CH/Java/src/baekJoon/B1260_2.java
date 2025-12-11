package baekJoon;

import java.io.*;
import java.util.*;

public class B1260_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 백준 1260, dfs와 bfs
        // 앞선 문제들은 i번째 줄에 정점 i의 방문순서를 출력해야 됬는데
        // 이번의 경우 v부터 방문된 점을 출력한다!

        // 공통 부분
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());

        // 그래프를 만들기 위한 첫 시작
        // 정수형 리스트들을 가지는 리스트 선언
        ArrayList<Integer>[] graph = new ArrayList[n + 1];

        // 내부 리스트 초기화
        for (int i = 1; i <= n; i++) {

            graph[i] = new ArrayList<>();

        }

        // 그래프의 간선 정보 채우기
        for (int i = 0; i < m; i++) {

            st = new StringTokenizer(br.readLine());

            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            graph[start].add(end);
            graph[end].add(start);

        }

        // 인접 정점 방문 방식 오름차순
        // 그래프의 내부 리스트 요소들을 정렬
        for (int i = 1; i <= n; i++) {

            Collections.sort(graph[i]);

        }

        // 여기까지는 공통


        // dfs
        // dfs용 방문 확인
        boolean[] visitedDfs = new boolean[n + 1];
        int[] visitedDfsEnd = new int[n];

        // dfs
        dfs(v, graph, visitedDfs, visitedDfsEnd);

        
        // dfs 출력
        for (int i = 0; i < n; i++) {

            if (visitedDfsEnd[i] == 0) {
                break;
            }

            bw.write(visitedDfsEnd[i] + " ");

        }

        bw.write("\n");


        // bfs
        // bfs용 방문 확인
        boolean[] visitedBfs = new boolean[n + 1];
        int[] visitedBfsEnd = new int[n];


        // bfs
        int bfsOrder = 0;
        Queue<Integer> que = new LinkedList<>();
        que.add(v);
        // 방문 확인 체크하고
        visitedBfs[v] = true;
        // 해당 순서에 어떤 정점인지 저장
        visitedBfsEnd[bfsOrder] = v;
        // 순서 더해준 다음
        bfsOrder++;

        while(!que.isEmpty()) {

            int node = que.poll();

            for (int i = 0; i < graph[node].size(); i++) {
                
                // 앞서 언급한 것을 반복
                if (!visitedBfs[graph[node].get(i)]) {
                    visitedBfs[graph[node].get(i)] = true;
                    visitedBfsEnd[bfsOrder] = graph[node].get(i);
                    bfsOrder++;
                    que.add(graph[node].get(i));
                }

            }

        }

        for (int i = 0; i < n; i++) {

            if (visitedBfsEnd[i] == 0) {
                break;
            }

            bw.write(visitedBfsEnd[i] + " ");

        }


        bw.close();
        br.close();
    }


    // dfs 함수
    private static void dfs(int node, ArrayList<Integer>[] graph, boolean[] check, int[] checkEnd) {
        
        // 스택
        Stack<Integer> stack = new Stack<>();
        stack.push(node);
        
        // 순서
        int order = 0;

        while (!stack.isEmpty()) {
            
            // pop 하고 방문 체크
            int num = stack.pop();
            
            // 중복 되면 패스
            if (check[num]) {
                continue;
            }
            check[num] = true;
            // 현재 순서에 num 더하고 ++
            checkEnd[order++] = num;
            
            // 뒤에서부터 값을 저장해야
            // 스택 dfs에서 순서를 보장 받는다
            for (int i = graph[num].size() - 1; i >= 0; i--) {

                stack.push(graph[num].get(i));

            }

        }

    }


}
