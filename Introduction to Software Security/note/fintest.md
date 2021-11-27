# 단기 진행과제 정리

## 대용량의 파일을 암호화하여 전송하고자 할때
보안성을 고려한다면 공개키 암호기법을 사용해야 하지만, 영화와 같은 대용량의 파일을 전송하는데 대칭키 암호기법에 비해 불리합니다.
대칭키 암호기법을 사용하되 대칭키를 공개키 암호기법을 통해 전송하여 대칭키를 송신자와 수신자가 공유하고, 대칭키 암호기법으로 전송합니다.

### 암호화 알고리즘별 특징

#### 대칭키 암호기법
Diffie hellman
- 대칭키 암호화 기법에 사용되며 이산대수라는 수학적 특징을 사용합니다
- 중간에서 도청당하더라도 실제키를 알수 없도록 하는 방법입니다

DES
- 블록단위(64bit)암호화 기법
- Confusion : 중복, 반복 패턴, 통계분석을 통해 해독하려는 시도를 막음
- Defusion : 암호문을 분석하여 평문의 반복패턴을 찾고자하는 시도를 방지

AES
- 블록의 단위, 키의 길이(128bit)가 DES보다 길다
- 우수한 Confusion, Defusion성질을 사용하여 안전
  - Substitution(S-P Net, SPN)

SEED
- 블록단위 암호기법으로 KISA에의해 개발된 암호알고리즘
- 128bit단위로 암호화하여 DES보다 키의 길이가 길기 때문에 더 안전합니다

#### 공개키 암호기법
RSA
- 공개키 암호화 기법에서 사용되며 소인수분해라는 수학적 특징을 사용합니다.

# 9주차 강의 필기

*long int*는 4byte일수도 있고, 8Byte일수도 있다.

스택 보호기법 적용(O)
```sh
gcc -m32 -fstack-protector -o cmu1 cmu.c
./cmu1
```
stack grows **upward**

스택 보호기법 적용(X) - 높은주소에서 낮은주소로 성장
```sh
gcc -m32 -fno-stack-protector -o cmu0 cmu.c
./cmu0
```
stack grows **downward**

64bit compile했을때 32bit와 달리 배열간 간격(12byte)이 있었다.
$\rArr$ 주소체계에 따라 메모리 할당 방식이 다르다.

## Buffer Overflow
```c
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int canary = 20;
    char buf[22];

    strcpy(buf,argv[1]);

    if(canary == 0x08010205)
        printf("Sucess\n");
    return 0;
}
```

```sh
./bo2 `perl -e 'print "A"x22, "\x05\x02\x01\x08"'`
```


## Vulnerable C Program
```c
#define MAX_LEN 10
int unsafe(char *a, char *b) {
    char t[MAX_LEN];
    strcpy(t,a);            // t에 a의 값 복사
    strcat(t,b);            // t에 b의 내용 concate
    return strcmp(t,"abc"); // return값이 조작될 수 있다
}
```

```c
strcpy(dst, source);            // overflow 취약점이 있다
strncpy(dst,src,sizeof(dst));   // overflow가 발생하지 않지만, 마지막의 null문자가 잘릴 수 있어 string의 끝을 파악하기 힘들다
strlcpy(dst,src,sizeof(dst))    // 마지막에 null문자를 삽입하여 정보는 손실될 수 있으나, 보안성이 좋아진다.
```

## Another Example

gets(buf) $\rarr$ fgets(buf,size,stdin)
: 입력받을 버퍼의 크기를 정하여 사용

strcmp(buf, PASSWORD) $\rarr$ strncmp(buf,PASSWORD,PASSWORD_SZ)
: 비교할 크기를 정하여 사용

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

# 11주차 강의 필기

## 난독화

- 프로그램 변환의 일종, 코드를 읽기 어렵게 함으로써 역공학을 방지
- 주로 java언어로 개발된 프로그램에 많이 사용
  - java언어로 개발된 프로그램은 쉽게 디컴파일되는 특성 때문
  - 안드로이드 앱도 주로 java언어로 개발되므로 난독화를 사용
- 일반 개발자들은 소프트웨어의 지적 재산권을 보호하기 위해 난독화 사용
- 악성 앱 개발자는 멀웨어 탐지 시스템을 회피하기 위해 난독화 사용

## 난독화 예시
- Identifier renaming(식별자 이름 변경)
  - 패키지, 클래스, 필드, 메소드, 변수 등의 이름을 무의미하게 변경, 이름을 통한 기능 유추 방지
- Encryption(암호화)
  - 문자열이나 데이터, 라이브러리 등을 암호화하여 저장하고, 런타임에 복호화
- Control-flow obfuscation(제어 흐름 난독화)
  - Dummy code삽입, 반복문 변경, 예외처리문(try-catch)삽입, 함수 호출 관계 변경 등을 통해 프로그램 제어흐름을 복잡하게 변경
- Reflection obfuscation(Reflection 난독화)
  - java의 reflection기능을 활용하여 직접적인 메소드 호출을 숨김
  - 클래스 이름을 문자열로 사용해 클래스 로딩, 새 인스턴스 생성, 접근하고자 하는 메소드 호출

## 과제 

### APK구조 
- APK : Android Application Package의 약자
- ZIP아카이브 포맷으로 java플랫폼의 jar포맷 그래도 이용
- APK구조
  - assets : 용량이 큰 파일
  - META-INF : APK서명 정보
  - res : 용량이 작은 파일
  - classes.dex : 안드로이드 앱이 안드로이드 디바이스에서 구동되기 위한 실행파일
  - AndroidManifest.xml : 안드로이드 설정 파일(패키지이름, 권한, 속성 등을 명시)

### 난독화 도구
- Obfuscapk
  - 2020년 1월에 논문으로 발표된 안드로이드 앱 무료 난독화 도구
  - **Aonzo, S., Georgiu, G. C., Verderame, L., & Merlo, A. (2020). Obfuscapk: An open-source black-box obfuscation tool for Android apps.SoftwareX,11, 100403**
  - Trivial과 non-Trivial techniques로 구분하여 여러가지 난독화 기능 제공
- 안드로이드 앱 분석 도구
  - Jadx : dex to java디컴파일러
  - **Apktool**(조교 권장) : dex to smali
  - AndroGuard
  - Dexdump
  - etc(IDA, IEB)
- VirusTotal

## 과제 수행

### obfuscapk : 난독화 도구
```sh
~/Desktop/HW_Obfuscation/Obfuscapk$ // 경로
source venv/bin/activate // 가상환경 활성화(obfuscapk)
cd src
python3 -m obfuscapk.cli - o ClassRename(난독화 옵션) ../../sample_apps/app_1.apk(난독화 대상) 
```
obfuscapk

### Apktool : 파일폴더 패키징
```sh
~/Desktop/HW_Obfuscation/sample_apps/obfuscation_working_dir$ // 경로
apktool b app_1/(폴더명) -o app_1_obfuscated.apk(패키지 파일이름)
```

### Androguard
```sh
~/Desktop/HW_Obfuscation/androguard$ // 경로
source venv-androguard/bin/activate
androguard analyze
a,d,dx = AnalyzeAPK("/home/security/Desktop/HW_Obfuscation/sample_apps/app_1.apk")
a.get_permissions()
a.get_activities()
...
```

### dexdump
```sh
dexdump app_1.apk
dexdump -g app_1.apk (control flow)
```
code난독화 기법 실험시 control flow그래프를 참고하면 가점

---

## Reverse Engineering(Reversing)

### Forward Engineering vs Reverse Engineering
- 구현이 끝난 소프트웨어를 분석하여 설계방식, 반영된 요구사항을 파악
- Forward Engineering
  - Android Compilation
- Reverse Engineering

### Android Compilation Process(Forward)
$source code\xRightarrow[\text{JAVAC}]{compile} Java Bytecode \xRightarrow[\text{PROGUARD}]{obfuscating} minimizedByte code\xRightarrow[\text{DEX}]{recompilation} DexBytecode$

Dex : 안드로이드 스마트폰의 바이트 코드(Dalvik byte code)

### Android De-compilation Process(Reverse)
$.APK \xRightarrow[\text{apk\_tool}]{de-compile} .samli,assets,mete-info, \dots\xRightarrow[\text{.smail to java}]{} Java Source Code$ 

### Reverse Engineering(Anti-reversing)
- 소프트웨어 엔지니어 관점에서 소프트웨어를 분석하고 디버깅하는것
- 악성코드 분석자들은 역공학을 기반으로 함

Software reverse engineering(SRE)
- 소프트웨어를 분석하여 내부구조를 파악
- 컴퓨터와 개발에 대한 이해가 필요
Binary reverse engineering
- 소스코드가 없을때 사용하는 역공학 기법
- 자바 플렛폼의 바이너리를 디컴파일하는것(예)

역공학 하는 이유?
- 취약점 분석
- 바이너리 레벨에서 패치, 보완
- 패스워드와 같은 민감한 정보를 빼내기 윟
- 프로토콜을 분석하기 위해
- 소프트웨어 보호기법을 우회하기 위해

### Reversing Applications
- Security related reversing
  - 악의적인 소프트웨어 파악
  - 암호알고리즘 역공학
    - 암호화 제품의 보안성을 평가하기위해 
  - DRM(Digital Rights Management) - 디지털 콘텐츠 권리 관리
    - 저작권있는 파일의 copy protection기법을 우회하기 위해
- Development-related reversing
  - 유지보수 품질 등...

### Security related reversing

- 멀웨어 개발자
  - 운영체제, 소프트웨어의 취약점을 파악하기위해 역공학
- 백신 소프트웨어 개발자
  - 악성코드를 분석하기위해 역공학
- Auditing Program Binaries
  - 소스코드를 사용할 수 없는 경우
- Breaking DRM
  - 저작권있는 파일의 copy protection을 우회하기 위해, DRM기술을 우회, 깨트리기 위해

### Tools
- Disassembler
  - IDA
  - JADX
  - ILDasm
- Debugger
  - JEB
- HEX Editor
- PE Analyzer

### Basic Approaches
- Elimateing symbolic Information
  - 메소드, 클래스, 변수와 같은 이름을 컴파일 단계에서 제거하여 디버깅을 어렵게함
- Code Encryption
  - 코드를 암호화하여 정적분석을 어렵게 함
- Anti-Debugging
- Obfuscating the Program
  - 프로그램을 난독화하여 역공학을 어렵게함.
  - layout, logic, data,구성등을 변경, 쉽게 분석할 수 없도록 함

### Code obfuscation : 코드 난독화
- Code obfuscation : 기능을 유지하면서 사람이 쉽게 코드를 읽을 수 없도록 변경
- Obfuscator(난독화 도구) : ProGuard, DexGuard, Allatori
- deobfuscator : 난독화 해제 도구

### 난독화 적용 사례
- NHN : 식별자 난독화, 문자열 암호화, 제어흐름 난독화
- 악성코드 난독화로 분석을 어렵게 함

### Obfuscation classification
- Layout obfuscation
- Control flow obfuscation
- Data obfuscation
- Preventive Transformations

# 12주차 강의 필기

## Cryptography(암호학)
- 데이터를 변환하는 원칙, 수단, 방법  
무분별한 변조를 방지하고 접근제어를 위해 데이터의 의미를 숨기기 위함
- confidentiality, data integrity, non repudiation and authenticity와 같은 보안을 제공하는 원칙, 수단, 방법을 포함하는 학과목
- 기존의 정보를 알아볼수 없게 바꾸고(암호화) 알아볼수 있는 정보로 되돌리는(복호화) 원칙, 수단, 방법

### 대칭키 암호화(Symmetric-key Cryptography)
암호화 복호화시 동일한 키를 사용
1. Plain text   평문
2. Encryption   암호화 -> secret key (동일한 키를 사용)
3. Cipher text  암호문
4. Decryption   복호화 -> secret key (동일한 키를 사용)
5. Plain text   평문

대칭키는 둘만 알고 있어야 한다.

### 공개키 암호화(Public-Key Cryptography) : 비대칭 방식
각 사용자마다 2개의 키를 가짐(public key, private key)  
수신자의 공개키를 통해 암호화후 수신자는 자신의 개인키로 복호화

엘리스가 밥에게 내용 전송
1. Plain text   평문
2. Encryption   암호화 -> secret key (bob의 공개키(public key)를 사용)
3. Cipher text  암호문
4. Decryption   복호화 -> secret key (bob의 개인키(private key)를 사용)
5. Plain text   평문

대칭키 방식과 달리 공개키는 누구나 열람할 수 있다.

### Cipher(암호, 암.복호화 시스템/알고리즘)
- 평문을 암호문으로 변환하는 일련의 과정
- 평문을 암호문으로 변환하는 암호학 시스템을 말하기도 한다.

### Encryption(암호화)
- 평문을 변환하여 암호문을 만든다
  - 기존의 데이터의 의미를 숨긴다

### Decryption(복호화)
- 암호문을 변환하여 평문으로 만든다

## Applications of Cryptography(암호학의 활용)
### Linux Encryption Methods(리눅스 암호 기법)
민감한 정보의 경우 램에서 하드드라이버로 암호화하여 저장

Unprotected System or file and folder protection
- 파일의 일부를 파일 또는 폴더단위로 암호화
FDE(Full disk encryption)
- 디스크의 파일을 모두 암호화하여 저장

### Database encryption
- 공개키 암호화 방식을 사용(Public key cryptography)
- 데이터 베이스의 중요한 정보들은 암호화해서 저장
- 신용카드 번호와 같은 민감한 정보는 평문으로 보관하면 위험하므로 암호화하여 저장

### Polymorphic Virus(다형성 바이러스)
- Encrypted viral code(암호화된 악성 코드)를 사용하여 바이러스 감지를 어렵게 함
- Decryption routine을 통해 악성코드를 복호화 하여 실행

### Encryption Trends
Cryptojacking : 희생자의 디바이스를 감염시켜 암호화폐를 채굴하는 공격은 상대적으로 감소

**좋은 예**
- Traffic을 암호화 보안성 강화
- Cloud의 데이터를 암호화
**나쁜 예**
- 악성소프트웨어의 의도를 숨기기위해 사용
- 암호화된 멀웨어의 증가

### Encrypted Threats
- 암호화 위협은 크게 증가하였다. 

# 13주차 강의 필기 : 암호학

## 암호학 개요

### Codebook & Cipher
- code : 암호화를 위해 사용되는 방법
- codebook : 암,복호화를 위해 사용되는 문서
- Ciphers : 개별적인 문자단위로 암호화, 비트 단위로 암호화($\lrArr$ code : 단어,구 단위)
  - 현대에는 비트, 문자 단위로 암호화
  - Cipher : 암호
  - Cryptography : 암호 작성술, 암호 방식, 암호 기법
  - Cryptography : 암호 해독술( = code breaking)
  - Cryptology : 암호 작성술

### world war I
- Zimmermann Telegram
  - codebook을 활용하여 암호화

### world war II
- Purple
- Enigma
  - 엘런 튜링 : 에니그마를 해독하기 위해 기계를 만듬
---
## Cryptography
- Plaintext (평문 = 원문) : original message
- Ciphertext (암호문) : coded message
- Encipher(Encode), Encryption (암호화)
- Decipher(Decode), Decryption (복호화) 
- Key : information used in encryption / decryption
- Cryptography (암호기법) 
  - 암호화, 복호화 하는 원리
  - Confidentiality, integrity, non-repudiation, authenticity
- Cyptanalysis(code breaking, 암호해독)
  - 키 없이 암호문을 가지고 원문으로 복구하는 기법
- Cryptology (암호학)
  - making, breaking secret codes
- Cryptographer - create ciphers
- Cryptanalyst - break ciphers
- 대칭 암호 : 암호키 복호키 동일
- 비대칭 암호 : 암호키 복호키 다름
- 암호 프로토콜 : 네트워크 상의 암호 관련 규약
- Cryptosystem 

### Cryptosystem

- E is encrytion algorithm
- D is decryption algorithm
- M(P) is the set of plain texts
- K is the set of keys
- C is the set of ciphertexts

### Encryption Alogorithm
대칭키 방식 Cipher
- Block : input is fixed blcoks of same length
- Stream : stream of input

### symmetric eky vs asymmetric key
- Key
  - 암호화시 사용되는 중요한 입력
  - Key는 비밀로 유지해야 한다.
  - 암호해독가들은 키를 알아내려고 노력한다
  - Keyspace : 모든 가능한 키 집합(키를 구성하는 비트의 길이가 길수록 안전하다)
  - Entropy : 무질서하게 생성하면 좋다
- 키를 안전하게 관리하기 위한 방법
  - TPM, secure co-processor, smartcards

## Crypto
- 키만 비밀이고 나머지 모두 공개되어 있다.
- Kerckhoff's  Principle(케르크 호프스의 원칙)
  - 암호화 시스템의 모든것이 공개되더라도 키는 안전해야 한다.
  - 알고리즘은 언젠가 노출된다(알고리즘을 비밀로 유지하는것은 어렵다)

## Turing
### Turing test
- 기계와 사람을 명확히 구분할 수 없으면 튜링테스트 통과

---
## Cipher(cypher)

### Subsitution Ciphers
substitutes one symbol for another  
$B \xrightarrow{B/A} A$  
$L\xrightarrow{L/A} N$  
하나의 심볼을 다른 심볼로 치환하는것(대치, 치환, 대체)

#### Addictive Cipher(덧셈 암호) : Monoalphabetic
- Caesar cipher = Shift cipher = Addictive chipher
  - 알파벳 순서를 3칸씩 미뤄 암호화(원형으로 x ->a, y->b, z->c, a->d)
  - 복호화는 3칸씩 당겨서
- Encryption : C = (P + k) mod 26
- Decryption : P = (C - k) mod 26
  - C : Ciphertext, P : Plaintext, k : key

#### Cryptoanalysis 
- Brute-force attack 
  - 키값을 모두 대입하여 암호 해독
  - Try them all
  - Exhaustive key search
  - 키값 범위가 작아 쉽게 해독할 수 있다.

#### Addictive Cipher with a keyword
단순 알파벳 순으로 암호화 하지 않고 암호에 키워드를 집어넣어 암호화

#### Cryptanalysis
- 암호문의 문자들마다 빈도수를 비교하여 통계적으로 자주 사용되는 문자에 매핑
  - 예를들어 암호문에 F, Q가 자주 등장하면 통계적으로 평문에서 자주사용되는 E, T가 F와 Q일 가능성이 높다.
- 영어는 특정 문자가 붙어다니는 경향이 있다. (2글자 : digram, 3글자 trigram)
  - th, he, in, er,...
  - the, ing, her, ere, ent, tha,...

Monoalphabetic (단일문자 치환 암호)는 문자 빈도수 분석 공격에 의해 쉽게 깨질 수 있다. 

#### Vigenere Cipher : Polyalphabetic
- 키워드를 통해 암호화
  - 키워드 길이만큼 평문을 분할
  - (plaintext + key) mod 26 = ciphertext
  - 문자 빈도수 분석 공격 완화(1대 다 매핑 )
- 원래 vigenere 방식
  - table을 이용 
    - 평문을 열, 키워드를 행에 대응시켜 암호문에 해당하는 알파벳
- 만약 우연히 평문에 같은 패턴이 나타나면 분석하기 쉬워진다.
- 키가 주기적으로 나타나는 특성을 없애기 위해서 (키워드 + 평문의 내용)를 키로 사용

### Transposition ciphers(전치암호)
위치를 조작

Columnar transposition : 컬럼단위로 위치 조작 

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