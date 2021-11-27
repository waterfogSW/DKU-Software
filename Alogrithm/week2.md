# 알고리즘 필기

레포트에서 중간 기말 출제, 35 35 20 10

## 1장 알고리즘

### 알고리즘 이란?

문제에 대한 답을 찾기 위하여 계산하는 절차, 입력을 받아 출력으로 전환시켜주는 일련의 계산 절차입니다.

이 과목에서는 알고리즘의 설계 기법, 전략, 성능분석을 배웁니다.

알고리즘의 표기 방법은 여러가지 입니다.

- 자연어
- 프로그래밍 언어 : C, C++, JAVA etc
- 의사코드(Pseudo-code)

### 성능 분석과 측정

1. 공간복잡도

- 필요한 공간의 크기, 고정공간과 가변공간

2. 시간복잡도

- 프로그램이 실행될 때 필요한 실행문의 실행 횟수
- 방법: 실행문의 빈도수를 계산

3. 점근표기법

- 대략적인 수행시간이나 공간을 예측하기 위해 사용
- 빅오(worst-case), 오메가(best-case) -> 대부분의 경우 빅오표기 사용

### 빅오 표기법

big O | type
------| ----
O(1) | 상수형(constant)  
O(log n) | 로그형  v
O(n) | 선형(linear)
O(n<sup>2</sup>) | 제곱형(quadratic)
O(n<sup>3</sup>) | 입방형(cubic)
O(2<sup>n</sup>) | 지수형(exponential)

### 성능측정

- System.currentTimeMillis() 함수를 사용

```java
long start = System.currentTimeMillis();
SelectionSort(arr, n);
long stop = System.currentTimeMillis();
```

*시간이 0인경우, 여러번 반복한 후 전체 시간을 반복 횟수로 나눈다.

### 테스트 데이터 생성

- 최악의 경우 : 대규모 무작위 데이터에 대한 결과값들 중 최대값(가장 시간이 오래걸린 값)
- 평균의 경우 : 대규모 무작위 데이터에 대한 결과값들 중 평균값

## Week 2

### 자바의 개요 및 프로그래밍 환경 구축

- 운영체제에 독립적
- 자바 프로그램 - 가상머신(JVM) - 운영체제
- 소스파일(.java) -> 컴파일(jdk) -> 실행파일(.class,바이트코드) -> JVM 인터프리팅 -> 실행

자바 프로그램의 종류

- 자바 애플리케이션
- 자바 애플릿
- 자바 서블릿
- JSP
- 자바스크립트

접근 제한자

- public, private, protected
- default : 같은 패키지 내의 클래스 
- static : 모든 인스턴스에서 공유, static 변수 사용시 객체를 생성하지 않고 클래스 명과 직접 사용 가능(전역 변수 기능)
- final : 초기값으로 고정됨
- abstract : 추상 함수

MyTest.java

```java
abstract class SumExample(){ //하나라도 추상함수가 들어있으면 abstract class
    public int sum(int x, int y){
        return x+y;
    }
    abstract public void ab_method(); //몸체 선언 불가능
}

class MyTest extends SumExample{ // MyTest.java SumExample 상속
    public void ab_method(){
        int result;
        result = sum(10, 20);
        System.out.println(result);
    }
    /*main함수가 MyTest class에 속해있지만 아무런 관련이 없음(장소만 빌렸다고 생각하면 됨)*/
    public static void main(String args[]){ 
        MyTest test = new Mytest();
        test.ab_method();
        System.out.println(test.sum(30,40));
    }
}
```
this, super, 그림자 변수

- 부모 클래스와 자식 클래스에 같은 이름의 변수가 존재할 때 자식 클래스에서 그 이름을 참조하면 자식 클래스의 변수가 사용된다. 이때 부모 클래스에 있는 변수를 그림자 변수라 한다.

- super : 부모 클래스이 변수, 메소드 나타낼때 super.day, super.month
- this : 클래스 내에서 자기 자신의 변수나 메소드를 나타낼 때 사용 this.day, this.month