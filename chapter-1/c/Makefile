CFLAGS ?= -g -O0 -fsanitize=address -fno-omit-frame-pointer -fno-stack-protector

all: challenge_bin

challenge_bin: challenge.o
	$(CC) $(CFLAGS) -o challenge_bin challenge.o

clean:
	rm -f challenge.o challenge_bin