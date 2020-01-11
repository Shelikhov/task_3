#include "mes_file.h"
#include <mutex>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "UdpSock.cpp"
#include <string>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstring>

void funServ(){
	UdpSock server;
	server.createServSock();
	char msg[1024];
	std::ifstream file("/home/money/c++/Задачи/Задача 3/data.mes", std::ios::in | std::ios::binary);
	T_PacketFileHeader header;
	if(file.read((char*)&header, sizeof(T_PacketFileHeader)))
		std::cout << "read header success" << std::endl;

	T_Packet packet;
	std::mutex mut;
	server.recvMsg(msg);
	std::cout << msg << std::endl;
	while(!file.eof()){
		mut.lock();
		file.read((char*)&packet, sizeof(T_Packet));
		server.sendMsg(packet.Data);
		mut.unlock();
	//	std::this_thread::sleep_for(std::chrono::milliseconds(packet.Time));
	}
	server.sendTerm();
	file.close();
	server.closeSock();
}

void funClient(){
	UdpSock client;
	client.createCliSock();
	char msg[] = "request";
	std::string str;
	client.sendMsg(msg);
	std::mutex mut;
	while(1){
		mut.lock();
		char data[1024];
		client.recvMsg(data);
		str = data;
		if(str == "end") break;
		mut.unlock();
	}
	client.closeSock();
}

int main(){
	std::thread serverThread(funServ);
	std::thread clientThread(funClient);

	serverThread.join();
	clientThread.join();
	return 0;
}
