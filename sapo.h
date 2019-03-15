#ifndef _SAPO_H_
#define _SAPO_H_

#include <iostream>
#include <ostream>
#include <random>
#include <string>

class Sapo {
	private:
		std::string identificador;
		int distancia_percorrida;
		int quantidade_pulos;
		int tamanho_pulo;
		// Random ==>
		std::random_device rd;
		std::default_random_engine gen;
		std::uniform_int_distribution<> dis;
		// ===
	public:
		static int distancia_corrida;
		Sapo ();
		Sapo (std::string id_);
		~Sapo ();
		std::string getIdentificador ();
		int getDistanciaPercorrida ();
		int getQuantidadePulos ();
		void setIdentificador (std::string newId);
		void setDistanciaPercorrida (int newDist);
		void setQuantidadePulos (int newQnt);
		int pular ();
};


#endif