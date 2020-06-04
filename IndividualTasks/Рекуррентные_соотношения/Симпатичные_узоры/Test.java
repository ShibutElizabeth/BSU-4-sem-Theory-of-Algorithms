import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Test {
    public static void main(String[] args) {
        Algorithm algorithm = new Algorithm();
    }
}

class Algorithm{
    int n, m;
    BigInteger [][] d;
    static List<Integer> input() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("in.txt")));
        List<Integer> input = new ArrayList<>();
        String temp = reader.readLine();
        while (temp != null) {
            input.add(Integer.parseInt(temp));
            temp = reader.readLine();
        }
        return input;
    }

    static void output(String str) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter("out.txt"));
        writer.write(str);
        writer.close();
    }
    
    Algorithm(){
        try {
            List<Integer> list = new ArrayList<>(input());
            m = list.get(0);
            n = list.get(1);

            d = new BigInteger[n + 1][(1 << m)];

            for (int i = 0; i < n + 1; ++i) {
                for (int mask = 0; mask < (1 << m); ++mask) {
                    d[i][mask] = BigInteger.ZERO;
                }
            }
            for (int mask = 0; mask < (1 << m); ++mask) {
                d[0][mask] = BigInteger.ONE;
            }
            for (int x = 0; x < n; ++x) {
                for (int mask = 0; mask < (1 << m); ++mask) {
                    ways(x, 0, mask, 0);
                }
            }
            BigInteger sum = BigInteger.ZERO;

            for (int mask = 0; mask < (1 << m); ++mask) {
                sum = sum.add(d[n - 1][mask]);
            }
            String str = sum + "";
            output(str);
        }
         catch (IOException e){
             System.out.println(e.getMessage());
         }
    }

    public void ways(int x, int y, int mask, int next_mask)
    {
        int left = 0, leftup = 0, up = 0;
        if (x == n)
            return;
        if (y >= m) {
            BigInteger s = d[x+1][next_mask];

            d[x + 1][next_mask] = s.add(d[x][mask]);
            return;
        }
        if (y == 0) {
            ways(x, y + 1, mask, 0);
            ways(x, y + 1, mask, 1);
            return;
        }
        int my_mask = (1 << y);
        if ((mask & my_mask) != 0)
            left = 1;
        else
            left = 0;

        my_mask >>= 1;
        if ((mask & my_mask) != 0)
            leftup = 1;
        else
            leftup = 0;

        if ((next_mask & my_mask) != 0)
            up = 1;
        else
            up = 0;

        my_mask <<= 1;
        if (((left ^ leftup) == 0) && ((left ^ up) == 0)) {
            if (left == 0)
                ways(x, y + 1, mask, (next_mask | my_mask));
            else
                ways(x, y + 1, mask, next_mask);
        }

        else {
            ways(x, y + 1, mask, (next_mask | my_mask));
            ways(x, y + 1, mask, next_mask);
        }
    }

}
