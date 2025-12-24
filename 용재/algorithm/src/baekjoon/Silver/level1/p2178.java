package baekjoon.Silver.level1;

import java.io.*;
import java.util.*;

public class p2178 { // 백준 2178번 문제, 미로탐색
    static int n;
    static int m;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken()); // 세로
        m = Integer.parseInt(st.nextToken()); // 가로

        int[][] maze = new int[n][m];

        for (int i = 0; i < n; i++) { // 미로 입력
            String line = br.readLine();
            for (int j = 0; j < m; j++) { // 붙어있는 숫자를 떼야하기 때문에 문자열로 받아서 하나씩 charAt으로 뜯은 뒤 '0' 빼준다.
                maze[i][j] = line.charAt(j) - '0';
            }
        }


        System.out.print(bfs(maze));
//        for (int[] line : maze) { // 테스트용 maze 출력문
//            System.out.println(Arrays.toString(line));
//        }
    }


    static int bfs(int[][] maze) { // bfs 구현함수
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0, 0}); // 시작점 정해져있음

        boolean[][] visited = new boolean[n][m]; // visited 배열 정의

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int y = curr[0];
            int x = curr[1];

            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];

                if (ny >=0 && nx >=0 && ny<n && nx <m) { // 배열범위 안벗어나게 하고
                    if (maze[ny][nx] == 1 && !visited[ny][nx]) { // 다음 체크할 곳이 1 = 방문아직 안함이랑 같은소리긴함, 아무튼 방문여부 체크
                        visited[ny][nx] = true; // 방문 체크하고
                        queue.add(new int[] {ny,nx}); // 큐에 다음으로 갈 곳 넣고
                        maze[ny][nx] = maze[y][x]+1; // 현재값 +1 해준다.
                    }

                }
            }
        }
        return maze[n-1][m-1];
    }
}
