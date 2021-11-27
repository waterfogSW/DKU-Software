# 멀티미디어 중간고사 기출

## Chapter 1

0. 멀티미디어의 특징

| Multimedia Characteristics                     | Meaning                                                                   |
| ---------------------------------------------- | ------------------------------------------------------------------------- |
| **Integrity**                                  | combining two different types of me                                       |
| **Duplex** Communication                       | **Communication in both directions**                                      |
| **Digital** Processing                         | multimedia contains digital concept                                       |
| Processing ability on **stand-alone computer** | **Not allow parallel computing**                                          |
| **Media interaction**                          | **Integration and interconnection of different media for multimedia APP** |
| **User Interface**                             | easy and convenient I/O                                                   |
| **Massive storage device**                     | Need to store massive data                                                |

1. 5 types of media
- text, audio, image, video, animation

2. Definition of multimedia
- Narrow : combination of more than two different media types
- Broad : all the technologies involved in expression, storage, transmission of information

3. 표준의 정의 (Give a brief definition of "standard")
- Documented agreements containing technical specifications to be used consistently

4. De jure와 De factor의 차이점
- De jure : 법적인 표준; 모든 회사가 반드시 따라야 하는 표준 (ITU, ISO)
- De factor : 전통적인 표준; 법적인 표준은 아니지만 많은 사람들이 사용하고 있는 표준 (IBM-PC)

5. ITU, ISO, W3C, IAE
- ITU : International Telecomunication Union
  - Office, ITU R, ITU T, ITU D
  - Making standard for telecommunication
- ISO : International Standard Organization
  - 나라마다 다른 산업, 통상 표준의 문제점을 해결하고자 국제적으로 통용되는 표준을 개발하고 보급한다
- W3C : World Wide Web Consortium
- IEC : International Eletrotechnical Commission
- IAE : International architecture Board
  - Standard regarding internet technolgy 

6. JPEG, MPEG를 표준화한 기관
- JPEG : ISO/IEC JTC 1  SC29 – WG1
- MPEG : ISO/IEC JTC 1  SC29 – WG11

7. MPEG1, MPEG2, MPEG4각각의 목적과 관련 응용분야에 대해 설명하라

- MPEG 1: Data compression, video CD
- MPEG 2: Data compression, Broadcasting
- MPEG 4: Data compression, Mobile
- MPEG 7: Information retrieval

>- MPEG1 : MPEG1은 오디오, 비디오, 다른 다양한 데이터를 표준 비트스트림으로 인코딩하여 저장하고, 다양한 컨텐츠 사이의 동기화 상태를 유지하기 위하여 사용하는 논리적 레이아웃과 방법을 규정한다. 세계적으로 가장 널리 쓰이는 형식 중 하나이며, 비디오 비디오 CD, 케이블/위성 TV, DAB 등에서 이용되고 있다.
>- MPGE2 : MPEG-2는 오디오와 비디오 인코딩에 관한 일련의 표준이다. 일반적으로 디지털 위성방송, 디지털 유선방송 등의 디지털 방송을 위한 오디오와 비디오 정보 전송을 위해 쓰이고 있다
>- MPGE4 : 오디오와 비디오 인코딩에 관한 일련의 표준이다. 1999년에 규격화된 직후부터 동영상을 장시간 기록하는 용도로 디지털 카메라에 사용되었다. 당초에는 파일 포맷이 규격화되어 있지 않았기 때문에 마이크로소프트사의 ASF 파일 포맷이 사용되었다. 근래에는 제3세대 휴대 전화의 동영상 포맷으로서 채용되고 PDA를 포함한 모바일 동영상 재생기의 주요 포맷이 되고 있다. 

8. Definition of Standard
- Standards are documented agreements containing technical specifications to be used consistently

9. Briefly explain about the "**aliasing effect**"
- it happens when undersampling, lose high freqeuncy and also it cannot recover  unique analog signal using the samples.

## Chapter 2
1. DSP(digital signal processing)의 장점과 단점
- 장점
  - 리피터를 통해 잡음을 제거하기 때문에 잡음에 강하고, 환경적인 요인에 영향을 받지 않기때문에 고품질의 신호처리가 가능하다.
  - Possible to set up **Programmable** digital system
    - DSP칩의 소프트웨어를 수정하여 쉽게 시스템의 기능을 변경할 수 있다.
  - Process **multimedia** data
    - 쉽게 다른종류의 디지털 미디어와 결합할 수 있다.
    - 저장 처리 변형이 쉽다.
  - **Low cost digital IC Chip** is available
    - 비용이 낮고, 작다
  - **Good security**
    - 코딩 기술에 따라 보안성을 높일 수 있다
- 단점 : 아날로그 신호를 디지털변환하게되면 처리해야할 데이터의 양이 늘어남.
  - 데이터 압축이 필요합니다.
  - 동기화가 필요하다
- 아날로그와 비교한 장점
  - 아날로그 신호와 달리 온도와 같은 환경적 요인에 강하고, 프로그래밍가능한 디지털 시스템에 적용할 수 있다.

- Advantage : high quality, programmable, multimedia, low IC chip
- Disadvantage : large amount of data

2. FM RADIO의 대역폭이 11 khz일때
- Sampling rate 계산
  - 11 khz * 2 = 22 khz
- 16-bit quantization시 data rate 계산
  - Data rate = Sampling rate * Quantization = 22 khz * 16 bit/sample = 352 Kbps

3. 한사람이 커튼 안쪽에서 3개의 피아노 건반을 동시에 누른다 가정할때 커튼 밖의 사람은 어떤 피아노 건반이 눌려 졌는지 알수 있는 방법은?
- fft(fast fourier transform)알고리즘을 적용하여 어떤 음이 눌렸는지 확인할 수 있다.

4. characteristic difference between low-frequency tone signal and high-frequency tone signal in terms of time-domain waveform and the loud-speaker sound.

| High-frequency Tone-signal            | Low-frequency Tone-signal            |
| ------------------------------------- | ------------------------------------ |
| relatively fast time varying          | relatively slow time varying         |
| relatively heard as high tone (pitch) | relatively heard as low tone (pitch) |

5. 5.5khz 대역폭의 아날로그 신호를 디지털로 변경할 때, 8bit quantization
- Sampling rate = 5.5 * 2 = 11khz
- Data rate = 11khz * 8bit = 88 kbps

6. 음성이 여자인지 남자인지 구분하고 싶을때
time domain wave form에 fft(fast fourier transform)알고리즘을 적용하여 낮은 주파수 형태를 가지고 있다면 남성, 높은 주파수 형태를 가지고 있다면 여성일 확률이 높다

7. Tone signal이란?
- 한가지 주파수로만 이루어진 신호를 tone signal이라고 합니다

8. What are the two steps of PCM procedure for analog to digital conversion(ADC)
- PCM : 1. Sampling, 2. Quantization

9. Briefly explain the difference between PCM and DPCM method.
- DPCM codes the difference of neighboring sample, instead of sample itself

10. What is a main different attribute between analog and digital?
- Analog information lies on the signal amplitude, but for digital signal, the information lies on the signal margin to distinguish binary 0 and binary 1


**PCM**
- pulse code modulation

**If too few quantization level**
- Sound : coarse hiss, loss of quiet passages, general fuzziness
- Images : banding and posterization


## Chapter 3

### Introduction to Graphics

0. What are the three human eye characteristics
  - Simultaneous contrast : 빛의 강도보다 차이에 민감하다
  - Mach bond effect : 사람의 눈은 색 변화의 경계에 민감하다
  - Lograrithmic sensitivity : 밝기에 대한 민감도는 지수함수적이다

1. 녹색의 산을 배경으로 사람을 찍은 사람이 있을때 low frequency area와 highfrequency area는 어느부분에 해당하는가?
- 흐린 배경은 low frequency area, 모서리 부분은 high frequency area이다
- In terms of frequency. High frequency as edge, low frequency as background

2. Bitmap image vs Vector graphic format

| -            | Vector Graphic                                                              | Bitmap Image                                                             |
| ------------ | --------------------------------------------------------------------------- | ------------------------------------------------------------------------ |
| Expression   | 점, 선과 같은 기하학적 표현                                                 | 픽셀                                                                     |
| Adavantage   | 메모리를 적게사용한다 확대로 인한 퀄리티 저하가 없고, 변형이 쉽다.          | 색상변화에 유리하며 모니터에 빠르게 출력된다.                            |
| Disadvantage | 색상변화에 취약하고 모니터에 느리게 출력된다. 별도의 mapping과정이 필요하다 | 메모리를 많이 사용하고, 확대 변형시 품질 저하가 발생하며, 변형이 어렵다. |

3. Briefly describe the meaning of resolution in digital camera. What are the important factors that mostly affect image quality in digital camera?
- resolution = total number of pixels in the largest image it can record, Size of C-MOS sensor (screen resolution)

4. MP3 Audio
   1. Briefly explain the basic principle of audio compression using MP3 algorithm? Is it lossless or lossy compression?
      - transform time domain audio signal into frequency domain using FFT
      - remove low energy part in high frequency area
      - remove the frequency components that human cannot hear :
          frequency components below hearing threshold, also the frequency 
          components those masked by neighbor
   2. What is the disadvantage of MP3 audio? 
   - Cannot reproduce high frequency part of the audio
   3. Briefly explain recent trend of audio file?
   - lossless audio, and multichannel audio

5. What is a main difference between bitmapped image and vector graphic?
- Image : born in analog
- vector graphic : born in digital

6. In digital camera, what is a meaning of resolution? What are the most important factor that affects the picture quality?
- the number of pixels in the largest image the digital camera can record
- ppi and COMS sensor

**Color mode의 종류**
- B/W
  - Monochrome : 1bit/pixel
  - Gray level image : 8bit/pixel
- Color
  - True color : 24bit/pixel
  - Hi color : 16bit/pixel

**Resolution in display device**

- VGA - 640
- FHD - **1920** x 1080
- UHD - **3840** x 2160
- Full UHD - **7680** x 4320

**그래픽 이미지 생산**
- Two steps - Modeling -> Rendering

**Transform Vectors * Bitmaps**
- Rasterize : Vector -> Bitmap
- Tracing : Bitmap -> Vector