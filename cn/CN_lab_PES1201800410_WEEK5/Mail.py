from socket import *
import ssl
import base64

# Message to send
msg = '\r\nI love computer networks!'
endmsg = '\r\n.\r\n'

# Choose a mail server (e.g. Google mail server) and call it mailserver
mailserver = 'smtp.gmail.com'

# Create socket called clientSocket and establish a TCP connection with mailserver
clientSocket = socket(AF_INET, SOCK_STREAM)

# Port number may change according to the mail server
clientSocket.connect((mailserver, 587)) #465 for ssl 587 for tls
recv = clientSocket.recv(1024)
print recv
if recv[:3] != '220':
	print '220 reply not received from server.'

# Send HELO command and print server response.
heloCommand = 'HELO gmail.com\r\n'
clientSocket.send(heloCommand)
recv1 = clientSocket.recv(1024)
print recv1
if recv1[:3] != '250':
	print '250 reply not received from server.'
	



clientSocket.send('starttls\r\n')
recv1 = clientSocket.recv(1024)
print recv1


secureConnect = ssl.wrap_socket(clientSocket, ssl_version=ssl.PROTOCOL_SSLv23)
                
                
secureConnect.send(heloCommand)
recv1 = secureConnect.recv(1024)
print recv1 , "ssl connet\n" 

secureConnect.send('AUTH LOGIN\r\n')
recv1 = secureConnect.recv(1024)

print recv1 , "auth login\n"

user = 'prashuhack1@gmail.com'
pw = "Pes@2018"

target = 'prashanthathunt@gmail.com'
subject = 'CN lab smtp client'
body = 'CN lab smtp client testing'

#secureConnect.send(base64.b64encode(user)+'\r\n')
#secureConnect.send(base64.b64encode(pw)+'\r\n')

Username = user
Password= pw


#UP=("\000"+Username+"\000"+Password).encode("base64")

#scc.send('auth login\r\n')
print base64.b64encode(Username) + "  username"
print base64.b64encode(Password) + "  Password"
secureConnect.send(base64.b64encode(Username)+'\r\n')
secureConnect.send(base64.b64encode(Password)+'\r\n')

#print UP , "printing UP\n"

#UP=UP.strip("\n")

#login = 'AUTH PLAIN '+ UP + '\r\n'
#print login , "print Login \n"


#secureConnect.send(login)
recv_from_TLS = secureConnect.recv(1024)
print recv_from_TLS

print secureConnect.recv(1024) , "1st one \n" 
#print secureConnect.recv(1024) , "2nd one\n"


#exit(0)

def sendmail (sender, receiver, subj, msg):
    secureConnect.send('mail from: ' + sender + '\r\n')
    print secureConnect.recv(1024) , sender 
    secureConnect.send('rcpt to: ' + receiver + '\r\n')
    print secureConnect.recv(1024) , receiver 
    secureConnect.send('data\r\n') 
    print secureConnect.recv(1024) 
    secureConnect.send('To: ' + receiver + '\r\nSubject: ' + subj +
    ('\r\n' + msg + '.'))
    print secureConnect.recv(1024) , msg 

#sendmail(('<' + user + '>'), ('<' + target + '>'), subject, body)



	
# Send MAIL FROM command and print server response.
mailfrom = 'MAIL FROM: <prashuhack1@gmail.com>\r\n'
secureConnect.send(mailfrom)
recv2 = secureConnect.recv(1024)
print recv2
if recv2[:3] != '250':
	print '250 reply not received from server.'


# Send RCPT TO command and print server response. 
rcptto = 'RCPT TO: <bob@yahoo.com>\r\n'
secureConnect.send(rcptto)
recv3 = secureConnect.recv(1024)
print recv3
if recv3[:3] != '250':
	print '250 reply not received from server.'

# Send DATA command and print server response. 
data = 'DATA\r\n'
secureConnect.send(data)
recv4 = secureConnect.recv(1024)
print recv4
if recv4[:3] != '354':
	print '354 reply not received from server.'

# Send message data.
secureConnect.send('SUBJECT: Greeting To you!\r\n')
secureConnect.send('test again')
secureConnect.send(msg)

# Message ends with a single period.
secureConnect.send(endmsg)
recv5 = secureConnect.recv(1024)
print recv5
if recv5[:3] != '250':
	print '250 reply not received from server.'

# Send QUIT command and get server response.
quitcommand = 'QUIT\r\n'
secureConnect.send(quitcommand)
recv6 = secureConnect.recv(1024)
print recv6
if recv6[:3] != '221':
	print '221 reply not received from server.'
	
	
secureConnect.close()
clientSocket.close()

