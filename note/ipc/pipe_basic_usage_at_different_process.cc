#include "../common.h"
#include <stdio.h>
#include <unistd.h>

void child_process_entry(int pipe_w) {
  std::cout << "hello, i'm child process " << std::endl;
  sleep(2);
  char temp[] = {"hello word message come from child process\n"};
  write(pipe_w, temp, sizeof(temp));

}

void parent_process_entry(int pipe_r) {
  std::cout << "hello, i'm parent process " << std::endl;
  sleep(2);

  char buffer[64];
  int ret = read(pipe_r, buffer, 64);
  write(STDOUT_FILENO, buffer, ret);
}


int main(void)
{
  int pipe_fd[2];
  int n;        
  pid_t   process_id;
  char line[32];

  if ((process_id = fork()) < 0) 
  {
    printf("fork error\n");
  }
  else if (process_id > 0) 
  {
    close(pipe_fd[0]);
    child_process_entry(pipe_fd[1]);
  }
  else 
  {
    close(pipe_fd[1]);
    parent_process_entry(pipe_fd[0]);
  }

  return 0;
}

