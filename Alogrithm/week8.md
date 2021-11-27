# 8주차

## Greedy

### Huffman코드

최소 가중 외부 경로길이를 갖는 이진트리를 메시지 M<sub>1</sub>, ... , M<sub>n</sub>에 대한 최적의 코드 집합을 얻는데 사용 가능

- 사용빈도가 높은 메시지일수록 짧은 경로를 부여할 수 있어서 최적의 코드 집합을 얻을 수 있음.
- 코드 단어를 복호하는 비용은 코드에 포함된 비트수에 비례

### 배낭문제에 대한 최적의 욕심쟁이 방법

```java
public void GreedyKnapsack(float m, int n) {
    for(int i = 1; i<=n; i++) x[i] = 0.0;
    float U = m;
    for(int i = 1; i<=n; i++) {
        if(w[i] > U) break;
        x[i] = 1.0;
        U -= w[i];
    }
    if(i <= n) x[i] = U/w[i];
}
```

### 트리 정점 분할 알고리즘

```java
void TVS(Tree T, int delta) {
    if(T != NULL) {
        d[T] = 0;
        for(each child v of T) {
            TVS(v, delta);
            d[T] = max {d[T], d[v] + w[T][v]};
        }
        if((T is not the root) && (d[T] + w[parent(T)]))
    }
}
```