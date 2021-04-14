target : Server.o Client.o 
	gcc Server.o Client.o -o target

Client.o : Client.c 
	gcc -c -Wall Client.c 

Server.o : Server.c 
	gcc -c -Wall Server.c 


clean : 	
	rm  *.o 