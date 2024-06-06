ALL = challenge_bin
all: $(ALL)

ARTIFACTS = *.o

clean:
	rm -rf $(ARTIFACTS)

challenge_bin: challenge.o
	$(CC) $(CFLAGS) -o challenge_bin challenge.o
ARTIFACTS += challenge_bin

asan: all
asan: CFLAGS += -g -fsanitize=address -fno-omit-frame-pointer -fno-stack-protector -O0