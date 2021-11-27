import java.util.Comparator;
public class MyComparator implements Comparator<Node> {
    public int compare(Node x, Node y) {
        return x.weight - y.weight;
    }
}