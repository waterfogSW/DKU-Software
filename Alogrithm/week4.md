# 4주차

## 2장 분할정복법

### 일반적인 방법

- 문제를 부분문제로 나눈후 각문제의 해를 구해 원래 문제의 해답으로 결합
- subproblem은 원래 problem과 같은 유형 -> **순환호출**사용
- 제어 추상화 : 흐름만 구체적으로 보여줌

```java
Type DandC(P) {
    if Samm(P) return S(P); // 분할할 수 없을경우 return
    else {
        divide P into smaller instances p1,p2,...,pk (k>=1);
        apply DandC each of these subproblems;
        return Combine(DAndC(p1),...,DAndC(pk))
    }
}
```
- DandC의 계산시간
- T(n) = if(n=small) : g(n)
- T(n) = else : T(n1) + ... + T(nk) + *f*(n)
  - *f*(n) : combine하는 시간
  - g(n) , T(n1) : 각 문제를 푸는 시간

#### 순환 관계식
  - 분할 정복 알고리즘의 복잡도는 일반적으로 순환식으로 표시
  - T(n) = if(n=1) : T(1) 
  - T(n) = if(n>1) : aT(n/b) + *f*(n)
    - a와 b는 이미결정된 상수
      - n을 b개로 나누어서 a = b라 생각할수 있는데 a의 값은 알고리즘에 따라 달라짐
    - n은 b의 멱수로 가정한다.
  - 모든 1 <= n <= log<sub>2</sub>n에 대해 T(n) = 2<sup>i</sup> T(n/2<sup>i</sup>) + i*n이므로 i = log<sub>2</sub>n이면 
  - T(n) = 2<sup>log n</sup> T(n/22<sup>log n</sup>) + nlog<sub>2</sub>n = n log<sub>2</sub>n + 2n
  - 시간복잡도 : O(n log n)
  
### 이진탐색

- 오름차순으로 정렬된 배열을 src로 가정
- 이진탐색은 combine하는 부분이 없음
- 리스트의 중간 k = (n+1) / 2를 통해 두개의 부분문제로 나누어 처리

```java
int BinSRch(int a[], int i, int l, int x) {
    if(l==i) {
        if(x==a[i]) return i;
        else return -1;
    } else {
        int mid = (i+l)/2;
        if(x==a[mid]) return mid;
        else if(x<a[mid]) return BinSrch(a,i,mid-1,x);
        else return BinSrch(a,mid,l,x);
    }
}
```
#### 순환 관계식

n이 2의 멱수일 경우 
- T(n) = if(n=1) : T(1)
- T(n) = if(n>1) : T(n/2) + c

치환법에 의해 T(n) = T(n/2<sup>i</sup>) + c*log<sub>2</sub>n(1<=i<=log<sub>2</sub>n)  
따라서 T(n) = O(log n)

#### 반복적 구조를 갖는 이진 탐색(lec4-2)

```java
int BinSerach(int a[], int n, int x) {
    int low = 0, high = n-1;
    while(low <=high) {
        int mid = (low + high)/2;
        if(x < a[mid]) high = mid - 1;
        else if(x > a[mid]) low = mid + 1;
        else return mid;
    }
    return -1;
}
```
#### 반복당 한번의 비교 사용(lec4-3)

```java
int BinSearch1(int a[], int n, int x) {
    int low = 0, high = n;
    while(low < high - 1) {
        int mid = (low + high)/2;
        if(x < a[mid]) high = mid;
        else low = mid;
    }
    if(x == a[low]) return(low);
    else return -1;
}
```
- 성공적인 탐색에 대해서 BinSearch1은 BinSearch보다 원소 비교를 log n/2더 만이 한다

### 합병정렬

- 최악의 경우에 대한 복잡도는 O(nlogn)
- n개의 원소 리스트를 두개의 부분으로 분할(void MergeSort())
- 정렬된 분할을 정렬 및 합병(void Merge())
- 합병함수는 임시 배열이 필요 -> 상대적으로 다른 정렬방식에 비해 메모리 사용률이 높다

```java
void MergeSort(int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        Merge(low, mid, high);
    }
}

void Merge(int low, int mid, int high) {
    int h = low, i = low, j = mid + 1, k;
    while ((h<=mid) && (j <= high)) {
        if(a[h] <= a[j]) { b[i] = a[h]; h++}
        else {b[i] = a[j]; j++;} i++;
    } //비교해서 들어가고
    if(h>mid) for (k=j; k<=high; k++)) {
        b[i] = a[k]; i++;
    } //앞 배열에 남은숫자 임시배열로 이동
    else for (k=j; k<=mid; k++) {
        b[i] = a[k]; i++;
    } //뒷 배열에 남은숫자 임시배열로 이동
    for(k=low; k<=high; k++) a[k] = b[k];
    // 정렬된 모든숫자 임시배열에서 원래 배열로 이동
}
```

#### 개선사항

- 임시 배열이 필요하므로 레코드의 크기가 큰 경우 많은 시간을 소요
  - -> 링크값을 사용하여 레코드를 이동시키지 않고 링크 값만을 이동, 좀더 적은 공간을 사용

