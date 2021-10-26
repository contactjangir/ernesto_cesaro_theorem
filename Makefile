
.PHONY = all clean

all:
	gcc test_knut98.c -o pie
clean:
	rm pie
