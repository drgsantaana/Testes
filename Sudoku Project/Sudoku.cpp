/*
 *###################################################
 *IFMG- BAMBUI
 *Nome: Daniel Reis Goncalves Sant'ana
 *Turma: ENGC-2022
 *Titulo: Sudoku Project
 *###################################################
*/
#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <conio.h>


#define N 9
#define facil 25 
#define medio 50
#define impossiel 60

int gabarito[N][N],jogofeito[N][N],vet1[N],vet2[N],vet3[N],cont;

unsigned seed = time(0);

//Menu
int menu()
{
    int opcao;

inicio:
    system("cls");
    system("color 0F");
    std::cout << "1 - JOGAR \n2 - REGRAS \n3 - CREDITOS \n4 - SAIR\n";
    opcao = getch();
    switch (opcao)
    {
    case '1':
dificuldade:
        system("cls");
        std::cout << "1 - FACIL \n2 - DIFICIL \n3 - IMPOSSIVEL \n4 - RETORNAR AO MENU INICIAL \n5 - SAIR\n";
        opcao = getch();
        switch(opcao)
        {
        case '1':
            system("cls");
            return 1;
            break;
        case '2':
            system("cls");
            return 2;
            break;
        case '3':
            system("cls");
            return 3;
            break;
        case '4':
            system("cls");
            goto inicio;
            break;
        case '5':
            std::cout << "Você pediu para sair, precione qualquer tecla para continuar" << std::endl;
            system("pause");
            exit(0);
        default:
            std::cout << "Você deve escolher uma opcao valida\n";
            std::cout << "Precione qualquer tecla para voltar ao menu\n\n";
            system("pause");
            goto dificuldade;
        }
        break;
    case '2':
regras:
        system("cls");
        std::cout << "REGRAS: " << std::endl;
        std::cout << std::endl << "O objetivo do jogo é completar todos os quadrados utilizando numeros de 1 a 9. " << std::endl;
        std::cout << std::endl << "Para completa-los basta seguir as seguintes regras:" << std::endl;
        std::cout << std::endl << "Não podem haver numeros repetidos nas linhas horizontais" << std::endl;
        std::cout << "Não podem haver numeros repetidos nas linhas verticais" << std::endl;
        std::cout << "Não podem haver numeros repetidos nos quadrados delimitados" << std::endl;
        std::cout << "O numero 0 equivale a um espaço vazio, Você devera preenchelos" << std::endl;
        std::cout << "Escreva a coordenada do espaço vazio e digite o numero desejado" << std::endl;
        std::cout << "ATENÇÃO: NENHUM NUMERO PODERA SER TROCADO, COM GRANDES PODERES VEM GRANDES RESPONSABILIDADES" << std::endl;
        std::cout << "SUDOKU é um jogo de raciocinio e logica." << std::endl;
        std::cout << std::endl << "1 - RETORNAR AO MENU INICIAL \n2 - SAIR\n" << std::endl;
        opcao = getch();
        switch(opcao)
        {
        case '1':
            system("cls");
            goto inicio;
            break;
        case '2':
            system("cls");
            std::cout << "Você pediu para sair, prencione qualquer tecla para continuar\n";
            system("pause");
            exit(0);
        default:
            std::cout << "Você deve escolher uma opcao valida\n";
            std::cout << "Precione qualquer tecla para voltar ao menu\n\n";
            system("pause");
            goto regras;

        }
        return 0;
        break;
    case '3':
creditos:
        system("cls");
        std::cout << "CREDITOS: " << std::endl;
        std::cout << std::endl << "###################################################" << std::endl;
        std::cout << "IFMG- BAMBUI" << std::endl;
        std::cout << "Nome: Daniel Reis Goncalves Sant'ana" << std::endl;
        std::cout << "Turma: ENGC-2022" << std::endl;
        std::cout << "Titulo: Sudoku Project" << std::endl;
        std::cout << "###################################################" << std::endl;
        std::cout << std::endl << "1 - RETORNAR AO MENU INICIAL \n2 - SAIR\n" << std::endl;
        opcao = getch();
        switch(opcao)
        {
        case '1':
            system("cls");
            goto inicio;
            break;
        case '2':
            system("cls");
            std::cout << "Você pediu para sair, prencione qualquer tecla para continuar\n";
            system("pause");
            exit(0);
        default:
            std::cout << "Você deve escolher uma opcao valida\n";
            std::cout << "Precione qualquer tecla para voltar ao menu\n\n";
            system("pause");
            goto creditos;
        }
        return 0;
        break;
    case '4':
        system("cls");
        std::cout << "Você pediu para sair, prencione qualquer tecla para continuar\n";
        system("pause");
        exit(0);
    default:
        std::cout << "Você deve escolher uma opcao valida\n";
        std::cout << "Precione qualquer tecla para voltar ao menu\n\n";
        system("pause");
        goto inicio;
    }



}


// "Print" mostra na tela matrizes 9x9
void print(int mat[N][N])
{
    std::cout << "Y= Linhas: X= Colunas: " << std::endl;
    std::cout << "Y:X:  1 2 3  | 4 5 6  | 7 8 9 "<< std::endl << std::endl;

    for (int lin = 0; lin < N; lin++)
    {
        for (int col = 0; col < N; col++)
        {
            if(col==0)
                std::cout << lin+1 << "     ";
            if(col == 3 || col == 6)
                std::cout << " | ";
            std::cout << mat[lin][col] <<" ";
        }
        if(lin == 2 || lin == 5)
        {
            std::cout << std::endl;
            for(int i = 0; i<N; i++)
                std::cout << "----";
        }
        std::cout << std::endl;
    }

}


//"verificavet"  faz a verificaï¿½ï¿½o dos vetores para que nenhum numero se repita.
bool verificavet(int v,int vet[])
{

    for(int i=0; i<N; i++)
    {
        if(v==vet[i])
        {
            return true;
        }
    }
    return false;
}


//"alimentavet" faz o preenchimento dos vetores vet1 vet2 e vet3 com chamada na verificaï¿½ï¿½o.
void alimentavet1()
{
    int valor;
    for(int lin=0; lin<N; lin++)
    {
        valor = (rand() % N) + 1;
        while(verificavet(valor, vet1))
        {
            valor = (rand() % N) + 1;
        }
        vet1[lin]=valor;
    }
}
void alimentavet2()
{
    int valor;
    for(int lin=0; lin<N; lin++)
    {
        valor = (rand() % N) + 1;
        while(verificavet(valor, vet2))
        {
            valor = (rand() % N) + 1;
        }
        vet2[lin]=valor;
    }
}
void alimentavet3()
{
    int valor;
    for(int lin=0; lin<N; lin++)
    {
        valor = (rand() % N) + 1;
        while(verificavet(valor, vet3))
        {
            valor = (rand() % N) + 1;
        }
        vet3[lin]=valor;
    }
}
//Fim do preenchimento dos vetores.


//"matrizdiagonal" faz o preenchimento das 3 matrizes 3x3 diagonais da matriz 9x9
void matrizdiagonal()
{
    int cont=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {

            gabarito[i][j] = vet1[cont];
            vet1[cont]=0;
            cont++;
        }
    }
    cont=0;
    for(int i=3; i<=5; i++)
    {
        for(int j=3; j<=5; j++)
        {

            gabarito[i][j] = vet2[cont];
            vet2[cont]=0;
            cont++;
        }
    }
    cont=0;
    for(int i=6; i<=8; i++)
    {
        for(int j=6; j<=8; j++)
        {

            gabarito[i][j] = vet3[cont];
            vet3[cont]=0;
            cont++;
        }
    }

}



//"temnacoluna" Verifica se Num esta presente na coluna ou nao
bool temnacoluna(int col, int num)
{
    for (int lin = 0; lin < N; lin++)
        if (gabarito[lin][col] == num)
            return true;
    return false;
}


//"temnalinha" Verifica se Num esta presente na linha ou nao
bool temnalinha(int lin, int num)
{
    for (int col = 0; col < N; col++)
        if (gabarito[lin][col] == num)
            return true;
    return false;
}


//"temnagrade" Verifica se Num esta presente na grade 3x3
bool temnagrade(int iniciogradeL, int iniciogradeC, int num)
{
    for (int lin = 0; lin < 3; lin++)
        for (int col = 0; col < 3; col++)
            if (gabarito[lin+iniciogradeL][col+iniciogradeC] == num)
                return true;
    return false;
}


//"lugarvazio" Acha um lugar vazio e atualiza lin e col
bool lugarvazio(int &lin, int &col)
{
    for (lin = 0; lin < N; lin++)
        for (col = 0; col < N; col++)
            if (gabarito[lin][col] == 0) //Marca com 0 quando vazio
                return true;
    return false;
}


//"lugarvalido" verifica se ï¿½ um espaçoo valido para o numero
bool lugarvalido(int lin, int col, int num)
{
    //Quando o numero nao ï¿½ encontrado na coluna na linha e na grade
    return !temnalinha(lin, num) && !temnacoluna(col, num) && !temnagrade(lin - lin%3,
            col - col%3, num);
}


//"geradordesudoku" gera o sudoku a partir da grade 9x9 existente
bool geradordesudoku()
{
    int lin, col;
    if (!lugarvazio(lin, col))
        return true; //Quando todos os espaçoes estao preenchidos
    for (int num = 1; num <= 9; num++)  //Numeros validos sï¿½o de 1 a 9
    {
        if (lugarvalido(lin, col, num))  //Se valido coloca um numero
        {
            gabarito[lin][col] = num;
            if (geradordesudoku()) //Recursivo troca de posiï¿½ao
                return true;
            gabarito[lin][col] = 0; //Coloca 0 quando nao ï¿½ um espaço valido
        }
    }
    return false;
}


//"sudokudousuario" faz uma copia do gabarito pra manipulaï¿½ï¿½o do usuario
void sudokudousuario()
{

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            jogofeito[i][j]=gabarito[i][j];
        }
    }


}


//"deletanumeros" deleta numeros do jogofeito(matriz do usuario) de acordo com a dificuldade
void deletanumeros(int dificuldade)
{
    int x,y;

    switch(dificuldade)
    {

    case 1:
        x=1+(rand()%9);
        y=1+(rand()%9);
        if(jogofeito[x][y]==0)
        {
            deletanumeros(1);
        }
        else
        {
            jogofeito[x][y]=0;
            cont++;
        }
        if(cont!=facil)
            deletanumeros(1);
        break;
    case 2:
        x=1+(rand()%9);
        y=1+(rand()%9);
        if(jogofeito[x][y]==0)
        {
            deletanumeros(2);
        }
        else
        {
            jogofeito[x][y]=0;
            cont++;
        }
        if(cont!=medio)
            deletanumeros(2);
        break;
    case 3:
        x=1+(rand()%9);
        y=1+(rand()%9);
        if(jogofeito[x][y]==0)
        {
            deletanumeros(3);
        }
        else
        {
            jogofeito[x][y]=0;
            cont++;
        }
        if(cont!=impossiel)
            deletanumeros(3);
        break;

    }


}
//"preencheu" verifica se o usuario preencheu um local valido
bool preencheu()
{

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(jogofeito[i][j]==0)
            {
                return true;
            }
        }
    }

    return false;
}
//"comecoujogo" comeï¿½a o jogo dps de ter o gabarito e a matriz do usuario
void comecoujogo()
{
    int x,y,num;
    bool continua;

    do
    {
        system("cls");
        print(jogofeito);
        //std::cout << std::endl; print(gabarito);   //Para testes retire o comentario no inicio da linha e vera o gabarito

jogando:
        std::cout << std::endl << "Digite a coordenada X: ";
        std::cin >> x;
        while(x<1 || x>9)
        {
            cout << "Digite uma coordenada X valida de 1 a 9: ";
            std::cin >> x;
        }
        std::cout << "Digite a coordenada Y: ";
        std::cin >> y;
        while(y<1 || y>9)
        {
            cout << "Digite uma coordenada Y valida de 1 a 9: ";
            std::cin >> y;
        }
        std::cout << "Digite o numero desejado: ";
        std::cin >> num;
        while(num<1 || num>9)
        {
            cout << "Digite um numero valido de 1 a 9: ";
            std::cin >> num;
        }
        if(jogofeito[y-1][x-1]== 0)
        {
            jogofeito[y-1][x-1]=num;
        }
        else
        {
            std::cout << "A coordenada ja estava preenchida, nenhum valor foi alterado.\n";
            std::cout << "Aperte qualquer tecla para continuar";
            system("pause");
        }
        continua=preencheu();


    }
    while(continua);


}
//"resetgabarito" reseta o gabarito para poder continuar jogando
void resetgabarito()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {

            gabarito[i][j]=0;

        }
    }



}


//BLOCO PRINCIPAL:

int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(seed);
    int dificuldade;


mainvolta:
    dificuldade=menu(); //Pega o nivel de dificuldade que a pessoa escolher+

    do
    {
        alimentavet1();

        alimentavet2();

        alimentavet3();

        matrizdiagonal();

        if (geradordesudoku() == true)
            sudokudousuario();

    }
    while(geradordesudoku()==false);
    cont=0;
    deletanumeros(dificuldade);

    if(dificuldade!=0)
    {
        comecoujogo();
    }
    int all=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(jogofeito[i][j]==gabarito[i][j])
                all=all+1;
        }
    }

    if(all==81)
    {
        system("cls");
        std::cout << "Parabens vocï¿½ venceu, aproveite seu premio ^^ :" << std::endl;

        std::cout <<  " ___________________ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½" << std::endl;
        std::cout << " _________________ï¿½ï¿½ï¿½ï¿½ï¿½___ï¿½ï¿½" << std::endl;
        std::cout << " ________________ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½___ï¿½" << std::endl;
        std::cout << " _______________ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½" << std::endl;
        std::cout << " ___________ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½" << std::endl;
        std::cout << " ________ï¿½ï¿½ï¿½ï¿½ï¿½___ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½____ï¿½ï¿½ï¿½ï¿½ï¿½" << std::endl;
        std::cout << " _____ï¿½ï¿½ï¿½ï¿½_________ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½__________ï¿½ï¿½ï¿½"<< std::endl;
        std::cout << " ____ï¿½ï¿½ï¿½______ï¿½____________________ï¿½__ï¿½ï¿½ï¿½"<< std::endl;
        std::cout << " ___ï¿½ï¿½________ï¿½ï¿½__ï¿½ï¿½_____ï¿½ï¿½__ï¿½ï¿½ï¿½________ï¿½ï¿½"<< std::endl;
        std::cout << " __ï¿½ï¿½_______________ï¿½ï¿½__ï¿½ï¿½_____ï¿½ï¿½ï¿½_______ï¿½ï¿½"<< std::endl;
        std::cout << " _ï¿½ï¿½______________________________________ï¿½"<< std::endl;
        std::cout << " ï¿½ï¿½________________________________________ï¿½"<< std::endl;
        std::cout << " ï¿½ï¿½________________________________________ï¿½"<< std::endl;
        std::cout << " _ï¿½ï¿½ï¿½____________________________________ï¿½ï¿½"<< std::endl;
        std::cout << " ___ï¿½ï¿½ï¿½ï¿½ï¿½____________________________ï¿½ï¿½ï¿½ï¿½ï¿½"<< std::endl;
        std::cout << " ____ï¿½ï¿½_ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½_ï¿½"<< std::endl;
        std::cout << " _____ï¿½____ï¿½_____ï¿½____ï¿½ï¿½____ï¿½_____ï¿½ï¿½___ï¿½ï¿½"<< std::endl;
        std::cout << " _____ï¿½____ï¿½ï¿½____ï¿½____ï¿½ï¿½____ï¿½_____ï¿½____ï¿½"<< std::endl;
        std::cout << " _____ï¿½ï¿½____ï¿½____ï¿½ï¿½___ï¿½ï¿½___ï¿½ï¿½____ï¿½ï¿½___ï¿½ï¿½"<< std::endl;
        std::cout << " ______ï¿½____ï¿½ï¿½___ï¿½ï¿½___ï¿½ï¿½___ï¿½ï¿½____ï¿½____ï¿½"<< std::endl;
        std::cout << " ______ï¿½ï¿½____ï¿½___ï¿½ï¿½___ï¿½ï¿½___ï¿½ï¿½___ï¿½ï¿½___ï¿½ï¿½"<< std::endl;
        std::cout << " _______ï¿½____ï¿½ï¿½___ï¿½___ï¿½ï¿½___ï¿½____ï¿½ï¿½___ï¿½"<< std::endl;
        std::cout << " _______ï¿½ï¿½___ï¿½ï¿½___ï¿½___ï¿½ï¿½___ï¿½____ï¿½___ï¿½ï¿½"<< std::endl;
        std::cout << " ________ï¿½____ï¿½ï¿½__ï¿½ï¿½__ï¿½ï¿½__ï¿½ï¿½___ï¿½ï¿½___ï¿½"<< std::endl;
        std::cout << " ________ï¿½ï¿½____ï¿½___ï¿½__ï¿½ï¿½__ï¿½___ï¿½ï¿½__ï¿½ï¿½"<< std::endl;
        std::cout << " _________ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½"<< std::endl;


        std::cout << std::endl << "Aperte qualquer tecla para continuar.\n";
        system("pause");
        resetgabarito();
        goto mainvolta;
    }
    else
    {
        system("cls");
        std::cout << "Não foi desta vez, Você perdeu" << std::endl;
        std::cout << "Aperte qualquer tecla para continuar.\n";
        system("pause");
        resetgabarito();
        goto mainvolta;

    }




    std::cout << std::endl;
    system ("pause");
    return 0;
}
