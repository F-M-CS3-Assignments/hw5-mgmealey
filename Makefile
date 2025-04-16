all:
	g++ -Wall -std=c++11 Graph.cpp GraphTests.cpp -o graph-tests
	g++ -Wall -std=c++11 Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests

try:
	./graph-tests
	./bpq-tests

run: all try