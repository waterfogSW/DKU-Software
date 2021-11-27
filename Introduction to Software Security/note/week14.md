# 14주차 강의 필기 : 암호기법
## Hill cipher
문자를 하나씩 대응시켜 암호화하면 빈도수 공격에 취약하다.  
->Polygraphic substitution cipher(문자를 블럭단위로 암호화)
- 평문들의 문자를 블록단위 그룹으로 묶음
- 동일한 길이의 블록으로 암호화
- n(한 블록의 문자 개수)이 너무 작지만 않다면 문자 빈도수 공격에 강하다.

Playfiar chipher(2개 문자단위로 암호화)
- 2x2 Hill cipher = Hill 2-cipher (or N x N Hill n-cipher)
- 알파벳을 숫자로 대응시킨다
- Key 행렬, 평문 행렬을 곱한후 mod 26연산
- n의 개수를 늘려 암호화 할 수 있다
- 평문의 개수가 n단위로 나누어 지지않으면 더미 문자를 삽입하여 행렬을 만든다
- 선형대수를 사용하므로 복호화도 가능하다
  - 역행렬을 취한후 mod 26 (암호화키의 역행렬은 복호화키)
- 특수문자가 포함되면 mod의 크기를 늘린다
- (3x3)은 12개로 구성될 수 있다.

## One-time Pad(OTP)
- 키의 길이는 평문의 길이와 같거나 길어야한다
- Secret bit string s는 두 당사자(송신자, 수신자)만 알고있다
- 암호문 = (평문의 비트) XOR (키의 비트) 
- 키는 한번, 무작위로 생성되어야 한다
- 이론적으로 아주 안전하다

## Transposition cipher(전치 암호)
문자들의 순서를 바꾼다

Simple Columnar Transposition
- 테이블을 채우기 위해 의미가 없는 문자, 단어를 추가할 수 있다

Numerically-Keyed Columnar Transposition
- Key의 알파벳을 숫자로 바꾸어 컬럼 번호 순서로 암호화

Double Transpostion
- row의 순서를 바꾼후 column의 순서를 바꾼다

Route-Fence Cipher
- 레일을 번갈아 써서 첫번째 레일을 먼저 쓰고, 두번쩌 레일을 2번째...

P-Boxes
- Straight P-box
  - 1:1 순서를 바꿈 
- Compression
  - 입력보다 출력이 적게 
- Expansion
  - 입력보다 출력이 많게

## Confusion과 Diffusion, DES와 AES
Claude Shannon(클로드 새넌)
- confusion & diffusion을 잘 사용하면 암호를 깨는것은 어렵다
  - Substitution(S-P) 네트워크의 기본적 아이디어

Confusion & Diffusion
- 평문의 통계적인 특성을 숨길수 있도록 해야한다
- Confusion(혼돈) 
  - 암호문의 통계적 특성과 암호키 값과의 관계를 가능한 복잡하게 하는 기법
  - 암호키,암호문과 평문사이의 관계를 가능한한 복잡하게 만듬
  - 암호문의 각 문자들은 키의 여러 파트에 의존
  - ex) Complex substitution
- Diffusion(확산) 
  - 암호문의 통계적 특성이 평문의 통계적 특성과 무관하게 하는 기법
  - 평문의 한 비트의 위치가 변경될경우 암호문에서 여러비트의 위치가 변경됨
  - ex) Permutation
- Caesar, Vigenere 암호문이 diffusion과 conffusion의 특성이 없어 취약
- 현대 암호기법은 diffusion과 conffusion의 특성을 가짐

### 대칭키 암호기법
DES
- Confusion : 중복, 반복 패턴, 통계분석을 통해 해독하려는 시도를 막음
- Defusion : 암호문을 분석하여 평문의 반복패턴을 찾고자하는 시도를 방지

AES
- 블록의 단위, 키의 길이가 DES보다 길다
- 우수한 Confusion, Defusion성질을 사용하여 안전
  - Substitution(S-P Net, SPN)

비교

블럭 크기  
DES : 64 bit  
AES : 128 bit  
블럭의 크기가 클수록 안전하다 -> 문자의 빈도수 패턴을 상쇄

키의 길이  
DES : 56 bit  
AES : 128, 192, 256  
kerckhoffs'의 원리
- 키를 제외한 암호시스템의 모든 정보가 공개되어도 키만은 공개되어서는 안된다. 
- 키의 길이가 길수록 안전하다

Block Cipher
- 블록단위 암호화(64, 128-bit block)

Stream Cipher
- 1bit, 1byte단위로 처리
- 처리 속도가 빠르다

## Diffie-Hellman 키 교환 방식
D(k,E(k,P)) = P  
P = plain text, D = Decryption algo, E = Encryption algo

Diffie-Hellman 키 교환 방식  
중간에서 도청당하더라도 실제키를 알수 없도록 하는 방법

Alice : A = $g^a \ mod \ p$, S = $B^a \ mod \ p$  
Bob  : B = $g^b \ mod \ p$, S = $A^b \ mod \ p$

## 대칭키와 공개키(비대칭키) 암호방식
대칭키 
- 비밀키를 송,수신자가 공유
- n명이 필요한 키의 개수 = n(n-1)/2

비대칭키(공개키 암호기법)
- 공개키
- 개인키
- n명이 필요한 키의 개수 = 2n
- 송신자는 수신자의 공개키로 암호화, 수신자는 자신의 개인키로 복호화
  - 오로지 개인키로만 암호화 가능
- 키 분배문제 해결

공개키 암호기법 종류
- RSA
- ECC
- EIGamal

secrete communication
- 송신자 - 수신자의 공개키로 암호화 
- 수신자 - 수신자의 개인키로 복호화

digital signature(사용자 확인)
- 송신자 - 송신자의 개인키로 암호화
- 수신자 - 송신자의 공개키로 복호화

### 대칭키 공개키
대칭키
- block cipher(des,ces), stream cipher(rc4)
- 덜복잡하고 빠르다
- 대량의 파일을 암,복호화할때 유리
- 기밀성

공개키 
- 복잡하고 느리다
- 대칭키 배포, 전자서명, 키 암호화에 사용