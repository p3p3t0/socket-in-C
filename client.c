#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>
int main(){

	int network_socket;
	network_socket=socket(AF_INET,SOCK_STREAM,0);

	// address specification 
	struct sockaddr_in server_addr ;
	server_addr.sin_family=AF_INET;
	server_addr.sin_port = htons(9002);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	int connection_status =connect(network_socket,(struct sockaddr *) &server_addr,sizeof(server_addr));
 	// 0 okay -1 prob
	if (connection_status== -1){
	printf("conn fialed");}
	//receiving data
	while(1){
	char server_response[256];
	printf("server > \n");
	recv(network_socket,&server_response,sizeof(server_response),0); //first arg socket ,seconde where to stock response	

	//print response
	printf(" %s \n", server_response);
	printf("client > \n");
	fgets(server_response, 256, stdin);
        send (network_socket,server_response,sizeof(server_response),0);
	
	}
	//close the socket
	//close(network_socket);

	return 0;





}
