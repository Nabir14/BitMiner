all: compile run
compile:
	g++ bitminer.cpp -o bitminer
run:
	./bitminer
clean:
	rm -rf bitminer
