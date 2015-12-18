CXX=g++
#CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

#CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES= test00

all: ${BINARIES}

test00: test00.o Life.o Hero.o Item.o Bag.o NPC.o
	${CXX} $^ -o $@

tests:${BINARIES}
	./test00
