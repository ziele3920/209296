a.out: main.o Statystyka.o Pliki.o Stoper.o
	g++ -Wall -pedantic main.o Statystyka.o Pliki.o Stoper.o

main.o: src/main.cpp inc/Statystyka.hh 
	g++ -c -Wall -pedantic src/main.cpp

Pliki.o: src/Pliki.cpp inc/Pliki.hh
	g++ -c -Wall -pedantic src/Pliki.cpp

Statystyka.o: src/Statystyka.cpp inc/Statystyka.hh
	g++ -c -Wall -pedantic src/Statystyka.cpp

Stoper.o: src/Stoper.cpp inc/Stoper.hh
	g++ -c -Wall -pedantic src/Stoper.cpp

clean:
	rm -f *.o 
