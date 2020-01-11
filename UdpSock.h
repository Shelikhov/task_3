//#include "CurTime.cpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include "ErrorCheck.h"
#include "PrintInfo.h"
#include <string>
#include <ctime>

#define PORT 8080

class UdpSock{
	public:
		void createServSock();//server socket
		void createCliSock();//client socket
		void closeSock();
		void recvMsg(auto &buffer);
		void sendMsg(auto &buffer);
		void sendTerm();
	private:
		int udpSocket;
		struct sockaddr_in serverAddr, clientAddr;
		struct in_addr addr;//network address
		int checkResult;
		socklen_t len;
		ErrorCheck err;//to check return value
		std::string nameSock;
		PrintInfo print;
};
