#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<netinet/in.h>

void main (int argc, char *argv[]) {
	if (argc < 2) {
		printf("usage: %s <hostname> \ni.e %s google.ecom\n", argv[0], argv[0]);
		exit(1);
	}

	struct hostent *addr = gethostbyname(argv[1]);
	struct in_addr **addrList;
	addrList = (struct in_addr **) addr->h_addr_list;

	printf("Domain Name: %s\n", addr->h_name);
	for (int i = 0; addrList[i] != NULL; i++) {
		printf("Host Address: %s\n", inet_ntoa(*addrList[i]));
	}


}
