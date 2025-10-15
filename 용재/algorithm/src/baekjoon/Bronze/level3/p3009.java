package baekjoon.Bronze.level3;

import java.util.*;
import java.io.*;

/*
7 5
5 7
5 5
*/
public class p3009 { // 백준 3009번 문제, 네 번째 점 (기하 1: 직사각형과 삼각형)
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] arr = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
        st = new StringTokenizer(br.readLine());
        int[] arr2 = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
        st = new StringTokenizer(br.readLine());
        int[] arr3 = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};

        int x;
        int y;

        if (arr[0] == arr2[0]) {
            x = arr3[0];
        } else if (arr[0] == arr3[0]) {
            x = arr2[0];
        } else {
            x = arr[0];
        }

        if (arr[1] == arr2[1]) {
            y = arr3[1];
        } else if (arr[1] == arr3[1]) {
            y = arr2[1];
        } else {
            y = arr[1];
        }
        System.out.print(x + " " + y);
    }
}
