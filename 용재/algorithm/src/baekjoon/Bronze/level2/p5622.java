package baekjoon.Bronze.level2;

import java.util.Scanner;

public class p5622 { // 백준 5622번, 다이얼 (문자열)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String word = sc.next();
        int time = 0;

        for(int i = 0; i<word.length(); i++) {
            char ch = word.charAt(i);

            switch (ch) {
                case 'A': case 'B' : case 'C':
                    time += 3;
                    break;
                case 'D': case 'E' : case 'F':
                    time += 4;
                    break;
                case 'G': case 'H' : case 'I':
                    time += 5;
                    break;
                case 'J': case 'K' : case 'L':
                    time += 6;
                    break;
                case 'M': case 'N' : case 'O':
                    time += 7;
                    break;
                case 'P': case 'Q' : case 'R': case 'S':
                    time += 8;
                    break;
                case 'T': case 'U' : case 'V':
                    time += 9;
                    break;
                case 'W': case 'X' : case 'Y': case 'Z':
                    time += 10;
                    break;
            }
        }

//        String[] arr = new String[]{"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
//
//        for (int i = 0; i < word.length(); i++) {
//            for (int j = 0; j < arr.length; j++) {
//                for (int k = 0; k < arr[j].length(); k++) {
//                    if (word.charAt(i) == arr[j].charAt(k)) {
//                        time += j + 3;
//                    }
//                }
//            }
//        }
        System.out.println(time);
    }
}
