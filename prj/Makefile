a.out: main.o Pliki.o Statystyka.o
	g++ -Wall -pedantic main.o Pliki.o Statystyka.o

main.o: src/main.cpp inc/Lista.hh inc/Stos.hh inc/Kolejka.hh inc/Statystyka.hh inc/InterfejsADT.hh
	g++ -c -Wall -pedantic src/main.cpp

Pliki.o: src/Pliki.cpp inc/Pliki.hh 
	g++ -c -Wall -pedantic src/Pliki.cpp

Statystyka.o: src/Statystyka.cpp inc/Statystyka.hh
	g++ -c -Wall -pedantic src/Statystyka.cpp

clean:
	rm -f *.o
