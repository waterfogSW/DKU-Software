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

