#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#define MAXLINE 100
#define LISTENQ 10

//void clear(char s[90],int index) {
//	int n = strlen(s);
//	for(int i = index; i < n; i++) {
//		s[i]=s[i+1];
//		s[n-1]='\0';
//	}
//}

//void clear_space(char*s) {
//   for(int i = 0; i < strlen(s); i++) {
//    	if(s[i]==' ' && s[i+1]==' ') {
//		clear(s,i);
//		i--;
//	}
  //  }
//    if(s[0]==' ')
//	clear(s,0);
//    if(s[strlen(s)-1]==' ')
//	clear(s,strlen(s)-1);
//}

//int count_word(char* s) {
//	int count = 1;
	//clear_space(s);
//	for (int i = 0; i < strlen(s); i++) {
//		if (s[i] == ' ') {
//			count++;
//		}
//	}
//	return count;
//}

int Reply(char* s) {
	int a, b;
	int result;
	
	for (int i = 0; i < strlen(s); i++) {
		a = atoi(& s[0]);
		b = atoi(& s[2]);
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
		switch(s[i]) {
			case '+': return result = a + b;
			case '-': return result = a - b;
			case '*': return result = a * b;
			case '/': return result = a / b; 
		}
	}
	}
	return result;
}

int main (int argc, char **argv) {
	int listenfd, connfd;
	struct sockaddr_in servaddr;
	char buffer[MAXLINE];
	int result;
	
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(1402);

	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	listen(listenfd, LISTENQ);

	for ( ; ; ) {
		connfd = accept(listenfd, (struct sockaddr*) NULL, NULL);
		
		read (connfd, buffer, MAXLINE);

		result = Reply(buffer);		
		printf ("Client text: \n");
		printf ("%s\n", buffer);
		
		snprintf(buffer, MAXLINE, "%s = %d", buffer, result);
		write (connfd, buffer, strlen(buffer));
		
		close(connfd);
	}
}
