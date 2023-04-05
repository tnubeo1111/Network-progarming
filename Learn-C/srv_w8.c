#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#define MAXLINE 100
#define LISTENQ 10

//void concatstr(char *str1, char *str2) {
//	for (int i = 0; i < 2; i++) {
//		strcat(str1, str2);
//	}
//}

int main (int argc, char **argv) {
	int listenfd, connfd, n;
	struct sockaddr_in servaddr;
	char buffer1[MAXLINE], buffer2[MAXLINE], buffer[MAXLINE];
	int result;
	
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(1453);

	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	listen(listenfd, LISTENQ);

	for ( ; ; ) {
		connfd = accept(listenfd, (struct sockaddr*) NULL, NULL);
		
		n = read (connfd, buffer1, MAXLINE); buffer1[n-1] = 0;
		read (connfd, buffer2, MAXLINE);
		
		snprintf(buffer, MAXLINE, "%s %s", buffer1, buffer2);
	
		write (connfd, buffer, strlen(buffer));
		
		close(connfd);
	}
}
