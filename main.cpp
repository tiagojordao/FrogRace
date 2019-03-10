#include <iostream>

#include "sapo.h"

using namespace std;

int Sapo::distancia_corrida = 50;

int main(int argc, char const *argv[]) {

	int i = 0;

	Sapo sapo;

	while (true){
		int result = sapo.pular (i);
			if (result == 1){
				sapo.printRace();
				std::cout  << std::endl << "--- Resultado Final ------------------------------------------------------" << std::endl << std::endl;
				cout << "Sapo (" << sapo.getIdentificador(i) << ") ganhou e percorreu uma distância de " << sapo.getDistanciaPercorrida (i) << "m com um total de " << sapo.getQuantidadePulos(i) << " pulos!" << endl;
				std::cout  << std::endl << "--------------------------------------------------------------------------" << std::endl;
				return 0;
			}
		i++;
		if (i == 3){
			sapo.printRace();
			i = 0;
		}
	}



	

	return 0;
}