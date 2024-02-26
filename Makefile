OBJDIR			:= objects
OBJECTS 		:= $(addprefix $(OBJDIR)/, main.o cc_algorithm.o misc.o)

INCLUDE			:= include/highCC.h

CC				:= gcc
CFLAGS 			:= -g -c

AR 				:= ar
ARFLAGS 		:= -r -c

ALL_CFLAGS 		:= -Wall -Wextra -pedantic-errors -fPIC -O2

LDFLAGS			:= -lsll

BIN				:= hcc

# ================================================================ #

ALGORITHM		:= $(addprefix source/, cc_algorithm.c)

MISC			:= $(addprefix source/, misc.c)

# ================================ #

all: $(BIN)

$(BIN): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJDIR)/main.o: main.c $(INCLUDE)
	$(CC) $(ALL_CFLAGS) $(CFLAGS) -o $@ $<

$(OBJDIR)/cc_algorithm.o: $(ALGORITHM) $(INCLUDE)
	$(CC) $(ALL_CFLAGS) $(CFLAGS) -o $@ $<

$(OBJDIR)/misc.o: $(MISC) $(INCLUDE)
	$(CC) $(ALL_CFLAGS) $(CFLAGS) -o $@ $<

# ================================================================ #

$(shell mkdir -p $(OBJDIR))

.PHONY: clean

clean:
	rm -rf $(BIN) $(OBJDIR)
