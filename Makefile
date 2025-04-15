all:
	g++ -Wall -std=c++11 Graph.cpp GraphTests.cpp -o graph-tests

try:
	./graph-tests

run: all try