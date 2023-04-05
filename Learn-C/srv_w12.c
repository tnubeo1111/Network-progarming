#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#define MAXLINE 100
#define LISTENQ 10

int main (int argc, char **argv) {
	pid_t pid;
	int listenfd, connfd, ticks;
	struct sockaddr_in servaddr, cliaddr;
	char buffer[MAXLINE];
	int result;
	int count;
	
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(1438);

	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	listen(listenfd, LISTENQ);

	for ( ; ; ) {
		int len = sizeof(cliaddr);
		connfd = accept(listenfd, (struct sockaddr*) &cliaddr, &len);
		count++;
		printf("connection from %s, port %d\n",
				inet_ntop(AF_INET, &cliaddr.sin_addr, buffer, sizeof(buffer)), 
				ntohs(cliaddr.sin_port));
			
			ticks = time(NULL);
			snprintf(buffer, sizeof(buffer), "Your client number is %d\n", count);
			
		if ( (pid = fork()) == 0 ) {	
			close(listenfd);
			
			while(read(connfd, buffer, strlen(buffer))) {	
			write(connfd, buffer, strlen(buffer));
			}
			
		//	close(connfd);
			exit(0);
		}
		
		close(connfd);
	}
}
