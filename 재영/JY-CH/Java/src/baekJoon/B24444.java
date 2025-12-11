package baekJoon;

import java.io.*;
import java.util.*;

public class B24444 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 백준 24444, 알고리즘 수업 - 넓이 우선 탐색 1
        // bfs 문제

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        // 방문 확인
        boolean[] visited = new boolean[n + 1];
        // 방문 순서확인
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

        int order = 1;
        Queue<Integer> que = new LinkedList<>();
        que.add(r);
        visited[r] = true;
        visitedEnd[r] = order++;

        while(!que.isEmpty()) {

            // peek == 앞에 값을 반환
            // poll == 앞에 값을 반환하고 삭제. pop
            // 여기에 peek 쓰면 무한으로 즐겨요~
            int node = que.poll();

            for (int i = 0; i < graph[node].size(); i++) {

                if (!visited[graph[node].get(i)]) {
                    visited[graph[node].get(i)] = true;
                    visitedEnd[graph[node].get(i)] = order++;
                    que.add(graph[node].get(i));
                }

            }

        }

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


}
