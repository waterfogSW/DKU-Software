import java.lang.Math;

public class Generater {
    public static int[] genNumber(int count) {
        int []array = new int[count];
        for (int i = 0; i < count; i++) {
            array[i] = (int)(Math.random()*999);
        }
        return array;
    }
}
