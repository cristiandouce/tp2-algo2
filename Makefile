PROJ = tp2
SRCS = $(shell find src vendor -name "*.cpp" | xargs)
ENTRY = main.cpp
OUTDIR = bin
OUTFILE = $(OUTDIR)/$(PROJ)
CXXARGS = -Wall -g
CXXFLAGS = -Isrc -Ivendor -I. -isystem $(CXXARGS)
LDFLAGS  =
CXX = g++

build-dev: bin/tp2

bin/tp2:
	$(CXX) $(CXXFLAGS) $(ENTRY) $(SRCS) -o $(OUTFILE)

test-perf:
	time $(OUTFILE) -i ./test/files/ones.input.txt -o ./test/files/ones.output.txt

.PHONY: bin/tp2