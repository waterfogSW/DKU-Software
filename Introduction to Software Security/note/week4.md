# 4주차 강의 필기

## Week 4-1

### 소프트웨어 보안 이슈

- 운영체제 내에 보안 구현
  - authentication, authorization, accountability
- OS는 복잡한 소프트웨어
  - 복잡할수록 보안 취약점이 많다.
  - 운영체제는 소프트웨어기 때문에 공격 취약점이 있을것이다.
    - 보안 내재화 필요

#### Threats related to software

- 악의적인 목적으로 개발된 소프트웨어
  - Malware
    - viruses, worms, ransomeware, spyware, bot..
- 고려해야 할점
  - 멀웨어 동작 방식
  - 운영자, 고객의 입장에서 방어하는 방법
  - 공격자(Trudy)는 멀웨어를 어떻게 하면 효과적으로 만드는 방법
  
### Summary

- Interception <-> Confidentiality
- Modification <-> Integrity
- Interruption <-> Availablity
- Fabrication <-> Authentication
- Repudiation <-> Non-Repudiation
- AccessControl = Authentication + Autorization

## Week 4-2

### 보안위협 및 취약점

#### CIA 사례

- **Data confidentiality 비밀유지**
  - 학점 - 학생들에게 민감한 개인정보
  - 기밀 유지 보장 방식
    - crptography
      - AES : 대칭키 암호기법, 암호화, 복호화 키가 같다.
      - RSA : 비대칭키 암호기법, 암호화, 복호화 키가 다르다.
    - 접근제어(strong access control)
      - never access, no read, no view
    - 정보 게시 장소 제한
- **Data Integrity 무결성**
  - 환자 식별 정보
  - 환자정보가 부정확하면 환자에 심각한 손해를 끼칠수 있음.
    - 미국에서는 의료보험의 양도 및 책임에 관한 법률을 제정, 민감한 개인 건강정보에 대한 규정을 정의
  - 접근제어(strong access control)
    - no write, no append
    - 암호학적 해쉬 알고리즘
      - MAC, SHA-256, MD5
        - 단방향 함수
        - avalanche effect : input 차이가 큰 outut 차이를 만듬.
      - 데이터 무결성을 침해하는 공격을 탐지
  - Documenting System Activity : 활동내역을 문서로 남김
    - 데이터 무결성을 규명할때 필요
- **Data Availability 가용성**
  - 웹사이트에 언제든지 접근하고 기능을 사용할 수 있어야 함 - E-commerce
    - DDOS공격으로 인해 서비스가 멈춘다면 큰 손해가 발생
  - Anti-DDOS system
    - CDN(content delivery networks) : 여러 노드를 가진 네트워크에 데이터를 저장하여 제공
      - 콘텐츠에 대한 병목을 방지
    - Scrubbing centers : 네트워크 트래픽을 분석하여 악의적인 트레픽을 제거
  - well established backup procedure : 백업절차를 잘 설정하여 데이터를 삭제하는 공격으로 부터 보호

#### CIA 위협 사례

- Confidentiality
  - 소프트웨어 : 불법 복제
  - 데이터 : 비인가 읽기, 통계적 데이터를 분석하여 데이터 도출
  - 통신 : 다른 사람이 메시지를 읽음, 네트웍 트래픽 패턴을 통해 정보 노출
- Integrity
  - 소프트웨어 : 프로그램이 변조되어 동작 실패하거나 의도하지 않은 동작 수행
  - 데이터 : 기존파일이 변조되거나 새로운 파일을 조작해서 만듦
  - 통신 : 송신자가 보낸 내용 modification, delayed, reorderd, duplicate, fabricate
- Availability
  - 하드웨어 : 장비를 훔치거나 못쓰게 만듦, 서비스를 불가하게 함
  - 소프트웨어 : 프로그램 삭제
  - 데이터 : 데이터 삭제
  - 통신 : 메시지 삭제, 네트워크 라인을 못쓰게 함(wifi, etc...)

## Week 4-3

### 보안 위협의 구성요소

- action, inaction that could cause disclosure, alteration, loss, damage or unavailability of company's/individual's assets
- Target : 조직의 자산, SW,HW, 서비스, 시스템 자원, 데이터, 정보
- Agent (존재 안할수도 있음) : 의도적으로, 비의도적으로 위협을 유발할 수 있음
  - 내부 직원, 전 직원, 해커, 라이벌 회사, 테러리스트
- Event : 타겟의 취약점을 악용하는 행위
  - 악의적으로 또는 우연히

- 취약점 완화(현실적으로 취약점을 완전히 없애는것은 불가능)
  - 최신버전으로 유지
  - 안전하게 코딩
  - 명세서 변경

#### Example : wifi

- Target : wifi내부의 취약점
- Agent : 데이터를 악용하려는 competitor
- Event : competitor의 악의적인 행동

#### 위협의 종류

- Threadt without agent
  - Asset : 백업되지 않은 data, server
  - event : server room의 홍수, 화재 
- outsider vs insider, deliberate vs accidental
  - 취약한 Asset
  - Agent : 관리자가 비밀번호를 바꾸지 않고 방치(inaction)
  - event : 의도적으로, 비의도적으로 패스워드르 노출

위협과 공격의 차이점
- Attack : 취약한 자산(Asset)에 의도적(Event)으로 agent가 이벤트를 수행할때
- Threat이 좀더 넓은 범위

#### Threat events : Intentional Attacks

- Passive attack(interception) : 본래 시스템 자원에 영향을 주지 않는다 -> 탐지의 어려움
  - confidentiality를 깨트리는 행위
    - 메시지 내용을 공개, 트래픽을 도청하는것
    - sniffing
- Active attack - 시스템 자원을 변경 -> passive attack에 비해 탐지가 용이한 편
  - Integrity or Availability
    - data modification를 깨트리는 행위
    - dos
    - masquerading
- deliberate software attacks
  - 특정한 소프트웨어를 사용하여 시스템의 보안을 위배시키는, 위태롭게하는 의도적인 행위
    - malware
    - password cracking
    - ddos
    - spoofing
    - sniffing
    - man int the middle
    - phishing
    - pharming

#### 실제 사례

- crack이란 보호기술이 적용된 소프트웨어를 불법으로 사용하기 위해 보호 방식을 제거하는 프로그램
- keygen 소프트웨어 불법사용을 위해 cd키나 등록번호를 만들어 내는 프로그램

#### Software Cracking

- software cracking : 보호 기능 무력화 하기 위한 소프트웨어 변조, software를 사용하기 어렵게함(에드웨어, nagscreens)
  - patch : 실행프로그램을 변조, 공격자는 본래 프로그램의 보호기능을 무력화하기 위해 패치
  - loader

#### 모바일 앱 보안

1. 공격 대상과 exploit을 정의
2. 코드 역공학
3. 코드 변조

- 결과
  - 소스코드 / IP(Intellectual Property) : 지적재산권 도용
  - 광고 제거/교체
  - 악성코드 삽입
  - Free pirated copies(유료앱 무료사용)
- 