#include <iostream>
#include <random>

#include "sapo.h"

Sapo::Sapo():rd(), gen(rd()), dis (1, 6) {
	tamanho_pulo = std::round(dis(gen));
	for (auto i(0) ; i < 3 ; i++){
		sapos [i][0] = i+1;
		for (auto j(1) ; j < 3 ; j++) {
				sapos [i][j] = 0;
		}
	}
}

Sapo::~Sapo () {

}

int Sapo::roll () {
	return std::round(dis(gen));
}
int Sapo::getIdentificador (int identificador) {
	return sapos [identificador][0];
}
int Sapo::getDistanciaPercorrida (int identificador) {
	return sapos [identificador][1];
}

int Sapo::getQuantidadePulos (int identificador) {
	return sapos [identificador][2];
}

void Sapo::setDistanciaPercorrida (int identificador, int value_) {
	sapos [identificador][1] = value_;
}

void Sapo::setQuantidadePulos (int identificador, int value_) {
	sapos [identificador][2] = value_;
}

int Sapo::pular (int identificador) {
	tamanho_pulo = std::round(dis(gen));

	sapos [identificador][1] += tamanho_pulo;
	sapos [identificador][2] += 1;

	// TEST
	// std::cout << std::endl << "------------------------------------------------------------" << std::endl;
	// std::cout << ">>>>> Sapo: " << identificador+1 << std::endl;
	// std::cout << ">>>>> Dado: " << tamanho_pulo << std::endl;
	// std::cout << ">>>>> Distancia: " << sapos [identificador][1] << std::endl;
	// std::cout << ">>>>> Quantidade: " << sapos [identificador][2] << std::endl;
	// std::cout << std::endl << "------------------------------------------------------------" << std::endl;
	// ENDTEST

	if (sapos [identificador][1] >= distancia_corrida){
		return 1;
	}
	return 0;	
}