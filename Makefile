CXX = g++
CXXFLAGS = -std=c++11 -Wall -pedantic

all:  main

main: data.o uni.o filesys.o pinfo.o scanner.o ProviderTerminal.o ManagerTerminal.o main.o
	${CXX} -o chocan data.o uni.o filesys.o pinfo.o scanner.o ProviderTerminal.o ManagerTerminal.o main.o

data.o: data.cpp data.h
	${CXX} ${CXXFLAGS} -c data.cpp

uni.o: uni.cpp uni.h
	${CXX} ${CXXFLAGS} -c uni.cpp

filesys.o: filesys.cpp filesysclass.h
	${CXX} ${CXXFLAGS} -c filesys.cpp

pinfo.o: pinfo.cpp pdrp.h 
	${CXX} ${CXXFLAGS} -c pinfo.cpp

scanner.o: scanner.cpp scanner.h
	${CXX} ${CXXFLAGS} -c scanner.cpp

ProviderTerminal.o: ProviderTerminal.cpp ProviderTerminal.h
	${CXX} ${CXXFLAGS} -c ProviderTerminal.cpp

ManagerTerminal.o: ManagerTerminal.cpp ManagerTerminal.h
	${CXX} ${CXXFLAGS} -c ManagerTerminal.cpp

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

clean:
	rm *.o chocan*
