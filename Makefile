all:
	g++ -Wall -std=c++11 Graph.cpp GraphTests.cpp -o graph-tests
	g++ -Wall -std=c++11 Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests
	g++ -Wall -std=c++11 Graph.cpp BetterPriorityQueue.cpp Dijkstra.cpp DijkstraTests.cpp -o dijkstra
try:
	./graph-tests
	./bpq-tests
	./dijkstra

run: all try