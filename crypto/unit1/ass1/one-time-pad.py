from Crypto.Util.number import *

msg1 = "attack at dawn"
msg2 = 'attack at dusk'

cipher1 = 0x6c73d5240a948c86981bc294814d


def ascii_to_int(msg):
    msg_int = []
    for i in msg:
        msg_int.append(ord(i))
    return msg_int
    
    
msg1_int = ascii_to_int(msg1)
    
temp = str(hex(cipher1))[2:]
#print(temp)
list_cipher = [int(eval('0x'+(temp[i:i+2]))) for i in range(0 , len(temp) , 2)]
#print(list_cipher , len(list_cipher))
    
def xor(a , b):
    #a and b are list
    temp = []
    for i in range(len(a)):
        temp.append(a[i]^b[i])
    return temp

key = xor(list_cipher , msg1_int)

## found the key now find the 2nd message    

msg2_int = ascii_to_int(msg2)
cipher2_int = xor(msg2_int , key)
for i in cipher2_int:
    print(str(format(i, '02x')), end="")
    
print(" --attack at dawn")#6c73d5240a948c86981bc2808548 --attack at dawn
print(temp, "--attack at dusk")#6c73d5240a948c86981bc294814d --attack at dusk



