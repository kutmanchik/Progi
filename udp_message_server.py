from socket import *
import sys
import pickle

# create a UDP socket
s = socket(AF_INET, SOCK_DGRAM)
host = gethostbyname(gethostname())
port = 10000
#bind the to the socket
server_addr = (host, port)
print('Starting up on ', server_addr)
s.bind(server_addr)

info = []
flag = 1
get = []
while True:
    mail, addr = s.recvfrom(4096)
    if mail:
        data = pickle.loads(mail)
        if 'Send' == data[0]:
            mailID = data[1]
            message = data[2]
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
            s.sendto(mail,addr)
        elif 'Receive' == data[0]:
            mailID = data[1]
            for each in info:
                if mailID == each[0]:
                    get = [mail for mail in each if mailID != mail]
                    del each[1::]
            if get:
                array = pickle.dumps(get)
                sent = s.sendto(array, addr)
                get = []
        else:
            print('No data receives from ', addr)
            break
