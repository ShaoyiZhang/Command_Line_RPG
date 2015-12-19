CXX=g++
#CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

#CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES= SaveAndLoad

all: ${BINARIES}

SaveAndLoad: SaveAndLoad.o Life.o Hero.o Item.o Bag.o Equipment.o Skill.o NPC.o
	${CXX} $^ -o $@

tests:${BINARIES}
	./SaveAndLoad

clean:
	/bin/rm -f ${BINARIES} *.o
