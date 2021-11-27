# 데이터베이스 기초 필기

## Week 4

### SQL

- 관계형 데이터베이스의 장점 : 사용자들이 쉽게 사용할 수 있는 SQL언어 제공
- 표준화(대부분의 DBMS 제품에 동일하게 적용)
- 비절차적 언어
  - DBMS의 처리방식을 명시할 필요가 없음

### SQL 개요

- 두가지 사용방식
  - 대화식 SQL : 사용자가 직접 입력
  - 내장 SQL : C, JAVA에 포함되어져서 사용되는 방식
- 명령어
  - DDL(데이터 정의어)
    - CREATE
    - DROP
  - DML(데이터 조작어)
    - INSERT
    - UPDATE
    - DELETE
  - QL(질의어)
    - SELECT

### SELECT

- select <컬럼이름>
- from <테이블 이름>
- where <검색조건>; -> 없으면 모든행을 의미
```sql
select ename, sal --이름과 급여
from emp --emp테이블에서
where empno = 7788; --사원번호가 7778인
```

### 실습

NULL의 값 연산자말고 is, is not 으로 확인해야 함
```sql
select ENAME
FROM EMP
WHERE MGR IS NULL;
```
컬럼 이름 바꿔서 출력
```SQL
select COUNT(*) AS NUM_OF_EMP
FROM EMP
WHERE JOB = 'CLERK';
```

- BETWEEN
- IN, NOT IN
- LIKE
