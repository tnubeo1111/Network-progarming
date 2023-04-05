#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 100

struct User {
	char n;
	char pw;
};

int main(int argc, char **argv){
	int sockfd, n;
	char recvline[MAXLINE + 1];
	char buffer1[MAXLINE], buffer2[MAXLINE];
	
	struct sockaddr_in servaddr;
	if (argc != 2)
		printf("usage: a.out < IPadd");

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		printf ("socket err");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(1410);

	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		printf("inet_pton err for %s", argv[1]);

	if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
		printf("connect err");
	
	printf("Enter user name: ");
	fgets(buffer1, sizeof(buffer1), stdin);
	write(sockfd, buffer1, strlen(buffer1));

	while ((n = read (sockfd, recvline, MAXLINE)) > 0) {
		printf("Enter password: ");
		fgets(buffer2, sizeof(buffer2), stdin);
		write(sockfd, buffer2, strlen(buffer2));
	
		recvline[n] = 0;
		if (fputs (recvline, stdout) == NULL)
			printf ("fputs err");	
		fputs(recvline, stdout);
	}		
	if(n < 0) printf ("read err");
		
	//close (sockfd);
	
	exit(0);
}
