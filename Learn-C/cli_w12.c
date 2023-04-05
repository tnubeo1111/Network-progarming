#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 100

int main(int argc, char **argv){
	int sockfd, n;
	char recvline[MAXLINE + 1];
	char buffer[MAXLINE];
	
	struct sockaddr_in servaddr;
	if (argc != 2)
		printf("usage: a.out < IPadd");

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		printf ("socket err");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(1438);

	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		printf("inet_pton err for %s", argv[1]);

	if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
		printf("connect err");
	
		printf("Say something: ");
		fgets(buffer, sizeof(buffer), stdin);
		write(sockfd, buffer, strlen(buffer));

		while ((n = read (sockfd, recvline, MAXLINE)) > 0) {
			recvline[n] = 0;
			if (fputs (recvline, stdout) == NULL)
				printf ("fputs err");	
		fputs(recvline, stdout);
		}		
		if(n < 0) printf ("read err");
		
	close (sockfd);
	
	exit(0);
}
