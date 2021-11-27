# 12주차 

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