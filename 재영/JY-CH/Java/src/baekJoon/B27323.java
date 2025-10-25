package baekJoon;

import java.io.*;

public class B27323 {
public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    int a = Integer.parseInt(br.readLine());
    int b = Integer.parseInt(br.readLine());

    int answer = a * b;

    bw.write(String.valueOf(answer));


    bw.close();
    br.close();
}


}