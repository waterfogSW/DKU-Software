import java.util.TreeMap;
import java.util.PriorityQueue;

public class Huffman {
    public static void main(String[] args) throws Exception {
        TreeMap<Character, Integer> map = Initialize.parseInput();
        Character[] key_arr = map.keySet().toArray(new Character[map.size()]);
        Integer[] value_arr = map.values().toArray(new Integer[map.size()]);

        System.out.print("Char : ");
        for (int i = 0; i < key_arr.length; i++) {
            System.out.print(String.format("%s ", key_arr[i]));
        }
        System.out.println();

        System.out.print("Freq : ");
        for (int i = 0; i < value_arr.length; i++) {
            System.out.print(String.format("%s ", value_arr[i]));
        }
        System.out.println();

        PriorityQueue<Node> q
            = new PriorityQueue<Node>(key_arr.length, new MyComparator());

        for(int i = 0; i < key_arr.length; i++) {
            Node hn = new Node();
            hn.ch = key_arr[i];
            hn.weight = value_arr[i];

            hn.left = null;
            hn.right = null;

            q.add(hn);
        }

        Node root = null;

        while(q.size() > 1) {
            Node x = q.peek();
            q.poll();

            Node y = q.peek();
            q.poll();

            Node f = new Node();
            f.weight = x.weight + y.weight;
            f.ch = '-';
            f.left = x;
            f.right = y;
            root = f;
            q.add(f);
        }

        printCode(root, "");
    }

    public static void printCode(Node root, String s) {
        if(root.left == null && root.right == null) {
            if(Character.isLetter(root.ch) || root.ch == ' '){
                System.out.println(root.ch + " : " + s);
                return;
            }
        }
        printCode(root.left, s + "0");
        printCode(root.right, s + "1");
    }
}
