a.out: main.o Statystyka.o Pliki.o TabHash.o TabAsoc.o
	g++ -Wall -pedantic main.o Statystyka.o Pliki.o TabHash.o TabAsoc.o

main.o: src/main.cpp inc/Lista.hh inc/Statystyka.hh inc/InterfejsADT.hh inc/TabHash.hh inc/TabAsoc.hh
	g++ -c -Wall -pedantic src/main.cpp

Pliki.o: src/Pliki.cpp inc/Pliki.hh
	g++ -c -Wall -pedantic src/Pliki.cpp

Statystyka.o: src/Statystyka.cpp inc/Statystyka.hh
	g++ -c -Wall -pedantic src/Statystyka.cpp

TabHash.o: src/TabHash.cpp inc/TabHash.hh
	g++ -c -Wall -pedantic src/TabHash.cpp

TabAsoc.o: src/TabAsoc.cpp inc/TabAsoc.hh inc/TabHash.hh
	g++ -c -Wall -pedantic src/TabAsoc.cpp


clean:
	rm -f *.o *.dat
