DIRS    := src src/SMA
SOURCES := $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))
OBJS    := $(patsubst %.cpp, %.o, $(SOURCES))
OBJS    := $(foreach o,$(OBJS),./obj/$(o))
DEPFILES:= $(patsubst %.o, %.P, $(OBJS))

CFLAGS   = -Wall -g -MMD -I/home/stuart/lib/jsoncpp/include -I/home/stuart/git/redispp/src -c 
LDFLAGS=-lPocoNet -lPocoFoundation -lPocoNetSSL ./lib/libredispp.a ./lib/libjsoncpp.a
COMPILER = g++
 
all : APITest

#link the executable
APITest: $(OBJS)
	$(COMPILER) $(OBJS) $(LDFLAGS) -o APITest
 
#generate dependency information and compile
obj/%.o : %.cpp
	@mkdir -p $(@D)
	$(COMPILER) $(CFLAGS) -o $@ -MF obj/$*.P $<
 
#remove all generated files
clean:
	rm -f APITest 
	rm -rf obj
 
#include the dependency information
-include $(DEPFILES)
