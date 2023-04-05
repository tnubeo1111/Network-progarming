#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
//#include <unp.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXLINE 100
#define LISTENQ 10

void dg_echo(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen){
	int n, a, b, total = 0; 
	socklen_t len;
	char mesg[MAXLINE], mesg1[MAXLINE], mesg2[MAXLINE];
	int matrix[100][100];
	
	for( ; ; ) {
		len = clilen;
		n = recvfrom(sockfd, mesg1, MAXLINE, 0, pcliaddr, &len);
		sendto(sockfd, mesg1, strlen(mesg1), 0, pcliaddr, len);
		
		n = recvfrom(sockfd, mesg2, MAXLINE, 0, pcliaddr, &len);
		//sendto(sockfd, mesg2, strlen(mesg2), 0, pcliaddr, len);
		
		a = atoi(mesg1);
		b = atoi(mesg2);
		for (int i = 0; i < a; i++) {
    			for(int j = 0; j < b; j++) {
    				matrix[i][j] = rand()%100; 
    				printf("%d ", matrix[i][j]);
    	}
    		printf("\n");
    }	
    		for (int i = 0; i < b; i++) {
    			total += matrix[0][i];
    		}
    		
		
		snprintf(mesg, MAXLINE, "Total 1st line is: %d", total);
		sendto(sockfd, mesg, strlen(mesg), 0, pcliaddr, len);
	}
}

int main (int argc, char **argv) {
	int sockfd;
	struct sockaddr_in servaddr, cliaddr;
	char buffer[MAXLINE];
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(1719);

	bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	dg_echo(sockfd, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
}
