import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;

public class Test {
    public static void main(String[] args) throws IOException {
        Random random = new Random();
        FileOutputStream fos = new FileOutputStream(".\\input.txt");
        PrintWriter pw = new PrintWriter(fos);
        for (int i = 0; i < 100; i ++) {
            //number of elements [100; 10000]
            int n = random.nextInt(9900) + 100;
            pw.println(n);
            //items
            for (int j = 0; j < n; j ++) {
                pw.println(random.nextInt(1000));
            }
            //items to check
            for (int p = 0; p < 100; p ++) {
                pw.println(random.nextInt(1000));
            }
            pw.println(-1);
        }
        pw.close();
    }
}
