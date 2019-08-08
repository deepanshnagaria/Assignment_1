
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<errno.h>
#include<netdb.h>
#include<arpa/inet.h>


int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please enter the host name\n");
        return 0;
    }
    char *hostname = argv[1];
    struct hostent *host_entry;
    struct in_addr **address_list;
    host_entry = gethostbyname(hostname);
    if(host_entry != NULL) {
        address_list = (struct in_addr **) host_entry->h_addr_list;
        printf("%s has the ip address %s\n", hostname, inet_ntoa(*address_list[0]));   
    }
    else {
        printf("ip address not found\n");
    }
    return 0;
}

