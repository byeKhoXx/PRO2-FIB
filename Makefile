OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o Tret.o Individu.o Cjt_trets.o Cjt_individus.o
	g++ -o program.exe *.o 

Tret.o: Tret.cc Tret.hh
	g++ -c Tret.cc $(OPCIONS) 

Individu.o: Individu.cc Individu.hh
	g++ -c Individu.cc $(OPCIONS) 

Cjt_trets.o: Cjt_trets.cc Cjt_trets.hh
	g++ -c Cjt_trets.cc $(OPCIONS) 

Cjt_individus.o: Cjt_individus.cc Cjt_individus.hh
	g++ -c Cjt_individus.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS) 

clean:
	rm *.o
	rm *.exe
