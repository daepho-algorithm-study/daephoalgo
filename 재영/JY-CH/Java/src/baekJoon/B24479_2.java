package baekJoon;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;
import java.util.StringTokenizer;

public class B24479_2 {
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
    

        
    // dfs 함수
    private static void dfs(int node, ArrayList<Integer>[] graph, boolean[] check, int[] checkEnd) {

        Stack<Integer> stack = new Stack<>();
        stack.push(node);

        int order = 1;

        while (!stack.isEmpty()) {

            int num = stack.pop();

            // 이거 안하면 재방문 하게됨 (스택의 LIFO 특성 때문에)
            // 우리가 확인을 하는건 pop을 하는 시점.
            // 아래 push 조건문에서 걸러지는 타이밍이 안맞아 중복이 발생함
            // 그래서 여기서 검증해야됨
            if (check[num]) {
                continue;
            }
            check[num] = true;
            checkEnd[num] = order++;
            
            // 스택 LIFO 특성에 따라서
            // 넣는 구조도 변경 해줘야함
            // 뒤에걸 먼저 넣는 식으로 해야 정상적인 순번을 가져감
            for (int i = graph[num].size() - 1; i >= 0; i--) {

                stack.push(graph[num].get(i));

            }


        }

    }


}
