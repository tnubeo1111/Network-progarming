#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#define MAXLINE 100
#define LISTENQ 10

int main (int argc, char **argv) {
	int listenfd, connfd;
	struct sockaddr_in servaddr;
	char buffer[MAXLINE];
	int result;
	int count;
	
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(1433);

	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	listen(listenfd, LISTENQ);

	for ( ; ; ) {
		connfd = accept(listenfd, (struct sockaddr*) NULL, NULL);
		 
		while(n = read (connfd, buffer, MAXLINE) > 0){
			count++;
			buffer[MAXLINE] = "Sentence no. : ";
			snprintf(buffer, MAXLINE, "%s", count);
			write (connfd, buffer, strlen(buffer));
		}
		
		close(connfd);
	}
}
