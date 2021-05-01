#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Representa o tamanho da tabela
#define M 19

typedef struct pessoa
{
    int matricula;
    char nome[50];
}Pessoa;

Pessoa tabelaHash[M];

void inicilaizar()
{
    int i;
    for ( i = 0; i < M; i++)
    {
        tabelaHash[i].matricula = -1;
    }
    
}

//Função de Espalhamento
int gerarHash(int chave)
{
    return chave % M;
}

//ler e retornar
Pessoa lerPessoa()
{
    Pessoa p;
    printf("Digite a Matricula: ");
    scanf("%d", &p.matricula);
 //   scanf("%c");
    printf("Digite o nome: ");
    fgets(p.nome, 50, stdin);
    return p;
}

//Inserir uma pessoa na tabela
void insere()
{
    inicilaizar();
    Pessoa p = lerPessoa();
    int indice = gerarHash(p.matricula);
    while (tabelaHash[indice].matricula != -1)
    {
        indice = gerarHash( indice+1 );
    }
    tabelaHash[indice] = p;
    
}

//Retorna um endereço ou retorna null
Pessoa* bucar(int chave)
{
    int indice = gerarHash(chave);

    while (tabelaHash[indice].matricula != -1)
    {
        if(tabelaHash[indice].matricula == chave)
        {
            return &tabelaHash[indice];
        }
        else
        {
            indice = gerarHash( indice + 1 );
        }
    }
    return NULL;
    
}

void imprimir()
{
    int i;
    printf("\n---------------------------------- TABELA ---------------------------------\n");
    for ( i = 0; i < M; i++)
    {
        if(tabelaHash[i].matricula != -1)
        {
            printf("%d = %d \n", i, tabelaHash[i].matricula);
        }
        else
        {
            printf("%d = %d \n", i);
        }
    }
    printf("\n---------------------------------------------------------------------------\n");
    
}

int main()
{
    int op, chave;
    Pessoa *p;


    do
    {
        printf("\n 1 - Inserir\n 2 - Buscar\n 3 - Imprimir\n 0 - Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("Saindo ...\n");
            break;
        case 1:
            insere();
            break;
        case 2:
            printf("Digite a matricula a ser buscada");
            scanf("%d", &chave);
            p = bucar(chave);
            if(p)
            {
                printf("\n\tMatricula : %d \tNome : %s\n", p->matricula, p->nome);
            }
            else
            {
                printf("\n\nMatricula Nao Encontrada\n\n");
            }
            break;
        case 3:
            imprimir();
            break;
        default:
            printf("Opcao Invalida\n");
            break;
        }
    } while (op != 0);


    return 0;
}