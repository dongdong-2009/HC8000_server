server : main.o net_init.o login.o pthread_spi.o pthread_read.o config.o
	arm-linux-gcc main.o net_init.o login.o pthread_spi.o pthread_read.o config.o -pthread -lm  -o server

main.o : main.c
	arm-linux-gcc main.c -c -o main.o

login.o : login.c
	arm-linux-gcc login.c -c -o login.o
	
net_init.o : net_init.c
	arm-linux-gcc net_init.c -c -o net_init.o

config.o : config.c
	arm-linux-gcc config.c -c -o config.o
	
pthread_read.o : pthread_read.c
	arm-linux-gcc pthread_read.c -c -o pthread_read.o
	
pthread_spi.o : pthread_spi.c
	arm-linux-gcc pthread_spi.c -c -o pthread_spi.o

clean :
	@rm -rf ./*.o
