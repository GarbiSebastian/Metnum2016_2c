export LC_ALL=C
CXXFLAGS= -Wall -pedantic -g -ggdb
LDFLAGS= -lpthread

OBJS=AlgoritmoLU.o AlgoritmoEG.o
MAIN=tp1

.PHONY: all clean new
all: $(MAIN)

$(MAIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp %.h 
	$(CXX) $@.o

clean:
	rm -f $(OBJS) $(MAIN)

new: clean all
