from socket import *
import sys
import pickle

## create a UDP socket
s = socket(AF_INET,SOCK_DGRAM)
host = gethostbyname(gethostname())
port = 10000
s_addr = (host, port)
try:
    fileptr = open("message_text.txt","r")
    if fileptr.mode == 'r':
        text = fileptr.read().splitlines()
    for i in range (len(text)):
        message = []
        if 'Send' in text[i]:
            message.append(text[i])
            message.append(text[i+1])
            message.append(text[i+2])
            print(text[i])
            print(text[i+1])
            print(text[i+2])
            array = pickle.dumps(message)
            sent = s.sendto(array, s_addr)
            test, addr = s.recvfrom(4096)
        elif 'Receive' in text[i]:
            message.append(text[i])
            message.append(text[i+1])
            print(text[i])
            print(text[i+1])
            i = i + 1
            array = pickle.dumps(message)
            sent = s.sendto(array, s_addr)
            data, server = s.recvfrom(4096)
            if data:
                msg = pickle.loads(data)
                for mail in msg:
                    print (mail)
            else:
                print('No message receives from', s_addr)
    fileptr.close()
finally:
    print('Closing socket')
    s.close()
