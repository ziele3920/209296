a.out: main.o Statystyka.o
	g++ -Wall -pedantic main.o Statystyka.o

main.o: src/main.cpp src/Lista.cpp src/Kolejka.cpp src/Stos.cpp inc/Statystyka.hh inc/InterfejsADT.hh src/ListaArr2x.cpp
	g++ -c -Wall -pedantic src/main.cpp

Statystyka.o: src/Statystyka.cpp inc/Statystyka.hh
	g++ -c -Wall -pedantic src/Statystyka.cpp

clean:
	rm -f *.o
