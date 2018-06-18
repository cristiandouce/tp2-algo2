PROJ = tp2
SRCS = $(shell find src vendor -name "*.cpp" | xargs)
ENTRY = main.cpp
OUTDIR = bin
OUTFILE = $(OUTDIR)/$(PROJ)
CXXARGS = -Wall -g
CXXFLAGS = -Isrc -Ivendor -I. -isystem $(CXXARGS)
LDFLAGS  =
CXX = g++

build: bin/tp2

bin/tp2:
	$(CXX) $(CXXFLAGS) $(ENTRY) $(SRCS) -o $(OUTFILE)

test: build
	./test/tests.sh

test-valgrind: bin/tp2
	# memcheck is default --tool
	valgrind --leak-check=yes $(OUTFILE) -i ./test/files/test_1_signals_10000_points.txt -o ./test/files/_garbage.txt
	valgrind --leak-check=yes $(OUTFILE) -i ./test/files/test_10_signals_1000_points.txt -o ./test/files/_garbage.txt
	valgrind --leak-check=yes $(OUTFILE) -i ./test/files/test_100_signals_100_points.txt -o ./test/files/_garbage.txt

.PHONY: bin/tp2