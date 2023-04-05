#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#define MAXLINE 100
#define LISTENQ 10

struct User {
	char name;
	char pw;
};

struct User data[100];

int main (int argc, char **argv) {
	int listenfd, connfd;
	struct sockaddr_in servaddr;
	char buffer[MAXLINE], buffer1[MAXLINE], buffer2[MAXLINE];
	int check, n;
	
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(1410);

	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	listen(listenfd, LISTENQ);
	
	struct User u1;
	u1.name = "nguyen";
	u1.pw = "123";
	
	struct User u2;
	u2.name = "hoang";
	u2.pw = "234";
	
	struct User u3;
	u3.name = "quoc";
	u3.pw = "345";
	
	struct User u4;
	u4.name = "bao";
	u4.pw = "987";
	
	for ( ; ; ) {
		connfd = accept(listenfd, (struct sockaddr*) NULL, NULL);
		 
		while(n = read (connfd, buffer1, MAXLINE) > 0){
			for (int i = 0; i < 4; i++){
				if (strcmp (buffer1, data[i].name) == 0){ 
					snprintf(buffer, MAXLINE, "%s", "Please enter password!!!");
					write (connfd, buffer, strlen(buffer));
					read (connfd, buffer2, MAXLINE);
					if (strcmp (buffer2, data[i].pw) == 0){ 			
						snprintf(buffer, MAXLINE, "%s", "Welcome User: ", data[i].name);
						write (connfd, buffer, strlen(buffer));
						break;	
				} 
				else {
					check++;
					if (check == 3) {
						snprintf(buffer, MAXLINE, "%s", "You’ve input wrong username/password more than 3 times.");
						write (connfd, buffer, strlen(buffer));
						break;
				}		
			}
		}
			else {
				check++;
				if (check == 3) {
					buffer[MAXLINE] = "You’ve input wrong username/password more than 3 times.";
					break;
				}
			}
		}		
	}
			//snprintf(buffer, MAXLINE, "%s", count);	
		}
		
	close(connfd);
}
