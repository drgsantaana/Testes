#include <iostream>
#include <stdlib.h>
#include <conio.h>

main()
{
    //menu
    int opcao;
    inicio:
    system("cls");
    system("color 0F");
    std::cout << "1 - JOGAR \n2 - RANKINGS \n3 - CREDITOS \n4 - SAIR\n";
    opcao = getch();
    switch (opcao) {
    case '1':
        system("cls");
        std::cout << "GAME\n";
        break;
    case '2':
        system("cls");
        std::cout << "Ranking\n";
        break;
    case '3':
        system("cls");
        std::cout << "Creditos\n";
        break;
    case '4':
        system("cls");
        std::cout << "voce pediu para sair, prencione qualquer tecla para continuar\n";
        break;
    default:
        std::cout << "Voce deve escolher uma opcao valida\n";
        std::cout << "Precione qualquer tecla para voltar ao menu\n\n";
        system("pause");
        goto inicio;
    }
}
