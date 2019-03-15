#include <iostream>
#include <string>
#include <unistd.h>

#include "sapo.h"
#include "jogo.h"

Jogo::Jogo (){

}

Jogo::~Jogo(){

}

void Jogo::addSapo (int newQuantidade_sapos){
	quantidade_sapos = newQuantidade_sapos;
	std::string id;
	for (auto i(0) ; i < quantidade_sapos ; i++){
		std::cout << "Nome do Sapo (" << i+1 << ") >>> ";
		std::cin >> id;
		sapos.push_back(new Sapo (id));
	}
	run ();
}

void Jogo::run (){

	while (true){
		(*sapos[sapo_atual]).pular();
		if (sapo_atual == 0)
			std::cout << "\n--- Rodada " << turno << " ---\n\n";
		printRace (sapo_atual,sapos[sapo_atual]->getDistanciaPercorrida());
			if ((*sapos[sapo_atual]).getDistanciaPercorrida() >= Sapo::distancia_corrida){
				for (int i = sapo_atual+1; i < quantidade_sapos ; i++){
					printRace (i, sapos[i]->getDistanciaPercorrida());
				}
				printVencedor ((*sapos[sapo_atual]).getIdentificador(),(*sapos[sapo_atual]).getDistanciaPercorrida(),(*sapos[sapo_atual]).getQuantidadePulos());
				break;
			}
			sapo_atual++;
			if (sapo_atual == quantidade_sapos){
				std::cout << "\n-------------------------\n\n";
				sapo_atual = 0;
				turno++;
			}
	}
}

void Jogo::printRace (int sapoatual_,int distancia) {
	std::cout << "Sapo " << sapos[sapoatual_]->getIdentificador() << " : ";
	for (auto i(0) ; i < distancia ; i++){
		std::cout << "> ";
	}
	std::cout << " (" << distancia << ")" << std::endl;
	usleep (75000);
}

void Jogo::printVencedor (std::string id, int distancia, int pulos) {
	std::cout << "\n-------------------------\n\n";
	std::cout << "\nO Sapo \"" << id << "\" Venceu a corrida e percorreu " << distancia << " metros com " << pulos << " pulos!\n" << std::endl;
	std::cout << "\n-------------------------\n\n";
}