Macro block 단위로 압축

## JPEG Encoder structure

### DCT
- spatial domain signal -> frequency components
- 저주파 영역에 비트할당 많이, 고주파 영역에 비트할당 적게 -> energy compaction
- Data Reduction

### Quantization Table(JPEG)
- DCT를 Quantization Table로 나누어 bit save
- Quantization Table 숫자가 클수록 압축률 증가, 작을수록 압축률 감소

### ZigZag Scan
- DC component(0,0) : DPCM coding
- AC component(not 0, not 0) : 0과 1의 반복패턴이 많으면 Run Length Encoding을 사용

### Entropy Coding
Huffman coding

### Decoding

- Sequntial Mode
- Progressive Mode

### JPEG 2000
- DWT : Wavelet decomposition : coarse -> fine

## Basic Image Processing
- Pixel - Point Processing
  - Histogram
- Pixel - Group Processing
  - filtering
- Geometrical transformation
  - Interpolation(bitmap 이미지 확대 알고리즘), reflection, rotation

### Histogram
#### 밝기
- 화소가 가진 명암값에 대한 막대그래프 
  - 어두운 영상 -> 왼쪽 편중(Low key)
  - 밝은 영상 -> 오른쪽 편중(High Key)
  - 이상적인 영상 -> 균일한 분포
- Image tone을 통해 밝기 대비를 조정할 수 있다. 
- 이미지의 밝기는 히스토그램의 분포에 따라 달라진다.
#### 대비
- Low Contrast : 폭이 좁게 분포
- High Contrast : 좌우로 넓게 분포 
### control
- 밝기
  - pixel의 값을 더하고 빼기, 255,0을 넘어갈경우 255, 0으로 truncate
- 대비
  - Histogram Equalization
  - 좌우로 히스토그램을 넓혀 대비를 개선
  - new pixel = [(oldpixel -low) / (high - low)] * 255
    - 좌측 끝을 0으로 이동한 다음 폭을 255로 넓히기
### S-curve mapping
- 밝기와 대비 조정을 위해 사용

### Pixel Group Processing
based on Mask
- Mask = template window kernel filter
- convolution = spatial filtering with mask

#### Image Smoothing - LPF
convolutino mask with equal weights

#### Gaussian Blurring (low pass filter)
- sum = 1
#### Sharpening (high pass filter)
#### Embossing Effects
#### Noise Filtering
- Median Filter : 픽셀값을 정렬후 이미지에 삽입
#### Edge Detection

### Interpolation
- Nearest Neighbor
- Bilinear Neighbor
  - 인접 픽셀값을 통해 추정
- Bicubic interpolation

### rotation
### reflection