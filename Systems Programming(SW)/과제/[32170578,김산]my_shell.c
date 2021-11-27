/* Simple_Shell program using system call, by San Kim, waterfog9580@gmail.com*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX_CMDLEN 100
#define MAX_LIST 10
#define BUF_SIZE 1024

static char* tokens[MAX_LIST];
static char cmd_line[MAX_CMDLEN];

/*Default  command set*/
char* default_cmd[] = {"ls", "cd","help","exit"};

int cmd_ls();
int cmd_help();
int cmd_exit();

/*shell function*/
int tokenizer(char* buf, const char* delimiter, char* tokens[], int maxTokens);

void exec_handler();
void exec_default();
void exec_redirect(int);

int parse_Defualt();
int parse_Background();
int parse_Redirect();

/*main*/
int main(){
    int token_num;
    while(1){
        fflush(NULL);
        printf("%s $ ", get_current_dir_name());
        fgets(cmd_line, MAX_CMDLEN, stdin);
        cmd_line[strlen(cmd_line) -1] = NULL;
        exec_handler();
        *tokens = NULL;
    }
    return 0;
}

/*Default  command set implementation*/
int cmd_ls(){
    char* path = get_current_dir_name();
    DIR * dp = opendir(path);
    struct dirent * ep;
    char newdir[512];

    if(!dp) {
        perror(path);
        return -1;
    }
    while((ep = readdir(dp))){
        if(strncmp(ep->d_name, ".", 1)) printf("%s\t", ep->d_name);
    }
    printf("\n");
    closedir(dp);
    return 1;
}

int cmd_cd()
{
    if (tokens[1] == NULL) {
        fprintf(stderr, "cd: expected argument to \"cd\"\n");
        }
    else {
        if (chdir(tokens[1]) != 0) {
            perror("cd");
        }
    }
    return 1;
}

int cmd_help(){
    printf("--------------------------------------\n");
    printf("Simple shell program\n");
    printf("by San Kim, waterfog9580@gmail.com\n");
    printf("default command\n");
    printf("1.ls 2.cd 3.help 4.exit\n");
    printf("--------------------------------------\n");
    return 0;
}
int cmd_exit(){
    exit(1);
}

/*shell function implementation*/
int tokenizer(char* buf,const char* delimiter,char** tokens,int maxTokens){
    char* token;
    int token_count = 0;
    if(buf==NULL && delimiter==NULL) return -1;

    token = strtok(buf, delimiter);
    while(token !=NULL && token_count < maxTokens){
        tokens[token_count++] = token;
        token = strtok(NULL, delimiter);
    }
    tokens[token_count] = NULL;

    if(token_count > maxTokens) return -1;
    return token_count;
}

int parse_Defualt(){
    int i;
    int num_default_cmd = sizeof(default_cmd) / sizeof(char *);
    for (i = 0; i < num_default_cmd; i++){
        if(strcmp(tokens[0],default_cmd[i]) == 0) return 1;
    }
    return 0;
}

int parse_Background(){
    int i;
    for (i = 0; tokens[i] != NULL; i++){
        if(!strcmp(tokens[i],"&")){
            return 1;
        }
    }
    return 0;
}

int parse_Redirect(){
    int i = 0;
    for (i = 0; tokens[i] != NULL; i++){
        if(!strcmp(tokens[i],">")){
            return i;
        }
    }
    return 0;
}

void exec_handler(){
    pid_t pid;
    int r_index;
    int token_num;
    
    token_num = tokenizer(cmd_line, " ", tokens, sizeof(tokens)/sizeof(char*));
    if(token_num == -1) return -1;

    if(tokens[0] != NULL){
        if(parse_Defualt()){
            exec_default();
            return;
        }
        else{
            switch (pid = fork()){
                case -1:
                    perror("fork error"); exit(1);
                case 0:
                    if(r_index = parse_Redirect()){
                        exec_redirect(r_index);
                    }
                    execvp(tokens[0], tokens);
                default:
                    if(!parse_Background())
                    wait(1);
                    break;
            }
        }
    }
    return;
}

void exec_default(){
    if(strcmp(tokens[0], default_cmd[0]) == 0) cmd_ls();
    if(strcmp(tokens[0], default_cmd[1]) == 0) cmd_cd();
    if(strcmp(tokens[0], default_cmd[2]) == 0) cmd_help();
    if(strcmp(tokens[0], default_cmd[3]) == 0) cmd_exit();
    return;
}

void exec_redirect(int i){
    int fd;
    if(!tokens[i+1]) return;
    else{
        if((fd = open(tokens[i+1],O_RDWR|O_CREAT|S_IROTH,0664)) == -1){
            perror(tokens[i+1]);
            return -1;
        }
    }
    dup2(fd,STDOUT_FILENO);
    close(fd);
    return;
}