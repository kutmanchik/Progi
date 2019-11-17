import socket
import sys

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
    prompt = input("Enter a arithmetic calculation in prefix form: ")
    print('Sending ', prompt)
    s.sendall(prompt.encode())

    msg = []

    data = s.recv(10000)         #Receive the data in small chunks
    print("Receiving data from server")
    if data:
        print("received data from server  ", data)
        msg.append(data)
    else:
        print('No data receives from', server_address)

    print('Received ', b''.join(msg).decode())

finally:
    print('Closing socket: The End')
    s.close()
