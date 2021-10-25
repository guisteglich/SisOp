#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main(){
	int contador = 0;
	std::string identidade;
	
	pid_t pID = fork();

	if (pID == 0){
		identidade = "Processo filho. ";
		contador++;
	}else if (pID < 0){
		std::cerr << "Falha ao criar. ";
		exit(1);
	}else {
		identidade = "Processo pai. ";
	}
	std::cout << identidade;
	std:cout << "contador: " << contador << std::endl;
	return 0;
}
