CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = checkers
OBJECTS = player.o board.o main.o xx.o oo.o piece.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
		${CXX} ${CXXFLAGS} ${OBJECTS} -lX11 -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
		rm ${OBJECTS} ${EXEC} ${DEPENDS}