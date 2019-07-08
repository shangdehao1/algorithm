#include "../common.h"
#include <unistd.h>


int main(void)
{

  // use pipe at the same process
  {
    int fd[2];
    int res;

    res = pipe(fd);
    if(res < 0) {
      cout << "pipe fails..." << endl;
    }
    
    res = write(fd[1], "hello world\n", 12);
    if (res < 0) {
      cout << "write pipe fails..." << endl;
    }

    
    char result[32];
    res = read(fd[0], result, 32);
    if (res < 0) {
      cout << "read pipe fails..."  << endl;
    }

    cout << result;

    close(fd[0]);
    close(fd[1]);
  }

  

/*
	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid > 0) {		// parent 
		close(fd[0]);
		write(fd[1], "hello world\n", 12);
	} else {					// child 
		close(fd[1]);
		n = read(fd[0], line, MAXLINE);
		write(STDOUT_FILENO, line, n);
	}
	exit(0);
*/

  return 0;
}
