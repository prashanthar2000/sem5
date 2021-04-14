#include "rsa.c"
#include "util.c"

int main () 
{
	/*
		Task 1 - Deriving a private key
											*/
	
	BIGNUM *p = BN_new();
	BIGNUM *q = BN_new();
	BIGNUM *e = BN_new();
	
	// Assign the first large prime
	BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
	
	// Assign the second large prime
	BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
	
	// Assign the Modulus
	BN_hex2bn(&e, "0D88C3");

	BIGNUM* priv_key1 = get_rsa_priv_key(p, q, e);
	// printBN("the private key for task1 is:", priv_key1);

	BIGNUM* enc = BN_new();
	BIGNUM* dec = BN_new();

	/*
		Task 2 - Encrypting a message
										*/
	// Assign the private key
	BIGNUM* priv_key = BN_new();
	BN_hex2bn(&priv_key, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

	// Assign the public key
	BIGNUM* pub_key = BN_new();
	BN_hex2bn(&pub_key, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	// printBN("the public key is: ", pub_key);

	// Assign the Modulus
	BIGNUM* mod = BN_new();
	BN_hex2bn(&mod, "010001");//e

	// We are going to encrypt the message 'A top secret!'.
	// In order to use RSA, first we need to convert this message into hex.
	// Then we can convert the hex into a BIGNUM for the computations.
	BIGNUM* message = BN_new();
	BN_hex2bn(&message, "4120746f702073656372657421");

	// printBN("the plaintext message for task2 is: ", message);
	enc = rsa_encrypt(message, mod, pub_key);
	// printBN("the encrypted message for task2 is: ", enc);
	dec = rsa_decrypt(enc, priv_key, pub_key);
	// printf("the decrypted message for task2 is: ");
	// printHX(BN_bn2hex(dec));
	// printf("\n");
	printf("PES1201800410 Prashanth A R\n");
	/*
		Task 3 - Decrypting a message
										*/
	// We are going to decrypt the following ciphertext
	// The ciphertext was given in hexadecimal format.
	// So we must convert to a BIGNUM for the computations.
	BIGNUM* task3_enc = BN_new();
	BN_hex2bn(&task3_enc, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");
	
	// We already have the public and private keys. 
	// We can decrypt using our rsa_decrypt function.
	dec = rsa_decrypt(task3_enc, priv_key, pub_key);
	// printBN("Decrypted Message = ", dec);
	// printHX(BN_bn2hex(dec));
	// printf("\n");
	// exit(0);

	/*
		Task 4 - Signing a message
									*/
	// In this task, we are to generate the signature for a message.
	// The message is "I owe you $2000". First we must convert this to hex.
	// python -c ’print("I owe you $2000".encode("hex"))’
	// Once we have the hex, we convert to a BIGNUM for the computations.
	BIGNUM* BN_task4 = BN_new();
	BN_hex2bn(&BN_task4, "49206f776520796f752024333030302e");
						 //"49206f776520796f752024333030302e"
						 //"49206f776520796f752024323030302e"
	
	// Since we already have the private key, all we need to do is encrypt.
	enc = rsa_encrypt(BN_task4, priv_key, pub_key);
	// printBN("the signature for task4 is: ", enc);
	
	// To verify the operations were conducted correctly, we decrypt as well.
	dec = rsa_decrypt(enc, mod, pub_key);
	//printBN("encrypted Message = " , enc);
	// printHX(BN_bn2hex(dec));
	// printf("\n");
	// exit(0);
	/*
		Task 5 - Verifying a signature
										*/
	// In this task, we are going to verify a signature.
	// So we will use our public key to decrypt a message 
	// that has been encrypted with the private key,
	// And then compare the message with our decrypted result.
	BIGNUM* BN_task5 = BN_new();
	BIGNUM* S = BN_new();
	BN_hex2bn(&BN_task5, "4c61756e63682061206d6973736c652e");
	BN_hex2bn(&pub_key, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115"); //n
	BN_hex2bn(&S, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");//s
	
	// Here we decrypt the message with the public key.

	dec = rsa_decrypt(S, mod, pub_key);
	// BN_mod_exp(des, S, mod , pub_key)
	// printBN("encrypted message = ", dec);
	// return 0 ;

	
	// printHX(BN_bn2hex(dec));
	// printf("\n");
	
	// Now we corrupt the signature, and try to verify again.
	BN_hex2bn(&S, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F");
	
	// Here we decrypt a corrupted message with the public key.
	dec = rsa_decrypt(S, mod, pub_key);
	// printf("the message for task5 is: ");
	
	// We should see a corrupted output here.
	// printHX(BN_bn2hex(dec));
	// printf("\n");

	/*
		Task 7 - Manually Verifying an X.509 Certificate
															*/
	// We extracted the public key and modulus from the certificate at example.com
	// The command was: openssl x509 -in c1.pem -text -noout
	
	// Assign the public key
	BIGNUM* task7_pub_key = BN_new();
	BN_hex2bn(&task7_pub_key, "DCAE58904DC1C4301590355B6E3C8215F52C5CBDE3DBFF7143FA642580D4EE18A24DF066D00A736E1198361764AF379DFDFA4184AFC7AF8CFE1A734DCF339790A2968753832BB9A675482D1D56377BDA31321AD7ACAB06F4AA5D4BB74746DD2A93C3902E798080EF13046A143BB59B92BEC207654EFCDAFCFF7AAEDC5C7E55310CE83907A4D7BE2FD30B6AD2B1DF5FFE5774533B3580DDAE8E4498B39F0ED3DAE0D7F46B29AB44A74B58846D924B81C3DA738B129748900445751ADD37319792E8CD540D3BE4C13F395E2EB8F35C7E108E8641008D456647B0A165CEA0AA29094EF397EBE82EAB0F72A7300EFAC7F4FD1477C3A45B2857C2B3F982FDB745589B");
	// printBN("the public key is: ", task7_pub_key);

	// Assign the modulus
	BIGNUM* task7_mod = BN_new();
	BN_hex2bn(&task7_mod, "010001");
	
	// We extracted the signature (RSA-signed sha256) from the certificate:
	// openssl x509 -in c0.pem -text -noout

	// Assign the signature to a pointer to a BIGNUM
	BIGNUM* BN_task7 = BN_new();
	BN_hex2bn(&BN_task7, "737085ef4041a76a43d5789c7b5548e6bc6b9986bafb0d038b78fe11f029a00ccd69140bc60478b2cef087d5019dc4597a71fef06e9ec1a0b0912d1fea3d55c533050ccdc13518b06a68664cbf5621da5bd948b98c3521915ddc75d77a462c2227a66fd33a17ebbebd13c5122673c05da335896afb27d4ddaa74742e37e5013ba6d030b083d0a1c4752185b2e5fa670030a2bc53834dbfd6a883bbbcd6ed1cb31ef1580382008e9cef90f21a5fa2a306da5dbe9fda5da6e62fde588018d3f1627ba6a39faea86972638165ae8283a3b5978a9b2051ff1a3f61401e48d06b38f9e1fa17d8774a88e63d36244fef0ab99f70f38327f8cf2a057510a18a0a8088cd");

	// We generated the hash of the certificate body like so:
	// First, extract the body of the certificate
	// openssl asn1parse -i -in c0.pem -strparse 4 -out c0_body.bin -noout
	// Then, compute the hash:
	// sha256sum c0_body.bin
	// This hash will be used for comparison for when we decrypt the signature.
	
	// Now we decrypt the signature using the public key and modulus given from the certificate.
	// If the signature is valid, it should match our hash of the certificate body we computed earlier.
	BIGNUM* task7_dec = rsa_decrypt(BN_task7, task7_mod, task7_pub_key);
	
	// Print the decrypted hash. This is a non-masked value.
	// Follow up - we want to bitmask & this value with 256
	// In other words, the first 32 bytes of this value should 
	// match the hash generated from the body of the certificate.
	printBN("signed message = ", task7_dec);
	// printf("\n");

	// printf("the pre-computed hash was: ");
	// printf("902677e610fedcdd34780e359692eb7bd199af35115105636aeb623f9e4dd053");
	// printf("\n");

}
