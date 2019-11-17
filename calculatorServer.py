import socket
import sys

#definition of evalutePrefix function
def evaluatePrefix(string):
    string = string[::-1]       #reverse string using slicing
    stack = []
    for element in string:
        if element > 47 and element < 58 :
            stack.append(element - 48)
        else:
            o1 = stack.pop()
            o2 = stack.pop()
            if element == ord('*'):
                stack.append(o1*o2)
            elif element == ord('/'):
                stack.append(o1//o2)
            elif element == ord('+'):
                stack.append(o1+o2)
            else:
                stack.append(o1-o2)
    return stack[0]

#create a TCP/IP socket
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
host = socket.gethostbyname(socket.gethostname())
port = 10000
#bind the socket to the port
server_address = (host, port)
print('Starting up on port ', server_address)
s.bind(server_address)

#listen for incoming connections
s.listen(1)

while True:
    print('Waiting for a connection')
    connection, client_address = s.accept()      #wait for a connection
    print('try to connecting...',client_address)
    try:
        print('Connected to ', client_address)
        while True:         #Receive the data in small chunks and retransmit it
            data = connection.recv(10000)
            if data:
                result = evaluatePrefix(data)
                #print('Data after evaluation', result)
                print('Sending data back to the client')
                connection.sendall(str(result).encode())
            else:
                print('No data receives from ', client_address)
                break
    finally:        #clean up the connection

        connection.close()
