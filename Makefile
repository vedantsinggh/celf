.SILENT:

run: main.cpp celf.cpp celf.h
	g++ -Wall -Wextra -o app main.cpp celf.cpp

refresh: main.cpp celf.cpp celf.h
	clear
	g++ -Wall -Wextra -o app main.cpp celf.cpp
	./app
	
view: sample.ppm
	feh --keep-zoom-vp  --force-aliasing sample.ppm	
	
