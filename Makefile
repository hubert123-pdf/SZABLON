CPPFLAGS= -c -g -Iinc -Wall -pedantic

uklad_rownan:  obj/UkladRownanLiniowych.o obj/Macierz.o obj/Wektor.o obj/LZespolona.o obj/main.o
	g++ -Wall -pedantic -o uklad_rownan obj/Wektor.o obj/Macierz.o obj/UkladRownanLiniowych.o obj/LZespolona.o obj/main.o

obj/main.o: src/main.cpp inc/UkladRownanLiniowych.hh inc/Macierz.hh inc/Wektor.hh  inc/rozmiar.h inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/UkladRownanLiniowych.o: src/UkladRownanLiniowych.cpp inc/UkladRownanLiniowych.hh inc/Macierz.hh
	g++ ${CPPFLAGS} -o obj/UkladRownanLiniowych.o src/UkladRownanLiniowych.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh inc/Wektor.hh 
	g++ ${CPPFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh inc/rozmiar.h
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o -Wall -pedantic src/LZespolona.cpp



clean:
	rm -f obj/*.o uklad_rownan
	