import java.util.Scanner;
import java.util.TreeMap;
import java.io.File;
import java.io.FileNotFoundException;

public class Initialize {
    public static TreeMap<Character, Integer> parseInput() {
        Scanner sc_file = new Scanner(System.in);
        System.out.print("Input file name : ");
        String path = sc_file.nextLine();
        String text = "";
        try{
            File file = new File(path);
            String abs_path = file.getAbsolutePath();
            System.out.println(abs_path);
            file = new File(abs_path);
            Scanner scan = new Scanner(file);
            while(scan.hasNextLine()){
                text += scan.nextLine();
            }
            scan.close();
        }catch (FileNotFoundException e) {
            System.out.println("Error : no such file or directory" + path);
            sc_file.close();
            return null;
        }

        sc_file.close();
        TreeMap<Character, Integer> map = new TreeMap<>();
        for (int i = 0; i < text.length(); i++) {
            Character c = text.charAt(i);
            Integer val = map.get(c);
            if(val != null) {
                map.put(c,val + 1);
            }
            else {
                map.put(c,1);
            }
        }
        return map;
    }
}
