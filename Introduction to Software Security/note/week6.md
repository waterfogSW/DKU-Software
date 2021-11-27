# 6주차 강의 필기

## Week 6-1

### Think Like Trudy
- 모의 해킹 수요 급증
  - 보안회사에 소속된 화이트 해커가 고객사에 파견돼 모의 해킹 업무 수행
  - 자사 제품 및 서비스 취약점을 신고하면 포상금을 주는 기업도 늘어나고 있다.
  - 실제 해커들과 동일한 기술, 방법으로 해킹해 취약점을 찾는다.
- 앨런 튜링, 오픈 SSL 취약점, 크롬 HTTPS
  - Open SSL이라는 암호화 소프트웨어 라이브러리에서 고위험군 취약점 발견
  - 크롬 4월 중순부터 https강제적용
- 악성앱 이용한 스마트폰 해킹 공포
  - 스마트폰 대상 악성앱 악성코드 증가
  - 배터리광탈, 데이터 사용량 급증, 화면 이동 변경시 악성코드 감염 의심
  - 스마트폰에서 탈취한 개인정보 바탕으로 대부분 2차피해 발생
-  금융보안원 - 모의해킹, 악성코드분석 분야등 2021년도 신입직원 채용

### 소프트웨어 취약점

#### 소프트웨어의 종류
- System Software : OS, compiler, loader
- Business software : Payroll, accounting
- 캐드, 일기예보
- 페이스북, 구글 크롬
- 임베디드 소프트웨어
- 모바일 앱

#### 소프트웨어 보안의 중요성
- 암호알고리즘, 접근제어, 네트워크 프로토콜
  - 소프트웨어로 구현된다.
- 만약 소프트웨어가 공격대상이 된다면, 보안이 깨질것
- 소프트웨어가 취약하면 보안이 흔들린다
  - 소프트웨어 취약점
  - 버그, flaw, defect weakness

### 소프트웨어 위기
- 프로젝트의 예산, 시간
- 소프트웨어의 비효율성, 퀄리티, 요구사항을 만족시키지 않음
- 유지보수의 어려움
- 소프트웨어는 실행파일만 공개하기때문에 내부 문제를 알수 없다.
소프트웨어 공학은 역사가 짧기에 아직 미성숙하다.

### 소프트웨어 버그, 결함, 취약점의 종류

- Bug
  - Improper Initialization
  - Side Effects (ex, 대입연산, 비교연산의 잘못된 사용)
    - `if(foo == 12 || (bar=13)) baz == 12;`
  - Scoping : 동일한 이름의 변수를 지역, 전역에 선언하여 발생
  - Control flow(1) : 세미콜론의 위치에 따라 반복문이 의도치 않은 방향으로 수행될 수 있다.
  - Control flow(2) : goto의 중복 사용으로 조건문에 해당하지 않는데도 goto해버리는 경우가 발생
  - NULL 포인터 참조
  
```c
  ...
if((err = someerror) != 0)
  goto fail;
  goto fail;
  ...
fail:
  return err;
```
goto의 중복 사용으로 조건문에 해당하지 않는데도 goto해버리는 경우가 발생
```c
int main() {
    double x = 0.1;
    while (x != 1.1) {
        x = x + 0.1;
        printf("x = %f\n", x);
    }
}
```
실수 표현방식은 오차가 있기 때문에 무한루프

```c
int *ptr = NULL;
printf("Value of ptr : %d\n", ptr);

int *p = 0;
*p = 1;
```
segmentation fault 발생, 잘못된 방식으로 주소 할당

```c
int length;
    char *buff;

    scanf("%d", &length);
    buff = (char*)malloc(length+1);
    strcpy(buff,"hello world!, welcome!");
```
충분한 길이의 공간 할당이 이루어 지지 않으면, 기대값이 출력되지 않음

```c
void Pointer(int *ptr) {
    *ptr = *ptr + 5;
}

main() {
    int num = 10;
    Pointer(&num);
    Pointer(NULL);
}
```
NULL값으로 인한 segmentation fault 발생

```c
node *find(node **curr,int val) {
    while(*curr != NULL) {
        if(*curr->val == val) return *curr;
        else *curr = *curr->next;
    }
}
```
arrow operator `->`, dot operator `.`의 우선순위가 `*`보다 높기 때문에 (*curr)->val 로 사용해야 한다.

```c
char cresult, c1, c2, c3;
c1 = 100; c2 = 90; c3 = -120;
cresult = c1 + c2 + c3;
printf("%c, %d, %c, %d\n", cresult, cresult, c3, c3);
```
각 자료형별 범위에 유의(ex char, unsigned char)

### Bad Software

- Nasa Mars Lander(화성 기후궤도 탐사선)
- Denver airport(공항 물ㄹ시스템 버그)
  - 11개월간 공항 운항 연기
- MV-22 Osprey
  - 소프트웨어 결함으로 시험비행 사고
- 마취기의 결함 -> 의료사고
- 패트리어트 방어시스템의 버그, 28명 사망
이러한 버그를 방지하는거을 bug hunting tasks라고 함

### Bug Bounty

CWE - Common Weakness Enumerations
1. Cross site scripting
2. Out of bounds write
```c
int returnChunckSize(void *) {
    if(chunck info is unvalid) return -1;
}
int main() {
    ...
    memcpy(destBuf, srcBuf,(returnChunckSize(destBuf) -1));
    ...
}
```
`size_t`는 `unsigned int`이므로 음수가 되면 엄청나게 큰수를 반환

- 국내 SW, 잘 알려진 보안 취약점도 대응 못해
  - XSS, SQL등 익숙한 유형이 다수
- Bug Bounty(보안취약점 포상제)
  - 해킹피해를 사전에 예방하기 위해, 보안취약점에 포상금을 걸고 제보를 받는 버그 바운티 제도


CWE의 25개 취약점을 숙지할 필요가 있다.

## Integer Overflow/Underflow

### Top 10 IT disasters of All Time
1. Faulty soviet early warning system nearly caueses WW3
- 조기경보 시스템의 오류로 햇빛을 미사일로 오인, 소프트웨어의 오류로 밝혀짐
2. AT&T
- 해커의 공격이 아니라, 복잡한 소프트웨어 업그레이드 중에 발생한 코드 오류
3. Arian 5
- 64비트 숫자를 16비트 공간에 채우면서 유발된 overflow 오류
4. Airbus A380, incompatible software issues
5. Mars climate observer metric problem
- 화성의 기후궤도 탐사선의 불시착, 단위의 차이
...

### Integer Ranges

32비트
```c
#include <stdio.h>
int main() {
	int i;
	double d;
	char *cp;
	short *sp;
	printf("size of char  		: %hd byte\n", sizeof(char));
	printf("size of short 		: %hu byte\n", sizeof(short)); // hu : half unsiend
	printf("size of int 		: %d byte\n", sizeof(int));
	printf("size of long 		: %u byte\n", sizeof(long));
	printf("size of float 		: %u byte\n", sizeof(float));
	printf("size of double		: %u byte\n", sizeof(double));

	printf("size of (char*)		: %u byte\n", sizeof(char*));
	printf("size of (short*)	: %u byte\n", sizeof(short*));
	printf("size of (double*)	: %u byte\n", sizeof(double*));

	printf("size of i 		: %u byte\n", sizeof(i));
	printf("size of d 		: %u byte\n", sizeof(d));
	printf("size of cp 		: %u byte\n", sizeof(cp));
	printf("size of sp 		: %u byte\n", sizeof(sp));
}

```
32비트 컴파일 결과
```
size of char            : 1 byte
size of short           : 2 byte
size of int             : 4 byte
size of long            : 4 byte
size of float           : 4 byte
size of double          : 8 byte
size of (char*)         : 4 byte
size of (short*)        : 4 byte
size of (double*)       : 4 byte
size of i               : 4 byte
size of d               : 8 byte
size of cp              : 4 byte
size of sp              : 4 byte
```
64비트
```c
#include <stdio.h>
int main() {
	int i;
	double d;
	char *cp;
	short *sp;
	printf("size of char  		: %u byte\n", sizeof(char));
	printf("size of short 		: %d byte\n", sizeof(short)); // hu : half unsiend
	printf("size of int 		: %ld byte\n", sizeof(int));
	printf("size of long 		: %lu byte\n", sizeof(long));
	printf("size of float 		: %lu byte\n", sizeof(float));
	printf("size of double		: %lu byte\n", sizeof(double));

	printf("size of (char*)		: %lu byte\n", sizeof(char*));
	printf("size of (short*)	: %lu byte\n", sizeof(short*));
	printf("size of (double*)	: %lu byte\n", sizeof(double*));

	printf("size of i 		: %lu byte\n", sizeof(i));
	printf("size of d 		: %lu byte\n", sizeof(d));
	printf("size of cp 		: %lu byte\n", sizeof(cp));
	printf("size of sp 		: %lu byte\n", sizeof(sp));
}

```

64비트 컴파일 결과
```
size of char            : 1 byte
size of short           : 2 byte
size of int             : 4 byte
size of long            : 8 byte
size of float           : 4 byte
size of double          : 8 byte
size of (char*)         : 8 byte
size of (short*)        : 8 byte
size of (double*)       : 8 byte
size of i               : 4 byte
size of d               : 8 byte
size of cp              : 8 byte
size of sp              : 8 byte
```

서식  | 설명
------|------
%d    | decimal signed integer
%u    | unsigned integer
%i    | any integer(decimal/octal/hexadecimal) 
%hd   | short
%hu   | unsigned short
%hhd  | char
%hhu  | unsigned char
%ld   | decimal signed long
%lu   | unsigned long
%o    | octal integer
%x    | hexadecimal integer