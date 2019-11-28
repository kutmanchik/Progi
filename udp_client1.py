from socket import *
s = socket(AF_INET,SOCK_DGRAM)
host = gethostbyname(gethostname())
port = 10000
server_addr = (host,port)
msg = "Hello Kutman"
try:
    print("Sending ", msg)
    sent = s.sendto(msg.encode(),server_addr)
#receie response

    print("Waiting to receive :::")
    data, server = s.recvfrom(4096)
    print("received ",data)
finally:
    print("closing socket")
    s.close()
