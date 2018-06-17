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
	@./test/tests.sh

.PHONY: bin/tp2