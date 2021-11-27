from dataclasses import dataclass
from typing import List

@dataclass
class Process:
    p_name: str = None
    ariv_t: int = 0
    rema_t: int = 0
    serv_t: int = 0
    time_q: int = 0
    qlevel: int = 0
    ticket: int = 100

class ReadyQueue:
    buff  : List[Process] = []
    front : int = 0
    rear  : int = 0
    count : int = 0

    def __init__(self,_size) :
        self.front  = _size - 1
        self.rear   = _size - 1
        self.count  = 0
        self.size   = _size

    def enqueue(self, item : Process) :
        self.rear = (self.rear + 1) % self.size
        if self.rear == self.front :
            self.rear -= 1
        else :
            self.buff[self.rear] = item
        self.count
    
    def dequeue(self) :
        if self.front == self.rear :
            return None
        self.front = (self.front + 1) % self.size
        self.count -= 1
        return self.buff[self.front]

    def del_data(self, p : Process) :
        count = self.count
        tmp : Process
        for _ in range(count):
            tmp = self.dequeue()
            if tmp != p :
                self.enqueue(tmp)

    def getFront(self) :
        return self.buff[(self.front + 1) % self.size]

class Simulator:
    proc_num   : int            = 0
    total_time : int            = 0
    output     : List[str]      = []
    task       : List[Process]  = []
    rq         : ReadyQueue

    def __init__(self) :
        self.parseInput()
        self.sortInput()
        self.setTotalTime()
        self.rq = ReadyQueue(10)

    def parseInput(self):
        self.proc_num = 0
        f = open("./input.txt")
        for line in f:
            ps = Process()
            x = line.split()
            ps.p_name = str(x[0])
            ps.ariv_t = int(x[1])
            ps.rema_t = int(x[2])
            ps.serv_t = int(x[2])
            ps.qlevel = 0
            ps.ticket = 100
            self.task.append(ps)
            self.proc_num += 1
        f.close()
    
    def sortInput(self) :
        tmp : Process
        for i in range(self.proc_num - 1, 0, -1) :
            for j in range(0, i) : 
                if self.task[j].ariv_t > self.task[j].ariv_t :
                    tmp = self.task[j+1]
                    self.task[j+1] = self.task[j]
                    self.task[j] = tmp
                elif self.task[j].ariv_t == self.task[j+1].ariv_t and self.task[j].p_name > self.task[j+1].p_name :
                    tmp = self.task[j+1]
                    self.task[j+1] = self.task[j]
                    self.task[j] = tmp
    
    def setTotalTime(self) :
        sum : int = 0 
        for i in range(0, self.proc_num) :
            sum += self.task[i].serv_t
        self.total_time = sum

    def setTimeQ(self, q : int) :
        for i in range(0,self.proc_num) :
            self.task[i].time_q = q
    
    def fcfs(self) :
        next_idx = 0
        cpu_time = 0

        cur : Process = self.task[next_idx]
        next_idx += 1
        while cpu_time < self.total_time :
            while next_idx < self.proc_num and self.task[next_idx].ariv_t == cpu_time:
                self.rq.enqueue(self.task[next_idx])
                next_idx += 1
            self.output.append(cur.p_name)
            cur.rema_t -= 1
            if cur.rema_t == 0 :
                cur = self.rq.dequeue()


def main():
    s = Simulator()
    



if __name__ == "__main__":
    main()
