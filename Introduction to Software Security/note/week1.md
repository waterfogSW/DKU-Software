
# SW보안개론

## 1주차 1

### 강의 목적

공격자의 관점을 이해해야 방어할 수 있다  
기본적인 사이버 보안 지식, 소프트웨어 보안 중심으로 강의

### 성적평가

성적에 반영되는 Quiz가 "시험 및 설문" 을 통해서 제시될 수 있음  
문의게시판 활동이 활발한 학생들에게는 가산 부여  
비율은 교수님 마음대로

### 자료

[SEED labs] Hands-on Labs for Security Education  
<http://www.cis.syr.edu/~wedu/seed/index.html>:  
A Suite of Instructional Laboratories for Computer SEcurityEDucation  

### 과제

- 3개이상의 개인과제, 1개의 3~4명 팀과제  
- 과제물은 제시되면 2주내(정해진 기간 내)에 제출  
- 취약점 분석, 간단한 시스템 라이브러리 개발

---

## 1주차 2

### Data vs Information

- 컴퓨터 : 데이터와 정보를 처리하고 결과를 제공하는 기기
  - 범용 목적
    - Desktop, Server
    - Laptops, Tablets
    - Smartphones
  - 특수 목적(Embedded devices)
    - Router, AP, Smart-meter
    - Gaming consoles, Robot vaccums
    - Industrial controllers


|       데이터        |       정보        |
| :-----------------: | :---------------: |
|      Raw facts      | Useful & Relevant |
|     Unorganized     |     Organized     |
|     Unprocessed     |     processed     |
| Chaotic or Unsorted | Ordered or Sorted |
| Input to a Process  | Output of Process |

> 정보, 데이터의 중요성 증가

### 정보기술(IT)

데이터나 정보를 처리하거나 배포할 목적으로 네트웍이나 컴퓨터 시스템을 개발하거나 활용하는 기술

- 직업
  - IT 공학자 : 새로운 소프트웨어나 하드웨어를 개발하거나 업그래이드 하는 사람.
  - IT 관리자
  - IT 설계자
  - IT 매니저 
  - IT 보안전문가 : 보안프로그램을 제작하거나 실행하여 시스템의 security와 safety를 유지하는 사람

### SW 공학자 vs SW 개발자

- SW 공학자 : 개발, 테스트, 유지보수

> 요구사항 분석 (Document) > 설계 (Software architecture) > 개발 (Implementation) > 검증 (Verification) > 유지보수(Maintenance)

전체 과정에 관여하기 때문에 이슈관리의 스케일이 큼.

- SW 개발자 : 다양한 유형의 컴퓨터에서 수행될 소프트웨어를 구현하는 전문가, 주로 구현단계에 기여

제한된 규모의 이슈에 관여

### Information System

데이터, 소프트웨어, 하드웨어, 네트워크, 사람, procedures, policies 까지 포함

> procedures, policies는 정보를 처리하거나 배포하는데 관련되어 있는 절차나 정책을 말함.

각 요소는 단점, 강점, 보안 요구사항이 존재

정보는

- 하드웨어에 저장되고
- 소프트웨어에 의해 처리되고
- communication에 의해 전송되고
- 사람에 의해 사용되고
- policies에 의해 통제된다.

> 데이터와 정보는 밀접한 관련이 있다

---

## 1주차 3

보안 : 위협이 없는 안전한 상태, 공격자가 있는 상황에서도 원하는 특성을 만족하는 상황

최근 동향

- Crypto miners (38%) : 암호화폐 채굴 강제하는 공격
- Botnet (28%) : 서비스 거부공격(DDOS)에 주로 악용되는 악성코드
- Mobile (27%) : 모바일 공격
- Banking (18%) : 은행을 공격하는 사이버 공격, 피싱
- Infostealer (18%) : 정보유출
- Ransomware (7%) : 데이터 암호화 시켜서 돈을 요구

공격 방식

- Interruption : 정보의 흐름을 가로막기(DDOS공격)
- Interception : 가로채기, 도청(패킷 캡처)
- Modification : 데이터 변조 공격
- Fabrication : 데이터 위조 공격

보안의 중요한 속성(CIA)

- Confidentiality : 권한을 가진사람만이 정보에 접근(도청공격 방어)
- Integrity : 정보에 대한 인가를 가진 사람만이 정보를 수정할 수 있음(변조공격 방어)
- Availability : 인가된 사용자만이 정보에 접근(DDOS공격 방어)
- Authenticity, Anonymity...

정보 보안 - 인가되지 않은것으로부터 정보를 보호하는것

- 접근
- 사용
- 기록
- 분열(정보의 일부를 알아보지 못하게 하는것)
- 파괴
- 변조

### What is computer security

컴퓨터 시스템을 적대적인 환경으로부터 보호하는것을 정보보안이라고 한다.

### 컴퓨터 보안 vs 정보보안

컴퓨터 보안 - 디지털 형태의 정보만을 주로 다룸

정보 보안(디지털+아날로그 정보) > 컴퓨터 보안(디지털 형태의 정보)

> 공통점은 컴퓨터 시스템과 네트워크를 다양한 위협으로부터 보호하는것
