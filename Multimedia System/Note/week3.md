# 3주차

## 표준 국제 기구

**ITU (International Telecommunication Union)**: 국제전기통신 위원회

- un산하 국제 표준화 기구
- sub-divisions and SG(study group)
- 실질적으로는 WP(working play)에서 표준을 만듬

**ISO(International standard organization)**  
**IEC(International Electrotechnical Commission)**  
**ISO/IEC JTC 1(Joint technical committee)**  

- **SC29 - WG1 : JPEG, and JBIG**
- **SC29 - WG11 : MPEG (MP3: MPEG layer 3 / MPEG4 =  H.264 )**
- SC29 - WG12 : MHEG  

**IAB(Internet Architecture Board)**

- Standard document is called RFC(request for comments)

**W3C**  
월드 와이드 웹  

3가지 목표

- 언제 어디서나 접속가능해야 함
- 효과적으로 정보를 검색
- 게시물에 대한 책임

Subcommunity

- IETF(internet engineering task force)


MPEG의 종류 각각의 목적, 사용분야 조사

## Multimedia Fundamental

### Signal

- 추상적인 개념의 정보를 전류나, 전압의 전기적 파형으로 표현한것
- 시그널은 정보를 전달하는 수단
- **speech, audio, image는 아날로그의 형태로 존재**

정보의 변환

- Information -> Transducer -> Signal

Digital hearing aid system

- Input signal(Microphones) -(증폭)-> A/D -(디지털변환)-> DSP -> D/A -(아날로그변환)-> Output Signal(Receiver)
- Analog -> Digital -> Analog
- Digital Signal Processing

Analog Signal(continuous time signal)

- x(t), y(t)

Digital Signal(discrete time signal)

- 아날로그 신호를 일정시간 간격마다 샘플링한 값

Signal classification

- Time-varying : Audio
- Spatial-varying : Image
- Time, Spatial-varying : moving pictures = Video

### 아날로그 신호와 디지털 신호의 차이점

Analog Signal  

- 아날로그 신호는 진폭에 담겨있다.  
- x(t) = A * sin(2πft + Θ)
- A : amplitude, F : requency in Hz, Θ - phase

#### Amplitude

- 소리의 세기
  - loudness or strength of the sound => SPL(sound pressure level) dB
  - SPL (dB) = 20 * log(P/P<sub>0</sub>)
    - P<sub>0</sub> : 기준음악, 작은 소리를 저장하고 조금씩 키워가면서 들리는 순간에 측정한 소리 크기
    - P는 소리의 크기
    - SPL이 0이라는 뜻은 소리가 들리기 시작하는 시점
- 이미지에서 진폭은 빛의 강도