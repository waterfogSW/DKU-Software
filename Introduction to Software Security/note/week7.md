# 7주차 강의 필기

## Week 7-1

| data type      | range          |
| -------------- | -------------- |
| Singed char    | -128 ~ 127     |
| Unsigned char  | 0 ~ 255        |
| Short          | -32768 ~ 32767 |
| Unsigned Short | 0 ~ 65535      |

```c

#include <stdio.h>    /* my_a.c*/
#include <stdio.h>
void main(void){
  unsigned short us = 65535;   // unsigned short MAX (16비트)
  short ss= 32767;
  unsigned char uc= 255;      // unsigned char MAX
  signed char sc= 127;
  
  printf("us = %d (%u), ss= %d (%u)\n", us, us, ss, ss);
  printf("uc= %d (%u), sc= %d (%u)\n\n", uc, uc, sc, sc);
  
  printf("us = %hd, %hu, %hhd, %hhu\n", us, us, us, us); // half decimal
  // 2의 보수 표현법에 따라 출력, 앞부분 짤림(hd = 8bit출력)
  printf("us+1= %hd, %hu, %hhd, %hhu\n", us+1, us+1, us+1, us+1); // integer overlfow
  printf("ss= %hd, %hu, %hhd, %hhu\n\n", ss, ss, ss, ss); // 
  
  printf("uc= %hd, %hu, %hhd, %hhu\n", uc, uc, uc, uc);
  printf("uc+1= %hd, %hu, %hhd, %hhu\n", uc+1, uc+1, uc+1, uc+1);
}
```

```c
#include <stdio.h>    /* hex_oct.c*/
#include <stdio.h>
void main(void){
  unsigned short us = 65535;
  short ss= 32767;
  unsigned char uc= 255;
  signed char sc= 127;
  printf("us = 0x%x (0%o), ss= 0x%x (0%o)\n\n", us, us, ss, ss);
  printf("uc= 0x%x (0%o), sc= 0x%x (0%o)\n\n", uc, uc, sc, sc);
  printf("32 = 0x%x (0%o), 16 = 0x%x (0%o)\n\n", 32, 32, 16, 16);
  printf("15 = 0x%x (0%o), 8 = 0x%x (0%o)\n", 15, 15, 8, 8);
}
```

- 자료형의 범위를 벗어나면 overflow, wraparound가 발생한다(예상하지 못한 결과가 출력)
- 자원관리, exection control에 문제 발생
- CIA를 깨트릴수 있다
  - A : 예상하지 못한 문제 발생 - 시스템 불가용(e.g while문의 index의 overflow)
  - I : overflow로 인한 데이터 손상 (은행 입금한돈 overflow)
  - C : buffer overflow를 통해 악의적인 코드를 실행하는데 실행

## Week 7-2

### Integer Range

- 1111 -> 0000 ( -1 -> 0 )
- 0111 -> 1000 ( 7 -> -8 )

- Format specifier
  - %d - decimal signed integer
  - %u - unsinged integer
  - %o - octal integer
  - %i - hexadecimal integer
  - %hd - short
  - %hu - unsigned short
  - %hhd - char
  - %hhu - unsigned char

Sign Magnitude의 경우 최상위비트가 음수를 나타냄

- 1의 보수 표현법 : 0,1 바꾸기
- 2의 보수 표현법 : 1의 보수에 1 더하기

2 + (-3) = 0010 + 1101(2의 보수) = 1111(-1)
- 음수에 대해 2의 보수를 취함

### overflow / underflow

INT_MAX = 2147483647(0x7FFFFFFF)  
INT_MIN = 0x80000000

INT_MAX + 1 -> overflow
INT_MIN - 1 -> underflow

### Prevention

```java
throw new MyoverflowExecption
```
```c
static void update_value(char op) {
    if(op == '+') {
        if (value + 1 > value) value++;
        else printf("too big!");
    } else {
        if (value - 1 < value) value--;
        else printf("too small!");
    }
}
```
- 분석단계 : 비교적 안전한 컴파일러 사용, 언어 사용
- 설계단계 : 적절한 라이브러리 사용, SafeInt, IntegerLib
- 구현단계 : 범위를 항상 확인

## 부호관련 버그
- 부호가 없는 변수가 부호가 있는 변수로 해석
- 부호가 있는 변수가 부호가 없는 변수로 해석
