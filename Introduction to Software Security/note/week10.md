# 10주차 강의 필기

## Buffer Overflow(CWE-119)
- 버퍼의 경계를 넘어서서 내용을 쓰는것
- 버퍼의 경계 바깥의 내용을 읽는것
- 사람들마다 사용하는 용어의 뜻이 다르기 때문에 Improper restriction of operations within the bounds of a memory buffer라고 하는것이 더 정확하다

결과
- CIA를 깨뜨릴 수 있다.

## 단계별 취약점 완화 방법
Requirements
- Java, Perl과 같은 자체적으로 메모리를 관리하는 언어를 사용
Build & Compilation
- 컴파일시 buffer overflow를 탐지할 수 있도록 설정하라
  - MS visual studio/GS flag, Fedora/Red Hat= FORTYFY SOURCE GCC flag, StackGuard, ProPolice
Implementation
- Double check, 버퍼가 의도한 대로만 사용되고있는지 이중으로 체크
- `strncpy()`와 같이 안전한 라이브러리 함수를 사용
Operation
- ASLR, Position-Independent Executables와 같은 기법이 적용된 환경에서 실행
- Data Execution Proctection(NX) : code segment에 있는 코드만 실행
  - 임의의 코드가 data seg, stack seg에 들어가 수행되는것을 방지