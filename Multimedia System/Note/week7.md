# 7주차

### 갤럭시 시리즈

- PPI < 600
  - Technical limitation in OLED mask
- VR과 AR을 위해서는 PPI > 800
![](./img/캡처.JPG)
- 동일한 해상도라도 화면사이즈가 다르면 PPI가 달라진다

### 디지털 카메라
- Low end - 72PPI
- High end > 300 PPI
- Comparing image quality
  - 3M - 72PPI, 300PPI
  - 3M, 6M camera 300PPI
- Size of CMOS sensor

### 모니터
- 모니터의 이미지는 **array of pixels**
- Set pixel value by **graphics library**

### 컴퓨터 그래픽
2D, 3D그래픽이나 애니메이션은
- **모델링**-**렌더링** 두단계를 거쳐서 만들어 진다.
  - 모델링 - 뼈대만드는 작업
  - 렌더링 - 입체감


### Bitmap & Vector
- 비트맵 이미지
  - array of pixel value
- Vector graphic
  - 그래픽 객체가 벡터단위로 표현(Represented as vector)
  - 벡터값을 픽셀 값으로 매핑해줘야 함(need to convert vector values to pixels)

### Memory Requirement

- Bitmapped
  - Bitmapped **w * h** using **c** bytes
  - Per pixel occupies **w * h * c**  
- Vector
  - 그림의 **복잡도**에 따라 파일사이즈 결정

Compare memory requirements
- Bitmap image
  - 128 * 128 * 3 = **48kbytes**
- Vector graphic in SVG format(W3C)
  - metadata `<path fill= ... />`
  - 86 bytes + some SVG header = 284 bytes

#### 중요
Vector Graphic

Mathmatical description of gemoetry
- Less Memory
- Easy and no quality loss for zoon in, transforamtion| Good for gradual color change representation
- Slow disply speed on monitor
- 점차적으로 바뀌는 색 표현에 취약

Bitmap Image
- Pixels
- Good for gradual color change
- Fast display speed on momitor
- Large memory
- Complicate and low quality for zoom in, transformation