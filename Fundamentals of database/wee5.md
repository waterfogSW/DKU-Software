# 데이터베이스 기초 필기

## Week 5

### 정렬

- asc : 오름차순, desc : 내림차순
- group by 뒤에 올수있는것은 group by에 서술된 컬럼이름, avg, sum괴 깉은집계함수 
- order by 를 group by와 함께 사용하는 경우 order by 다음에 올 수 있는것은 select에 있는 컬럼이름
- where : 각 행에 적용되는 조건을 지정
- havaing : 그룹에 적용되는 조건을 지정

### 기본키와 외래키

- 무결성 규칙
  - DBMS에게 실세계의 제약조건을 알리기 위함
  - 데이터 값의 결정 -> 현실의 반영
  - 데이터베이스의 정의는 무결성 규칙의 포함을 필요로 한다.
- Example : 부서-사원 데이터베이스를 위한 규칙 목록
  - 부서 번호의 형식 : nn
  - 부서의 위치는 모두 미국내에 있어야 한다
    -  DBMS가 모든 미국내의 도시의 이름을 알아야하기 때문에 구현하기 어렵다. 
  - 입사일자 : 1980-01-01~ 현재일자 이내여야 한다
  - 사장은 mgr정보가 null이어야 한다

=> 무결성 규칙은 테이블을 생성할 때 지정해 준다.
 어떤 무결성 규칙은 구현할 수 없는 것도 있다(미국내에 있어야함).

- 데이터 베이스의 제한성 규칙에 부가하여 두개의 일반적인 무결성 규칙을 갖는다.
  - 후보키
  - 외래키
  
#### 1. 후보키(중복성 검사)
- 가장 기본적인 무결성 규칙
  - 테이블에 튜플이 입력될 때 중복이 없어야 한다.
  - 새로운 튜플 입력시 중복성 검사를 해야 한다.
  - 모든 컬럼의 값을 비교해 볼수 없으니, 기준이 되는 몇개 또는 하나의 컬럼만 보고 중복성 여부를 판단 -> 후보키
  - 후보키 : 중복성 여부를 판단할 수 있는 컬럼
    - 주민번호, 전화번호, 고객번호 etc..
    - 기본키 : 테이블에 대한 유일 식별자
    - 대체키 : 후보키 중 기본키로 지정되지 않은 다른 키

테이블은 적어도 하나의 후보키를 가지고 있다.
- 테이블은 중복된 튜플을 갖지 않음
- 모든 컬럼 조합이 후보키가 되는 경우도 존재

Note
- 한테이블은 하나 이상의 후보키를 가질 수 있다.
- 단순 후보키 vs 복합 후보키(여러후보키를 묶어서)

어느것이 기본키로 선택되는가?
- 기준은 없다
- 단순키와 복합키가 있다면 단순키를 기본키로 선택

### 2. 외래키

- R2라는 기본 테이블에서 R2의 속성 집합의 부분집합 중에서 다음을 만족시키는 FK를 R2의 외래키라고 한다
  - CK를 후보키로 갖는  기본 테이블 R1이 이미 존재하고 있어야 한다.
  - 주어진 어느 시간이라도 R2의 현재값의 각 FK의 값은 R1의 현재값의 어떠한 튜플인 CK의 값과 같아야 한다.
- 기본키의 일부가 외래키인 경우도 있다
- 자식테이블의 외래키는 부모 테이블의 기본키를 참조하도록 되어있다.

자기참조
- 외래키 정의 관계에 있는 테이블 R1, R2가 동일한 테이블일때 

### 참조 무결성 규칙
- 데이터베이스는 부합되지 않는 어떠한 외래키 값도 포함해서는 안된다.
- 만일 B가 A를 참조한다면, A는 반드시 존재해야 한다.
  - 외래키를 지원하는 것과 참조 무결성을 지원하는 것은 같은 의미
  - 무결성이 깨지는 경우 : 외래키의 값이 R1테이블에 실제로 존재하지 않을때 
  - 따라서 DBMS는 새로운 데이터를 넣으면 외래키의 값이 실제로 존재하는지 확인

참조 무결성의 수행
- 옳지 못한 연산이 수행될 경우 시스템이 거부
- 부가적인 보상 연산을 통해 시스템 무결성 유지

데이터 베이스 설계자는
- 어떤 연산이 거부되어야 하는지 정의
- 어떤 보상연산이 수행되어야 하는지를 정의

외래키 참조의 대상이 되는 후보키를 갱신할때
- 제한 : 부합되는 후보키가 없을 경우에만 삭제 -> 주로사용하는 방법
- 연쇄 : 부합되는 모든 후보키도 함께 갱신
- Nullfy : 부서배치가 안되었을때 NULL
- Nothing : 무결성이 깨진상태로 놔두는것 -> 잘 쓰지 않음

NULL
- 부재정보를 다루는 기본적인 방법
- 생일이 알려져 있지 않음
- 자료형이 없다, 공백과 0과는 다름

### 개체 무결성 규칙
- 기본테이블의 기본키의 어떤 성분도 널일수 없다.
  - 기본 테이블은 현실세계의 객체들에 해당.
  - 식별되지 않는 개체는 존재하지 않는다

### 조인 연산
두개이상의 테이블을 연결하여 하나의 테이블처럼 보이게 하는 연산

어디서 왔는지 알수 있는 컬럼은 테이블 이름 명시안해도 됨
```sql
SELECT EMPID,ENMAE, EMP.DEPTNO, DNAME
FROM EMP, DEPT
WHERE EMP.DEPTNO = DEPT.DEPTNO
```

테이블 별칭 지정
```sql
SELECT EMPID,ENMAE, E.DEPTNO, DNAME
FROM EMP E, DEPT D
WHERE EMP.DEPTNO = DEPT.DEPTNO
```
