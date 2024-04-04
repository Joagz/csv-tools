CC      = gcc
CFLAGS  = -Wall -D_FORTIFY_SOURCE=2 -Werror=implicit-function-declaration
BINS    = csv-tools.o
MAIN    = csv-tools
ROOT    = ./
# ============= GENERIC ACTIONS (BETTER KEEP) =============
all: $(MAIN)
$(MAIN): $(BINS)
	$(CC) $(CFLAGS) -o $(MAIN) $(BINS)
%.o: $(ROOT)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<
clean: 
	rm -f $(BINS) $(MAIN)
