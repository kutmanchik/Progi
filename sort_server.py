from socket import *
import pickle
s = socket(AF_INET,SOCK_DGRAM)
host = gethostbyname(gethostname())
port = 10000
server_address = (host,port)
s.bind((host,port))
while True:
    print("connecting to ",server_address)
    data , addr = s.recvfrom(1024)
    if data:
        data.decode()
        list1 = []
        for i in str(data):
            if i.isdigit():
                list1.append(int(i))
        so = sorted(list1)
        print(so)
        sent = s.sendto(str(so).encode(),addr)
