#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>
int main(){

	char server_message[256]="you are connected to server !";
	int server_socket=socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in serv_addr;
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(9002);
	serv_addr.sin_addr.s_addr= inet_addr("127.0.0.1");

	//bin hya associate ip and port
	bind (server_socket, (struct sockaddr*) &serv_addr,sizeof(serv_addr));
	listen (server_socket,5);
	int i=0;
	int client_socket=accept(server_socket,NULL,NULL);
	printf("client connected\n");
	while(1){
	if (i ==0){
	send (client_socket,server_message,sizeof(server_message),0);
	i++;
	}
	else{
	printf("client > ");
	char server_response[256];
        recv(client_socket,&server_response,sizeof(server_response),0); //first arg socket ,>

        //print response
        printf(" %s \n", server_response);
	printf("server >: \n");
  
    // Read input from the user
    	fgets(server_message, 256, stdin);
 	send (client_socket,server_message,sizeof(server_message),0);
}
}
	return 0;





}
