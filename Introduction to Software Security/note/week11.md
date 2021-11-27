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