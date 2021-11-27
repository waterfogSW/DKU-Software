# 5주차

## 합병정렬

### 개선사항

- 문제점 :
  - 보조 기억 장소를 사용하여 합병하므로 각 호출에서 저장된 결과를 다시 복사해야 함.
  - -> 키를 포함하는 레코드의 크기가 큰 경우 많은 시간을 소요
- 개선점 :
  - 해당 레코드를 가리키는 링크값(해당 변수를 저장하고 있는 배열의 인덱스)을 사용하여 레코드를 이동시키지 않고 링크 값 만을 이동한다.
  - 시간복잡도는 기존의 병합정렬과 같다.
  - 링크값 0은 리스트의 끝을 의미하므로 인덱스는 1부터 시작해야 함.

```c
int MergeSort1(int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        int q = MergeSort1(low, mid);
        int r = MergeSort1(mid + 1, high);
        return (Merge1(q,r));
    }
    else return low;
}
```
link배열을 통해 linked list방식으로 정렬
```c
if(a[i] <= a[j]) {
    link[k] = i; k = i; i = link[i];
} else {
    link[k] = j; k = j; j = link[j];
}
```

### 링크를 사용하는 합병(lec4-5)
```c
int Merge1(int q, int r) {
    int i = q, j = r, k = 0;
    while (i != 0 && j != 0) {
        if(a[i] <= a[j]) {
            link[k] = i; k = i; i = link[i];
        }
        else {
            link[k] = j; k = j; j = link[j];
        }
    }
    if(i == 0) link[k] = j;
    else link[k] = i; 
    return(link[0]);
}
```


```
  a:   [0] [1] [2] [3] [4] [5] [6] [7] [8]
​        -  50  10  25  30  15  70  35  55
link:   0   0   0   0   0   0   0   0   0
q r p
1 2 2   2   0   1   0   0   0   0   0   0   (10,50)
3 4 3   3   0   1   4   0   0   0   0   0   (10,50), (25,30)
2 3 2   2   0   3   4   1   0   0   0   0   (10,25,30,50)
5 6 5   5   0   3   4   1   6   0   0   0   (10,25,30,50)(15,70)
7 8 7   7   0   3   4   1   6   0   8   0   (10,25,30,50)(15,70)(35,55)
5 7 5   5   0   3   4   1   7   0   8   6   (10,25,30,50)(15,35,55,70)
2 5 2   2   8   5   4   7   3   0   1   6   (10,15,25,30,35,50,55,70)
```

링크값만 바뀌었기 때문에 링크값을 이용하여 재배치해주어야 한다.

- link를 따라가면서 0,1,2... 오름차순으로 순위를 매김
- 순위에 따라 배열 재배치

## 퀵정렬 (quick sort)

- 합병정렬과는 달리 두 부분 배열로의 분할이 나중에 결합될 필요가 없다.
- 리스트에 존재하는 n개의 원소를 재배치하여 특정값 j에 대하여 다음과 같이 세 개의 리스트로 나눈다.
  - -> 분할
  - P1 = a[1],...,a[j-1]
  - P2 = a[j]
  - P3 = a[j+1], a[j+2],...,a[n]
- 이때 a[j]를 분할 원소라ㅎ며, 리스트에서 j번재 작은 원소이다. 따라서 a[j]는 리스트가 정렬된 후에도 위치 변동이 없게된다.
- 퀵 정렬은 P1, P3에 대해서 이러한 분할 과정을 반복한다.
- 리스트에 한개의 원소만 존재할 때 Small(P)기 true가되며, 이경우 리스트는 정렬된것으로 간주, 바로 return한다
- 마지막에 아주 큰값을 삽입하는것은 메모리를 낭비하지만, 시간을 줄일수 있는 효과가 있음

```java
void QuickSort(int p, int q) {
    if(p<q) {
        int j = Partition(a,p,q+1);
        QuickSort(p, j-1);
        QuickSort(j+1);
    }
}

int Partition(int a[], int m, int p) {
    int v = a[m];
    int i = m,j = p;
    do {
        do i++;
        while(a[i] < v);
        do j--;
        while(a[j] > v);
        if(i < j) Interchange(a,i,j);
    } while(i < j);
    a[m] = a[j]; a[j] = v; return(j);
}
```

- **분할**의 각 호출에서 원소 비교 횟수는 많아야 p-m+1이다
- r을 순환호출의 임의의 레벨에서 분할의 모든 호출에 포함된 원소들의 총 수라할때 레벨 1에서 r = n, 레벨 2에서 r = n-1, ... 그리고 각 레벨의 분할에서 O(r)원소 비교가 이루어 진다.
- 따라서 시간복잡도는 O(n)

### 비교횟수

- 최악의 경우 O(n<sup>2</sup>)
- 평균의 경우 O(nlogn)
- 스택공간
  - 분할 후 생성된 2개의 리스트중 더 짧은 리스트를 먼저 정렬하여 필요한 스택 공간을 O(longn)으로 줄일 수 있다.


#### 퀵정렬의 반복적 버전
```java

import java.util.Stack;
void QuickSort2(int p, int q) {
    Stack<Integer> stack = new Stack<Integer>();
    do {
        while(p < q) {
            int j = Partition(a,p,q+1);
            if((j-p) < (q-j)) {
                stack.push(j+1);
                stack.push(q); q = j-1;
            }
            else {
                stack.push(p);
                stack.push(j-1); p = j+1;
            }
        };
        if(stack.isEmpty()) return;
        q = stack.popo(); p = stack.pop();
    } while(true);
}

```