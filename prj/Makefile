a.out: main.o Statystyka.o Pliki.o Stoper.o
	g++ -Wall -pedantic -std=c++11 main.o Statystyka.o Pliki.o Stoper.o

main.o: src/main.cpp inc/ListArr2x.hh inc/Statystyka.hh inc/InterfejsADT.hh
	g++ -c -Wall -pedantic -std=c++11 src/main.cpp

Pliki.o: src/Pliki.cpp inc/Pliki.hh
	g++ -c -Wall -pedantic -std=c++11 src/Pliki.cpp

Statystyka.o: src/Statystyka.cpp inc/Statystyka.hh
	g++ -c -Wall -pedantic -std=c++11 src/Statystyka.cpp

Stoper.o: src/Stoper.cpp inc/Stoper.hh
	g++ -c -Wall -pedantic -std=c++11 src/Stoper.cpp


clean:
	rm -f *.o
