# 멀티미디어 기말고사 정리

## 벡터 그래픽
- 벡터 그래픽
  - 장점 : 파일사이즈가 작고, 확대했을때의 손실이 없다
  - 단점 : 색 변화에 약하고, 디스플레이 출력이 느리다
- 모델링과 렌더링의 차이
  - 모델링 : Set up geometrical feature of object
  - 렌더링 : 3D객체에 색, 질감, 표면 특성을 부여하는것으로 ray-casting, ray-tracing, radiosity가 있다.
  - anti-aliasing은 gray algorithm을 적용하여 해결
- Non-zero winding number rule
  - 임의의 선을 그려서 counter 0부터 시작하여 edge를 만나면 1을증가하고 그다음 만나면 1을 감소시키는것을 반복하여 어디가 안이고 어디가 바깥인지 알수 있도록 하기 위해 반든 방법

## 이미지 프로세싱
- JPEG
  - Image preparation
    - segment image in 8X8 Macro Block(MB)
  - DCT 
    - Transform spatial-domain image into frequency domain, At this point, Low frequency has large energy, but high frequency has less energy
  - Quantization
    - Quantize frequency coefficients using quantization table
  - Zigzag Scan
    - Map 8X8 quantized coefficient into 1X64 vector
  - DPCM 
    - Applied to DC components of DCT quantized values
  - RLE(Run lenth) coding
    - Applied to AC components of DCT quantized values
  - Entropy coding (Huffman Coding)
- RGB와 CMY/K의 차이 
  - RGB ~ additive mix로 섞을수록 밝아진다, monitor, color TV
  - CMY/K ~ subtractive mix로 섞을수록 어두워진다, color ink printer, publishing

## 기타 등등
- Fractal의 self-similarity
  - 재귀적으로 같은 구조를 계속해서 모든레벨에 걸쳐 반들어 내는것을 자기 유사성이라 한다.
- "Distribution of image histogram determines the (brightness) of image, while the width of  histogram affects the (contrast) of image."

## VIDEO
- "Human eye is very sensitive to the (brightness), but less sensitive to (color)."
- By using YUV, YIQ color mode, how can you save BW(bandwidth) compared to RGB color mode in video signal transmission by knowing the fact in
  - 사람의 눈이 색보다는 밝기에 민감하다는 점을 이용하여 많은 대역폭을 밝기에 할당하고 적은대역폭을 색차에 할당하여 대역폭을 아낄수 있다
- How much of BW can you save in each of YUV, YIQ color mode? Explicitly answer in rough number
  - RGB의 경우 각 색상당 6Mhz가 필요하므로 18Mhz가 필요하지만 YUV,YIQ의 경우 Y=4.2 Mhz, I=1.6 Mhz, Q=0.6 Mhz와 같이 Y(밝기) 색차에 더 적은 대역폭을 할당하여 대역폭을 아낄수 있다.

- Suppose we have analog NTSC video 720(Number of column)X480(Number of row). If we do 4:2:2 chroma sub-sampling in digitization process, how many samples of Luminance Y and Chrominance(Cb, Cr) per frame are taken? If we use 4:2:0 sub-sampling, then how many samples of Luminance and Chrominance per frame are taken? Answer the question in following format.
  - For 4:2:2 sub-sampling
    - Luminance = 720 X 480, Chrominance(Cb) = 360X480, Chrominance(Cr)=360X480
  - For 4:2:0 sub-sampling
    - Luminance = 720 X 480, Chrominance(Cb) = 360X240, Chrominance(Cr)=360X240
  - Data rate (4:2:2) = 30 frame x [(720x480) x 8bit + 2x(360*480) x 4 bit]
  - Data rate (4:2:0) = 30 frame x [(720x480) x 8bit + 2x(360*240) x 4 bit]

- 비디오 압축알고리즘의 두가지 key ideas
  - Spatial(intra frame) compression
    - 프래임을 하나의 이미지로 보고 압축
  - Temporal(inter frame) compression. 
    - 프레임과 프레임간의 차이만을 저장하는 방식으로 압축
  - compression ratio에 미치는 영향이 큰것?
    - Numer of key frames/sec.
frames/sec

- Interlace scanning
  - 하나의 frame을 두개의 field로 나누어 두번 스캐닝하는 방식