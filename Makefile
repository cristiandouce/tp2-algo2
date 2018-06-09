SRCS = $(shell find src vendor -name "*.cpp" | xargs)
ENTRY = main.cpp
OUT = bin
CXXARGS = -g -Wall
CXXFLAGS = -Isrc -Ivendor -I. -isystem $(CXXARGS)
LDFLAGS  =
CXX = g++


build-dev: ./bin/tp2


./bin/tp2:
	$(CXX) $(CXXFLAGS) $(ENTRY) $(SRCS) -o $(OUT)