import java.util.Scanner;

public class E_DIST_TEST {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("String 1  : ");
        String str1 = sc.nextLine();
        System.out.print("String 2  : ");
        String str2 = sc.nextLine();
        sc.close();

        E_DIST E = new E_DIST(str1,str2);
        System.out.println("Min cost : " + E.editDistDP());
        System.out.println("-----Cost Table-----");
        for (int i = 0; i < E.cost.length; i++) {
            for (int j = 0; j < E.cost[i].length; j++) {
                System.out.print(E.cost[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("--------------------");
        System.out.println("-----Edit Table-----");
        for (int i = 0; i < E.edit.length; i++) {
            for (int j = 0; j < E.edit[i].length; j++) {
                System.out.print(E.edit[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("--------------------");

        char order[] = E.optOrder();
        System.out.print("Edit Order : ");
        for (int i = 0; i < order.length - 1; i++) {
            System.out.print(order[i] + "->");
        }
        System.out.println(order[order.length-1]);

        String s_order[] = E.orderApply(order);
        System.out.print("Edit Order : ");
        for (int i = 0; i < s_order.length - 1; i++) {
            System.out.print(s_order[i] + "->");
        }
        System.out.println(s_order[s_order.length-1]);
    }
}
