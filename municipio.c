#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Municipio
{
    char nome_mun[100];
    char UF[50];
}municipio;

void verificar_municipio(char nome[])
{
    FILE *arq_mun = fopen("municipio.bin", "rb+");
    if(arq_mun == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }
    while(fread(&municipio, sizeof(struct Municipio), 1, arq_mun))
    {
        if(!strcmp(municipio.nome_mun,nome))
        {
            printf("\n----------------------\n");
            printf("Municipio ja cadastrado!\n");
            printf("----------------------\n");
            system("pause");
            exit(1);
        }
    }
    system("cls");
    printf("\n-----------------------------------\n");
    printf("      Prossiga o cadastro:\n");
    printf("-----------------------------------\n");
    strcpy(municipio.nome_mun, nome);
    printf("Digite o estado a qual pertence: ");
    fflush(stdin);
    gets(municipio.UF);

    fwrite(&municipio, sizeof(struct Municipio), 1, arq_mun);

    printf("---------------------------------------------------\n");
    printf("\tCadastro realizado com sucesso!\n");
    printf("---------------------------------------------------\n");
    printf("Municipio: %s - %s\n", municipio.nome_mun, municipio.UF);
    printf("---------------------------------------------------\n");
    system("\npause");

    fclose(arq_mun);
}

void inclusao_municipio() // cadastrar os municipios
{
    char nome[100];
    FILE *arq_mun = fopen("municipio.bin", "ab");
    if (arq_mun == NULL){
        printf("\nErro ao abrir arquivo");
        exit(1);
    }
    system("cls");
    printf("\n-----------------------------------\n");
    printf("Digite o nome do municipio: ");
    fflush(stdin);
    gets(nome);

    verificar_municipio(nome);

    fclose(arq_mun);
}

void listar_municipio() // mostrar todos os municipios cadastrados
{
    FILE *arq_mun = fopen("municipio.bin", "rb");
    if (arq_mun == NULL){
        printf("\nArquivo inexistente!");
        return;
    }

    while(fread(&municipio, sizeof(struct Municipio), 1, arq_mun))
    {
        printf("\n------------------------\n");
        printf("Municipio: %s - %s\n",municipio.nome_mun, municipio.UF);
        printf("------------------------\n");
    }
    system("pause");
    fclose(arq_mun);
}

void consultar_municipio()
{
    char nome[100];
    int aux;

    FILE *arq_mun = fopen("municipio.bin", "rb");
    if(arq_mun == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }else{
        printf("\n-----------------------------------\n");
        printf("Digite o municipio que procura: ");
        fflush(stdin);
        gets(nome);

        while(fread(&municipio, sizeof(struct Municipio), 1, arq_mun))
        {
            if(strstr(municipio.nome_mun, nome))
            {
                printf("\n------------------------\n");
                printf("Municipio: %s - %s\n", municipio.nome_mun, municipio.UF);
                printf("------------------------\n");
                aux = 1;
            }
        }
        if(aux != 1)
        {
            printf("\n------------------------\n");
            printf("Municipio nao cadastrado!\n");
            printf("------------------------\n");
        }
    }
    system("pause");
    fclose(arq_mun);
}

unsigned long int posicao_municipio(char nome[])
{
    FILE *arq_mun = fopen("municipio.bin", "rb+");
    if(arq_mun == NULL)
    {
        printf("\nErro ao abrir arquivo!\n");
        exit(1);
    }else{
        fseek(arq_mun, 0, SEEK_SET);
        unsigned long posicao = 0;

        while(fread(&municipio, sizeof(struct Municipio), 1, arq_mun))
        {
            if(strstr(municipio.nome_mun, nome))
            {
                return posicao;
            }
            posicao += sizeof(struct Municipio);
        }
    }
    fclose(arq_mun);
    return -1;
}

void alterar_municipio()
{
    char nome[50];
    FILE *arq_mun = fopen("municipio.bin", "rb+");
    if(arq_mun== NULL)
    {
        printf("Arquivo inexistente!\n");
        exit(1);
    }else{
        printf("\n-----------------------------------\n");
        printf("Digite o municipio que deseja alterar: ");
        fflush(stdin);
        gets(nome);

        unsigned long int pos = posicao_municipio(nome);

        if(strstr(municipio.nome_mun, nome)) {
            system("cls");
            printf("\n------------------------\n");
            printf("Municipio: %s - %s\n", municipio.nome_mun, municipio.UF);
            printf("------------------------\n");

            printf("\n------------------------\n");
            printf("Novo nome: ");
            fflush(stdin);
            gets(municipio.nome_mun);
            printf("Nova UF: ");
            fflush(stdin);
            gets(municipio.UF);

            fseek(arq_mun, pos, SEEK_SET);
            fwrite(&municipio, sizeof(struct Municipio), 1, arq_mun);

            printf("------------------------\n");
            printf("   Cadastro alterado\n");
            printf("------------------------\n");
            printf("Nome: %s - %s\n", municipio.nome_mun, municipio.UF);
            printf("------------------------\n");
            system("pause");
        }else{
            printf("\nMunicipio nao existe no sistema!\n");
            exit(1);
        }
    }
    fclose(arq_mun);
}

void excluir_municipio()
{
    FILE* arq_mun = fopen("municipio.bin","rb+");
    FILE* novoArquivo = fopen("exclusao.bin","wb+");
    char excluido[50];

    printf("Digite o partido que deseja excluir: ");
    fflush(stdin);
    gets(excluido);

    while((fread(&municipio, sizeof(struct Municipio), 1, arq_mun)) == 1){
        if(!(strcmp(excluido, municipio.nome_mun))){
            printf("\n-------- Partido excluida ----------\n");
        }
        else{
            fwrite(&municipio, sizeof(struct Municipio), 1, novoArquivo);
        }
    }
    fclose(arq_mun);
    fclose(novoArquivo);
    remove("municipio.bin");
    rename("exclusao.bin", "municipio.bin");
}
/*
int menu(void)
{
    int opcao;
    do {
        printf("\tMENU\n");
        printf("-----------------------------------\n");
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
    int op = menu();
    switch(op)
    {
        case 1:
            inclusao_municipio();
            break;
        case 2:
            listar_municipio();
            break;
        case 3:
            consultar_municipio();
            break;
        case 4:
            alterar_municipio();
            break;
        case 5:
            excluir_municipio();
            break;
        default:
            break;
    }
}
*/