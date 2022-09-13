/*
 *###################################################
 *IFMG- BAMBUI
 *Nome: Daniel Reis Goncalves Sant'ana
 *Data: 15/08/2022
 *Turma: ENGC-2022
 *Titulo: Gerador de numeros aleatorios
 *###################################################
*/
#include <iostream>
#include <stdlib.h> 
#include <clocale> 
#include <cstdlib> 

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int tam;
    cout << "Digite o tamanho de um vetor: ";
    cin >> tam;
    int vet[tam];

    for(int i=0;i<tam;i++){
        cout << i+1 << "º posição: ";
        vet[i]=rand();
        cout << vet[i]<<endl;
    }

    cout << "Fim";

    cout << endl;
    system ("pause");
    return 0;
}
