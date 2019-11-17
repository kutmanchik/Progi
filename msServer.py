import socket
import numpy as np
import sys
import pickle

#create a TCP/IP socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostbyname(socket.gethostname())
port = 10000
#bind the socket to the port
server_address = (host, port)
print('Starting up on port ', server_address)
s.bind(server_address)

#listen for incoming connections
s.listen(1)

info = []
flag = 1
get = []
while True:
    print('Waiting for a connection')
    connection, client_address = s.accept()      #wait for a connection
    try:
        print('Connection from', client_address)
        while True:
            print("connected to ",client_address)
            data = connection.recv(10000)
            data = data.decode()
            if data:
                if "send" in data:
                    comm, mailID, message = data.split()
                    if not info:
                        temp = []
                        temp.append(mailID)
                        temp.append(message)
                        info.append(temp)
                    else:
                        for each in info:
                            if mailID == each[0]:
                                 each.append(message)
                                 flag = 0;
                        if flag:
                            temp = []
                            temp.append(mailID)
                            temp.append(message)
                            info.append(temp)
                        flag = 1
                elif 'receive' in data:
                    comm, mailID = data.split()
                    for each in info:
                        if mailID == each[0]:
                            get = [mail for mail in each if mailID != mail]
                    arr = pickle.dumps(get)
                    connection.send(arr)
                    del each[1::]
                    get = []
            else:
                print('No data receives from ', client_address)
                break
    finally:        #clean up the connection
        connection.close()
