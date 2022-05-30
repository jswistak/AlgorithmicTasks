output  = server client
CFLAGS  = -std=gnu99 -fsanitize=address,undefined -g
LDFLAGS = -fsanitize=address,undefined
LDLIBS  = -lm -lrt
ERR = -Werror
all: $(output)
%: %.c	
	$(CC) $(CFLAGS) $(LDLIBS) $< -o $@ 
.PHONY: clean all
clean:
	rm $(output)