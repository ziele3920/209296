a.out: main.o Tablica.o Pliki.o Statystyka.o
	g++ -Wall -pedantic main.o Tablica.o Pliki.o Statystyka.o

main.o: src/main.cpp inc/Tablica.hh inc/Statystyka.hh
	g++ -c -Wall -pedantic src/main.cpp

Tablica.o: src/Tablica.cpp inc/Tablica.hh inc/Pliki.hh inc/Framework.hh
	g++ -c -Wall -pedantic src/Tablica.cpp

Pliki.o: src/Pliki.cpp inc/Pliki.hh 
	g++ -c -Wall -pedantic src/Pliki.cpp

Statystyka.o: src/Statystyka.cpp inc/Statystyka.hh
	g++ -c -Wall -pedantic src/Statystyka.cpp

clean:
	rm -f *.o
