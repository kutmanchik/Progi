from socket import *
import pickle
s = socket(AF_INET,SOCK_DGRAM)
host = gethostbyname(gethostname())
port = 10000
server_address = (host,port)
print("Connection to ", server_address)
list1 = []
try:
    print("Enter how many numbers in the list: ",end='')
    num = int(input())
    while num>0:
        print("Enter number: ",end="")
        num1 = int(input())
        list1.append(num1)
        num -=1
    s.sendto(str(list1).encode(),server_address)

    print("receiving data...")
    data,server = s.recvfrom(1024)
    data.decode()
    print("received sorted list ",data)
finally:
    print("Closing socket")
    s.close()
