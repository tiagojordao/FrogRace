#include <iostream>
#include <ostream>
#include <random>
#include <unistd.h>

#include "sapo.h"
#include <string>

Sapo::Sapo(std::string id_):identificador(id_), distancia_percorrida(0), quantidade_pulos(0), rd(), gen(rd()), dis (1, 6) {
}

Sapo::~Sapo () {

}

// ==> Getters
std::string Sapo::getIdentificador () {
	return identificador;
}
int Sapo::getDistanciaPercorrida () {
	return distancia_percorrida;
}
int Sapo::getQuantidadePulos () {
	return quantidade_pulos;
}

// ==> Setters
void Sapo::setIdentificador (std::string newId) {
	identificador = newId;
}

void Sapo::setDistanciaPercorrida (int newDist) {
	distancia_percorrida = newDist;
}

void Sapo::setQuantidadePulos (int newQnt) {
	quantidade_pulos = newQnt;
}

// ==> Jump Function (Return 1 if the frog cross the endline, else 0)
int Sapo::pular () {
	tamanho_pulo = std::round(dis(gen));

	distancia_percorrida += tamanho_pulo;
	quantidade_pulos++;

	if (distancia_percorrida >= distancia_corrida){
		return 1;
	}
	return 0;	
}