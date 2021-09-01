#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Eleitores
{
    char nome[100];
    unsigned long int rg;
    unsigned long int cpf;
    unsigned long int titulo_eleitor;
}eleitores;

void verificar_eleitor(char nome[], unsigned long int aux)
{
    FILE *arq_eleitor = fopen("eleitor.bin", "rb+");
    if (arq_eleitor == NULL){
        printf("\nArquivo inexistente!\n");
        exit(1);
    }
    fseek(arq_eleitor,0, SEEK_SET);
    while(fread(&eleitores, sizeof(struct Eleitores), 1, arq_eleitor))
    {
        if(aux == eleitores.cpf)
        {
            printf("\n--------------------------------\n");
            printf("CPF ja cadastrado(a)!\n");
            printf("--------------------------------\n");
            system("pause");
            exit(1);
        }
    }
    system("cls");
    printf("\n-----------------------------------\n");
    printf("      Prossiga o cadastro:\n");
    printf("-----------------------------------\n");
    strcpy(eleitores.nome, nome);
    eleitores.cpf = aux;
    printf(" Insira seu RG (somente numeros): ");
    scanf("%ld",&eleitores.rg);
    printf(" Insira seu titulo eleitoral (somente numeros): ");
    scanf("%ld",&eleitores.titulo_eleitor);

    fseek(arq_eleitor, 0, SEEK_END);
    fwrite (&eleitores, sizeof(struct Eleitores), 1, arq_eleitor);

    printf("\n---------------------------------------------------\n");
    printf("\tCadastro realizado com sucesso!\n");
    printf("---------------------------------------------------\n");
    printf("Nome: %s\n", eleitores.nome);
    printf("RG: %ld\n", eleitores.rg);
    printf("CPF: %lu\n", eleitores.cpf);
    printf("Titulo Eleitoral: %ld\n", eleitores.titulo_eleitor);
    printf("---------------------------------------------------\n");

    system("pause");
    fclose(arq_eleitor);
}


void inclusao_eleitor()
{
    unsigned long int aux;
    char nome[100];
    FILE *arq_eleitor = fopen("eleitor.bin", "ab");
    if (arq_eleitor == NULL){
        printf("\nErro ao abrir arquivo");
        return;
    }

    printf("\n------------------------------------\n");
    printf(" Digite seu nome completo: ");
    fflush(stdin);
    gets(nome);
    printf(" Insira seu CPF (somente numeros): ");
    scanf("%ld",&aux);

    verificar_eleitor(nome, aux);

    fclose(arq_eleitor);
}

void listar_eleitor()
{
    FILE *arq_eleitor = fopen("eleitor.bin", "rb");
    if (arq_eleitor == NULL){
        printf("Arquivo inexistente!");
        return;
    }

    while(fread (&eleitores, sizeof(struct Eleitores), 1, arq_eleitor))
    {
        printf("\n-----------------------------------------------------------\n");
        printf("Nome: %s\n", eleitores.nome);
        printf("RG: %ld\n", eleitores.rg);
        printf("CPF: %lu\n", eleitores.cpf);
        printf("Titulo Eleitoral: %ld\n", eleitores.titulo_eleitor);
        printf("---------------------------------------------------\n");
    }
    system("pause");
    fclose(arq_eleitor);
}

void consultar_eleitor()
{
    unsigned long int num = 0;
    int aux;

    FILE *arq_eleitor = fopen("eleitor.bin", "rb");
    if(arq_eleitor == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }else {
        printf("\n-----------------------------------------\n");
        printf("Insira seu CPF (somente numeros): ");
        scanf("%lu", &num);
        printf("------------------------------------------\n");

        while (fread(&eleitores, sizeof(struct Eleitores), 1, arq_eleitor))
        {
            if (num == eleitores.cpf)
            {
                printf("\n-----------------------------------------------------------\n");
                printf("Nome: %s\n", eleitores.nome);
                printf("RG: %lu\n", eleitores.rg);
                printf("CPF: %lu\n", eleitores.cpf);
                printf("Titulo Eleitoral: %lu\n", eleitores.titulo_eleitor);
                printf("-----------------------------------------------------------\n");
                aux = 1;
            }
        }
        if(aux != 1)
        {
            printf("\n-----------------------\n");
            printf("CPF nao cadastrado!\n");
            printf("-----------------------\n");
        }
    }
    system("pause");
    fclose(arq_eleitor);
}

unsigned long int posicao_eleitor(unsigned long int aux)
{
    FILE *arq_eleitor = fopen("eleitor.bin", "rb+");
    if(arq_eleitor == NULL)
    {
        printf("\nErro ao abrir arquivo!\n");
        exit(1);
    }else{
        fseek(arq_eleitor, 0, SEEK_SET);
        unsigned long int posicao = 0;

        while(fread(&eleitores, sizeof(struct Eleitores), 1, arq_eleitor))
        {
            if(aux == eleitores.cpf)
            {
                return posicao;
            }
            posicao += sizeof(struct Eleitores);
        }
    }
    fclose(arq_eleitor);
    return -1;
}

void alterar_eleitor()
{
    unsigned long int aux;
    FILE *arq_eleitor = fopen("eleitor.bin", "rb+");
    if(arq_eleitor == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }else{
        printf("\n----------------------------------------------------\n");
        printf("Digite o CPF que deseja alterar (somente numeros): ");
        scanf("%lu", &aux);

        unsigned long int pos = posicao_eleitor(aux);

        if(aux == eleitores.cpf) {
            system("cls");
            printf("\n-----------------------------------------------------------\n");
            printf("Nome: %s\n", eleitores.nome);
            printf("RG: %lu\n", eleitores.rg);
            printf("CPF: %lu\n", eleitores.cpf);
            printf("Titulo Eleitoral: %lu\n", eleitores.titulo_eleitor);
            printf("-----------------------------------------------------------\n");

            printf("\n-----------------------------------------------------------\n");
            printf("Novo nome: ");
            fflush(stdin);
            gets(eleitores.nome);
            printf("Novo RG: ");
            scanf("%lu", &eleitores.rg);
            printf("Novo CPF: ");
            scanf("%lu", &eleitores.cpf);
            printf("Novo titulo eleitoral: ");
            scanf("%lu", &eleitores.titulo_eleitor);

            fseek(arq_eleitor, pos, SEEK_SET);
            fwrite(&eleitores, sizeof(struct Eleitores), 1, arq_eleitor);

            printf("\n-----------------------------------------------------------\n");
            printf("   Cadastro alterado\n");
            printf("-----------------------------------------------------------\n");
            printf("Nome: %s\n", eleitores.nome);
            printf("RG: %lu\n", eleitores.rg);
            printf("CPF: %lu\n", eleitores.cpf);
            printf("Titulo Eleitoral: %lu\n", eleitores.titulo_eleitor);
            printf("-----------------------------------------------------------\n");
        }else{
            printf("\nCPF nao existe no sistema!\n");
            exit(1);
        }
    }
    system("pause");
    fclose(arq_eleitor);
}

void excluir_eleitor()
{
    FILE *arq_eleitor = fopen("eleitor.bin","rb+");
    FILE *novoArquivo = fopen("exclusao.bin","wb+");
    long int excluido;

    printf("\n---------------------------------------------------------------\n");
    printf("Digite o CPF do eleitor que deseja excluir (SOMENTE NUMEROS): ");
    scanf("%ld", &excluido);

    while((fread(&eleitores, sizeof(struct Eleitores), 1, arq_eleitor)) == 1){
        if(excluido == eleitores.cpf){
            printf("\n-------- Eleitor excluido ----------\n");
        }
        else{
            fwrite(&eleitores, sizeof(struct Eleitores), 1, novoArquivo);
        }
    }
    fclose(arq_eleitor);
    fclose(novoArquivo);
    remove("eleitor.bin");
    rename("exclusao.bin", "eleitor.bin");
    system("pause");
}
/*
int menu(void) // menu CRUD
{
    int opcao;
    do {
        printf("\tMENU\n");
        printf("1. Cadastrar\n");
        printf("2. Listar\n");
        printf("3. Consultar\n");
        printf("4. Alterar\n");
        printf("5. Excluir\n");
        printf("6. Retornar para o menu inicial\n");
        printf("0. Sair\n");
        printf("======================================\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        if ((opcao < 0) || (opcao > 6))
            printf ("\nOpcao Digitada Incorreta!\n");
    } while ((opcao < 0) || (opcao > 6));

    return opcao;
}

int main()
{
    int op = 0;
    op = menu();
    switch(op)
    {
        case 1:
            inclusao_eleitor();
            break;
        case 2:
            listar_eleitor();
            break;
        case 3:
            consultar_eleitor();
            break;
        case 4:
            alterar_eleitor();
            break;
        case 5:
            excluir_eleitor();
            break;
        default:
            break;
    }
}*/