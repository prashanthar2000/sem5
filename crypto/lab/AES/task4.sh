echo -n "12345">f1.txt
echo -n " 1234567890">f2.txt
echo -n "1234567890abcde">f3.txt
ls -l f*.txt
openssl enc -aes-128-cbc -e -in f1.txt -out f1.bin -k 001122334455667788899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f
openssl enc -aes-128-cbc -e -in f2.txt -out f2.bin -k 001122334455667788899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f
openssl enc -aes-128-cbc -e -in f3.txt -out f3.bin -k 001122334455667788899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f
openssl enc -aes-128-cbc -d -in f1.bin -out p1.txt -nopad -k 001122334455667788899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f
openssl enc -aes-128-cbc -d -in f2.bin -out p2.txt -nopad -k 001122334455667788899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f
openssl enc -aes-128-cbc -d -in f3.bin -out p3.txt -nopad -k 001122334455667788899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f
ls -l f*bin 
sleep 10 
xxd p1.txt
xxd p2.txt
xxd p3.txt 
