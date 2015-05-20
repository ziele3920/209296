a.out: main.o Statystyka.o Pliki.o Stoper.o
	g++ -Wall -pedantic main.o Statystyka.o Pliki.o Stoper.o

main.o: src/main.cpp inc/Statystyka.hh  inc/DrzewoBinarne.hh inc/ITestable.hh inc/DrzewoBinarneTest.hh inc/DrzewoAVL.hh inc/DrzewoAVLTest.hh inc/Wezel.hh inc/WezelAVL.hh
	g++ -c -Wall -pedantic src/main.cpp

Pliki.o: src/Pliki.cpp inc/Pliki.hh
	g++ -c -Wall -pedantic src/Pliki.cpp

Statystyka.o: src/Statystyka.cpp inc/Statystyka.hh inc/IObserwator.hh inc/IObserwowany.hh
	g++ -c -Wall -pedantic src/Statystyka.cpp

Stoper.o: src/Stoper.cpp inc/Stoper.hh
	g++ -c -Wall -pedantic src/Stoper.cpp

clean:
	rm -f *.o 
