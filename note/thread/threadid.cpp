#include "../include/apue.h"
#include <pthread.h>
#include <iostream>

using namespace std;

pthread_t ntid;

void printids(const char *s){
    pid_t pid;
    pthread_t tid;
    pid = getpid(); 
    tid = pthread_self();
    cout<<s<<endl;
    cout<<"process id is "<<pid<<endl;
    cout<<"thread id is "<<tid<<endl;
    //printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid,
     //   (unsigned long)tid, (unsigned long)tid);
}

void* thr_fn(void *arg){
    printids("new thread: ");
    cout<<(char*)arg<<endl;
    return((void *)0);
}

int main(void){

    int err;
    const char* p="this is thread function parameter";
    err = pthread_create(&ntid, NULL, thr_fn, (void*)p);
    if (err != 0){
       cout<<(err, "can't create thread");
    }
    printids("main thread:");
    sleep(1);
    exit(0);
}
