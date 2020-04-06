GCC = g++
CFLAGS = -I include/
LDFLAGS = 

PROGRAM = test

ODIR = obj
BIN = bin
IDIR = src
SDIR = as

OUT = $(BIN)/$(PROGRAM)

debug: CFLAGS += -g
debug: all

release: CFLAGS += -O2
release: all

#Here we add the binaries that need to be compiled against our modules
all:  $(IDIR) $(ODIR) $(BIN) 				\
								bin/bintree \
								bin/matrix_generator\
								bin/adjacency_parser\
								bin/normalized_test\
								bin/debug1\
								bin/debug2

run: all
	./$(OUT)

C_SOURCES = $(shell find $(IDIR) -type f -name *.cpp -printf "%f\n")

OBJECTS = $(patsubst %.cpp, $(ODIR)/%.o,$(C_SOURCES))
S_CODE = $(patsubst %.cpp, $(SDIR)/%.s,$(C_SOURCES))

#Lib folder is for standalone programs/utilities that dont need to be compiled against the project
bin/%: lib/%.cpp
	$(GCC) $(CFLAGS) $(LDFLAGS) $^ -o $@

#Debug is for debugging/testing programs
bin/%: $(OBJECTS) debug/%.cpp
	$(GCC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(ODIR)/%.o : $(IDIR)/%.cpp
	$(GCC) $(CFLAGS) -c $^ -o $@

$(SDIR)/%.s : $(IDIR)/%.cpp
	$(GCC) -g -o $@ $(CFLAGS) -S $^

$(ODIR)/%.o : $(IDIR)/**/%.cpp
	$(GCC) $(CFLAGS) -c $^ -o $@

$(SDIR)/%.s : $(IDIR)/**/%.cpp
	$(GCC) -g -o $@ $(CFLAGS) -S $^


$(OUT): $(OBJECTS)
	$(GCC) $(LDFLAGS) -o $(BIN)/$(PROGRAM) $(OBJECTS)

clean: $(ODIR) $(BIN)
	rm -rf $(ODIR)
	rm -rf $(BIN)
	rm -rf $(SDIR)

clean-dis: $(SDIR)
	rm -rf $(SDIR)

$(ODIR):
	mkdir $(ODIR)
$(BIN):
	mkdir $(BIN)
$(IDIR):
	mkdir $(IDIR)
$(SDIR):
	mkdir $(SDIR)
dis: all $(SDIR) $(S_CODE)
