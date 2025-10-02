package baekjoon.Silver.level5;

import java.util.Scanner;

public class p2941 { // 백준 2941번 , 크로아티아 알파벳 (심화1)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String word = sc.nextLine();

        int cnt = 0;

        for (int i = 0; i < word.length(); i++) {
            cnt++;
            if (word.charAt(i) == 'c') {
                if (i < word.length() - 1) {
                    if (word.charAt(i + 1) == '=') {
                        i++;
                    } else if (word.charAt(i + 1) == '-') {
                        i++;
                    }
                }
            } else if (word.charAt(i) == 'd') {
                if (i < word.length() - 1) {
                    if (word.charAt(i + 1) == 'z') {
                        if (i < word.length() - 2) {
                            if (word.charAt(i + 2) == '=') {
                                i += 2;
                            }
                        }
                    } else if (word.charAt(i + 1) == '-') {
                        i++;

                    }
                }
            } else if (word.charAt(i) == 'l') {
                if (i < word.length() - 1) {
                    if (word.charAt(i + 1) == 'j') {
                        i++;
                    }
                }
            } else if (word.charAt(i) == 'n') {
                if (i < word.length() - 1) {
                    if (word.charAt(i + 1) == 'j') {
                        i++;
                    }
                }
            } else if (word.charAt(i) == 's') {
                if (i < word.length() - 1) {
                    if (word.charAt(i + 1) == '=') {
                        i++;
                    }
                }
            } else if (word.charAt(i) == 'z') {
                if (i < word.length() - 1) {
                    if (word.charAt(i + 1) == '=') {
                        i++;
                    }
                }
            }
        }

        System.out.println(cnt);

        sc.close();
    }
}
