# 데이터베이스 기초 필기

## 7주차

### 외래키가 있는 테이블 생성
```sql
create table emp2(
  empno int,
  ename varchar(10),
  job varchar(9),
  deptno decimal(2,0),
  primary key (empno),
  foreign key (deptno) references dept(deptno)
    on delete restrinct on update cascade
)
```
-> dept테이블이 먼저 정의된 후 emp2테이블을 생성할 수 있음.

### varchar vs char

varchar
- 데이터 길이 가변

char
- 데이터 길이 고정
- 데이터 길이가 항상 일정할때(e.g 학번)주로 사용

### ALTER
테이블의 구조를 변경할때
```SQL
ALTER TABLE EXAMPLE ADD COLUMN HOMPAGE VARCHAR(30);
ALTER TABLE EXAMPLE CHANGE COLUMN HOMPAGE HOME VARCHAR(50);
ALTER TABLE EXAMPLE DROP COLUMN HOME
ALTER TABLE EXAMPLE RENAME TO NEW_EXAMPLE
```

### DROP
```SQL
DROP TABLE NEW_EXAMPLE;
```

### INSERT UPDATE DELETE

- INSERT
```SQL
INSERT INTO DEPT (LOC, DNAME, DEPTNO)
VALUES ('YANJI','MANUFACTURE',5);
```
```SQL
INSERT INTO DEPT
VALUES (5,'YANJI','MANUFACTURE');
```
일부 컬럼만 입력하는 경우
```SQL
INSERT INTO DEPT (DEPTNO, DNAME)
VALUES (5, 'MANUFACTURE');
```
`LOC`컬럼이 `NULL`을 허용할때 입력 가능하다.

- UPDATE
```SQL
UPDATE EMP
SET SAL = SAL * 1.1
WHERE JOB = 'ENGINEER';
```
- DELETE
```SQL
DELETE FROM EMP
WHERE JOB = 'WORKER'
```