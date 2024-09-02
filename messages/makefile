message_hidder.o: message_hidder.c encrypt.h
	gcc -c message_hidder.c

encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c

message_hidder: message_hidder.o encrypt.o
	gcc message_hidder.o encrypt.o -o message_hidder