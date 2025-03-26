all: compile
compile: 
	g++ main.cpp Customer.cpp Room.cpp -o app
clean:
	rm -f make *.o