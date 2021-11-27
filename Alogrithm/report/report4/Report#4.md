# 레포트 #4
<div style="text-align: right"> 알고리즘 3분반, 32170578, 김산 </div>

## 소스코드

### E_DIST.java
```java
public class E_DIST {
    int m, n;
    int cost[][];
    char edit[][];
    String str1, str2;

    E_DIST(String _str1,String _str2) {
        str1 = _str1;
        str2 = _str2;
        m = _str1.length();
        n = _str2.length();
        cost = new int [m+1][n+1];      // Minimum Cost
        edit = new char [m+1][n+1];     // Edit Order
    }

    private int minEdit(int del, int chg, int ins,int i, int j) {
        if(del < chg && del < ins) {
            edit[i][j] = 'D';
            return del;
        } else if(chg < ins && chg < del) {
            edit[i][j] = 'C';
            return chg;
        } else {
            edit[i][j] = 'I';
            return ins;
        }
    }

    public int editDistDP() {
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    cost[i][j] = j;
                    edit[i][j] = 'I';
                }
                else if(j == 0) {
                    cost[i][j] = i;
                    edit[i][j] = 'D';
                }
                else if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    cost[i][j] = cost[i - 1][j - 1];
                    edit[i][j] = 'C';
                }

                else
                    cost[i][j] = minEdit(cost[i-1][j] + 1,
                                        cost[i-1][j-1] + 2,
                                        cost[i][j - 1] + 1,
                                        i,j);
            }
        }
        edit[0][0] = '-';
        return cost[m][n];
    }
    public char[] optOrder() {
        int i = m;
        int j = n;
        int count = 0;
        char c_tmp = edit[i][j];
        char temp[] = new char[m+n];
        while(i != 0 || j != 0) {
            if (edit[i][j] == 'I'){
                c_tmp = 'I';
                j--;
            } else if (edit[i][j] == 'D') {
                c_tmp = 'D';
                i--;
            } else {
                c_tmp = 'C';
                i--;
                j--;
            }
            temp[count++] = c_tmp;
        }

        char order[] = new char[count];
        for(int k = 0; k < count; k++) {
            order[k] = temp[count - k - 1];
        }
        return order;
    }

    public String[] orderApply(char order[]) {
        int i = 0, j = 0;
        String[] orderApply = new String[order.length];
        for (int k = 0; k < order.length; k++) {
            String tmp = "";
            switch (order[k]) {
                case 'I':
                    j++; 
                    break;
                case 'D':
                    i++;
                    break;
                case 'C':
                    i++;
                    j++;
                    break;
            }
            tmp = str2.substring(0,j) + str1.substring(i,str1.length());
            orderApply[k] = tmp;
        }
        return orderApply;
    }

}
```

### E_DIST_TEST.java(Main함수)
```java
import java.util.Scanner;

public class E_DIST_TEST {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("String 1  : ");
        String str1 = sc.nextLine();
        System.out.print("String 2  : ");
        String str2 = sc.nextLine();
        sc.close();

        /*2개의 문자열 입력을 받아 최적 경로를 구하기 위한 객체를 생성합니다. */
        E_DIST E = new E_DIST(str1,str2);
        System.out.println("Min cost : " + E.editDistDP());
        /*비용 배열을 출력합니다.*/
        System.out.println("-----Cost Table-----");
        for (int i = 0; i < E.cost.length; i++) {
            for (int j = 0; j < E.cost[i].length; j++) {
                System.out.print(E.cost[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("--------------------");
        /*편집 배열을 출력합니다.*/
        System.out.println("-----Edit Table-----");
        for (int i = 0; i < E.edit.length; i++) {
            for (int j = 0; j < E.edit[i].length; j++) {
                System.out.print(E.edit[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println("--------------------");
        
        /*최적의 편집 순서열을 구합니다*/
        char order[] = E.optOrder();
        System.out.print("Edit Order : ");
        for (int i = 0; i < order.length - 1; i++) {
            System.out.print(order[i] + "->");
        }
        System.out.println(order[order.length-1]);

        /*최적의 편집 순서열을 적용하여 문자열 편집 순서를 나타냅니다.*/
        String s_order[] = E.orderApply(order);
        System.out.print("Edit Order : ");
        for (int i = 0; i < s_order.length - 1; i++) {
            System.out.print(s_order[i] + "->");
        }
        System.out.println(s_order[s_order.length-1]);
    }
}
```


## 실행결과

### Case 1
| String 1 | String 2 |
| -------- | -------- |
| aabab    | babb     |

![image](https://user-images.githubusercontent.com/28651727/117564172-bffd9b00-b0e5-11eb-9b90-1644118740d2.png)

### Case 2
| String 1 | String 2 |
| -------- | -------- |
| san      | sun      |

![image](https://user-images.githubusercontent.com/28651727/117565128-bcb8de00-b0ea-11eb-9265-5d5b5bdad889.png)

### Case 3
| String 1 | String 2 |
| -------- | -------- |
| sunday   | saturday |

![image](https://user-images.githubusercontent.com/28651727/117565045-5207a280-b0ea-11eb-9842-35fc7ce4e15f.png)

### Case 4
| String 1 | String 2 |
| -------- | -------- |
| food     | money    |

![image](https://user-images.githubusercontent.com/28651727/117565089-8bd8a900-b0ea-11eb-8947-f48109dbd3ed.png)


### Case 5
| String 1  | String 2   |
| --------- | ---------- |
| voldemort | dumbledore |

![image](https://user-images.githubusercontent.com/28651727/117565113-a1e66980-b0ea-11eb-934e-18c7fce388a5.png)