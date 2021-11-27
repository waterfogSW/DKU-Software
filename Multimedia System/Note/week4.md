# 4주차

## Analog Signal

정보가 진폭에 담겨있다.

### Amplitude

- 소리의 세기
  - loudness or strength of the sound => SPL(sound pressure level) dB
  - SPL (dB) = 20 * log(P/P<sub>0</sub>)
    - P<sub>0</sub> : 기준음악, 작은 소리를 저장하고 조금씩 키워가면서 들리는 순간에 측정한 소리 크기
    - P는 소리의 크기
    - P = P<sub>0</sub> : SPL이 0이라는 뜻은 소리가 들리기 시작하는 시점
- 이미지에서 진폭은 빛의 강도

### **Frequncy(중요)**

- 1초동안 반복되는 패턴
- Period(T) = 1/f(unit:sec)
- 주파수가 높을수록 높은소리, 낮을수록 낮은소리
- tone signal = 하나의 주파수만 가지고있는 signal
  - pilot singal : 네트워크 신호를 확인, 스피커 주파수 테스트
  - 음악의 경우 다양한 주파수를 조화롭게 배치
- 가청주파수 20hz~20khz

### Phase

- 두개의 신호간 time delay

## Digital Binary

- 진폭의 크기는 큰 상관이 없다.(0과1의 margin만 충분하면 됨)
  - 전력소모때문에 진폭을 무한정 크게할 수는 없다.

### Advantage of DSP

#### **High quality of signal processing**

- Analog transmission
  - 잡음
  - sinal세기가 줄어드는 문제(attenuation) -> 약 5km마다 증폭기를 설치
  - 잡음도 같이 증폭되어 신호의 품질 저하
- Digital transmission
  - Repeater
    - Binary 1,0 판정
    - 소음제거
      - P<sub>e</sub> : probablity of error 10<sup>-6</sup> ~ 10<sup>-10</sup> 에러율이 매우 적음
- repater를 이용해 잡음을 제거하기 때문에 잡음에 대해 강하다 -> 고품질의 신호처리가 가능
  
#### **Programmable**

#### **Multimedia**

#### **Low cost IC Chip**

#### **Good security**

### Weak point of DSP
- 아날로그 신호를 디지털변환하게되면 **데이터의 양이 늘어남**
  - data compression이 필요
- 동기화 중요

## Analog to Digital Conversion

아날로그 신호 - **A/D - DSP - D/A** - 아날로그 신호

- DSP
  - filter 잡음제거
  - compression 압축
  - encryption 암호화
- Two Step in ADC(AD converter)
  - 1. Samlping
    - sampling period T<sub>s</sub> : 시간 간격으로 아날로그 값을 취함
    - sampling rate = *f*<sub>s</sub> = 1/T<sub>s</sub>(sample/sec=Hz)
  - 2. Quantization and Digitization 
    - Quantization : 컴퓨터가 표현할 수 있는 값으로 truncate, 맵핑
    - Digitization : quantization된 값을 컴퓨터 값으로 표현(ex 3bit)
  - PCM pulse code modulation
