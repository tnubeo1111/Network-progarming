#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 100

void dg_cli(FILE *fp, int sockfd, struct sockaddr *pservaddr, socklen_t servlen){
	int n;
	char sendline[MAXLINE], recvline1[MAXLINE + 1], sendline1[50], sendline2[50], recvline2[MAXLINE + 1], recvline[MAXLINE + 1];
	
	
		printf("Send 1st number: ");
		fgets (sendline1, MAXLINE, fp);
		sendto(sockfd, sendline1, strlen(sendline1), 0, pservaddr, servlen);
		n = recvfrom(sockfd,recvline1, MAXLINE, 0, NULL, NULL);
		fputs(recvline1, stdout);
		
		printf("Send 2nd number: ");
		fgets (sendline2, MAXLINE, fp);
		sendto(sockfd, sendline2, strlen(sendline2), 0, pservaddr, servlen);
		n = recvfrom(sockfd,recvline2, MAXLINE, 0, NULL, NULL); 
		fputs(recvline2, stdout);
		
		//n = recvfrom(sockfd,recvline, MAXLINE, 0, NULL, NULL); 
		
		recvline2[n] = 0;
		fputs(recvline2, stdout);
}

int main(int argc, char **argv){
	int sockfd;
	
	struct sockaddr_in servaddr;
	
	if (argc != 2)
		printf("usage: a.out < IPadd");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(1719);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
		
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	dg_cli(stdin, sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	
	exit(0);
}
