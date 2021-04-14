#/*   decrypt.py  */
from Crypto import Random
from Crypto.Cipher import AES

print("PES1201800410 Prashanth A R ")
file = open("keys.txt", "r")
ciphertext = "d06bf9d0dab8e8ef880660d2af65aa82"

for i in range(0,7200):
    str = file.readline()
    key = (str[:-1]).decode("hex")
    IV = "09080706050403020100A2B2C2D2E2F2".lower().decode("hex")
    plaintext1 = "255044462d312e350a25d0d4c5d80a34".decode("hex")
    cipher = AES.new(key, AES.MODE_CBC, IV)
    encrypted =  cipher.encrypt(plaintext1)
    #print("Encrypted: " + (encrypted).encode("hex"))
    if ciphertext == encrypted.encode("hex")[0:32]:
        print("")
        print("Match found")
        print("key: "+str[:-1])
        print("Ciphertext: " + ciphertext)
        print("Encrypted: " + (encrypted).encode("hex"))
        print("")


