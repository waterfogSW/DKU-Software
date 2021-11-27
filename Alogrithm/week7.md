# 7주차

## Greedy Method

부분 집합형의 제어 추상화
```C
SolType Greedy(Type a[],int n) {
  SolType soluton = EMPTY;
  for(int i = 1; i <= n; i++) {
    Type x = Selection(a);
    if Feasible(solution, x) //사용가능한지
      solution = Union(solution,x);
  }
  return solution;
}
```

순서형의 제어 추상화
```C
SolType Greedy(Type a[],int n) {
  SolType soluton = EMPTY;
  for(int i = 1; i <= n; i++) {
    Type x = Selection(a);
    solution = Union(solution,x);
  }
  return solution;
}
```

### 4.2 단일 출발지 최단-경로
최단경로 문제
- 단일 출발지/모든 종점(간선의 길이가 양수일 경우) : Greedy사용 가능
- 단일 출발지/모든 종점(일반적일 경우)
- 모든 쌍의 최단 경로

```c
void ShortestPath(int n, int v) {
    for (int i = 0; i < n; i++) {
        s[i] = false;
        dist[i] = length[v][i];
    }
    s[v] = true;
    dist[v] = 0;
    for(i = 0; i<n-2; i++) {
        int u = choose(n);
        s[u] = true;
        for(int w = 0; w < n; w++) {
            if(!s[w]) {
                if(dist[u] + length[u][w] < dist[w])
                    dist[w] = dist[u] + length[u][w];
            }
        }
    }
}
```
시간복잡도 O(n<sup>2</sup>)

### 4.5 최적 합병 패턴(호프만 코드)

합병할 리스트의 길이가 각각 m,n일때 합병에 걸리는 시간은 O(n+m)

욕심쟁이 방법
- 파일의 길이는 합병 시간에 영향을 준다.
- 전략 : 각 단계에서 가장 작은 크기의 파일들을 먼저 합병
  
이진합병트리와 최적 합병 패턴
- 사각형 노드 - 외부노드, 원형 노드 - 내부노드
- 작은 크기의 파일을 먼저 진행하여 작은 외부노드가 더 많이, 큰 외부노드가 더 적게 각 단계에 기여하도록 합병

### 호프만 코드

최소 가중 외부 경로 길이를 갖는 이진트리를 최적의 코드 집합을 얻는데 사용할 수 있다