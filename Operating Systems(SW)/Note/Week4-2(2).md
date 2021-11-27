# [OS] Scheduling - Multiprocessor Scheduling

## CPU Cache

- 캐시는 용량이 작고, 빠른 특성때문에 자주사용되는 데이터를 주로 저장합니다
  - Temporal locality(시간 지역성)
    - 마지막에 접근한 데이터를 다시 접근하는 특성을 말합니다.
    - stack, for loop
  - Spatial locality(공간 지역성)
    - 접근한 데이터의 주변 데이터를 다시 접근하는 특성을 말합니다.
    - Array, sequential execution ... 
- Benefit
  - Cache hit : 캐시에 담아놓은 데이터를 접근하게 되면 Cache hit, 담아놓지 않은 데이터를 접근하면 Cache miss가됩니다. Cache hit하게 되면 메모리보다 훨씬 빠른속도로 데이터에 접근할 수 있습니다.
  - Delayed Write : 쓰기 작업시 바로 메모리에 접근하지 않고, 캐시에 쓰기작업을 한 후 메모리에 접근할 때 한번에 쓰기작업을 합니다.

## Cache Affinity

- CPU Cache는 job이 이전에 접근한 메모리를 저장해놓고있는데 Context Switch이후 캐시되어 있는 프로세서가 아닌 다른 프로세서에 스케줄링 되면 Cache miss로 인해 성능저하(Cache miss)가 발생할 수 있습니다.
- 이를 방지하기 위해서 이전에 수행했던 프로세서에 스케줄링하여 Cache hit를 높이는것이 좋습니다.

### SQMS(Single Queue Multiprocessor Scheduling)

여러개의 코어를 하나의 큐로 스케줄링
- 장점 : 구현이 간단하다, job이 공평하게 분배됨
- 단점 : 공유자원인 큐에 대한 lock오버헤드 발생

### MQMS(Multi Queue Multiprocessor Scheduling)

각 코어마다 큐를 가지고 있음.
- 장점 : Affinity가 좋다, lock으로 인한 오버헤드가 적다.
- 단점 : load balancing을 고려해야 한다.

#### Load balancing(부하균등)

- 각 CPU의 큐는 독립적이므로 서로의 상태를 알지 못한다.
- 스케줄러는 가장 여유로운 큐를 Source큐로 선택, 임의 선택된 Target큐가 Source큐보다 Busy하면 Source큐는 Target큐의 Job을 Steal(Work stealing, Migration).

