CFLAGS= -g -O0 -fno-stack-protector -fsanitize=address

all: challenge_bin

challenge_bin: challenge.o
	cc $(CFLAGS) -o challenge_bin challenge.o

clean:
	rm -f libstringlist.o challenge.o challenge_bin
