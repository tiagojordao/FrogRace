/*
* @Authors: Tiago Jordão Pereira Cabral de Morais
*	   	    Louis Arthur Machado Bezerra
* @Teacher: Silvio Costa Sampaio
* @University: UFRN
* @Class: LP1
* @Project: FrogRace
*/

#include <iostream>

#include "sapo.h"
#include "jogo.h"

int Sapo::distancia_corrida = 50;

int main( void ) {

	Jogo jogo;

	int qnt_sapos;

	std::cout << "\n------------------------------------------\n";
	std::cout << "Adicione o Número de Sapos: \n>>> ";
	std::cin >> qnt_sapos;
	jogo.addSapo (qnt_sapos);

	return 0;
}