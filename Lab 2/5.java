import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;


public class DFS {
    private static boolean isWay;
    static int[][] field;
    static int e1, e2;
    static int n, m;


    public static void main(String[] args) {
        isWay = false;
        Scanner in = null;
        int s1, s2;

        try {
            in = new Scanner(new FileReader("file.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        n = in.nextInt();
        m = in.nextInt();

        field = new int[n + 2][m + 2];
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < m + 2; j++) {
                field[i][j] = 1;
            }
        }


        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                field[i][j] = in.nextInt();
            }
        }


        s1 = in.nextInt();
        s2 = in.nextInt();
        e1 = in.nextInt();
        e2 = in.nextInt();

        if (field[s1][s2] == 1 || field[e1][e2] == 1) {
            System.out.println("NO");
        } else {
            dfs(s1, s2);
            if (!isWay) {
                System.out.println("NO\n\n");
                for (int i = 0; i < n + 2; i++) {
                    for (int j = 0; j < m + 2; j++) {
                        System.out.print(field[i][j] + " ");
                    }
                    System.out.println();
                }
            }
        }

    }


    private static void dfs(int a, int b) {
        if (a == e1 && b == e2) {
            isWay = true;
            field[a][b] = 3;
            System.out.println("YES\n\n");
            for (int i = 1; i < n + 1; i++) {
                for (int j = 1; j < m + 1; j++) {
                    System.out.print(field[i][j] + " ");
                }
                System.out.println();
            }
            return;
        }
        field[a][b] = 2;

        if (field[a + 1][b] == 0) {
            dfs(a + 1, b);
        }
        if (field[a - 1][b] == 0) {
            dfs(a - 1, b);
        }
        if (field[a][b + 1] == 0) {
            dfs(a, b + 1);
        }
        if (field[a][b - 1] == 0) {
            dfs(a, b - 1);
        }


    }
}