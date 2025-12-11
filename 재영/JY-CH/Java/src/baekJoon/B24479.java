package baekJoon;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class B24479 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 백준 24479, 알고리즘 수업 - 깊이 우선 탐색 1
        // dfs 문제

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        // 방문 확인
        boolean[] visited = new boolean[n + 1];
        int[] visitedEnd = new int[n + 1];

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

            // 양방향
            graph[start].add(end);
            graph[end].add(start);

        }

        // 인접 정점 방문 방식 오름차순
        // 그래프의 내부 리스트 요소들을 정렬
        for (int i = 1; i <= n; i++) {

            Collections.sort(graph[i]);

        }

        // dfs
        dfs(r, graph, visited, visitedEnd);
        
        // 방문순서 저장한 배열 값 있으면 해당 값을
        // 아니면 0을 출력하도록 함
        for (int i = 1; i <= n; i++) {

            if (visitedEnd[i] == 0) {
                bw.write("0" + "\n");
            } else {
                bw.write(visitedEnd[i] + "\n");
            }

        }


        bw.close();
        br.close();
    }
    
    // static 영역에서 변수 설정을 통해 dfs에서 사용할 순서 변수
    static int order = 1;
        
    // dfs 함수
    private static void dfs(int node, ArrayList<Integer>[] graph, boolean[] check, int[] checkEnd) {

        // 방문 여부 변경
        check[node] = true;
        // 1. 현재 방문 순서 저장 2. order값을 더함.
        // ex 현재 방문 순서가 1번이고 시작 정점이 1이면
        // 방문 순서 저장배열에 1을 저장하고
        // 방문순서 값을 1 추가함
        checkEnd[node] = order++;

        // 간선 연결 정보 순회하면서
        // 만약 방문 하지 않은 정점이 있다면
        // 해당 정점을 넣고 다시 dfs
        for (int i = 0; i < graph[node].size(); i++) {
            if (!check[graph[node].get(i)]) {
                dfs(graph[node].get(i), graph, check, checkEnd);
            }

        }

    }


}
