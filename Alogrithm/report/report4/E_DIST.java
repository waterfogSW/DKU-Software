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