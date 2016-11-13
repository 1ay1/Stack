#include <stdio.h>     /* for printf() and fprintf() */
#include <sys/socket.h>   /* for socket(), connect(), send(), recv() */
#include <string.h>    /*for memset() */
#include <arpa/inet.h>   /* for sockaddr_in and inet_addr() */
#include <stdlib.h>    /* for atoi() */
#include <unistd.h>   /* for close() */


/* now its time to just fix a recieve buffer size */
#define RCVBUFSIZE 32

/* Error handing fucntion */
void DieWithError(char *errorMessage)
{
    printf(errorMessage);
}


int main(int argc, char *argv[])
{
    int sock; /* socket descriptor */
    struct sockaddr_in echoServAddr ; /*echo server address*/
    unsigned short echoServPort; /*echo server port */
    char *serverIP;  /* server IP, usually an argument to the original program (argv[1])*/
    char *echoString; /*echo Sring which the program executer will feed to the program (argv[2])*/
    char echoBuffer[RCVBUFSIZE];
    unsigned int echoStringLen;
    int bytesRecvd, totalBytesRecvd; /* bytes recieved in one recv() call and total bytes recieved*/

    /*----------------------------------*/
    /* invalid arguments handler */
    if((argc < 3) || (argc > 4))
    {
        fprintf(stderr, "Usage: %s <Server IP> <Echo Word> [<Echo Port.]\n", argv[0]);
        exit(1);
    }

    /*-----------------------------------*/
    serverIP = argv[1]; /*let the first argument be the server's IP and assign it to the serverIP char pointer*/
    echoString = argv[2]; /*let the second argument be the string you wanna send to server and assign it to echoString char pointer*/
    /*----------------------------------------*/

    if(argc ==4)
    {
        echoServPort = atoi(argv[3]); //use given port if any
    }
    else
    {
        echoServPort = 7; //otherwise just use default
    }

    /*-----------------------------------------*/
    /*now we will create a reliable, stream socket*/
    sock = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(sock <0)
    DieWithError("Unable to create socket");

    /*---------------------------------------*/
    /*construct the server address structure*/
    memset(&echoServAddr,0,sizeof(echoServAddr)); //initiate all the values of the sockaddr_in structure zero
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = inet_addr(serverIP);
    echoServAddr.sin_port = htons(echoServPort);
    /*-------------------------------------------------------------*/
    /*server address structure defined */

    /*now lets just connect the socket to the server*/
    if(connect(sock,(struct sockaddr *) &echoServAddr,sizeof(echoServAddr)) < 0)
        DieWithError("connect() is failed!");
    /*-----------------------------------------*/

    echoStringLen = strlen(echoString);

    if (send(sock, echoString, echoStringLen,0) != echoStringLen)
    {
        DieWithError("Something is just wrong with the sending of message!");
    }

    /*------------------------------------------*/
    /*now we will recieve the same string back from the server*/
    totalBytesRecvd = 0;
    printf("Recieved: ");
    while (totalBytesRecvd < echoStringLen) {
        if ((bytesRecvd = recv(sock, echoBuffer,RCVBUFSIZE - 1, 0)) <= 0)
            DieWithError("Couldnt get the message from the server!");
        totalBytesRecvd += bytesRecvd;
        echoBuffer[bytesRecvd] = '\0' ;
        printf(echoBuffer);

    }

    printf("\n");
    close(sock);
    exit(0);
}
