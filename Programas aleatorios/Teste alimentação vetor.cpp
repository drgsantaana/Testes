/*
 *###################################################
 *IFMG- BAMBUI
 *Nome: Daniel Reis Goncalves Sant'ana
 *Data: 15/08/2022
 *Turma: ENGC-2022
 *Titulo: Alimentando vetores de formas diferentes
 *###################################################
*/
#include <iostream> // Biblioteca padrao c++
#include <stdlib.h> // Biblioteca c
#include <clocale> //  Biblioteca de localização
#include <cstdlib> //Numeros aleatorios...


//VARIAVEIS GLOBAIS:



//FUNÇOES:



//BLOCO PRINCIPAL:

int main() {
    setlocale(LC_ALL, "Portuguese");

    std::string vet1[5]={"teste1","teste1","teste1","teste1","teste1"}; //Todos os valores ja foram preenchidos
    std::string vet2[5]={"teste2","teste2"}; // 2 valores foram preenchidos

    for(int i=0;i<5;i++){
        std::cout << vet1[i] << " ";
    }

    std::cout << std::endl;

    for(int i=0;i<5;i++){
        if(vet2[i].empty()){
            std::cout << "Digite o valor da: " << i+1 << "º posição: ";
            std::cin >> vet2[i];
        }
    }
    std::cout << std::endl;
    system ("pause");
    return 0;
}
