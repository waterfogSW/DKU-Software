# 5주차 강의 필기

## Week 5-1

### Security Threat Model

Threat Model
- 보안운영을 최적화하고 계획하기 위한 방법
- 위협과 취약한 자산, 위협에 대한 대응을 전반적으로 생각하여 최적화하는것이 위협 모델링이다

위협
- Malware : viruses, spyware, adware
- Zero-day vulnerabilities
- DDOS
- Phishing

위협 모델링의 구성요소
- Secure design
- Threat intelligence
- Asset identification
- Mitigation capabilities
- Risk assessment
- Mapping and modelling

**Secure design**
- 개발단계에서 부터 모든 코드를 분석, 보안 테스트

**Threat intelligence**
> - 현존하거나 발생가능한 위협에 대한 대응을 결정에 사용할 수 있도록 위협 맥락 메커니즘, 지표, 예상 결과 및 실행가능한 조언 등을 포함하는 증거 기반의 지식
> - 사이버 위협에 관련된 공격자, 공격절차, 공격방법 정보를 포함하고, 보안 솔루션 벤더의 연구로 산출된 위협 정보, 전세계의 탐지센서로 부터 수집된정보 와 같은 모든 정보에 대한 상관관계 데이터
> - 위협 정보를 수집해 상황 분석, 효과적으로 대응하는 방법
- 공개된 정보일수도 있고, 특정 회사의 SW안에 있는 DB일수도 있다. 다양한 형태로 존재


**Asset identification**
- 조직, 가정 내에 어떤 자산들이 있는지 잘 파악하고 있어야 한다.
- 새로운 자산, 제 3의 자산을 통해 보안팀이 인지하지 못하게 접근할 수 있다.

**Mitigation capabilities**
- 위협을 완화시키는것
- 공격을 탐지하고 해결(e.g 멀웨어 제거)

**Risk assesment**
- 다양한 IT component에 대해 자산별로 위협 ranking
- 중요한 취약점을 위주로 먼저 제거

**Mapping and Modeling**
- 시각적으로 위협을 보여줌
- 현존하는, 미래의 위협을 계획하고 대처하기 위한 목적으로 workflow을 시각화하고 보안운영계획을 결합

### Microsoft STRIDE model

- Spoofing(-> authentication)
  - fabrication의 일종, 다른사람인척해서 어떤 행동을 하게 하는것
- Tampering(-> Integrity)
  - modification, 권한이 없는 사람이 임의로 데이터 변조
- Repudiation(-> non-repudiation)
  - 다른사람이 증명하기 어려운 방식으로 행위를 하고 하지 않았다 잡아 떼는것, 발뺌
- Information disclosure(-> confidentiality)
  - 민감한 정보를 불법으로 보는것
- Denial of service(-> availability)
  - 사용자가 정상적으로 서비스를 이용할수 없도록 하는것
- Elevation of Privilege(-> authorization)
  - 인가되지 않은 수단을 통해 권한 상승(Rooting)

## Week 5-2

### Common Weakness Enumeration(CWE)

- CWE : 약점 유형들의 목록을 보안전문가 커뮤니티에 공개
- Weakness : 소프트웨어 하드웨어에 존재하는 결점 결함 버그 오류 등을 말한다. 코드, 설계, 아키텍쳐에 존재할 수 있다. 공격자들이 악용할수 있는 발판이 될 수 있다.

**CWE top 25 software weaknesses**
- 가장 위험하고 영향력이 큰 이슈
- 쉽게 발견될수 있고 누구나 이용할 수 있음, 공격자가 이를 활용할 가능성이 높다.
- top25는 개발자, 테스터, 유저, 보안연구자, 교육자 들에게도 아주 많은 도움을 준다. 현재 가장 심각하고 중요한 약점에 대한 정보 제공


**Cross Site Scripting (XSS)**

주로 스크립트 언어로 인해 발생
- 신뢰할수 있는 사이트에 악의적인 스크립트를 업로드, 희생자는 웹사이트에 방문하여 해커의 악의적인 스크립트를 실행
  - 스크립트를 실행하여 개인정보를 빼냄
- 해커가 스크립트가 주입이된 링크를 희생자에게 보냄(친밀도가 있는척)
  - 사이트에 접속하면 악성 스크립트를 실행하여 희생자의 개인정보를 빼냄
- 게시판에 스크립트를 올리지 못하게하기
- 이상한 링크로 판단되면 링크를 클릭하지 않기

**SQL Injection**
- "id = '1' or '1=1'--"을 입력, sql은 둘중 하나라도 참이면 true, 사용자 정보를 모두 나타낼 수 있음. (--는 주석처리)
  - SQL문장을 악용하여 database정보 사용

- Threat agents : 내부, 외부사용자, 관리자
- Attack vector : 공격자는 sql문장을 오동작시킬수 있는 텍스트를 활용
- Security weakness : 매우 일반적, sql, xpath, ldap쿼리 에서 종종 발견
- techincal impacts : 데이터 손실, 파괴, 호스트가 위험에빠짐, 로그기록 불가, 서비스 불가
- Business Impact : 은행 신뢰도 하락

### Basic Mobile App Security

Malicious mobile apps
- 의도적으로 민감한 데이터를 수집하는 앱

Risks with malicious apps
- 개인정보 수집
- 은밀하게 도정, 공격자에게 전달
- 클라우드와 연결하여 내용 expolit
- 랜섬웨어
- 금융사기와 관련된일을 하도록 유도
- rooting, jailbreck
- 신뢰되는 앱 조작
- 신뢰되는 앱과 데이터 공유

악의적이지 않은 앱도 위험할 수 있다.
- ios, adroid앱은 일반인들도 만들수 있기 때문에 취약점이 있을 수 있다.
- 안전하지 않은 네트워크 연결
- 보호되지 않은 영역에 파일 저장
- 민감한 정보를 시스템 로그로 남김
- 웹 브라우저의 취약점
- 안전하지 않은 암호

보안전문가들은 이를해결하기 위해
- 앱의 숨겨진 위협을 확인
- 잠재적으로 위험한 앱을 설치하지 않도록 막음

### Mobile app security risks

1. 운영체제의 취약점 이용, 권한 상승
2. 앱스토어를 활용하여 악의적인 앱을 배포 시도
   - 껍데기만 있는 앱으로 인증받고 설치후 동적으로 공격코드를 다운로드하여 위협 

Application risks
- Secure coding을 하지 않으면위험
- app/hacking / reverse

Device Risks
- Rooted, jailbroken
- Outdated OS
- Malware

Session Risks
- insecure connection
- SMS forwarding(공격자의 휴대폰으로 문자가 전송됨)

Protect
- 취약점 제거
- 역공학을 막기 위해 코드 난독화, anti debugging
- 멀웨어감염된 디바이스의 접속 제한
- 루팅, 탈옥된 스마트폰의 접근 제한/ 루팅 탈옥 사전에 제한

### Think like an intruder
공격자의 입장에서 생각
- 과거에는 해킹에 관련된 자료가 공개되는것이 꺼려졌으나, 최근에는 내용을 공개해서 많은사람들이 알고 대처할수 있도록 함.
- 공격자의 동기를 이해할 필요가 있다.
- 공격자의 방식
- 공격자 처럼 생각해야 함

