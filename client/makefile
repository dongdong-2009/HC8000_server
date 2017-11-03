client : client.o login.o
	gcc client.o login.o -o client

client.o : client.c
	gcc client.c -c -o client.o
	
login.o : login.c
	gcc login.c -c -o login.o

clean :
	@rm -rf ./*.o