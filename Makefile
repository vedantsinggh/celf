.SILENT:

run: main.cpp celf.cpp celf.h
	g++ -Wall -Wextra -o app main.cpp celf.cpp

refresh: main.cpp celf.cpp celf.h
	clear
	g++ -Wall -Wextra -o app main.cpp celf.cpp
	./app
	
	
