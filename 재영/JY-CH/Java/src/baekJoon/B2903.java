package baekJoon;

import java.io.*;

public class B2903 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int input = Integer.parseInt(br.readLine());

//        int square = 1;
//
//        for (int i = 0; i < input * 2; i++) {
//            square = square * 2;
//        }
//
//        int side = 0;
//        int middle = (square / (2 * input)) + 1;
//
//        for (int i = 1; i <= (square / (2 * input)); i++) {
//            side = side + i;
//        }
//
//        int answer = (side * 2) + middle;
//
//        bw.write(String.valueOf(answer));


        int side = 1;

        for (int i = 0; i < input; i++) {
            side = side * 2;
        }

        int sidePoint = side + 1;

        int answer = sidePoint * sidePoint;

        bw.write(String.valueOf(answer));


        bw.close();
        br.close();
    }


}
