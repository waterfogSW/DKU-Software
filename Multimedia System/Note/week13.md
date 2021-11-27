# 13주차 정리

## Color
- 사람의 눈은 3원색에 가장 민감하다.

### Color mode
- RGB Color
  - 섞을수록 밝아진다.
- CMY/K
  - Cyan, Magenta, Yellow / Kappa
  - 섞을수록 어두워짐
- CMY와 RGB는 보색관계에 있다.
- HSV(B) mode
  - Hue(색조)
  - Saturation(채도)
  - Brightness(명도, intensity)
- Indexed Color
  - 8 bit color
  - 자주사용되는 색을 Look-Up table을 통해 index로 표현
  - 파일사이즈가 줄어드는 효과
  - table을 pallete이라고도 함
  - Dither
  - Web-safe pallete
- Channels
  - RGB값 각각을 지칭
  - 조절하여 색을 보정할 수 있다.

### Color space
- 표현할수 있는 색의 범위
- Lab > Adobe RGB > **sRGB**(defecto standard)
  - 색을 더촘촘하게 표현할 수 있어서 sRGB를 더 ㅁ낳이 사용

### Color space Based on color differences
- YUB and $YC_BC_R$
- 비디오에서는 밝기와 색정보로 나눈다. 

#### Luminance Y
Y = 0.2125 + 0.7145G + 0.0721B

#### YUV
- Color difference
- analog TV

#### $YC_BC_R$
- digital TV

## Chapter 7 - Video
- Persistence of vision(잔상효과)
- Flicker(깜박임)

### Color space
- image의 colorspace와 다름
- 사람의 눈은 밝기에 민감하다
- Luminance(밝기)
- Chrominace(색차)

###  YUV Color Format
1. Bandwith를 8MB로 줄일 수 있다.
2. 흑백 TV와 호환성

### YIQ Color Mode

### $YC_BC_R$

### Type of video connection

#### Component Video
- higher end videol system, most computer
- 3 seperate videosignal for RGB
- crosstalk (간섭)이 없다
#### Composite Video - 1 channel
- Luminance와 clor signal이 한 시그널에 전송되어 간섭 발생 가능

#### S-Video, 2signals
- Less crosstalk than comp

### analog tv Broadcating
- 동영상과 음성 신호 동시 전송
- NTSC경우 브라운관에 영상 재생시 525개 주서선필요
  - 30 frame/sec(fps)
  - 주사방법 : 순차 주사, 비월 주사

### analog color tv
flickering을 해결하기위해 Inlerlace scan 사용
- Inlerlace scan
  - 1개의 frame에 대해 2번의 scan을 하게됨
  - 1개 frame에 대해 2개의 field
- 30 fps -> 60 fps의 착시효과