#include <iostream>
#include <sys/socket.h> // 
#include <netinet/in.h>
#include <cstdlib>
#include <csignal> // SIGINT
#include <string.h> // bzero
//#include <unistd.h> // read
using namespace std;


static volatile int keepRunning=1;

void intHandler(int dummy){
	keepRunning=0;
	cout<<"Here";
}

int main(int argc, char **argv){
	if (argc!=3){
		cout<<"BAD call. Must be '"<<argv[0]<<" name port'."<<endl;
		return -1;
	}
	
	int portno = 0;
	if((portno=atoi(argv[2]))==0){
		cout<<"BAD value for port."<<endl;
		return -2;
	}
	cout<<"Puerto: "<<portno<<endl;
	int server_fd;
	
	if((server_fd=socket(AF_LOCAL, SOCK_STREAM, 0))==0){
		cout<<"Socket FAIL."<<endl;
		return -3;
	} else cout<<"Socket inicializado"<<endl;
	
	struct sockaddr_in address;
	address.sin_family= AF_LOCAL;
	address.sin_addr.s_addr = INADDR_ANY; // localhost
	address.sin_port = htons(portno);
	
	if(bind(server_fd, (struct sockaddr *) &address, sizeof(address))<0){
		cout<<"Bind FAIL."<<endl;
		return -4;
	} else cout<<"Bind ok."<<endl;
	
	if(listen(server_fd, 3)<0){
		cout<<"Listen FAIL."<<endl;
		return -5;
	} else cout<<"Listening ..."<<endl;
	
	int new_socket;
	int addrlen = sizeof(address);
	if((new_socket=accept(server_fd, (struct sockaddr *) &address, (socklen_t*)  &addrlen))<0){
		cout<<"Accept FAIL."<<endl;
		return -6;
	} else cout<<"Socket pair."<<endl;
	
	char buffer[1024]={0};
	int valread;
	signal(SIGINT, intHandler);
	cout<<"Running...";
	while(keepRunning){
		//
		valread=read(new_socket, buffer, 1024);
		cout<<"Len: "<<valread<<endl;
		cout<<"Buffer: '"<<buffer<<"'"<<endl;
		bzero(buffer, 1024);
	}
	cout<<"Cerrando conexión..."<<endl;
	if(close(new_socket)!=0) cout<<"Socket pair to cliente fail to close."<<endl;
	if(close(server_fd)!=0) cout<<"Socket server  fail to close."<<endl;
	cout<<"END."<<endl;
	return 0;
}
