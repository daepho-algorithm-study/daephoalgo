package baekjoon.Silver.level1;

import java.io.*;
import java.util.*;

/**
 * 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
 * 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
 * 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
 */
public class p1697 { // 백준 1697번 문제, 숨바꼭질
    static int n, k;
    static int[] visited = new int[100_001]; // 입력 최대값이 100,000이므로 배열 크기 고정

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken()); // 수빈이가 있는 위치
        k = Integer.parseInt(st.nextToken()); // 동생이 있는 위치

        if (n==k) {
            System.out.println(0);
        } else {
            bfs(n);
        }

    }

    static void bfs(int start) {
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        visited[start] = 1; // 방문처리

        while (!q.isEmpty()) {
            int now = q.poll();
            int[] nextMove = {now - 1, now + 1, now * 2};

            for (int next : nextMove) {
                if (next == k) {
                    // 다음 스텝에 동생 찾으니까 현재 위치 시간 그대로 출력
                    System.out.println(visited[now]);
                    return;
                }
                // 범위 체크, 방문하지 않은곳인지 체크
                if (next >= 0 && next <= 100_000 && visited[next] == 0) {
                    visited[next] = visited[now]+1;
                    q.add(next);
                }
            }
        }
    }
}
