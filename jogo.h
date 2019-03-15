#ifndef _JOGO_H_
#define	_JOGO_H_

#include <iostream>
#include <vector>

class Jogo {
	private:
		std::vector <Sapo*> sapos;
		int quantidade_sapos;
		int turno = 1;
		int sapo_atual = 0;
		void printVencedor (std::string id, int distancia, int pulos);
	public:
		Jogo();
		~Jogo();
		void addSapo (int quantidade_sapos);
		void run ();
		void printRace (int sapoatual_, int distancia);
};

#endif