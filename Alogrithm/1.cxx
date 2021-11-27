#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int n;  //  정점 수
int e;  //  간선 수
int maxl;  // 촤대 레벨

/* 입력

간선 0 - 1 2 9
간선 1 - 1 3 7
간선 2 - 1 4 3
간선 3 - 1 5 2
간선 4 - 2 6 4
간선 5 - 3 6 2
...
...
*/

/* 
각 정점의 레벨 입력
1 0
2 1
3 1
4 1
5 1
6 2
7 2
8 2
..
..

*/

/* 입력
12 21 4 
1 2 9
1 3 7
1 4 3
1 5 2
2 6 4
2 7 2
2 8 1
3 6 2
3 7 7
4 8 11
5 7 11 
5 8 8
6 9 6
6 10 5
7 9 4
7 10 3
8 10 5
8 11 6
9 12 4
10 12 2
11 12 5
*/

int dp[10000+1]; //  정점의 수 1<= n <= 10000 으로 가정 
int MAX_INT = 1e9;

int min_cost(int G[][3], int level[], int n, int e, int maxl){
    // 시작정점 비용 0
    dp[1] = 0;

    // for 간선
    // 시작점 = G[i][0]
    // 끝점 = G[i][1]

    // dp[끝점] = max(dp[끝점], G[i][2])  // cost 비교
    for(int i=0; i<e; i++){
        int start = G[i][0];
        int end = G[i][1];
        dp[end] = min(dp[end], dp[start] + G[i][2]);
    }

    int result = MAX_INT;
    // 마지막 레벨 정점들 비용 비교
    for(int i=1; i<=n; i++){
        if(level[i] == maxl)
            result = min(result, dp[i]);
    }

    return result;    
}

int main(){
    cin >> n >> e >> maxl;

    for(int i=1; i<=n; i++){
        dp[i] = MAX_INT;
    }

    // 각 정점 레벨을 나타냄.
    int level[n+1];
    // 시작 정점은 1,  레벨 0
    level[1] = 0;

    int G[e][3];  // e는 간선의 수
    //vector<vector<int>> G(e, vector<int>(3));   // s, e, cost

    for(int i=0; i<e; i++){
        int s, e, cost;
        cin >> s >> e >> cost;
        G[i][0] = s;
        G[i][1] = e;
        G[i][2] = cost;

        level[e] = level[s]+1;
    }    

    for(int i=0; i<e; i++){
        cout << G[i][0] << G[i][1] << G[i][2] << endl;
    }
    for(int i=1; i<=n; i++){
        cout << level[i] << endl;
    }

    int result = min_cost(G, level, n, e, maxl);

    // 
    cout << "##########" << '\n';  
    for(int i=1; i<=n; i++){
        cout << dp[i] << '\n';

    }
    cout << "##########" << '\n';

    cout << result << endl;

}