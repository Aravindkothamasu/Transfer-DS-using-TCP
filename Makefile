

all:
	gcc tcp_ser.c DS.c -o server
	gcc tcp_cli.c DS.c -o client
clean:
	rm -i server
	rm -i client
