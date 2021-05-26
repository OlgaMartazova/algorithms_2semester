import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Random;

public class data {
    public static void main(String[] args) throws FileNotFoundException {
        Random random = new Random();
        FileOutputStream fos = new FileOutputStream("input.txt");
        PrintWriter pw = new PrintWriter(fos);
        for (int i = 0; i < 100; i ++) {
            //number of elements [2; 100]
            int l = random.nextInt(900) + 100;
            pw.println(l);
            int r = random.nextInt(900) + 100;
            pw.println(r);
            for (int j = 0; j < l; j ++) {
                //number of edges [1; r]
                int tmp = random.nextInt(r-1) + 1;
                pw.print(tmp + " ");
                HashSet<Integer> set = new HashSet<>();
                for (int k = 0; k < tmp; k++) {
                    int x = random.nextInt(r-1) + l + 1;
                    while (!set.add(x)) {
                        x = random.nextInt(r-1) + l + 1;
                    }
                    pw.print(x + " ");
                }
                pw.println();
            }
        }
        pw.close();
    }
}
