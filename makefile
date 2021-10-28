prog: main.o hangman.o tictacto.o
	g++ -std=c++11 -g -Wall main.o hangman.o tictacto.o -o prog

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

tictacto.o: tictacto.h tictacto.cpp
	g++ -std=c++11 -g -Wall -c tictacto.cpp tictacto.h

hangman.o: hangman.h hangman.cpp
	g++ -std=c++11 -g -Wall -c hangman.cpp hangman.h

clean:
	rm -fr *.o prog.* hangman.h.gch tictacto.h.gch
