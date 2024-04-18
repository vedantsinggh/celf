.SILENT:

run: main.cpp celf.cpp celf.h
	g++ -Wall -Wextra -o app main.cpp celf.cpp
