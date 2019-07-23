
// how to implement async connect ? 
// 1 : set socket to non-block..
// 2 : connect socket to remote socket. 
//      - if connect return 0, show connection successfully. 
//      - if connect return -1 and EINPROGRESS, show connection in the way !!! 
// 3 : use select or epoll to monitor epoll fd. 
//      - once socket become writable, use getsocketopt to check status 
//            - return 0, show connection successfully.
//            - return -1, show connection fails.
// 
 
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <string.h>
 
void setnonblock(int fd)
{
    int flags = fcntl(fd, F_GETFL);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}
 
int main(){
  const char* ip = "127.0.0.1";
  short port = 9999;
  
  // set socket address
  struct sockaddr_in addr;
  socklen_t socklen = sizeof(struct sockaddr_in);
  memset(&addr , 0 , sizeof(struct sockaddr_in));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip);
  addr.sin_port = htons(port);
  
  // create socket
  int fd = socket( AF_INET , SOCK_STREAM , 0);
  if (fd < 0){
    printf("socket() error\n");
    return -1;
  }

  // set socket to be writable.
  setnonblock(fd);
  
  // connect to remote side.
  int res;
  res = connect(fd , (struct sockaddr*)&addr , socklen);
  if (res == 0){
    printf("connect ok(1)\n");
  } else if (res == -1 && errno != EINPROGRESS){
    printf("connect err(1)\n");
    close(fd);
    return -1;
  } else {
    int epfd;
    // create epoll
    epfd = epoll_create(1024);
    if ( (epfd = epoll_create(1024) ) == -1){
      printf("epoll_create() err\n");
      close(fd);
      return -1;
    }

    // add socket into epoll
    struct epoll_event ev;

    // writable event.
    ev.events = EPOLLOUT;
    ev.data.fd = fd;
    epoll_ctl( epfd , EPOLL_CTL_ADD , fd , &ev);
    
    //编写网络程序的时候,epoll是程序的主循环.我们这里为了测试,连接上或connect超时(75秒)就break掉.
    //正常的流程是写一个处理connect结果的回调函数.
    int event_max = 1;
    struct epoll_event events[event_max];
    int i;
    while (1){
      res = epoll_wait( epfd , events , event_max , -1);
      if (res > 0){
        for ( i = 0 ; i < res ; i++){
          if ( events[i].data.fd == fd && ( events[i].events & EPOLLOUT) ){ //29(EPOLLOUT|EPOLLERR|EPOLLHUP)  //4(EPOLLOUT)
            int optval;
            socklen_t optlen = sizeof(optval);

            // get socket status.
            int res1 = getsockopt(fd, SOL_SOCKET, SO_ERROR, &optval, &optlen);
            if ( res1 < 0 || optval){
              close(fd);
              close(epfd);
              printf("connect err(2)\n");
              return -1;
            } else {
              printf("connect ok(2)\n");
            }
          }
        }
        break;
      }
    }
    close(fd);
    close(epfd);
  }

}
