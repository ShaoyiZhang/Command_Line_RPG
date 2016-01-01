CXX=g++
#CXX=clang++

#CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

CXXFLAGS = -std=c++11

#CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES= test01 test02

all: ${BINARIES}

test01: test01.o Item.o Bag.o tddFuncs.o
	${CXX} $^ -o $@

test02: test02.o Life.o Hero.o Item.o Bag.o Equipment.o Skill.o NPC.o Monster.o Dungeon.o World.o
	${CXX} $^ -o $@

tests:${BINARIES}
	./test01
	./test02

clean:
	/bin/rm -f ${BINARIES} *.o
