# The @ symbol is used to hide what command is beign ran.
# CFLAGS = -somekindofflag -anotherkind -smaller -ok
# the above variable can be access below by using it like this $(CFLAGS)

message_hidder.o: message_hidder.c encrypt.h
	@echo "Compiling the main file"
	gcc -c message_hidder.c

encrypt.o: encrypt.c encrypt.h
	@echo "Compiling the encrypt file"
	gcc -c encrypt.c

message_hidder: message_hidder.o encrypt.o
	@echo "Linking files and outputing message_hidder executable"
	gcc message_hidder.o encrypt.o -o message_hidder

all: message_hidder

clean:
	@echo "Removing everything except the source files"
	rm encrypt.o message_hidder.o message_hidder