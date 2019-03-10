#ifndef _SAPO_H_
#define _SAPO_H_

#include <iostream>
#include <ostream>
#include <random>

class Sapo {
	private:
		// ==> sapos [quantidade de sapos = 3][1: Identificador do sapo, 2: Distancia percorrida, 3: Quantidade de Pulos]
		int sapos [3][3];
		int tamanho_pulo;
		int turno = 1;
		std::random_device rd;
		std::default_random_engine gen;
		std::uniform_int_distribution<> dis;
	public:
		static int distancia_corrida;
		friend std::ostream& operator<< (std::ostream &o, Sapo const t);
		Sapo ();
		~Sapo ();
		int getIdentificador (int identificador);
		int getDistanciaPercorrida (int identificador);
		int getQuantidadePulos (int identificador);
		void setDistanciaPercorrida (int identificador, int value_);
		void setQuantidadePulos (int identificador, int value_);
		void printRace ();
		int pular (int identificador);
};


#endif