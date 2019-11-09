import socket
def get_hostname():
    try:
        hostname = socket.gethostname()
        hostip = socket.gethostbyname(hostname)
        print("Hostname is ",hostname)
        print("IP is ",hostip)
    except:
        print("unable to get ")
get_hostname()