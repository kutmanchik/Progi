import socket
import sys
import pickle

#create a TCP/IP socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostbyname(socket.gethostname())
port = 10000
#connect the socket to the server listening port
server_address = (host, port)
print('Connecting server port ', server_address)
s.connect(server_address)


try:
    # Send data
    fileptr = open("message.txt","r")
    if fileptr.mode == 'r':
        text = fileptr.readlines()
    text = [line.rstrip() for line in text]

    for mail in text:
        print(mail)
        s.sendall(str(mail).encode())
        if 'receive' in mail:
            data = s.recv(1024)
            msg = pickle.loads(data)
            if data:
                for mail in msg:
                    print (mail)
            else:
                print('No message receives from', server_address)
finally:
    print('Closing socket: The End')
    s.close()
