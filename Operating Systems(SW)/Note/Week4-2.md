# [OS] Scheduling - Proportional Share(Fair Share)

## Proportional Share(Fair Share)

- Turnaround time과 response time에 중점을 두기보다는 각 job이 일정한 비율의 CPU time을 보장받을수 있도록 하여 fairness에 중점을 두는 방식입니다.
- Lottery, Stride, ... 의 스케줄링 방식이 이에 해당합니다.

## Lottery Scheduling

Lottery는 복권이란 뜻을 가지고 있습니다.
- Ticket을 많이 가지고 있을수록 스케줄링될 확률이 올라갑니다.
  - 우선순위를 고려하여 각 프로세스에 Ticket을 할당합니다
  - 랜덤하게 번호를 뽑아서 해당 번호의 Ticket을 가지고있는 프로세스를 스케줄링 합니다
  - 따라서 우선순위가 낮다고 해서 Starvation되지 않습니다
- Ticket currency
  - 각 유저가 서로다른 양만큼의 ticket을 job에 발행하고 CPU 자원을 공유하면 불공평하게 CPU자원이 배분될 수 있습니다.
  - 예를들어 유저 A가 2개의 job에 각각 500개의 ticket을 발행하고, 유저 B가 1개의 job에 10개의 ticket을 발행하면 50:50:1의 비율로 스케줄링 되는 경우가 발생합니다. 따라서 local currency를 global currency로 변경하는 작업이 필요합니다.
- Ticket Transfer
  - 프로세스가 자신의 Ticket을 다른 프로세스에 양도합니다
  - 이 방법은 Client/server 환경에서 유용합니다. client가 요청을 보내면서 ticket을 같이 보내면 Server가 요청과 함께 Ticket을 받아서 프로세스의 우선순위를 높일 수 있습니다. 작업이 완료되면 다시 ticket을 client에게 보냅니다.
- Ticket Inflation
  - 프로세스가 자신이 가진 ticket의 수를 일시적으로 늘리거나, 줄입니다. ticket inflation은 프로세스 그룹이 서로 신뢰하는 환경에서 적용할수 있습니다. 어떤 프로세스가 더 많은 CPU 점유 시간이 필요하다는 것을 알게 되면 다른 프로세스와의 통신 없이 시스템에 필요한 사항을 반영하기 위한 방법으로 ticket inflation을 활용할 수 있습니다.

```c
//counter : used to track if we'veround the winner yet
int counter = 0;

// winner : use some call to a random number generator to 
//            get a value, between 0 and the total of tickets
int winner = getrandom(0, totaltickets);

// currnet : use this to walk through the list of jobs
node_t *current = head;

// Loop until the sum of ticket values > the winner
while(current){
    counter = counter + current->tickets;
    if(counter > winner)
        break; // found the winner
    current = current->next;
}
// current is the winner; schedule it
```

## Stride Scheduling

Stride는 보폭이라는 뜻을 가지고 있습니다. 
- Lottery scheduling과 달리 deterministic합니다 .(Lottery scheduling은 random number를 사용하기 때문)
- Pass value는 0부터 시작합니다.
- 프로세스 수행후 각프로세스에 부여된 Stride값 만큼 Pass value에 더해줍니다
- 스케줄러는 Pass value가 가장 작은 값을 스케줄링 합니다.
- Stride = (임의의 큰 숫자) / (Tickets)
