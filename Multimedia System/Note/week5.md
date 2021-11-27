# 5주차

## Analog to digital conversion (ADC)

sampling rate = *f*<sub>s</sub> = 1/T<sub>s</sub>(sample/sec=Hz)

### **Nyquist Shannon samling theory**
- twice the maximum frequency component

기존의아날로그 신호에 포함된 가장 높은 진동수의 2배로 샘플링한 디지털 신호로부터 완벽하게 아날로그 신호를 복원할 수 있다.

Nyquist rate : *f*<sub>s</sub> = 2*B*

예를들어 음악이 최대 20kHz를 포함하고 있다면 Nyquist rate는 40kHz

### Alias effect

*f*<sub>s</sub> < 2 * *f*<sub>max</sub>

### Quantization
Quantization에러를 줄이기 위해 Quantization 비트수를 늘려야 하지만 Quantization비트수를 늘리면 처리해야 할 데이터의 양이 많이 늘어난다. 반면 줄이게 되면 signal의 퀄리티가 떨어진다.

- Sound : 잡음이 생김

- Image : 색이 퍼지거나 끊기는 현상이 발생

### Bit rate(Data rate)

**Bit rate** = R = *f*<sub>s</sub>(sample/sec) * N(bits/sample)
- unit : (sample/sec) * (bits/sample) = bits/sec = bps, 초당 처리해야할 비트수
- 아날로그 speech를 디지털로 변환할 때 초당얼마만큼의 bit이상으로 처리해야 기존의 아날로그 품질 이상을 유지할 수 있는가

#### speech signal bit rate
- 아날로그 speech의 대역폭은 대략 4Khz
  - sampling rate : *f*<sub>s</sub> = 4Khz * 2 = 8Khz
  - Quantization = 8bit/sample
  - bit rate R = 8000 X 8 = 64kbps
  - 초당 64kbit이상으로 처리해야만 기존의 아날로그 음성 품질 이상으로 유지할 수 있다.

#### music signal bit rate

- 음악의 대역폭은 대략 22.05Khz
  - sampling rate : *f*<sub>s</sub> = 22.05Khz * 2 = 44.1Khz
  - Quantization = 16bit/sample
  - bit rate R = 44100 X 16 = 0.705Mbps(MONO)
  - 스테리오 음악의 경우 x2
    - 0.705Mbps(MONO) x 2 = 1.41Mbps

### Frequency and Spectrum

- 컴퓨터의 음성파일이 남자인지 여자인지 구분하고 싶을때 
  - time domain wave form에 fft(fast fourier transform)알고리즘을 적용하여 구할 수 있다.
  - 높은 주파수 spectrum을 가지고 있다면 여성일 가능성이 높다
  - 낮은 주파수 spectrum을 가지고 있다면 남성 ...
- DTMF(dual tone mutiple frequency)
  - 버튼을 누를때 마다 2개의 tone signal이 더해져 발생함.
  - 중계기는 들어온 신호에 fft를 적용하여 스펙트럼을 얻고 어떤 주파수 성분이 있는지 파악하여 어떤 번호가 눌렸는지 확인
- Vuvuzelas noise
  - notch filter를 통해 부부젤라의 소음을 제거
  - notch filter : 특정 주파수 성분만 제거
  
### Two signal representations in DSP

- **Time domain wave form** : 시간에따른 변화 (일반적인 컴퓨터 음성파일)ㄷ  
- **Frequency domain wave form** : 주파수에 따른 변화


### Bandwidth definition

- *BW*<sub>DSP</sub> : 최고주파수(*f*<sub>max</sub>) - 0
- *BW*<sub>com</sub> : 최고주파수 - 최저주파수
- *BW* = distance in Hz from 0Hz to max freq. comp(일반적으로 dsp)

 일반적으로 음성신호가 가지는 유의미한 신호는 4kHz이다. 보통 음성주파수 대역폭(BW)는 4kHz라고 한다. 따라서 BW는 유의미한 주파수 성분까지지의 거리라고 할 수 있다.

피아노 건반의 tone signal과 일반적인 tone signal은 왜 다르게 들릴까?
- 악기의 경우 tone signal과 hamonics 주파수 성분이 더해져 들리게 됨 -> 풍부한 소리

## HW2
- A/D technology 조사
  - PCM, DPCM, ADPCM, DM, ADM
- Audio quality
  - CD, SACD, DVD-audio,XRCD, HDCD 포멧간의 차이

