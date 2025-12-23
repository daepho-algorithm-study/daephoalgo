package baekJoon;

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class B11403 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // 11403. 경로 찾기
        // 첫째줄에 정점 개수
        // 둘째둘부터 n개줄 인접행렬


        int n = Integer.parseInt(br.readLine());

        // 그래프 이용할거
        ArrayList<Integer>[] graph = new ArrayList[n];

        // 리스트 초기화
        for (int i = 0; i < graph.length; i++) {

            graph[i] = new ArrayList<>();

        }

        for (int i = 0; i < graph.length; i++) {

            // 행렬 값 입력 받을거
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int j = 0; j < graph.length; j++) {

                int num = Integer.parseInt(st.nextToken());
                // 1이면 ? 해당 정점과 연결이 되있단 소리
                if (num == 1) {
                    // 그래서 j를 추가해야됨
                    graph[i].add(j);
                }

            }

        }

        // 경로 확인을 위한 배열
        int[][] check = new int[n][n];


        // 방문배열은 반복때마다 초기화하기 위해서 내부에 선언
        // 왜? 해당 반복문에서 시작점이 바뀌기 때문에 다시 방문 배열을 초기화하고 다시 확인해야함
        for (int i = 0; i < n; i++) {
            boolean[] visited = new boolean[n];
            solution(i, i, graph, check, visited);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bw.write(check[i][j] + " ");
            }
            bw.write("\n");
        }



        bw.close();
        br.close();
    }
    // start = 시작점 (고정), node = 지금 dfs 하는 위치
    private static void solution(int start, int node, ArrayList<Integer>[] graph, int[][] check, boolean[] visited) {
        
        // 반복문 돌면서 확인
        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node].get(i);

            // 현재 '시작점' 기준으로 방문기록 없으면
            if (!visited[next]) {
                // 체크
                visited[next] = true;
                // 현재 '시작점' 에서 다음 위치에 갈 수 있음을 표기
                check[start][next] = 1;
                // 재귀
                solution(start, next, graph, check, visited);
            }
        }
    }




    }



