# 3주차

## 기본적인 자료구조

### 1. 연결리스트

순서리스트를 연결 포인터를 사용하여 표현하는 것

- 노드는 data부분, link부분으로 구성되며 link필드를 따라 다음 노드 정의

#### Generic Class

- 다양한 종류의 데이터를 처리할수 있는 방법으로 C++의 템플릿 개념
- 자바버전 1.5부터 추가됨
- 2가지 방법
  - 타입 매개변수 \<Type\> 을 선언
  - 다형성을 이용하여 모든 종류의 클래스를 받을 수 있는 Object 클래스로 선언

노드 클래스

```java
public class ChainNode <Type> {
    Type element;
    ChainNode <Type> next;

    // package visible constructors
    ChainNode() {}

    ChainNode(Type element) {
        This.element = element;
    }

    ChainNode(Type element, ChainNode <Type> next) {
        This.element = element;
        this.next = next;
    }
}
```

체인 클래스

```java
public class Chain <Type2>{
    protected CahinNode<Type2> firstNode;
    protected int size;
    public Chain(int initialCapacity);
    public Chain();

    public boolean isEmpty();
    public int size();
    void checkIndex(int index);
    public Type2 get(int index);
    public int indexOf(Type the Element);
    public Type2 remove(int index);
    public void add(int index, Type2 the Element);
    
    public String toString();
    /*toString()함수는 모든 클래스가 상속받고 있지만 연결리스트의경우
    다음 노드를 링크를 통해 따라가야 하므로 첫노드만 출력하게됨.
    따라서 toString을 새로 정의*/
}
```

### 2. 연결 스택과 큐

스택과 큐를 연결 리스트로 구현하는 것

연결 스택 클래스

```java
public class stack <Type2>{
    protected ChainNode<type2> topNode;
    public boolean empty();
    public Type2 peek();
    public void push(Type2 the Object);
    public Type2 pop();
}
```

연결 큐 클래스

```java
public class stack <Type2>{
    protected ChainNode<type2> front;
    protected ChainNode<type2> rear;
    public boolean empty();
    public Type2 getFrontElement();
    public Type2 getRearElement();
    public void put(Type2 the Object);
    public Type2 remove();
}
```

### 3. 히프

- 우선 순위 큐
  - 삽입은 일반적인 큐와 같으나 삭제는 우선순위가 가장 높은 것이 먼저 삭제
  - 최대(최소) 히프는 최대(최소) 우선순위 큐를 구현하는데 사용된다.
- 최대 히프의 정의
  - 최대 트리 : 각 노드의 키값이 그 자식의 키값보다 작지 않은 트리
  - 최소 트리 : 각 노드의 키값이 그 자식의 키값보다 크지 않은 트리
  - 최대 히프 : 최대 트리 & 완전 이진 트리
  - 최소 히프 : 최소 트리 & 완전 이진 트리

최대 히프 클래스

```java
public class MaxHeap {
    Comparable [] heap; // 히프를 위한 일차원 배열
    int size;
    public boolean isEmpty();
    public int size();
    public Comparable getMax();
    public void put(Comparable the Object);
    public Comparable removeMax();
}
```

void put()

```java
public void put(Comparable theElement) {
    //increase array size if necessary
    if(size == heap.length -1)
        System.out.println("Heap is full. No insertion.");
    else{
        //find place for theElement
        //currnetNode starts at new leaf and moves up tree
        int currentNode = ++size;
        while (currnetNode != 1 && heap[currentNode/2].compareTo(theElement) < 0){
            //cannot put the Element in heap[currentNode]
            heap[currentNode] = heap[currentNode/2];
            currentNode /= 2;
        }
        heap[currentNode] = theElement;
    }
}
```

Comparable

- 템플릿 개념으로 사용, 어떤 클래스의 객체를 사용하더라도 비교할수 있도록
(e.g Float, Integer과 같은 wrapper class)

compareTo 메소드 - A.compareTo(B)

- 2개 객체를 비교 int형 값을 반환하는 메소드
- A == B : 0
- A > B : 양수 반환
- A < B : 음수 반환

### 4. 이진탐색트리

임의의 한노드를 삽입, 삭제, 탐색하는데 유리

- 모든 원소는 키를 가지며 동일한 키가 없다
- 왼쪽 서브트리에 있는 키들은 루트의 키값보다 작다
- 오른쪽 서브트리에 있는 키들은 루트의 키값보다 크다
- 왼쪽, 오른쪽 서브트리도 이진탐색트리이다

#### 탐색

key = root : found
key < root : left subtree
key > root : right subtree

#### 삽입

동일한 키값을 가진 원소가 있는가 확인 후, 없으면 그지점에 삽입  
항상 단말 노드에 삽입
시간복잡도 O(h)

#### 삭제

- 리프노드의 삭제 : 부모의 자식 필드에 null을 삽입
- 하나의 자식을 갖는 비단말 노드의 삭제
  - 삭제된 노드의 자식을 삭제된 노드의 자리에 대체
- 두개의 자식을 갖는 비단말 노드
  - 왼쪽 서브트리에서 가장 큰노드로 대체
  - 오른쪽 서브트리에서 가장 작은 노드로 대체

#### 이진탐색트리 클래스

```java
public class BinaryTreeNode{
    Object element; //object의 자식클래스는 모두 element필드에 저장될 수 있음
    BinaryTreeNode leftChild;
    BinaryTreeNode rightChild;
    public BinaryTreeNode() {}
    public BinaryTreeNode(Object theElement) {
        element = theElement;
    }
    public BinaryTreeNode(Object theElement,
                    BinaryTreeNode theleftChild,
                    BinaryTreeNode therightChild){
        element = theElement;
        leftChild = theleftChild;
        rightChild = therightChild;
    }
}
```

이진 탐색 클래스

```java
public classBinarySearchTree{
    protected BinaryTreeNode root; //이진탐색트릐 루트

    public BinaryTreeNode get(Object theKey); // 탐색
    public Object put(Object theKey); // 삽입
    public Object remove(Object theKey); // 삭제
    public void ascend(); //중위순회 
;
}
```

탐색

```java
public BinaryTreeNode get(Object theKey){
    BinaryTreeNode p = root;
    Comparable searchKey = (Comparable)theKey;
    while(p!=null){
        if(searchKey.compareTo(p.element) < 0)
            p = p.leftChild
        else{
            if(searchKey.compareTo(p.element) > 0)
                p = p.rightChild;
            else
                return p;
        }
    }
    return null;
}
```