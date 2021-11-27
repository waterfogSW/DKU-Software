#include<iostream>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<iomanip>
#include<stdlib.h>
#include<cmath>
#include<bitset>
using namespace std;

/*Access State*/
#define NA 0 // No action
#define LH 1 // Load hit
#define LM 2 // Load miss
#define SH 3 // Store hit
#define SM 4 // Store miss

/*Policy Map*/
map<string,int> wh_map = {{"write-through",1},{"write-back",2}};            //write hit policy
map<string,int> wm_map = {{"write-allocate",1},{"no-write-allocate",2}};    //write miss policy
map<string,int> re_map = {{"lru",1},{"fifo",2},{"random-evictions",3}};     //replacement policy

/*Summary Information*/
int total_loads = 0;
int total_stores = 0;
int total_cycles = 0;
int load_hits = 0;
int load_misses = 0;
int store_hits = 0;
int store_misses = 0;

/*Cache configuration structure*/
struct config_cache{
    int sets_num;   //positive power of 2, least 1, S
    int line_num;   //positive power of 2, least 1, E
    int bytes_size; //positive power of 2, least 4, B
    int wh_policy;  //write hit policy
    int wm_policy;  //wirte miss policy
    int re_policy;  //replacing policy
};

/*Cache class*/
class myCache{
private:
    int set,line,byte;
public:
    int State = NA;
    int **tag;
    int **valid;
    int **frequency;
    int **loadtime;
    int s,b,t;  // s:set index, b:block offset, t:tag index

    /*Policy*/
    int write_hit_policy;   // write-through : 1, write-back : 2;
    int write_miss_policy;  // write-allocate : 1, no-write-allocate : 2;
    int replace_policy;   // lru : 1, fifo : 2, random-evictions : 3

    /*Cache initialize*/
    myCache(int setnum, int linenum ,int bytesize,int wh_p,int wm_p,int re_p){ //set num, cache line num, block bytes size
        set = setnum;
        line = linenum;
        byte = bytesize;

        write_hit_policy = wh_p;
        write_miss_policy = wm_p;
        replace_policy = re_p;

        b = log2(bytesize);
        s = log2(setnum);    
        t = 32-s-b;

        tag = new int*[set];
        for(int i = 0; i < set; i++) tag[i] = new int[line];
        valid = new int*[set];
        for(int i = 0; i < set; i++) valid[i] = new int[line];
        frequency = new int*[set];
        for(int i = 0; i < set; i++) frequency[i] = new int[line];
        loadtime = new int*[set];
        for(int i = 0; i < set; i++) loadtime[i] = new int[line];
    }
    void access_cache(string acctype, unsigned int addr, int time);
};

void myCache::access_cache(string acctype, unsigned int addr,int time){
    bitset<32> accessaddr;
    accessaddr = bitset<32> (addr); //the address from the tracefile, treansform by bitset;

    /*Get tag, index, offset*/
    int input_tag = (bitset<32>((accessaddr.to_string().substr(0,t))).to_ulong());
    int input_index = (bitset<32>((accessaddr.to_string().substr(t,s))).to_ulong());
    int input_offset = (bitset<32>((accessaddr.to_string().substr(t+s,b))).to_ulong());

    /*check cache hit*/
    for(int i = 0 ; i < line; i++){
        if((tag[input_index][i] == input_tag) && (valid[input_index][i] == 1)){
            frequency[input_index][i]++;
                if(acctype.compare("l")==0){
                    load_hits++;
                    total_cycles += 1;
                }
                else if(acctype.compare("s")==0){
                    store_hits++;
                    if(write_hit_policy == 1) total_cycles += 100; 
                    if(write_hit_policy == 2) total_cycles += 1;
                }
            return;
        }
    }

    /*cache miss*/
    if(acctype.compare("l")==0){
        load_misses++;
        total_cycles += 1;
    }
    else if(acctype.compare("s")==0){
        store_misses++;
        if(write_miss_policy == 1) total_cycles += 1; 
        if(write_miss_policy == 2){ total_cycles += 100; return;}
    }

    for (int i = 0; i < line; i++){
        if(valid[input_index][i] == 0){
            tag[input_index][i] = input_tag;
            valid[input_index][i] = 1;
            frequency[input_index][i] = 1;
            loadtime[input_index][i] = time;
            return;
        }
    }
    /*Replacement*/
    int replaced_line = 0;
    if(replace_policy == 1){            //LRU
        for (int i = 0; i < line; i++){
            if(frequency[input_index][i] < frequency[input_index][replaced_line]) replaced_line = i;
            }    
        }
    else if(replace_policy == 2){       //FIFO 
        for (int i = 0; i < line; i++){
            if(loadtime[input_index][i] < loadtime[input_index][replaced_line]) replaced_line = i;
        }
    }
    else{                               //Random
        replaced_line = rand() % line;
    }
    tag[input_index][replaced_line] = input_tag;
    valid[input_index][replaced_line] = 1;
    frequency[input_index][replaced_line] = 1;
    loadtime[input_index][replaced_line] = time;
}

/*main*/
int main(int argc,char* argv[]){

    /*Set Cache Configuration*/
    config_cache config;
    config.sets_num = atoi(argv[1]);
    config.line_num = atoi(argv[2]);
    config.bytes_size = atoi(argv[3]);
    config.wm_policy = wm_map[argv[4]];  //write miss policy
    config.wh_policy = wh_map[argv[5]];  //wirte hit policy
    config.re_policy = re_map[argv[6]];  //replacing policy

    if(config.wh_policy == 2 && config.wm_policy == 2){
        cout << "can't combine no write allocate with write back" << endl;
        return 0;
    }

    myCache c(config.sets_num,config.line_num,config.bytes_size,config.wh_policy,config.wm_policy,config.re_policy);

    ifstream traces;
    traces.open(argv[7]);

    string line;
    string accesstype;  // the load/store access type from the memory trace;
    string xaddr;       // the address from the memory trace store in hex;
    unsigned int addr;  // the address from the memory trace store in unsigned int;        
    bitset<32> accessaddr; // the address from the memory trace store in the bitset;

    /*Simulate*/
    if (traces.is_open()){
        int time = 0;
        while (getline (traces,line)){   // read command line

            istringstream iss(line);
            if (!(iss >> accesstype >> xaddr)) break; //split access type & address(=xaddr)
            stringstream saddr(xaddr);
            saddr >> std::hex >> addr;

            c.access_cache(accesstype,addr,time);
            time++;
        }
        total_loads = load_hits+load_misses;
        total_stores = store_hits+store_misses;

        /*Pirnt summary information*/
        cout << "Total loads:  " << total_loads << endl;
        cout << "Total stores: " << total_stores << endl;
        cout << "Load hits:    " << load_hits << endl;
        cout << "Load misses:  " << load_misses << endl;
        cout << "Store hits:   " << store_hits << endl;
        cout << "Store misses: " << store_misses << endl;
        cout << "Total cycles: " << total_cycles << endl;
        traces.close();
    }
    else cout<< "Unable to open trace file " << endl;
    return 0;
}