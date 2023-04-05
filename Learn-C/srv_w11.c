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

int main (int argc, char **argv) {
	int listenfd, connfd, a, b, n;
	struct sockaddr_in servaddr;
	char buffer[MAXLINE], buffer1[MAXLINE], buffer2[MAXLINE];
	int matrix[100][100];
	
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(1459);

	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	listen(listenfd, LISTENQ);

	for ( ; ; ) {
		connfd = accept(listenfd, (struct sockaddr*) NULL, NULL);
		
		FILE *fp = fopen("matrix.txt", "w");
		if (fp == NULL) {
			printf ("File not exist");
		}
    				
		read (connfd, buffer1, MAXLINE);
		a = atoi(buffer1);
		
		read (connfd, buffer2, MAXLINE);
		b = atoi(buffer2);	
			
		for (int i = 0; i < a; i++) {
    			for(int j = 0; j < b; j++) {
    				matrix[i][j] = rand()%100; 
    				printf("%d ", matrix[i][j]);
    				fprintf(fp, "%d\t", matrix[i][j]);
    				fprintf(fp, "\n");
    			}
    		printf("\n");
    		}
    		
    		//snprintf();
    		//write (connfd, buffer, MAXLINE);		
	fclose(fp);
	
	fp = fopen("matrix.txt", "r");
	while (fgets(buffer, MAXLINE, fp) != NULL)
		write (connfd, buffer, strlen(buffer));
	fclose(fp);
	
	close(connfd); 
	}
}

