package baekjoon.Silver.level4;

import java.util.*;
import java.io.*;

public class p1269 { // 백준 1269번 문제, 대칭 차집합 (집합과 맵)
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());


        HashSet<Integer> A = new HashSet<>(); // 집합 A
        HashSet<Integer> B = new HashSet<>(); // 집합 B

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A.add(Integer.parseInt(st.nextToken()));
        }
        int intersectionCount = 0;
        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < M; j++) {
            int elementalB = Integer.parseInt(st.nextToken());
            if(A.contains(elementalB)) {
                intersectionCount++;
            }
        }

//        for (int j = 0; j < M; j++) {
//            B.add(Integer.parseInt(st.nextToken()));
//        }
//        // A-B
//        HashSet<Integer> temp = new HashSet<>();
//        temp.addAll(A);
//        A.removeAll(B);
//
//        // B-A
//        B.removeAll(temp);
//        메모리 낭비가 심하다 생각해 AI에게 최적화 자문
        // A-B + B-A = A+B - 2* A ∩ B
        int result = 0;

//        result = A.size() + B.size();
        result = N+M-(2*intersectionCount);
        bw.write(String.valueOf(result));

        br.close();
        bw.close();
    }
}
