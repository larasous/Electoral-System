#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Partido
{
    char partido_nome[100];
    char sigla_partido[100];
    unsigned long int num_partido;
}partido;

void verificar_partido(char nome[])
{
    FILE *arq_partido = fopen("partido.bin", "rb+");
    if(arq_partido == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }
    while(fread(&partido, sizeof(struct Partido), 1, arq_partido))
    {
        if(!strcmp(partido.partido_nome,nome))
        {
            printf("\n----------------------\n");
            printf("Partido ja cadastrado!\n");
            printf("----------------------\n");
            system("pause");
            exit(1);
        }
    }
    system("cls");
    printf("\n-----------------------------------\n");
    printf("      Prossiga o cadastro:\n");
    printf("-----------------------------------\n");
    strcpy(partido.partido_nome, nome);
    printf("Digite a sigla do partido: ");
    fflush(stdin);
    gets(partido.sigla_partido);
    printf("Digite o numero do partido: ");
    scanf("%ld", &partido.num_partido);

    fwrite(&partido, sizeof(struct Partido), 1, arq_partido);

    printf("\n---------------------------------------------------\n");
    printf("\tCadastro realizado com sucesso!\n");
    printf("---------------------------------------------------\n");
    printf("Partido: %s - %s\n", partido.partido_nome, partido.sigla_partido);
    printf("Numero: %ld\n", partido.num_partido);
    printf("---------------------------------------------------\n");
    system("\npause");
    fclose(arq_partido);
}

void inclusao_partido()
{
    char nome[100];
    FILE *arq_partido = fopen("partido.bin", "ab");
    if (arq_partido == NULL){
        printf("Erro ao abrir arquivo");
        return;
    }
    printf("\n---------------------------\n");
    printf("Digite o nome do partido: ");
    fflush(stdin);
    gets(nome);

    verificar_partido(nome);

    fclose(arq_partido);
}

void listar_partido()
{
    FILE *arq_partido = fopen("partido.bin", "rb");
    if (arq_partido == NULL){
        printf("\nArquivo inexistente!");
        return;
    }

    while(fread(&partido, sizeof(partido), 1, arq_partido))
    {
        printf("\n------------------------\n");
        printf("Partido: %s - %s\n", partido.partido_nome, partido.sigla_partido);
        printf("Numero: %ld\n", partido.num_partido);
        printf("------------------------\n");
    }
    system("pause");
    fclose(arq_partido);
}

void consultar_partido()
{
    int aux;
    char nome[10];

    FILE *arq_partido = fopen("partido.bin", "rb");
    if(arq_partido == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }else {
        printf("\n------------------------------------\n");
        printf("Digitea sigla do partido que procura: ");
        fflush(stdin);
        gets(nome);

        while(fread(&partido, sizeof(struct Partido), 1, arq_partido))
        {
            if (strstr(partido.sigla_partido, nome))
            {
                printf("\n------------------------\n");
                printf("Partido: %s - %s\n", partido.partido_nome, partido.sigla_partido);
                printf("Numero: %ld\n", partido.num_partido);
                printf("------------------------\n");
                aux = 1;
            }
        }
        if(aux != 1)
        {
            printf("\n------------------------\n");
            printf("Partido nao cadastrado!\n");
            printf("------------------------\n");
        }
    }
    system("pause");
    fclose(arq_partido);
}


unsigned long int posicao_partido(char nome[])
{
    FILE *arq_partido = fopen("partido.bin", "rb+");
    if(arq_partido == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }else{
        fseek(arq_partido, 0, SEEK_SET);
        unsigned long posicao = 0;

        while(fread(&partido, sizeof(struct Partido), 1, arq_partido))
        {
            if(strstr(partido.sigla_partido, nome))
            {
                return posicao;
            }
            posicao += sizeof(struct Partido);
        }
    }
    fclose(arq_partido);
    return -1;
}

void alterar_partido()
{
    char nome[50];
    FILE *arq_partido= fopen("partido.bin", "rb+");
    if(arq_partido == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }else{
        printf("\n-----------------------------------\n");
        printf("Digite a silga do partido que deseja alterar: ");
        fflush(stdin);
        gets(nome);

        unsigned long int pos = posicao_partido(nome);
        if(strstr(partido.sigla_partido, nome)) {
            system("cls");
            printf("\n------------------------\n");
            printf("Partido: %s - %s\n", partido.partido_nome, partido.sigla_partido);
            printf("Numero: %ld\n", partido.num_partido);
            printf("------------------------\n");

            printf("\n------------------------\n");
            printf("Novo partido: ");
            fflush(stdin);
            gets(partido.partido_nome);
            printf("Nova sigla: ");
            fflush(stdin);
            gets(partido.sigla_partido);
            printf("Novo numero: ");
            scanf("%ld", &partido.num_partido);

            fseek(arq_partido, pos, SEEK_SET);
            fwrite(&partido, sizeof(struct Partido), 1, arq_partido);

            printf("\n------------------------\n");
            printf("   Cadastro alterado\n");
            printf("------------------------\n");
            printf("Partido: %s - %s\n", partido.partido_nome, partido.sigla_partido);
            printf("Numero: %ld\n", partido.num_partido);
            printf("------------------------\n");
            system("pause");
        }else{
            printf("\n Partido nao existe no sistema!\n");
            exit(0);
        }
    }
    fclose(arq_partido);
}

void excluir_partido()
{
    FILE* arq_partido = fopen("partido.bin","rb+");
    FILE* novoArquivo = fopen("exclusao.bin","wb+");
    char excluido[50];

    printf("Digite a sigla do partido que deseja excluir: ");
    fflush(stdin);
    gets(excluido);

    while((fread(&partido, sizeof(struct Partido), 1, arq_partido)) == 1){
        if(!(strcmp(excluido, partido.sigla_partido))){
            printf("\n-------- Partido excluido ----------\n");
        }
        else{
            fwrite(&partido, sizeof(struct Partido), 1, novoArquivo);
        }
    }
    fclose(arq_partido);
    fclose(novoArquivo);
    remove("partido.bin");
    rename("exclusao.bin", "partido.bin");
}

/*
int menu()
{
    int opcao;
    do{
        printf("MENU PARA CADASTRO DE UFs\n");
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
    }while ((opcao < 0) || (opcao > 6));

    return opcao;
}

int main()
{
    int op = menu();
    switch(op)
    {
        case 1:
            inclusao_partido();
            break;
        case 2:
            listar_partido();
            break;
        case 3:
            consultar_partido();
            break;
        case 4:
            alterar_partido();
            break;
        case 5:
            excluir_partido();
            break;
        default:
            break;
    }
}
*/