/*************************************************************************
	> File Name: More.c
	> Author:fangsong
	> Mail: 
	> Created Time: 2020年03月21日 星期六 19时29分41秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define LENLINE 512
#include<termios.h>
#include<sys/ioctl.h>
#include<termios.h>
#include<signal.h>
#include<unistd.h>
int PAGLINE;

void f(){
    struct winsize size;
    ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
    PAGLINE = size.ws_row;
}

int get_cmd(FILE *fp) {
    printf("more:");
    int c;
    while((c = fgetc(fp))!=EOF) {
        if(c == 'q') return 0;
        else if(c == ' ') return PAGLINE;
        else if(c == '\n')return 1;
    }
    return -1;
}

void do_more(FILE *fp) {
    char line[LENLINE] = {0};
    FILE *cmd = fopen("/dev/tty", "r");
    int num_line = 0, reply, get_cmd(FILE *);
    while(fgets(line, LENLINE, fp)) {
        if(num_line == PAGLINE) {
            reply = get_cmd(cmd);
            if(reply == 0) break;
            num_line -= reply;
        }
        if(fputs(line, stdout) == EOF) {
            perror("fputs");
            exit(1);
        }
        num_line++;
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    f();
    if(argc == 1) {
        do_more(stdin);
    } else {
        while(--argc) {
            if((fp = fopen(*++argv,"r"))!=NULL) {
                do_more(fp);
            }
        }
    }
    return 0;
}
