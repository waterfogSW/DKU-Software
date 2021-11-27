
# 오픈소스 활용

## week 1-1 강의 개요

매주 복습한것은 ipython notebook 사용
-> pdf로 작성하여 보냄
이메일 제출이 될듯

팀플???

---

## Week 2

각 프로그래밍 언어의 공통된 역할을 하는것들이 있기때문에 python사용에 무방

최근 10년 이내에 가장 많이 사용되고 있는 언어 python, Effective python은 효과적인 표현방법을 정리해놓은 책.

### jupyter lab 사용

```python
import sys
print(sys.version_info)
print(sys.version)
```

### [Item 2]PEP 8 스타일 가이드

가용성과 코드에 대한 표현, 가독성같은 스타일에 대한 이야기

#### Whitespace

- indentation - 4 spaces, tab보단 space선호
- 각 행은 79개의 문자 이하로 사용
- 함수나 클래스는 2개의 blank line으로 나뉘어야 함
- class와 methods는 한개의 blank line으로 나뉘어야 함
- white space
- = 연산자의 앞뒤에 공백
- 함수의 입력 매개변수에 대해 데이터 타입을 명시하는것이 좋음.

```python
pi : float = 3.142
def circumference(radius : float) -> float:
    return 2 * pi *radius
```

#### Naming

- 함수, 변수, 속성은 소문자 + _ 포맷
- protected 인스턴스의 경우 맨앞에 _ 를 사용하는 것이 좋다
- private 인스턴스의 경우 맨앞에 __ 를 사용하는 것이 좋다(2개)
- 클래스와 예외는 대문자로 
- 모듈 레벨의 상수는 모두 대문자.
- 인스턴스 메소드는 self 첫번째 파라미터를 사용해야함
- 클래스 자체에 대한 메소드는 cls

#### Expressions and statements

- 코드가 한 라인이 넘어가면 백슬래시(\)와 인덴트를 통해 구분

#### Imports

**중요**

- standard library module -> third-party module -> custom module 순으로 import하는것을 권고!

### [Item 3] Know the differences between bytes and str

Two string type

1. Binary encoding(bytes)ASCII
2. Text encoding(str)

assert는 디버깅할때 사용 만족하지않으면 에러 발생

서로다른 데이터 형에 대한 연산은 class로 정의할 수 있음.

바이트 인코딩, 텍스트 인코딩