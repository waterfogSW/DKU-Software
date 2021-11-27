# [OS] Scheduling - MLFQ

## MLFQ (Multilevel Feedback Queue)

- Turnaround time을 최적화 하면서 Response time을 최소화하기 위한 방법
  - Multi-Level Feedback Queue

### MLFQ : Basic Rules

- 선점형 스케줄링 방식으로 여러개의 Ready Queue에 사용
- 각 Queue마다 다른 Priority level 을 부여받음
- 같은 우선순위에서는 Round Robin으로 수행
- 높은 우선순위의 Queue가 먼저 스케줄되며, 같은 queue내에서는 RR방식 적용함
  - Rule 1 : Priority(A) > Priority(B) 일때 A가 먼저 수행합니다.
  - Rule 2 : Priority(A) = Priority(B) 일때 라운드 로빈 방식으로 수행합니다.
  - Rule 3 : Job이 들어오면 가장 상위 Ready Queue에 할당합니다.
  - Rule 4a : 할당된 Time slice(time quantum)가 끝나면 하위 Queue로 우선순위가 내려갑니다.
  - Rule 4b : Time slice가 끝나기전 스케줄링이 해제 동일한 우선순위 레벨에 남습니다.

### Attempt #1: How to Change Priority

- How to assign a priority to each process?
  - Job이 들어오면 가장 상위 Ready Queue에 할당
  - Time slice를 모두 사용하면 하위 Queue로 이동
  - Time slice전 끝나면 우선순위 유지

- Problem with our current MLFQ
  - Pros of the current version
    - Share CPU fairly among long-running jobs
    - Allow short-running or I/O intensive jobs to run quickly
  - Issue
    - Starvation : 너무 많은 대화형 작업이 존재하여, 실행시간이 긴 작업이 CPU를 할당받지 못하는 경우
    - User can trick the scheduler : 임의로 실행시간을 짧게 하여 항상 우선순위를 최상위로 유지
    - A program may change its behavior : 작업이 CPU위주 Batch작업에서 대화형 interative작업으로 바뀔경우

### Attempt #2: The priority Boost

- Starvation을 방지하기 위한 방법
  - Periodic boosting : 일정시간(S)이 지나면 주기적으로 모든 job을 우선순위를 최고 우선순위로 상향

Rule 5 : 일정 시간이 지나면 모든 작업을 최상위 큐로 상향 

### Attempt #3: Better Accounting

- 항상 우선순위를 최상위로 유지하는것을 방지하기 위한 방법
  - time slice 기준으로 demote -> 해당 단계에서 사용한 CPU시간을 기준으로 demote

Rule 4 : 해당 단계에서 할당된 시간을 모두 소진하면 하위큐로 하향

### Tuning MLFQ and Other Issues 

- How many queues?
- How big should the time slice be per queue? Same or Different?
- How often do the priority boost?

- 일반적으로 우선순위가 높은큐에서는 Response time이 중요한 대화형 작업이 주를 이루고, 낮은큐에서는 Batch작업이 주를 이룹니다. 따라서 우선순위가 높은 큐에서는 짧게 time slice를 설정하고, 낮은 큐에서는 길게 타임슬라이스를 설정하여 context switch로 인한 overhead를 줄입니다.
- Solaris에서는 이러한 MLFQ스케줄링 요소에 대한 Table을 제공하여 스케줄러의 동작 방식을 바꿀 수 있습니다.
-  FreeBSD 스케줄러(버전 4.3)는 수식을 사용하여 프로세스의 CPU 사용량에 따라 작업의 현재 우선 순위 수준을 계산하고, 시간이 지나 사용량이 감소함에 따라 적절한 priority boost를 제공합니다.

### MLFQ 요약

- Name analysis
  - 여러 단계의 큐로 구성
  - job의 행동을 추적하여 적절하게 feed back
- Final Rules
  - Rule 1 : Priority(A) > Priority(B) 일때 A가 먼저 수행합니다.
  - Rule 2 : Priority(A) = Priority(B) 일때 라운드 로빈 방식으로 수행합니다.
  - Rule 3 : Job이 들어오면 가장 상위 Ready Queue에 할당합니다.
  - Rule 4 : 해당 단계에서 할당된 시간을 모두 소진하면 하위큐로 하향합니다.
  - Rule 5 : 일정 시간이 지나면 모든 작업을 최상위 큐로 상향합니다.

### Scheduling comparison

- FCFS : First come First served
- Round robin
- SPN(SJF) : 최단 실행시간 우선
- SRT(Preemptive SJF) : 최단 잔여시간 우선
- HRRN : (대기시간 + 실행시간) / 실행시간 -> 대기한 시간이 올라갈수록 우선순위가 높아짐.