#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc,char *argv[])
{	
    char group_addr[16]="224.0.0.88";
	int socked=socket(AF_INET,SOCK_DGRAM,0);  
	if(socked<0)
	{
		perror("socket failed!");
		return 2;
	}
				
	struct sockaddr_in remote_addr;
	memset(&remote_addr,0,sizeof(remote_addr));
				
	remote_addr.sin_family=AF_INET;
	remote_addr.sin_addr.s_addr=inet_addr(group_addr);
	remote_addr.sin_port=htons(8888);
									
	char buf[1024]="This is a group udp";
	int length=0;
 	while(1)
	{
		memset(buf, 0, sizeof(buf));  
																
		length=sendto(socked,buf,strlen(buf),0,(struct sockaddr *)&remote_addr,sizeof(remote_addr));
		printf("Send Message%s\n",buf);
	}
	close(socked);
	return 0;
}
