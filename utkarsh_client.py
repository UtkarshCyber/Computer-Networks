from socket import *

serverName = "DESKTOP-OQ77SAC"
serverPort = 12004
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
sentence = input("Enter file name: ")

clientSocket.send(sentence.encode())
filecontents = clientSocket.recv(1024).decode()
print("From Server: ", filecontents)
clientSocket.close()
