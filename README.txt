1. Client sends request to a server.
2. Server reads data from data.mes file and sends data to the client.
   Format of data into the mes_file.h. Data.mes file conains header and data packets.
   For each packet specified the time of sending.
   Server should to send packets according with specified time.
3. Server and client output logs into console. Log information contains only metadata(size of packet, time and etc. except data).
4. At the end server sends message to client, and threads of client and server terminate.
