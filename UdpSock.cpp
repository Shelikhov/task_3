#include "UdpSock.h"

void UdpSock::createServSock(){
        udpSocket = socket(AF_INET, SOCK_DGRAM, 0);
        err.checking(udpSocket, "server socket");
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = PORT;
        serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        checkResult = bind(udpSocket, (const sockaddr *)&serverAddr, sizeof(serverAddr));
        err.checking(checkResult, "server bind");
	len = sizeof(clientAddr);
	nameSock = "server";
}

void UdpSock::createCliSock(){
        udpSocket = socket(AF_INET, SOCK_DGRAM, 0);
        err.checking(udpSocket, "client socket");
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = PORT;
        serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientAddr = serverAddr;
	len = sizeof(serverAddr);
	nameSock = "client";
}

void UdpSock::closeSock(){
        close(udpSocket);
}

void UdpSock::recvMsg(auto &buffer){
        checkResult = recvfrom(udpSocket, &buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddr, &len);
        err.checking(checkResult, "recvfrom");
	print.printMeta(nameSock, "received", sizeof(buffer));
}

void UdpSock::sendMsg(auto &buffer){
        checkResult = sendto(udpSocket, &buffer, 1024, 0, (struct sockaddr*)&clientAddr, sizeof(clientAddr));
        err.checking(checkResult, "sendto");
	print.printMeta(nameSock, "sent", 1024);
}

void UdpSock::sendTerm(){
	char end[] = "end";
	checkResult = sendto(udpSocket, end, sizeof(end), 0, (struct sockaddr*)&clientAddr, sizeof(clientAddr));
	err.checking(checkResult, "terminate msg");
	print.printMeta(nameSock, "sent", sizeof(end));
}
