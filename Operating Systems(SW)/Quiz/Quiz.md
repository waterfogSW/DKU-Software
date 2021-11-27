# Operating System - QUIZ

## Week 1-1

### Operating System과 Application의 차이점

Operating System(이하 OS)의 경우 Kernel mode에서 Application의 효율적이고 안정적인 실행을 위한 컴퓨터 자원을 제공하는 역할을 합니다.

이러한 컴퓨터 자원 중 일부는 멋대로 접근해서는 안됩니다. 가령 메모리를 할당하는데 있어 할당한 영역의 일부가 OS나 타 Application의 핵심적인 영역을 침범하면 원치 않은 결과를 초래할 수 있습니다. 이러한 일을 방지하기 위해 user space와 kernel space를 따로 두어 Process가 시스템 자원을 필요로 할때, OS는 kernel mode에서 Application이 시스템 자원에 안정적이고 효율적으로 접근하는 인터페이스(eg, system call)를 제공합니다.

반면, Application은 User mode에서 isolate하게 동작을 하여 Application의 악의적이거나 우발적인 동작이 타Application이나 OS에 미치는 영향을 줄입니다. 필요시 Application은 System call을 통해 시스템 자원을 제공받을 수 있습니다.

### Chapter1의 Dialog에 등장하는 철학자

### **공자 (Confucius)**

<center>

```text
나는 듣고 잊는다.
나는 보고 기억한다.
나는 행하고 이해한다.
```

</center>

비록 공자에 대해서 잘 알지 못하고, 이 격언의 배경에 대해서도 잘 알지 못하지만 배우는 것에 있어서 평소에 가지고 있던 생각이랑 비슷한 것 같아 공감이 많이 되었습니다.

어떤 작업을 반복해서 몸에 익히다 보면 별다른 자각없이 일을 해내는 자신을 발견할 수 있습니다. 제 개인적인 경험으로 수십줄의 기타 악보를 보면서 매일치다 보면 악보 없이도 곡을 연주할 수 있었습니다. 몇 달이 지나 까먹더라도 도입부만 기억해내면 손가락이 먼저 움직였습니다.

조금 비약인 이야기일지 모르지만 과거에 운동을 했던 사람이 중간에 휴식기를 거쳐 근육량이 줄어들더라도 근육 세포의 핵은 줄어들지 않는다는 &quot;머슬 메모리&quot; 라는 이론이 있습니다. 이 이론에 따르면 한창 운동을 하던 때의 세포의 핵이 남아 있기 때문에 휴지기를 거치더라도 빠르게 퍼포먼스를 회복할 수 있습니다.

비슷한 맥락인 것 같습니다. 단순히 강의를 듣기만 하면 잊게 되고, 보기만 하면 짧은 기억으로만 남습니다. 직접 예제를 여기저기 바꾸어 보면서 실행해보고 결과물을 만들어 낼 때 이해하고 평생 써먹을 수 있는 &quot;머슬 메모리&quot;가 되는 것 같습니다.

---

## Week 1-2

### OS가 관리하는 자원

- Physical resource : CPU, DRAM, Disk, Flash, Network, ...
- Virtual resource : Process, Virtual memory, File, Directory, Protocol, Security, ...

OS는 Physical resource를 Virtual resource로 추상화 하여 관리합니다. 대표적인 예로 CPU의 경우 process와 thread로, DRAM의 경우 virtual memory로, Disk는 File로 추상화 합니다.

### ./cpu A & ···

&는 앞선 명령어의 백그라운드 수행을 지시하고 뒤따르는 명령어를 수행합니다. 해당 코드를 실행하게 되면 네 프로세스가 동시에 실행되어 스케쥴링된 순서에따라 A,B,C,D를 반복하여 출력하게 됩니다.
 교수님 강의를 듣기전에 OSTEP에서 소스코드를 실행해 보았는데 ctrl+c가 되지 않아 당황했습니다.

## Week 2-1

### Disk와 DRAM의 차이

DRAM과 DISK모두 저장장치의 역할을 하지만 각각이 가지고 있는 특징이 다르기 때문에 서로 다른 용도로 사용이 됩니다.

DRAM의 경우 속도가 뛰어나지만 가격이 높고, 휘발성이 있어 데이터가 영구적으로 저장되지 못한다는 특징이 있습니다. 또 바이트 단위로 데이터에 접근합니다. 때문에 CPU가까이(데이터의 이동이 잦은곳)에서 프로세서가 필요로 하는 데이터를 저장한 후 공급하는 주기억장치의 역할을 합니다.

반면 DISK의 경우 DRAM에 비해 현저하게 느린 데이터 전송속도를 가지지만, 휘발성이 없고 섹터단위로 데이터에 접근합니다. 때문에 데이터를 저장하는 보조기억장치 역할을 합니다.

개인적으로 램의 성능을 테스트해보고 싶어서 램을 주 기억장치로 사용하는 램디스크를 사용해 속도를 테스트 해보았습니다. 램디스크는 RAM을 주 기억 장치가 아니라 보조 기억 장치로 사용하는 개념입니다. 메모리를 기반으로 한 파일시스템이기 때문에 SSD, HDD에 비해 속도면에서 아주 우수하며 caching또는 작업 디렉토리 용도로 사용될수 있습니다. 제 개인적인 경험으로는 DRAM의 휘발성을 생각하고 RAM disk를 윈도우 인터넷 익스플로러의 임시파일 경로로 활용했던 경험이 있습니다.

아래 명령어를 통해 램 디스크를 마운트 한후

```c
$ sudo mount -t tmpfs -o size=1G tmpfs /workspace/ramdisk
```

램디스크가 성공적으로 마운트 된것을 확인하고

```c
$ df -h
...
D:\             466G  111M  466G   1% /mnt/d
tmpfs           1.0G     0  1.0G   0% /workspace/ramdisk
```

간단하게 dd유틸리티를 사용하여 속도를 테스트 해보았습니다.

on RAM disk
```c
$ dd if=/dev/zero of=/workspace/ramdisk/perf bs=256M count=1; rm -f /workspace/ramdisk/perf

1+0 records in
1+0 records out
268435456 bytes (268 MB, 256 MiB) copied, 0.100249 s, 2.7 GB/s
```

on disk
```c
$ dd if=/dev/zero of=/workspace/perf bs=256M count=1; rm -f /workspace/perf

1+0 records in
1+0 records out
268435456 bytes (268 MB, 256 MiB) copied, 0.159167 s, 1.7 GB/s
```

속도면에서 차이가 있는것을 확인할 수 있었습니다.

### Trap vs Interrupt

#### Trap

> Trap은 user program이 OS에 특정 동작을 지시하는 signal로 동기적으로 발생하며, 주로 0으로 나눈다던지 잘못된 메모리를 참조하여 Page fault가 발생한경우, 시스템 호출을 사용한 경우가 있습니다.  
>Software interrupt라고 불리기도 합니다.

#### Interrupt

> Interrupt는 프로그램 실행 도중 하드디스크, 그래픽카드, 입출력 장치 등 하드웨어 장치가 프로세서로 보내는 signal로 비동기적으로 발생합니다. 키보드를 누르거나 마우스를 움직이는 동작도 Interrupt를 발생시킨다 볼 수 있습니다.  
>Hardware interrupt라고 불리기도 합니다.

## Week 2-2

### 1.OS makes use of a **context switch** mechanism and a **scheduling** policy to virtualize CPU

### 2. State of parent and child process

먼저 fork()이후 자식프로세스가 생성되는데 이때 부모와 자식중 어느 프로세스가 먼저 CPU에 스케쥴링 될지는 정해져 있지 않으므로 두가지 경우로 나누어 설명하겠습니다.(리눅스 2.6.32 이후에는 부모가 먼저 실행되는것이 기본값이 되었습니다). 또한 싱글코어이며 어느 프로세스든 끝날때 까지 중간에 time out이 일어나지 않는다는 가정을 하겠습니다.

더하여 fork()이후에는 자식프로세스의 상태가 new일지 ready일지 고민하고 있었는데 문의 게시판에서 fork()이후 프로세스 상태에 대한 이준석학우님의 질문과 교수님의 답변을 보고 참고가 되어 fork()이후 메모리에 자리가 충분히 있다는 가정하에 자식프로세스의 상태는 ready로 생각하였습니다.

#### Parent first

>부모프로세스는 **line10**직후에도 **running**상태로 계속 수행하고 **line15**는 조건 분기에 해당하지 않으므로 지나가고 line 17에서 wait() 시스템 호출을 만나 line17이 끝나면 자식프로세스의 종료를 기다리는 waiting상태가 됩니다.
>
>자식프로세스는 **line10**의 fork()직후에는 **new**상태였다가 ready를 거쳐 부모프로세스가 waiting상태일때 scheduler가 dispatch하여 running상태가 됩니다. **line15**직후에도 **running**상태이며 **line18**은 조건에 해당하지 않으므로 수행하지않고 return을 만나 terminated됩니다.
>
>waiting상태의 부모프로세스는 자식 프로세스의 종료 signal인 SIGCHLD를 받게되어 ready상태를 거쳐 running상태가 됩니다. **line18**직후 running상태였다가 return을 만나 terminated됩니다.

| Current Run | Line   | Parent  | Child      |
| ----------- | ------ | ------- | ---------- |
| Parent      | line10 | Running | Ready      |
| Parent      | line15 | Running | Ready      |
| Child       | line15 | Waiting | Running    |
| Child       | line18 | Waiting | Running    |
| Parent      | line18 | Running | Terminated |

#### Child first

>**line10**직후 부모프로세스는 **running**상태였다가 ready상태가 되고 자식프로세스는 **new**상태였다가 스케쥴링 되어 running상태가 되고 다음 문장을 수행합니다. **line15**직후에도 **running**상태였다가 **line18**은 수행하지 않고 return을 만나 terminated됩니다.
>
>이후 부모프로세스는 scheduler가 dispatch하여 **line15**는 조건 분기에 해당하지 않으므로 지나가고 **line18**직후 running상태였다가 return을 만나 terminated됩니다.

| Current Run | Line   | Parent  | Child      |
| ----------- | ------ | ------- | ---------- |
| Parent      | line10 | Running | Ready      |
| Child       | line15 | Ready   | Running    |
| Child       | line18 | Ready   | Running    |
| Parent      | line15 | Running | Terminated |
| Parent      | line18 | Running | Terminated |

눈으로 꼭 확인해보고 싶었는데 코드에 프로세스의 상태를 가져오는 함수를 사용하자니 ready상태가 되었을때의 상태를 알수가 없었고, 프로세스상태를 모니터링 할수 있는 마땅한 유틸리티가 생각나지 않았습니다.

다만 ftrace를 통해 프로세스를 추적해 보았는데 fork()직후에도 부모프로세스가 수행을 하다가 wait()시스템 콜을 만나면 바로 자식프로세스로 context switch를 하고 자식프로세스가 끝나면 부모프로세스로 context switch가 일어나는 과정을 볼수 있어서 흥미로웠습니다.

![img](week2-2q.JPG)
![img](week2-2q2.JPG)
![img](week2-2q3.JPG)

여기서부터는 개인적인 사족입니다:)

ftrace를 사용하면서 처음에는 로컬에서 ftrace를 마운트하고 "echo function_graph > current_tracer" 명령을 통해 tracer를 선택하자마자 바로 cpu사용률이 급격히 증가해서 급하게 꺼버렸습니다. 아마 로컬에서 실행하다 보니 워낙 다른프로그램들이 실행되던것들이 많아서 그랬던것 같습니다. 시스템 프로그래밍 시간에 제공해주신 학교서버에서는 아쉽게도 권한문제로 ftrace를 마운트 할 수 없어서 AWS인스턴스로 테스트 했습니다. 어떤것을 테스트할때는 깔끔하게새로운 서버를 만들어서 테스트하는게 좋은것 같습니다.

개인적으로 퀴즈가 너무 재밌어서 다른 학우분들의 좋은 답변이 있다면 꼭 보고싶습니다. 감사합니다...


## Week 3-1

### 1. Mode switch, Context switch 몇번?

1. 프로세스 X가 Sys.call을 호출하고 mode switch가 1번, 이후 프로세스 X가 blocked, 프로세스 Y가 running 상태가 되면서 context switch가 1번
-> mode switch 1번, context switch 1번

2. 프로세스 Y가 Interrupt를 받아 mode switch가 1번, 이후 프로세스 Y가 Ready, 프로세스 Z가 running상태가 되면서 context switch가 1번 일어납니다.  
-> mode switch 1번, context switch 1번

3. 프로세스 Z가 Sys.call을 호출하고 mode switch가 1번일어납니다.  
-> mode switch 1번

4. 프로세스 Z가 Interrupt를 받아 mode switch가 1번, 이후 프로세스 Z가 Ready, 프로세스 X가 running상태가 되면서 context switch가 1번 일어납니다.  
-> mode switch 1번, context switch 1번

5. 프로세스 X가 Interrupt를 받아 mode switch가 1번, 이후 프로세스 X가 Ready, 프로세스 Y가 running상태가 되면서 context switch가 1번 일어납니다.  
-> mode switch 1번, context switch 1번

총 Mode Switch 5번 / Context Switch : 4번

### 2.Hyper-threading 기술에서 AS(Architectural state)는?

Architectural state(이하 AS)는 범용 레지스터, 제어 레지스터와 같이 프로세스의 상태를  유지하는 프로세서의 일부를 말합니다.

Intel의 Hyper-threading기술은 하나의 물리적 프로세서가 2개의 AS를 가집니다. 이러한 기술이 적용된 코어에서는 전체 프로세스 제어 블록을 제거하고 다른 프로세스 제어 블록을 로드할 필요 없이 사전에 프로세스의 상태가 저장된 AS로 바꾸기만하면 되므로 context switch로 인한 오버헤드가 줄어듭니다.

>(Intel® Hyper-Threading Technology Technical User’s Guide)

## Week 3-2

1. 점심을 위해 식당을 정할 때 우선적으로 고려하는 것

저의 경우 식당 직원의 Response time을 가장 우선적으로 고려합니다. 식당에 들어갔는데 메뉴판과 물도 안주고 오래 기다리게 되면 그것만큼 짜증나는게 없습니다.

그렇다고 해서 음식을 만드는데 Round Robin방식을 적용하게 되면 오래걸리는 음식은 늦게 나오게 되고 짧게 걸리는 음식은 금방 나오게되어 일부 손님들은 자기가 먼저 주문했는데 옆테이블의 음식이 먼저나와 화가나는 불상사가 생기게 됩니다.

따라서 홀 직원에게는 Response time을 고려하여 RR정책을 적용하고, 주방 직원에게는 FIFO을 적용하는것이 손님 입장에서는 가장 좋은것 같습니다.

Matric에 따라서는 

- Response time을 중점에 둔다면 성격이 급한 손님의 입장에서는 주문할수 있는 응답이 빨라 좋을것 같습니다.

- Fairness를 중점에 둔다면 앞서 말한 불상사가 생기는 경우가 적어질듯 합니다. 

- Throughput을 중점에 둔다면 식당의 회전률이 빨라져 업주 입장에서 좋을것 같습니다.  

2. 문맥 교환 부하가 0ms가 아니라 100ms로 바뀌면

**SJF방식**

- Turnaround time
  - A : 5s
  - B : 5 + 0.1 + 5 = 10.1s
  - C : 10.1 + 0.1 + 5 = 15.2s
  - Total : 30.3s
  - Average : 10.1s
- Response time
  - A : 0s
  - B : 5 + 0.1 = 5.1s
  - C : 5.1 + 5 + 0.1 = 10.2s
  - Total : 15.3s
  - Average : 5.1s

**Round Robin 방식**

- Turnaround time
  - A : 13 + 0.1*12 = 14.2
  - B : 14.2 + 1.1 = 15.3
  - C : 15.3 + 1.1 = 16.4
  - Total : 45.9
  - Average : 15.3
- Response time
  - A : 0s
  - B : 1.1s
  - C : 2.2s
  - Total : 3.3s
  - Average : 1.1s

| Time(sec)      | SJF  | RR   |
| -------------- | ---- | ---- |
| **Turnaround** | 10.1 | 15.3 |
| **Response**   | 5.1  | 1.1  |

따라서 response time을 중요하게 생각하면 RR방식을 turnaround time을 중요하게 생각하면 SJF방식을 적용하는것이 좋습니다.

## Week 4-1

### 1. What is the HRRN policy shown in page 24

HRRN방식은 Highest Respone Ratio Next의 약자로 프로세스의 우선순위를 (대기시간 + 실행시간) / 실행 시간 으로 결정하는 비선점형 스케줄링 방식입니다. 

SJF에서는 실행 시간이 긴 프로세스는 계속해서 CPU를 할당받을 수 없다는 단점이 있지만 HRRN방식에서는 CPU를 할당 받지 못한 시간(대기시간)만큼 우선순위가 높아지므로 SJF의 단점을 보완했다고 할 수 있습니다. 

### 2. Compare the average response time and the number of context switch

- q = 1
  - Average Response Time : (0 + 0 + 0 + 0 + 0) / 5 = 0
  - Num of Context Switch : 18
- q = 2<sup>i</sup>
  - Average Response Time : (0 + 0 + 0 + 1 + 0) / 5 = 0.2
  - Num of Context Switch : 12

time qauntum이 2<sup>i</sup>일때 time qauntum이 2인 큐에 있는 B에 의해 D의 response time이 늦어 졌지만 context switch의 횟수가 줄어들었으므로 context switch로 인한 overhead를 고려하여 time qauntum을 적절하게 사용하면 성능향상에 도움이 될것 같습니다.

## Week 4-2

### 1. 

We need to consider two things for multiprocessor scheduling.  
One is **Load balancing** that tries to distribute jobs evenly among CPUs and the other is **Cache affinity** that tries to run a job on the same CPU where the process ran previously. 

### 2. VM A,B,C 각각의 Tickets이 1,3,5일때

A,B,C각각의 stride를 구하기 위한 큰 숫자로 300을 가정하였습니다.
- Stride(A) = 300 / 1 = 300
- Stride(B) = 300 / 3 = 100
- Stride(C) = 300 / 5 = 60

각각의 pass value가 0에서 부터 시작하여 모든 pass value가 동일할 경우엔 알파벳 순으로 stride를 더해주었습니다.

첫번째 수행에서는 모든 pass value가 동일하므로 A, 
두번째 수행에서는 가장 작은 pass value를 가진 값중 앞선 알파벳 B,
세번째 수행에서는 가장 작은 pass value C,
그다음 부터 계속해서 가장작은 pass value를가진 process를 수행하고 stride값을 더해주어 나가는 식입니다.

| Pass(A) | Pass(B) | Pass(C) | Who Runs? |
| ------- | ------- | ------- | --------- |
| 0       | 0       | 0       | A         |
| 300     | 0       | 0       | B         |
| 300     | 100     | 0       | C         |
| 300     | 100     | 60      | C         |
| 300     | 100     | 120     | B         |
| 300     | 200     | 120     | C         |
| 300     | 200     | 180     | C         |
| 300     | 200     | 240     | B         |
| 300     | 300     | 240     | C         |
| 300     | 300     | 300     | ...       |

위의 표에 따라 A,B,C가 각각 1:3:5의 비율로 실행되는것을 확인 할 수 있었습니다.

이를 확인하기 위해서 간단하게 stride 스케줄링 코드를 작성해 보았습니다.

```c
#include <stdio.h>
#define PROC_NUM 3
#define COMMON 300

typedef struct{
    char proc_id;
    int tickets;
    int stride;
    int pass_val;
}Process;

void initProcess(Process *p) {
    p[0].proc_id = 'A';
    p[0].tickets = 1;
    p[0].pass_val = 0;

    p[1].proc_id = 'B';
    p[1].tickets = 3;
    p[1].pass_val = 0;

    p[2].proc_id = 'C';
    p[2].tickets = 5;
    p[2].pass_val = 0;
}

void setStride(Process *p){
    for (int i = 0; i < PROC_NUM; i++) {
        p[i].stride = COMMON / p[i].tickets;
    }
}

void stride_sch(Process *p) {
    for(int i = 0; i < 10; i++) {
        int min_idx = 0;
        int min_pass = 1000; //가장 작은 pass val 을 구하기위한 임의의 숫자

        /* 가장 작은 pass val을 가진 process의 index 구하기*/
        for (int i = 0; i < PROC_NUM; i++)
        {
            if(p[i].pass_val < min_pass) {
                min_pass = p[i].pass_val;
                min_idx = i;
            }
        }
        for (int i = 0; i < PROC_NUM; i++)
        {
            printf("%3d ",p[i].pass_val);
        }
        
        p[min_idx].pass_val += p[min_idx].stride;
        printf("%c \n", p[min_idx].proc_id);
    }
}

int main(){
    Process p[PROC_NUM];

    initProcess(p);
    setStride(p);
    stride_sch(p);
}
```
동일한 결과가 출력되는것을 확인할 수 있었습니다. 

figure 9.3에 대해서도 동일하게 수행을 해보았습니다.  
각 티켓으로 나눌 임의의 큰숫자 COMMON의값을 10000으로 변경하고  
티켓의 값을 각각 100, 50, 250으로 변경해 주었습니다.

같은 결과를 확인할 수 있었습니다.

## Week 5-1

### 1. fork()와 pthread_create()의 차이점을 컴퓨팅 자원 (CPU, 주소 공간, 파일)이라는 용어를 사용하여 설명하시오

`fork()`는 새로운 프로세스를 만들어 냅니다. 기존에 기존에 CPU에 스케줄링 되어 있던 프로세스와 다른 register, code, data, heap, stack과 같은 새로운 프로세스를 위한 주소공간과 files을 생성합니다.

반면 `pthread_create()`의 경우 기존에 CPU에 스케줄링 되어있던 Thread의 code와 data, heap, files를 공유하지만 독자적인 register와 stack 주소공간을 생성하여 사용합니다.

이러한 차이로 인해 스레드를 생성하는 `pthread_create()`는 stack과 register와 같이 exclusive한 자원만 만들기 대문에 프로세스를 생성하는 `fork()`에 비해 속도가 훨씬 빠릅니다. 하지만 같은 공유자원에 대해 여러제어 흐름이 생성되기 때문에 동시성제어 문제가 발생하기도 합니다. 

두함수의 속도차이를 비교하기 위해 간단히 프로그램을 작성하여 비교해 보았습니다.

```c
void *mythread(void *arg) {
    return NULL;
}

int main() {
    double sum, avg;
    struct timespec begin, end;
    pthread_t p;

    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        clock_gettime(CLOCK_MONOTONIC, &begin);
        if(fork() == 0) { exit(0);}
        // pthread_create(&p,NULL,mythread,"A");
        clock_gettime(CLOCK_MONOTONIC, &end);
        sum +=  (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    }
    avg = sum / 1000;
    printf("fork           : %lf\n", avg);

    sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        clock_gettime(CLOCK_MONOTONIC, &begin);
        pthread_create(&p,NULL,mythread,"A");
        clock_gettime(CLOCK_MONOTONIC, &end);
        sum +=  (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    }
    avg = sum / 1000;
    printf("pthread_create : %lf\n", avg);
    return 0;
}
```

결과는 다음과 같았는데, 프로세스 또는 스레드 생성후 종료까지 포함된 시간이기 때문에 생성시간만 정확히 측정할 수 있는 방법을 고민해야 할 것 같습니다. 

### 2. 그림 26.6의 프로그램을 사용하여 공유자원, 경쟁상태, 원자성, 임계영역, 상호배제이라는 단어를 설명하시오. (1.5점) 

그림 26.6에서 `pthread_create()`를 통해 생성된 두 스레드 A, B는 `static volatile int counter = 0;`로 전역변수로 선언된 `counter`변수를 **공유자원**으로 사용하게 됩니다.

`t0.c` 파일을 `gcc -S t0.c -pthread`를 통해 어셈블리 코드로 변환하였을때 `mythread()`함수에서 **임계영역(critical section)** 을 찾을 수 있습니다. 

```c
mythread:
  ...
	movl	counter(%rip), %eax   // line 1
	addl	$1, %eax              // line 2
	movl	%eax, counter(%rip)   // line 3
  ...
```

현재 `counter`변수의 값이 100이라고 가정합니다. *스레드A*가 counter변수라는 공유자원에 대해 `line 1~2`을 수행하고 `line3`을 수행하기 전에 *스레드 B*로 thread swtich가 발생하여 `line 1 ~ 3`을수행한 후 *스레드A* 가 `line 3`을 수행한다면 둘다 같은 101이라는 값을 counter변수에 store하게 됩니다. 이렇게 한 스레드가 모든 과정을 수행하지 않고 여러스레드가 동시에 접근하게 되면 **원자성**이 보장되지 않았다 라고 이야기 합니다.

여기서 **원자성**을 보장해 주기 위해서 하나의 스레드만 임계 영역에서 수행할수 있도록 하는 방법을 **상호배제**라고 합니다. 이러한 상호 배제는 mutex나 semaphore를 통해 달성할 수 있습니다.

다음은 `mythread()`함수의 임계영역을 mutex를 통해 상호배제를 구현하여 원자성을 보장해 준 예입니다.

```c
void *mythread(void *arg) {
    printf("%s : begin\n", (char *) arg);
    for (int i = 0; i < 1e7; i++) {
        pthread_mutex_lock(&lock);
        counter = counter + 1;
        pthread_mutex_unlock(&lock);
    }
    printf("%s : done\n",(char*) arg);
    return NULL;
}
```

mutex 적용전


mutex 적용후 

## Week 5-2

### 1. 그림 28.1에서 설명된 락 메커니즘이 정확히 동작하는지, 만일 정확하지 않다면 그 이유를 설명하시오

```c
void lock(lock_t *mutex) {
    while (mutex->flag == 1); // line 1
    mutex->flag = 1;          // line 2
}
```

line 1과 line 2사이에서 인터럽트되어 다른 스레드로 context swtich가 일어날 수 있습니다. 이경우 두 스레드 모두 임계영역에 진입하여 동작을 수행할 수 있기때문에 완벽하게 상호배제를 달성하기 어렵습니다.

```c
void *mythread(void *arg) {
    printf("%s : begin\n", (char *) arg);
    for (int i = 0; i < 1e7; i++) {
        lock(&mutex);
        counter = counter + 1;
        unlock(&mutex);
    }
    printf("%s : done\n",(char*) arg);
    return NULL;
}
```

figure 26.6의 코드에 28.1의 락 메커니즘을 사용하여 수행을 해보았는데 실제로 잘 동작하지 않았습니다. 특히 다양한 프로그램을 실행중인 제 로컬 환경에서는 정상적인 값(20000)이 출력 되는 경우가 매우 드물었고, 개인적으로 AWS서버를 연결하여 깔끔한 서버 환경에서는 정상적인 값이 출력되는 경우가 잦았습니다.

### 2. Course-grained lock과 Fined-grained lock의 장단점을 논하시오

Course-grained lock의 경우 적은수의 lock으로 넓은범위의 critical section에 lock을 하게 됩니다. 이경우 구현이 간단하지만 병렬화를 통한 이점을 가지기 힘듭니다.

반면 Fine-grained lock의 경우 많은 수의 lock을 통해 좁은 범위의critical section에 lock을 하게 됩니다. lock의 개수가 많은만큼 구현이 어렵고 오버헤드가 발생하지만 각 critical section에 스레드가 개별적으로 접근할 수 있게되어 병렬화를 통한 이점이 큽니다.

Fine-grained lock을 구현하기 위해서 프로그래머는 공유자원의 구조를 각 부분으로 분할하고 각 부분에 대한 상호 배제를 구현해야 합니다. 예를 들어서 연결리스트의 모든 부분을 하나로 Lock하는것은 Course-grained lock, 각 노드에 대한 Lock을 구현하는것을 Fine-grained lock이라 할 수 있습니다. 

과거 인텔에서는 Fine-grained lock의 구현의 어려움을 해결하기 위해 TSX(Transactional Synchronization Extensions)라는 기술을 개발하였습니다.

임계영역에 진입하면 트랜잭션 메모리에 값을 기록하고 이 시점의 다른 스레드는 트랜잭션이 완료되기 전까지 업데이트된 값을 알 수 없습니다. 임계영역을 빠져올때 데이터 충돌이 없다고 판단되면, 실제 메인 메모리에 업데이트된 값을 반영합니다.

현재 TSX는 Meltdown공격을 통한 보안취약점으로 인해 패치되었다고 합니다.

## Week 6-1

### 1. figure 29.7 vs figure 29.8

```c
    pthread_mutex_lock(&L->lock);
    node_t *new = malloc(sizeof(node_t));
    if(new == NULL) {
        perror("malloc");
        pthread_mutex_unlock(&L->lock);
        return -1;
    }
    ...
```

- 그림 29.7의 코드에서는 임계영역에 해당하지 않는 위와 같은 부분이 더 포함되어 있습니다. Lock의 범위가 커지면 커질수록 thread가 병렬적으로 처리할 수 있는 부분이 줄어들어 성능면에서 손해를 보게됩니다. 그림 29.8에서는 이러한 불필요한 부분을 줄여 lock의 범위를 좁혔습니다.

- 29.7의 코드에서는 하나의 lock코드에 대해 2개의 unlock코드가 존재합니다. 이로인해 타이밍 버그가 발생할 수 있기 때문에 그림 29.8에서는 lock과 unlock각각 1개씩 쌍으로 존재하게 구성하였습니다.

### 2. Approximate Counter

Sloppy Counter는 cpu의 개수만큼 local counter를 놓고 local counter가 threshold의 값을 넘어서면 global counter가 업데이트 되는 방식입니다. lock을 여러개로 나눈만큼 lock에 대한 contention은 줄어들었지만, local counter의 값이 모두 업데이트 되지 않은 상태가 존재하기 때문에 global counter는 실제 증가량보다 근사치만큼 존재할 수 있습니다.

이를 해결하기 위해 threshold의 값을 낮추면, 그만큼 scalability가 떨어져 lock으로 인한 성능저하가 크게 발생하게됩니다. 반면 threshold의 값을 키우면 scalability는 좋아져서 성능이 좋아지지만 실제 count값과 global value의 차이가 커지게 됩니다.

이렇게 Approximate Counter에서는 정확성과 성능간의 trade-off가 존재합니다.

## Week 6-2

### 1. Issues in producer/consumer problem

- Mutual exclusion
  - Data buffer에 여러 생산자나 소비자가 접근하여 데이터를 동시에 빼내려 하는경우에 문제가 발생할 수 있습니다.
- Empty case
  - 데이터 버퍼가 비어있는데 소비자가 호출되어 데이터를 꺼내가려 하는 경우 문제가 발생할 수 있습니다.
- Full case
  - 데이터 버퍼가 꽉 차있는데 생산자가 호출되어 데이터를 넣으려는 경우 문제가 발생할 수 있습니다.

### 2. figure 30.8

그림 30.8에서 `count`변수의 값을 확인하기 위해 `if`문을 사용하였습니다. `if`문을 사용할 경우 `count`의 값을 한번 확인하고 다음 문장을 수행합니다. 하나의생산자, 소비자가 존재할때는 정상적으로 작동하지만, 여러 생산자나, 소비자가 존재할 경우 생산이 종료된 이후 또 생산자가 스케줄링 되거나, 소비가 종료된 이후 또 소비자가 스케줄링되어 큐가 꽉 차있는데도 불구하고 또 `put`하거나 큐가 비어있는데도 불구하고 `get`하는 문제가 발생 할 수 있습니다.

예를 들어서 생산자 P, 소비자 C<sub>1</sub>, C<sub>2</sub>이 있다고 가정합니다. 

1. 가장먼저 C<sub>1</sub>이 실행되어 버퍼가 빈 상태인것을 확인하고 대기상태가 되며 락을 해제합니다. 
2. 이후 P가 실행되어 락을 획득, 버퍼를 채우고, 버퍼가 가득찼다는 신호를 보냅니다.  
3. C<sub>2</sub>가 끼어들어 실행되어 버퍼의 데이터를 소비합니다. 
4. C<sub>1</sub>의 실행이 재개되면 앞선 `if`문을 통해 데이터의 존재 유무를 확인했기 때문에 `if`문 이후의 문장을 실행하게 되는데 이때 데이터가 없는데도 불구하고 버퍼의 값을 꺼내려 하게됩니다.

이렇게 시그널이 쓰레드를 준비상태에서 대기상태로 전환만하는 `Mesa semantic`방식에서는  깨어난 스레드가 실제 실행되는 시점에서도 공유변수의 상태가 유지되었다는 보장이 없습니다.

따라서 항상 `if`문 보다는 `while`문을 사용하여 공유변수의 상태를 계속 재확인 하는것이 좋습니다.

## Week 7-1

### 1. figure 31.5

Value의 값이 1일때는 임계영역에 어떤 스레드도 진입하지 않았다는 것이고, Value의 값이 0일때는 임계영역에 1개 스레드가 진입하여 수행중이라는 상태이며, Value의 값이 -1일때는 이미 다른 스레드가 임계영역에서 작업을 수행중이므로 `sem_wait`를 호출한 스레드는 Value의 값이 0이될때까지 sleep상태가 됩니다. 이후 임계영역에 먼저 진입했던 스레드가 `sem_post`를 호출하면 Value값이 증가하여 0이되고 대기하고 있던 스레드를 깨워 작업을 수행하게 됩니다. 

만약 thread 0과 thread 1외에 thread 2가 하나 더있어 수행된다면, thread 0의 `sem_wait()`이후에 thread 1과 thread 2가 `sem_wait()`를 하게되어 Value의 값이 -2가 될 수 있습니다. 이렇게 음수인 경우 Value의 절댓값은 현재 대기중인 스레드의 개수를 나타냅니다.

### 2. Producer/Consumer, Reader/Writer

Producer/Consumer의 경우 생산자와 소비자 모두 임계영역의 값을 변경시키기 때문에 항상 상호배제가 요구됩니다.

반면 Reader/Writer에서 Reader는 임계영역의 값을 변경시키지 않고 읽기만 하기 때문에 여러 Reader가 들어가는 것이 허용됩니다. 따라서 생산자 소비자 문제에 비해 병렬성이 높아 좀더 성능이 좋습니다. 하지만, 여러 Reader로 인해 Writer가 진입하지 못하는 Starvation이 발생할 수 있기 때문에 우선순위에 대한 고려가 필요합니다.

## Week 7-2

### 1. 4-Conditions

1. Mutual exclusion
- 차량이 동시에 교차로(공유자원)을 점유할 경우 충돌이 일어날 가능성이 있습니다. 이 때문에 락을 사용해야할 상황이 생깁니다.
2. Hold and wait
- 1번 차량과 2번 차량이 동시에 교차로에 진입하면, 교차로에서 1번라인에 있는 차량이 2번 라인의 차량 진입으로 교차로의 2번을 사용하지 못하고 교차로 1번에서 대기하고 있는 상황이 발생합니다. 이러한 상황을 Hold and wait라고 하며, 1번차량이 진입하여 교차로 1번과 2번을 한번에 모두 점유하거나, 못하는 두가지 상황만 강제하여 Hold and wait를 예방할 수 있습니다.
3. No preemption for resource
- 교차로의 다른 부분을 점유하지 못하면 교차로에서 빠져나가는것을 No preemption이라고 합니다. 이때 교착상태가 계속되고 불필요하게 진입과 후진을 반복하는 상황을 Live lock이라고 합니다. 
4. Circular wait
- 각 차량이 동시에 교차로 1,2,3,4로 진입하면, 다음 진행해야할 교차로 부분은 다른 차량이 점유하고 있기 때문에 계속 대기하는 상태가 됩니다. 이를 환형대기라고 합니다. 이경우 차량이 교차로를 점유하는 순서를 바꾸어 해결할 수 있습니다. 예를들어 4번라인의 차량이 교차로 1번을 점유하고 난뒤 교차로 4번을 점유하도록 순서 관계를 변경해주면, 4번 차량이 진입했을때 1번차량은 진입하지 못하게 되기 때문에 4번차량은 교차로 1번,4번을 점유하여 빠져나갈 수 있게 됩니다. 

### 2.

- 자원 R5가 남아 있기 때문에 P2는 R5를 점유하고, 종료되어 R2, R4를 반납하게 됩니다. 
- P1와 P3는 각각 R2,R4와 R2를 자원이 남아 점유할 수 있기때문에 종료됩니다.
- P3가 종료됨에 따라 R0자원이 남아있기 때문에 P0는 R0를 점유하여 종료됩니다. 
- 따라서 교착상태가 발생하지 않습니다.

## Week 9-1

### 1. Benifits of DMA (compared to Interrupt-only, PIO)

**Compared to PIO**
- 많은 양의 데이터를 디바이스로 전송해야 할때, Programmed I/O에서는 CPU가 메모리와 device간의 데이터 copy를 수행하기 때문에 다른 프로세스를 수행할 수 있는 시간을 그만큼 낭비하게 됩니다. ![](https://user-images.githubusercontent.com/28651727/116014534-b3eaf580-a670-11eb-84db-67ba0c6f6a18.PNG) 
그림에서 Process 1이 데이터를 디스크에 쓰고자 할때, CPU가 메모리에서 디바이스로 copy작업을 담당하기 때문에 Process 2가 수행될 수 있는 시간이 그만큼 낭비되는것을 확인 할 수 있습니다. 
- DMA는 메모리와 디바이스간의 데이터 전송을 담당하여 CPU의 시간을 효율적으로 사용할 수 있게 해줍니다. ![](https://user-images.githubusercontent.com/28651727/116014682-6458f980-a671-11eb-8de5-fa6d3458f4df.PNG) 
OS는 메모리의 어느위치에 데이터가 있는지, 얼마만큼의 데이터를 복사할지, 어느 디바이스로 전송할지만 알려주면, OS는 데이터 전송을 위한 작업을 마치고 다른 프로세스를 수행할 수 있게 됩니다. 이렇게 데이터 복사작업이 DMA 컨트롤러에 의해 수행되기 때문에 그 시간만큼 CPU는 다른 작업을 수행할 수 있게 되어 CPU를 더 효율적으로 사용할 수 있습니다. 

**Compared to Interrupt only**
- 앞서 설명하 PIO의 경우와 마찬가지로 Interrupt only방식에서도 data copy작업은 cpu가 수행하게 됩니다. DMA방식을 사용하면 그 시간만큼 CPU에 여유가 생기기 때문에 효율적으로 사용할 수 있습니다. 

### 2. Block device driver vs Character device driver
| -        |         Character device          |             Block device             |
| -------- | :-------------------------------: | :----------------------------------: |
| 접근방식 |              Direct               |         Through file system          |
| 전송단위 | Single characters (bytes, octets) |        Entire blocks of data         |
| 종류     |    serial ports,, keyboard etc    | Hard disks, USB cameras, Disk-On-Key |


### Bonus. Linux module loading command

- insmod

## Week 9-2

### 1. Barracuda 디스크에서 순차(sequential)와 랜덤(random) 워크로드에 대해 I/O time과 I/O rate를 계산하시오.

- Random : Seek + Roatation + Transfer per 4KB
  - I/O time
    - T<sub>seek</sub> = 9ms
    - T<sub>rotation</sub> = 4.167ms(7200/(60*1000) = 0.12 rotation per second $\rArr$ 8.333ms $\rArr$ 평균 4.167ms)
    - T<sub>transfer</sub> = 0.038ms(4KB/105MB = 4KB * 1000 / 105 * 1000KB)
    - T<sub>I/O</sub> = 13.205ms
  - I/O rate : 4KB / 13.205ms = 약 0.31MB/s
- Sequntial : One seek/roatation per large data(eg 100MB)
  - I/O time = 9ms + 4.167ms + 952.381ms(100MB/105MB/s) = 965.548ms
  - I/O rate = 100MB/0.965s = 103.627 MB//s

### 2. CPU cache와 buffer cache의 공통점과 차이점을 논하시오. 
**공통점**
- 서로다른 하드웨어간의 속도차이에 의한 병목현상을 극복하기위해 지연쓰기를 하고 이를 통해 성능을 향상시키는것이 목적입니다.
**차이점**
- CPU cache의 경우 CPU와 가까이 위치하여 main메모리의 데이터에 접근하는데 걸리는 시간을 단축하기위해 사용되는 반면, Buffer의 경우 Disk에 위치하며 디스크와의 데이터 교환을 효율적으로 하기위해 사용됩니다.
- CPU cache는 SRAM을 사용하고, Disk buffer는 DRAM을 사용합니다.

## Week 10-1

### 1. 메타데이터의 정의를 설명하시오. stat() API를 통해 알 수 있는 메타데이터 정보의 예를 5개 이상 이름을 쓰시오. (1점) 

메타데이터는 파일과 파일시스템을 관리하기 위해 파일시스템에 의해 생성된 데이터로, 파일의 크기, i-node 번호, ownership 정보, 언제 파일이 접근되었고 수정되었는지와 같은 각 파일에 대한 정보를 담고 있습니다. 

터미널상에서 임의의 파일 hello에 대해 `stat`명령어를 사용하였을때 볼 수 있는 예시입니다. 
```sh
 ✘ san  ~/workspace/2021_Lecture   main ±  stat hello
  File: hello
  Size: 11              Blocks: 8          IO Block: 4096   regular file
Device: 810h/2064d      Inode: 29336       Links: 1
Access: (0644/-rw-r--r--)  Uid: ( 1000/     san)   Gid: ( 1000/     san)
Access: 2021-05-03 09:16:02.240000000 +0900
Modify: 2021-05-03 09:16:07.350000000 +0900
Change: 2021-05-03 09:16:07.350000000 +0900
 Birth: -
```
- 파일 이름, 파일의 크기, Inode번호, Link수, 접근권한, 접근시간, 수정시간 등을 확인할 수 있습니다.

### 2. "mkfs" 명령어를 사용해 VSFS(Very Simple File System)을 만들 때, 4개의 구성 요소(component)의 이름과 기능을 논하시오. (1점)

- Superblock
  - 파일시스템을 관리하기 위한 메타데이터로 데이터 블럭과 inode의 개수가 얼마나 있는지, inode table의 시작부분이 어디있는지와 같은 정보를 담고있습니다.
- Bitmap
  - free space를 관리하기위한 메타데이터로 데이터 블럭을 위한 bitmap, inode를 위한 bitmap이 있습니다.
- Inode
  - 파일을 관리하기 위한 메타데이터로 index node의 줄임말입니다. inode의 크기는 256Byte로 한 블럭당 16개의 inode가 들어갈 수 있습니다. 5개의 블럭이 존재하므로 총 80개의 파일을 생성할 수 있습니ㅏㄷ.
- User data
  - 유저에 의해 생성된 데이터로 파일시스템의 대부분의 공간을 차지하고 있습니다.


### (보너스) 아래 그림에서 "b", "c", "rw", "5", "8", "1"의 의미를 설명하시오. (1점)

- "b", "c"
  - `b`
    - 파일시스템상에서 블록 디바이스를 파일의 형태로 표현한 것입니다
    - 블록디바이스란 하드디스와 ,CD/DVD와 같은 저장장치를 말하며, 블록이나 섹터 등의 정해진 단위로 데이터를 전송합니다.
  - `c`
    - 파일시스템상에서 캐릭터 디바이스를 파일의형태로 표현한 것입니다
    - 캐릭터 디바이스에는 키보드, 마우스, 테이프, 모니터, 프린터 등이 있으며, byte단위로 데이터를 전송합니다.
  - 이외에도 디렉토리를 가리키는 `d`, 심볼릭 링크를 가리키는 `l`, regularfile을 가리키는 `-`등이 있습니다.
- "rw"
  - 3글자씩, user, group, other의 파일에 대한 권한을 가리키며, rw는 읽고 쓸수 있는 권한이 있다는 뜻입니다.
- "5", "8"
  - 파일의 크기(size)를 나타냅니다.
- "1"
  - hard link의 개수를 나타냅니다.

## Week 10-2

### 1. 70KB 크기의 a.out 파일을 생성할 때 데이터 영역(data region)에서 몇개의 디스크 블록을 할당하는가? (1점) 

1개의 디스크 블록의 크기가 4kb인 파일시스템에서, direct pointer로 할당할 수 있는 디스크 블록의 크기는 48kb가 최대이므로 데이터 영역에서  1개의 index블록을 더하여 12개의 데이터 블록 + 1개의 1인덱스 블록 + 6개의 데이터블록 순서대로 총 19개의 데이터블록을 할당하게 됩니다. 

### 2. 오른쪽 그림에서 알 수 있듯이 파일을 읽을 때 (또는 쓸 때) inode와 데이터 영역을 번갈아 접근하는데, 이때 탐색 거리(seek distance)가 커져 성능 저하의 가능성이 발생한다. 이 문제를 해결할 수 있는 아이디어를 제시하시오. (1.5점)

가용공간의 여러군데에 inode를 복사하여 현재 헤더의 위치에서 가장 가까운 inode를 참조하도록하여 탐색거리에 의한 성능저하를 최소화 하는 방법이 좋을것 같습니다. 이경우에는 파일을 쓰는데에 가용공간을 확인하고 해당공간에 inode를 복사해야 하기 때문에 쓰기의 오버헤드가 크지만, 읽을때의 오버헤드를 감소시킬수 있을것이라 생각합니다.

## Week 11-1

### 1. 외부 단편화가 발생하는 이유, defragmentation 도구의 장점

 ostep에서의 그림과 같이 파일 B와 D가 삭제하지 않을 파일을 사이에 두고 삭제되면 디스크의 유휴공간(free space)이 띄엄띄엄 생깁니다.
이때 파일 E를 배치하고자 하면 파일 B, D가 삭제된 유휴공간에 배치하게 되어 파일 E가 불연속적으로 배치됩니다. 이러한 과정을 통해 외부단편화가 발생하게 됩니다.

이러한 외부단편화가 발생하게 되면 파일 E를 읽기 위해 E1, E2를 읽고 seek한후 E3, E4를 읽어 중간에 seek time이 발생하여 성능이 떨어지게 됩니다. Defragmentation tool은 disk블럭을 재배치하여 파일과 유휴 공간을 가능한한 연속적으로 배치하여 이러한 외부단편화를 해결하여 성능향상을 가져올 수 있습니다.

### 2. 4개의 디렉터리(/, /a, /b, /b/c)와 4개의 파일(/a/d, /b/e, /b/c/f, /b/c/g)을 생성할 때, FFS에서 실린더 그룹을 어떻게 할당하는지 논하시오. (2점, 각 디렉터리는 1개의 디스크 블록, 각 파일은 2개의 디스크 블록 사용)

- /, /a, /b, /b/c는 디렉터리로 Allocation rule 1을 적용하여 비어있는 그룹에 배치됩니다.
- /a/d, /b/e, /b/c/f, /b/c/g는 파일로 Allocation rule 2를 적용하여 연관 디렉토리가 있는 실린더 그룹에 배치됩니다.

따라서 디스크 블록의 배치는 다음과 같습니다.

| group | inodes     | data       |
| ----: | ---------- | ---------- |
|     0 | /--------- | /--------- |
|     1 | ad-------- | add------- |
|     2 | be-------- | bee------- |
|     3 | cfg------- | cffgg----- |
|   ... | ...        | ...        |

## Week 11-2

### 1. 아래 왼쪽 그림을 사용하여 inconsistent, space leak, garbage read, dangling reference라는 용어를 설명하시오.

- inconsistent : 그림에서 bitmap을 통해 inode와 data부부분에서 어떤부분이 유휴공간인지 파악할 수 있습니다. inode 2번째, data 4번째가 사용중이므로 bitmap에서도 inode 2번재, data 4번째가 사용중임을 확인할 수 있습니다. 만약 해당 inode와 data block이 특정 파일에 의해 사용중임에도 불구하고, bitmap이 해당 공간을 유휴공간으로 나타내면 inconsistent state라고할 수 있습니다.
- space leak : inode와 data block이 사용중이지 않음에도 불구하고 bitmap이 사용중이라고 나타내면 해당 공간을 사용할 수 없게되어 공간을 낭비하게 됩니다. 이를 space leak이라고 합니다. 예를들어 inode 2와, data block의 4를 제외한 나머지 공간은 실제로 사용중이지 않지만, bitmap에서 나머지 공간이 사용중이라 나타내면 해당공간은 비어있음에도 사용할 수 없게 됩니다.
- garbage read : inode의 값(또는 bitmap + inode)만 쓰여지고 data block의 값이 쓰여지지 않으면 inode가 가리키는 data block을 읽었을때 쓰래기 값을 읽게 됩니다. 이를 garbage read라고 합니다. 
- dangling reference : 심볼릭 링크가 가리키고 있던 기존 파일이 삭제되었을때 dangling reference가 발생합니다. 예를 들어 inode2에대한 심볼릭 링크를 생성하였을때 inode2가 아닌 새로운 inode를 생성하고 해당 inode는 inode2를 참조합니다. 이때 inode2가 삭제되면 dangling pointer현상이 발생합니다. 

### 2. FTL의 기능인 1) address mapping, 2) garbage collection, 3) wear-leveling을 설명하시오.

1. FTL에서 Address mapping은 file system의 논리적 주소를 flash memory의 물리적 주소로 mapping하는 것으로 여러 방식이 존재합니다. 모든 logical page가 physical page에 직접 mapping되는 direct mapped의 경우 매번 쓰기마다 해당 page가 들어있는 block전체를 read, erase, program해야 하므로 비용이 큽니다. 또 파일시스템이 메타데이터나 유저데이터를 반복해서 덮어쓰기 한다면 같은 블럭이 계속해서 erase되고 program되기를 반복하여 블럭의 수명이 감소하게 됩니다.  
이러한 단점때문에 최근 대부분의 FTL은 log-structured방식을 사용합니다. Log-structured방식에서는 write시 메모리의 mapping table에 logical block과 physical block의 관계 정보를 기록하여, 정보를 수정할때 overwrite할 필요 없이 mapping table만 바꾸어 주면 됩니다.  
여기서 mapping단위에따라 page-based mapping, block-based mapping, hybird mapping으로 종류를 나눌 수 있습니다. page-based mapping의 경우 page단위로 table을 관리하여 page table의 크기가 커져 메모리를 많이 사용하게 됩니다. 이러한 mapping으로 인한 비용을 줄이기 위해 block-based mapping은 block단위로 table을 관리합니다. Block level의 mapping방식은 mapping table로 인한 비용을 줄이지만 쓰기 단위가 device의 physical block size보다 작을경우 성능저하가 발생합니다. Hybrid Mapping은 이러한 쓰기로인한 성능저하와 mapping으로 인한 비용을 줄이기 위해 block-level, page-level을 혼합하여 사용합니다. 

2. flash memory의 경우 쓰기를 위한 program 연산은 1에서 0으로 바꾸는것만 가능합니다. 따라서 기존데이터가 있는 위치에 새로운 데이터를 쓰기 위해서는 erase연산을 하여 0을 1로 바꾸어 주어야하는데 erase 연산의 수행속도는 아주 느린편입니다. 따라서 매번 program연산을 위해 erase연산을 하게 되면 성능저하가 크게 발생하게 됩니다. 이를 해결하기 위해 블록을 실제로 삭제하지 않고 유휴 블록에 데이터를 할당하게 되는데 이때 기존 블럭은 유효한 상태임에도 불구하고 garbage 값이 남아있게 됩니다. 이러한 garbage값이 들어있는 garbage block을 다시 사용할수 있게끔 만드는것을 garbage collection이라 합니다.

3. flash memory의 경우 쓰기 횟수가 정해져 있습니다. 만약 동일한 block에 erase와 program연산이 너무 자주 일어나면 수명이 다하여 쓸수 없게됩니다. 이를 방지하기 위해 쓰기 연산을 모든 블럭에 균등하게 분배하는것을 wear-leveling이라 합니다.

## Week 12-1

### 1. 아래 그림을 사용하여 다음 용어를 설명하시오: 

1. 가상 메모리  
프로그램의 관점에서 사용하는 메모리를 가상 메모리 라고 합니다. figure 15.1은 가상 메모리를 보여줍니다. 0Kb부터 16Kb까지 할당되어 있으며, 각 프로세스마다 독립적입니다.
2. 물리 메모리  
물리 메모리는 실제 컴퓨터의 메인 메모리를 말합니다. figure 15.2는 물리 메모리를 보여줍니다. 가상 메모리와 달리 시작주소가 0Kb가 아니라 가변적입니다.
3. 주소 공간  
프로그램이 실행되면 프로세스를 위한 주소공간이 할당됩니다. 주소공간은 Code, Data, Heap, Stack으로 구성되어 있으며, Code, Data영역은 정적이고 Heap, Stack영역은 동적으로 할당됩니다.
4. 주소 변환  
가상메모리의 주소값을 실제 물리메모리의 주소값으로 변환하는것을 주소변환 이라 합니다. 그림에서 가상메모리의 시작 주소는 0에서부터 시작하지만 Base register를 통해 물리메모리에서의 실제 시작주소를 가리킵니다. 또 Limit register를 통해 할당된 메모리의 끝부분을 알 수 있습니다. 
5. 재배치 가능  
이러한 주소변환을 통해 프로세스의 가상 주소공간을 물리 메모리의 임의의 위치에 배치할 수 있으며 수행중에 재배치도 가능합니다. 

### 2. 아래 그림에서 가상 주소 1KB, 3KB, 15KB, 17KB의 물리 주소는 각각 어떻게 됩니까?

그림에서 물리주소의 시작부분은 32KB이므로 가상 주소의 물리 주소는 각 주소값에 32KB를 더해준 값이 됩니다. 따라서 물리주소는 각각 32KB, 35KB, 47KB, 49KB가 됩니다. 

## Week 12-2

### 1. 컴파일러, OS, CPU기능
1. 컴파일러  
컴파일러는 소스코드에서 바이너리파일을 생성하면서 가상메모리의 layout을 정의합니다.
2. OS  
**메모리 관리** - 새로운 프로세스를 위한 메모리를 할당하거나, 종료된 프로세스의 메모리를 회수하고, free 공간을 관리합니다.  
**Base/Bounds register** - 문맥교환이 발생했을 때 base register와 bounds register를 교환하는 역할을 담당합니다. 
**예외 처리** - segmentation을 야기한 프로세스를 종료하고 문제를 해결하는 등의 예외처리를 위한 역할을 담당합니다.
3. CPU  
CPU의 MMU는 base register,bounds register와 같이 가상메모리 주소에서 물리메모리 주소로의 주소변환을 위한 하드웨어를 지원하고 업데이트하여 주소변환을 돕습니다. 또 특권 명령어나 out-of-bounds memory가 발생할 경우 예외를 발생시키는 역할을 합니다.

### 2. segment번호, offset을 사용하여 풀이

- Virtual address : 100
  - Segment : $00\rArr Code$
  - Offset  : $0000 0110 0100_2$(100)
  - Physical address : 32K + 100
  - Segment Encoding : 00 0000 0110 0100

- Virtual address : 3000
  - Segment : $00\rArr Code$
  - Offset  : $1011 1011 1000_2$(3000)
  - Physical address : 32K + 3000
  - Segment Encoding : 00 1011 1011 1000

- Virtual address : 5000
  - Segment : $01\rArr Heap$
  - Offset  : $0000 0110 0100_2$(904)
  - Physical address : 34K + 904
  - Segment Encoding : 01 0000 0110 0100

### Bonus. SEG_MASK, SEG_SHIFT, OFFSET_MASK 각각의 값

가상주소와 SEG_MASK의 13번째, 14번째 부분을 1로하여 and 비트연산을 하면, Segment number부분을 제외한 나머지 부분을 0으로 만들 수 있고, 우측으로 12번 shift연산하면 Segment값을 얻을 수 있습니다.

가상주소와 OFFSET_MASK의 1번째 부터 12번째 부분을 1로하여 and비트연산을 하면 , offset부분을 제외한 나머지 부분을 0으로 만들어 offset값을 얻을 수 있습니다. 

- SEG_MASK : 0011 0000 0000 0000 (0x3000)
- SEG_SHIFT : 12
- OFFSET_MASK : 0000 1111 1111 1111 (0xFFF)

## Week 13-1

### 1. 아래 그림을 사용하여 다음 용어를 설명하시오: 1) 스왑 아웃 (LN2에서는 suspend로 배웠음), 2) 재배치 가능, 3) 외부 단편화, 4) 컴팩션 (compaction), 5) 분할 (splitting). (1.5점. 반드시 아래 그림을 사용하여 설명)

- 1)스왑 아웃
  - 그림 (d)에서 8M의 메모리 할당을 요구하는 새로운 프로세스가 실행되면, 메모리의 가용공간은 현재 4M이므로 메모리 공간이 충분하지 않습니다. 그림 (e)는 메모리 가용공간을 확보하기 위해 최근에 수행되지 않았던 프로세스 2를 디스크의 스왑공간으로 이동하여 메모리의 가용 공간을 확보하고, 그림 (f)에서 확보한 공간에 새로운 프로세스 4가 할당된것을 보여줍니다.
  - 이렇게 새로운 프로세스를 위한 메모리 공간을 할당해 주기 위해서 최근에 수행되지 않았던 프로세스를 골라 디스크의 Swap공간으로 이동시켜 메모리 공간을 확보하는것을 스왑아웃이라 합니다. 
- 2)재배치 가능
  - 그림 (e)와 그림 (h)를 비교해 보면 프로세스 2가 동일한 프로세스임에도 불구하고 주소 위치가 바뀐것을 확인할 수 있습니다. 이렇게 프로세스를 사용가능한 다른 물리메모리 주소에 재배치 할 수 있습니다.
- 3)외부 단편화
  - 그림 (f)에서 프로세스 2를 스왑 아웃하고 프로세스 4를 할당하여 작은 가용공간들이 생겨났습니다. 이러한 작은 가용공간들은 새로운 segment를 할당하기 어렵게 합니다. 이를 외부 단편화 라고 합니다. 
- 4)컴팩션
  - 앞서 설명한 외부 단편화를 해결하기 위해 메모리의 segment를 재배치 하는것을 컴팩션이라고 합니다. OS는 프로세스가 실행중이든 아니든 일단 중지하고 물리메모리에 연속적으로 재배치하여 큰 가용공간을 만들어 냅니다.
- 5)분할
  - 그림 (e)-(f)에서 프로세스 4를 할당할 때 14M의 free공간을 나누어 프로세스 4를 할당하였습니다. 이렇게 물리메모리에 할당하려는 메모리보다 더 큰free공간이 있을때 해당 공간을 나누어 할당합니다. 이를 분할이라고 합니다.

### 2. "문의 게시판"에 흥미로운 질문들이 많이 있습니다. 그 중 하나를 골라 자신의 응답 또는 의견을 추가하고, 추가한 내용을 이 퀴즈의 답변으로 응답하시오. (1.5점)

제목 : 캐싱과 버퍼링 관련 질문드립니다

이전에 리눅스는 unified buffer cache를 사용하여 페이지 캐시와 버퍼캐시 두 용어에 큰 차이가 없다 라는 이야기를 인터넷에서 보고 차이점에 대해서 크게 생각해 보지 않았는데, 이 질문을 통해 운영체제별로 구현하는 방식에 따라 다르다는 점과 두 용어의 정확한 의미를 알게되어 좋았습니다.

## Week 13-2

### 1. 1) 연속 할당, 2) 세그멘테이션, 3) 페이징의 차이점을 설명하시오. (1점) 

- 연속할당의 경우 base register, limit register를 통해 한 프로세스를 연속적으로 물리메모리에 할당합니다. 이와 달리 세그멘테이션과 페이징은 불연속적으로 물리메모리에 할당합니다. 세그멘테이션의 경우 code, data, heap, stack과 같이 세그먼트 별로 세그먼트 레지스터 또는 세그먼트 테이블을 통해 물리메모리에 할당합니다. 이때 세그먼트의 크기는 가변적입니다. 반면 페이징은 고정된 크기의 페이지를 페이지 테이블을 통해 물리메모리에 할당합니다. 고정된 크기를 할당 하기 때문에 세그멘테이션과 달리 외부 단편화 문제가 발생하지 않으며 TLB와 같은 하드웨어 지원이 쉽습니다.

### 2. 다음과 같이 가정합시다: 1) 가상메모리 크기 = 64B, 물리메모리 크기 = 128B, 페이지 크기 = 프레임 크기 = 16B, 2) 페이지 0, 1, 2가 프레임 3,6,1에 적재(loading)됨. 이때 가상 주소 4, 21, 60의 물리 주소를 구하시오. (1.5점, VPN, PFN, 옵셋이라는 용어를 사용하여 설명)

- 가상주소 : 4 -> 00 0100
  - VPN : 0
  - Offset : 4(0100)
  - PFN : VPN 0은 프레임 3에 적재되므로 PFN은 3입니다.
  - 물리주소 : 3 * 16B(Page size) + 4(offset) = 52
- 가상주소 : 21 -> 01 0101
  - VPN : 1
  - Offset : 5(0101)
  - PFN : VPN 1은 프레임 6에 적재되므로 PFN은 6입니다.
  - 물리주소 : 6 * 16B(Page size) + 5(offset) = 101
- 가상주소 : 60 -> 11 1100
  - VPN : 3
  - Offset : 12
  - PFN : VPN 3은 현재 Present bit가 꺼져있으므로 현재 메모리상에 없고 디스크 상에 존재합니다. 만약 접근하려 한다면 page fault가 발생하고, 디스크에서 메모리로 올린후에 수행을 계속합니다. 

최근 구글에서 fuchsia라는 새로운 OS를 개발하고 있는데 이는 zircon이라는 마이크로 커널을 기반으로 동작합니다. zircon은 

이전에 리눅스는 unified buffer cache를 사용하여 페이지 캐시와 버퍼캐시 두 용어에 큰 차이가 없다 라는 이야기를 인터넷에서 보고 차이점에 대해서 크게 생각해 보지 않았는데, 이 질문을 통해 운영체제별로 구현하는 방식에 따라 다르다는 점과 두 용어의 정확한 의미를 알게되어 좋았습니다. 

## Week 14-1
### 1. 용어 설명 
MMU
- MMU는 Memory management unit의 약자로 주소변환을 빠르게 하기 위한 하드웨어 지원을하는 요소들을 말합니다. MMU에는 base register, limit register, segment, page관련 레지스터 및 TLB등을 포함합니다. 

TLB
- TLB는 Translation lookaside buffer의 약자로 최근에 주소전환한 page number와 frame number를 캐싱하여 페이지 테이블을 위한 메모리 접근 횟수를 줄여 성능을 향상시킵니다.  

페이지 디렉터리 
- 페이지 디렉터리는 Muti-level page table방식에서 사용되며 페이지 디렉터리의 각 entry는 페이지 테이블을 가리키고 있습니다. 페이지 디렉터리의 valid bit를 통해 사용하지 않는 페이지 테이블을 줄여 내부단편화를 해결할 수 있습니다.  

역 페이지 테이블
- 기존 페이지 테이블은 index로 page number를 사용하여 한 프로세스당 하나가 존재합니다. 이로인해 프로세스의 개수가 많아지면 그만큼 페이지 테이블이 차지하는 사이즈가 커지게 됩니다. 이를 해결하기 위해 index로 frame number를 사용하고, value로 page number를 사용하여 기존의 페이지 테이블과 반대로 동작합니다. 또 linear scan, hash등의 방식을 통해 page number를 검사하여 주소변환을 수행합니다. 

### 2. 18 페이지 예에서, a 배열을 접근할 때 TLB 적중율이 70%라고 배웠습니다. 
#### 1) 만일 페이지 크기가 16B가 아니라 32B로 커지면 적중율이 어떻게 됩니까?  

만일 페이지의 크기가 16B에서 32B로 커지게 되면 메모리에 다음과 같이 배치됩니다.

| VPN | 00   | 04   | 08   | 12   | 16   | 20   | 24   | 28   | 32   |
| --- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| ... | ...  | ...  | ...  | ...  | ...  | ...  | ...  | ...  | ...  |
| 06  | ...  | a[0] | a[1] | a[2] | a[3] | a[4] | a[5] | a[6] | a[7] |
| 07  | a[8] | a[9] | ...  | ...  | ...  | ...  | ...  | ...  | ...  |
| ... | ...  | ...  | ...  | ...  | ...  | ...  | ...  | ...  | ...  |

처음 배열에 접근하게 되면 a[0]와 a[8]에서 TLB miss가 발생합니다. 이외 a[1],...,a[7]과 a[9]은 page acess miss가 발생한 주소와 같은 page에 있기 때문에 TLB가 update되어 이후 모두 TLB hit가됩니다. 따라서 적중률은 80%가 됩니다. 

이렇게 긴 배열을 저장하는 경우 page의 크기에 따라 TLB 적중률이 달라지는 것을 볼 수 있었습니다. TLB의 적중률을 높이기 위해서는 page의 크기를 늘려야하지만 page의 크기를 늘린만큼 내부단편화가 발생하여 메모리가 낭비될수 있기 때문에 이둘은 tradeoff 관계에 있는것으로 보여집니다. 

#### 2) 왼쪽 하단의 코드처럼 “for (i=0; i<10; i++)” 외부에 “for (j=0; j<2; j++)”가 추가되면 적중율이 어떻게 됩니까?

첫 루프(j=0)에서 a[0], a[3], a[7]에 대해서만 TLB miss가 발생하고 이후루프에서는 모두 hit이므로 전체 총 20번의 배열 접근중 17번은 hit입니다 따라서 적중률은 85%가 됩니다. 이러한 적중률 증가는 temporal locality를 통한 cache의 성능향상효과를 보여줍니다.

## Week 14-2
### 1. 용어 설명
**요구 페이징**
- 프로세스가 실행될때 프로세스의 모든 가상주소 공간이 항상 물리메모리에 적재될 필요는 없습니다. 자주 사용하지 않는 페이지는 디스크의 스왑공간에 저장해 두었다가 필요할때 페이지를 물리 메모리로 적재하는것을 요구 페이징 이라 합니다. 이러한 요구페이징을 통해 실제 물리메모리의 크기보다 큰 가상메모리를 사용할 수 있습니다.

**페이지 폴트**
- 페이지 폴트는 물리메모리에 존재하지 않는 페이지에 접근하려 할때, 즉 Present bit가 0일때 발생합니다. 발생하면 프로세스를 즉시 종료하는 세그멘테이션 폴트(segmentation fault)와 달리 페이지 폴트는 합법적인 접근으로, 발생하면 page-fault handler를 호출하여 디스크의 스왑공간에서 메모리로 페이지를 가져온후 프로세스 수행을 재개합니다.  
만약 메모리에 충분한 공간이 없을 경우 Replacement Policy에 따라 페이지를 쫒아내고(page out) 실제 사용할 페이지를 위한 공간을 만들어 냅니다.

**쓰래싱 (thrashing)**
- 사용가능한 물리메모리보다 프로세스들의 페이지 요구가 클경우 쓰래싱이 발생합니다. 만약 물리메모리의 모든 프레임이 사용중이고 또다른 프로세스가 프레임을 요구할 경우 페이지 교체가 필요하지만 이미 모든 페이지가 사용중이므로 교체되더라도 교체된 프로세스는 또 페이지를 요구하여 교체가 필요하게 됩니다. 이로인해 지속적으로 page fault가 발생하여 page fault의 비율이 매우 높아지는 현상을 쓰래싱이라 합니다.

**워킹 셋(working set)**
- 현재시간 t 에서 t-Δ시간 사이에 참조된 페이지들의 집합을 워킹 셋이라 합니다. 한 프로세스가 원활하게 수행되기 위해 필요한 최소한의 페이지들의 집합이라 볼 수 있습니다.  
- 현재 시스템의 모든 워킹 셋의 합을 기준으로 쓰래싱의 발생을 예측하고 몇몇 프로세스를 중지하거나, 새로운 프로세스를 실행하거나를 결정할 수 있습니다. 
- 워킹셋을 통해 쓰래싱을 방지하고 최적의 멀티프로그래밍 레벨을 유지할 수 있습니다. 

### 2. 시스템에 3개의 가용 프레임이 있고, 페이지 참조 스트링이 “1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5”라고 할때

✔ **FIFO, LRU, Optimal (MIN)의 적중율이 어떻게 됩니까?** 

**FIFO**

| Access | Hit/Miss | Evict | Cache state |
| ------ | -------- | ----- | ----------- |
| 1      | Miss     | -     | 1           |
| 2      | Miss     | -     | 1,2         |
| 3      | Miss     | -     | 1,2,3       |
| 4      | Miss     | 1     | 2,3,4       |
| 1      | Miss     | 2     | 3,4,1       |
| 2      | Miss     | 3     | 4,1,2       |
| 5      | Miss     | 4     | 1,2,5       |
| 1      | Hit      | -     | 1,2,5       |
| 2      | Hit      | -     | 1,2,5       |
| 3      | Miss     | 1     | 2,5,3       |
| 4      | Miss     | 2     | 5,3,4       |
| 5      | Hit      | -     | 5,3,4       |

Hit ratio = 3 / 12 = 25%

**LRU**

| Access | Hit/Miss | Evict | Cache state |
| ------ | -------- | ----- | ----------- |
| 1      | Miss     | -     | 1           |
| 2      | Miss     | -     | 1,2         |
| 3      | Miss     | -     | 1,2,3       |
| 4      | Miss     | 1     | 2,3,4       |
| 1      | Miss     | 2     | 3,4,1       |
| 2      | Miss     | 3     | 4,1,2       |
| 5      | Miss     | 4     | 1,2,5       |
| 1      | Hit      | -     | 2,5,1       |
| 2      | Hit      | -     | 5,1,2       |
| 3      | Miss     | 5     | 1,2,3       |
| 4      | Miss     | 1     | 2,3,4       |
| 5      | Miss     | 2     | 3,4,5       |

Hit ratio = 2 / 12 = 16.7%

**Optimal**

| Access | Hit/Miss | Evict | Cache state |
| ------ | -------- | ----- | ----------- |
| 1      | Miss     | -     | 1           |
| 2      | Miss     | -     | 1,2         |
| 3      | Miss     | -     | 1,2,3       |
| 4      | Miss     | 3     | 1,2,4       |
| 1      | Hit      | -     | 1,2,4       |
| 2      | Hit      | -     | 1,2,4       |
| 5      | Miss     | 4     | 1,2,5       |
| 1      | Hit      | -     | 1,2,5       |
| 2      | Hit      | -     | 1,2,5       |
| 3      | Miss     | 1     | 2,5,3       |
| 4      | Miss     | 2     | 5,3,4       |
| 5      | Hit      | -     | 5,3,4       |

Hit ratio = 5 / 12 = 41.7%

✔ **만일 가용 프레임 개수가 4개라면, 위 페이지 참조 스트링에서 FIFO, LRU, Optimal (MIN)의 적중율이 어떻게 됩니까?**

**FIFO**

| Access | Hit/Miss | Evict | Cache state |
| ------ | -------- | ----- | ----------- |
| 1      | Miss     | -     | 1           |
| 2      | Miss     | -     | 1,2         |
| 3      | Miss     | -     | 1,2,3       |
| 4      | Miss     | -     | 1,2,3,4     |
| 1      | Hit      | -     | 1,2,3,4     |
| 2      | Hit      | -     | 1,2,3,4     |
| 5      | Miss     | 1     | 2,3,4,5     |
| 1      | Miss     | 2     | 3,4,5,1     |
| 2      | Miss     | 3     | 4,5,1,2     |
| 3      | Miss     | 4     | 5,1,2,3     |
| 4      | Miss     | 5     | 1,2,3,4     |
| 5      | Miss     | 1     | 2,3,4,5     |

Hit ratio = 2 / 12 = 16.7%

**LRU**

| Access | Hit/Miss | Evict | Cache state |
| ------ | -------- | ----- | ----------- |
| 1      | Miss     | -     | 1           |
| 2      | Miss     | -     | 1,2         |
| 3      | Miss     | -     | 1,2,3       |
| 4      | Miss     | -     | 1,2,3,4     |
| 1      | Hit      | -     | 2,3,4,1     |
| 2      | Hit      | -     | 3,4,1,2     |
| 5      | Miss     | 3     | 4,1,2,5     |
| 1      | Hit      | -     | 4,2,5,1     |
| 2      | Hit      | -     | 4,5,1,2     |
| 3      | Miss     | 4     | 5,1,2,3     |
| 4      | Miss     | 5     | 1,2,3,4     |
| 5      | Miss     | 1     | 2,3,4,5     |

Hit ratio = 4 / 12 = 33.3%

**Optimal**

| Access | Hit/Miss | Evict | Cache state |
| ------ | -------- | ----- | ----------- |
| 1      | Miss     | -     | 1           |
| 2      | Miss     | -     | 1,2         |
| 3      | Miss     | -     | 1,2,3       |
| 4      | Miss     | -     | 1,2,3,4     |
| 1      | Hit      | -     | 1,2,3,4     |
| 2      | Hit      | -     | 1,2,3,4     |
| 5      | Miss     | 4     | 1,2,3,5     |
| 1      | Hit      | -     | 1,2,3,5     |
| 2      | Hit      | -     | 1,2,3,5     |
| 3      | Hit      | -     | 1,2,3,5     |
| 4      | Miss     | 1     | 2,3,5,4     |
| 5      | Hit      | -     | 2,3,5,4     |

Hit ratio = 6 / 12 = 50%

### (보너스) 퀴즈 2를 이용하여 Belady's anomaly를 설명하시오

일반적으로 캐시의 가용프레임 개수가 늘어나면 캐시의 히트율이 늘어난다는 생각이 듭니다. 하지만 퀴즈 2에서 캐시의 가용프레임 개수가 3일때 4일때의 FIFO정책을 비교하면 4일때 16.7%로 오히려 캐시의 히트율이 낮아진것을 확인할 수 있습니다. 이를 Belady's anomaly라고 합니다.