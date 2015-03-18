a.out: main.o Lista.o Pliki.o Statystyka.o
	g++ -Wall -pedantic main.o Lista.o Pliki.o Statystyka.o

main.o: src/main.cpp src/Lista.cpp inc/Statystyka.hh inc/InterfejsADT.hh
	g++ -c -Wall -pedantic src/main.cpp

Lista.o: src/Lista.cpp inc/Pliki.hh inc/Framework.hh inc/InterfejsADT.hh
	g++ -c -Wall -pedantic src/Lista.cpp

Pliki.o: src/Pliki.cpp inc/Pliki.hh 
	g++ -c -Wall -pedantic src/Pliki.cpp

Statystyka.o: src/Statystyka.cpp inc/Statystyka.hh
	g++ -c -Wall -pedantic src/Statystyka.cpp

clean:
	rm -f *.o
