#include <iostream>
#include <ostream>
#include <random>
#include <unistd.h>

#include "sapo.h"

Sapo::Sapo():rd(), gen(rd()), dis (1, 6) {
	for (auto i(0) ; i < 3 ; i++){
		sapos [i][0] = i+1;
		for (auto j(1) ; j < 3 ; j++) {
				sapos [i][j] = 0;
		}
	}
}

Sapo::~Sapo () {

}

int Sapo::getIdentificador (int identificador) {
	return sapos [identificador][0];
}
int Sapo::getDistanciaPercorrida (int identificador) {
	return sapos [identificador][1];
}

void Sapo::setDistanciaPercorrida (int identificador, int value_) {
	sapos [identificador][1] = value_;
}

int Sapo::getQuantidadePulos (int identificador) {
	return sapos [identificador][2];
}

void Sapo::setQuantidadePulos (int identificador, int value_) {
	sapos [identificador][2] = value_;
}

int Sapo::pular (int identificador) {
	tamanho_pulo = std::round(dis(gen));

	sapos [identificador][1] += tamanho_pulo;
	sapos [identificador][2] += 1;

	if (sapos [identificador][1] >= distancia_corrida){
		return 1;
	}
	return 0;	
}

void Sapo::printRace () {
	std::cout  << std::endl << "--- Turno (" << turno << ") ---" << std::endl << std::endl;
	turno++;
	for (auto i(0) ; i < 3 ; i++){
		std::cout << "Sapo (" << sapos [i][0] << "): ";
		for (auto j(0) ; j < sapos[i][1] ; j++){
			std::cout << "> ";
			usleep (10000);
		}
		(sapos [i][1] == 1) ? (std::cout << " : " << sapos[i][1] << " pulo" << std::endl) : (std::cout << " : " << sapos[i][1] << " pulos" << std::endl); 
	}
}

std::ostream& operator<< (std::ostream &o, Sapo const t){
	// >>> STUB == error: call to implicitly-deleted copy constructor of 'CLASS'

	return o;
}