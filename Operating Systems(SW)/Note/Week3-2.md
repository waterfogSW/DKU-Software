# [OS] 운영체제 정리 - Scheduling

## CPU Scheduling

많은 프로세스가 동시에 자원을 요구할 때 어떤 프로세스가 CPU를 먼저 사용할지 결정하는 정책을 말합니다.

## Workload (작업부하)

- 프로세스가 얼마나 많은 양의 자원을 요구하느냐

### Simple assumtion about porcess

- 각 작업은 같은 시간동안 수행된다
- 모든 작업은 같은 시간에 시작된다
- 한번 시작되면 완료될때 까지 실행된다
- 모든 작업은 CPU만을 사용한다.
- 각 작업의 수행시간을 미리 알고 있다.

Job & Process

- 동일한 의미의 단어지만 스케줄러를 연구하는 도메인 에서는 job이라는 단어를 선호합니다.

>**프로세스**(Process)는 주소공간을 가지고 있는 실행중인 프로그램을 말합니다
>
>**작업**(job)은 셸에서 사용하는 개념으로 실행중인 대화형 프로그램을 말합니다. 데몬과 반대되는 개념입니다. 대화형 프로그램을 실행 중인 경우 ctrl + z키를 눌러 프로그램을 일시 중단할 수 있습니다.  
>
>**Deamon** - 사용자가 직접적으로 제어하지 않고, 백그라운드에서 돌면서 여러 작업을 하는 프로그램입니다.

## Metric

성능, 의존성 등과 같은 것을 측정하기위한 척도

### Metric for Scheduling

- Turnaround time(반환시간, Complete time - Arrived time)
  - 처음 실행시간부터 작업을 완료하는데 소요된 시간(CPU, waiting, I/O 등 모든 시간을 포함)
- Response time(응답시간, First run time - Arrived time)
  - 처음 실행시간부터 작업이 응답하기까지 소요된 시간
- Fairness(형평성)
  - 두개의 프로세스가 종료되는 시간이 얼마나 비슷한지
- Throughput(처리율, jobs/sec)
  - 단위시간당 처리하는 작업의 수(처리량)
- Deadline(마감시간)
  - Turnaround time < Deadline time

## Response time(응답시간)

**Turnaround time** - Time required for a particular process to complete, from submission time to completion. It is equal to the sum total of Waiting time and Execution time.  
-> batch 시스템에서 유리

**Response time** - The time taken in a program from the issuance of a command to the commence of a response to that command.(i.e., the time-interval between submission of a request, and the first response to that request, not the output .)  
-> interactive 시스템에서 유리

## FIFO(First In First Out)

처음으로 도착한 프로세스를 먼저 스케줄링하는 정책(a.k.a FCFS(First Come First Serve))

- Pros : 1) 간단하다 2) 구현하기 쉽다
- Cons : 1) 대기시간이 길어질 수 있다. (convoy effect)

>Convoy Effect -  The whole Operating System slows down due to few slow processes

## SJF(Shortest Job First)

수행시간이 가장 짧은 작업에 높은 우선순위를 부여(a.k.a SPN(Shortest Process Next))

- Pros : 최적의 알고리즘으로 증명됨
- Cons : 짧은 수행시간의 작업이 늦게 도착했을때 어떻게 하나?

## STCF(Shortest Time to Completion First)

SJF와 유사하나 선점형(Preemptive) 스케줄링 방식입니다

Non-preemptive Scheduling(비선점형 스케줄링)

- 프로세스가 한번 스케줄 되면 그 프로세스가 끝날때까지 수행합니다.

Preemptive Scheduling(선점형 스케줄링)

- 프로세스가 완료되지 않더라도 중간에 멈추고 다른 프로세스가 끼어들 수 있는 스케줄링 방식입니다.
- context switch가 요구됩니다.
- 최근 모든 스케줄러는 선점형 스케줄링 방식을 사용합니다

## Response time

- Turnaround time : batching 시스템에서 유리한 metric
- Response time : interactive 시스템에서 중요한 metric(ex, 대화형 쉘에서 프로그램을 실행했는데 늦게 실행되면 답답)

## RR(Round Robin)

Run queue의 작업이 완료될때 까지 **Time quantum**만큼 빠르게 돌아가며 수행  
-> Response Time 단축, Turnaround time 증가

### Tradeoff of time slice(time quantum)

- Samll : 높은 응답 속도, Context switch로 인한 오버헤드 증가
- Large : 낮은 응답 속도, Context switch로 인한 오버헤드 감소

-> time quantum의 크기가 커질수록 FCFS와 동일하게 동작하며 0에 가까울수록 switching overhead가 증가하여 비효율적입니다. 

### Tradeoff of between response time and turnaround time

- Traditional isuue in CS : Interactivity(응답속도) vs Performance(성능)
- 두마리 토끼를 동시에 잡을수는 없다

## Incorporating I/O

프로세스로 부터 입출력 요청이 있을때 프로세스는 입출력이 완료될 때 까지 기다려야 합니다. 

- Busy waiting : 프로세스 A의 I/O가 수행되는동안 상태 확인, CPU자원 낭비
- Blocked : 프로세스 A의 I/O가 수행되는동안 프로세스 B를 스케줄 하여 자원 낭비를 최소화
