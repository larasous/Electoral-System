#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Estado
{
    char codigo[50];
    char descricao[50];
}estado;

void verificar_estado(char nome[])
{
    FILE *arq_estado = fopen("estado.bin", "rb+");
    if(arq_estado == NULL)
    {
        printf("Arquivo inexistente!\n");
        exit(1);
    }
    while(fread(&estado, sizeof(struct Estado), 1, arq_estado))
    {
        if(!strcmp(estado.descricao,nome))
        {
            printf("\n----------------------\n");
            printf("Estado ja cadastrado!\n");
            printf("----------------------\n");
            system("pause");
            exit(1);

        }
    }
    system("cls");
    printf("\n-----------------------------------\n");
    printf("      Prossiga o cadastro:\n");
    printf("-----------------------------------\n");
    strcpy(estado.descricao, nome);
    printf("Informe a UF do estado: ");
    fflush(stdin);
    gets(estado.codigo);

    fwrite(&estado, sizeof(struct Estado), 1, arq_estado);

    printf("---------------------------------------------------\n");
    printf("\tCadastro realizado com sucesso!\n");
    printf("---------------------------------------------------\n");
    printf("Estado: %s - %s\n", estado.descricao, estado.codigo);
    printf("---------------------------------------------------\n");
    system("pause");

    fclose(arq_estado);
}

void inclusao_estado()
{
    char nome[20];

    FILE *arq_estado = fopen("estado.bin", "ab");
    if (arq_estado == NULL) {
        printf("Erro ao abrir arquivo");
        return;
    } else{
        system("cls");
        printf("\n-----------------------------------\n");
        printf("Digite o nome do estado: ");
        fflush(stdin);
        gets(nome);
        verificar_estado(nome);
    }
    fclose(arq_estado);
}

void listar_estado()
{
    FILE *arq_estado = fopen("estado.bin", "rb");
    if (arq_estado == NULL){
        printf("Arquivo inexistente!");
        return;
    }

    while(fread(&estado, sizeof(struct Estado), 1, arq_estado))
    {
        printf("\n------------------------\n");
        printf("UF: %s - %s\n",estado.descricao, estado.codigo);
        printf("------------------------\n");
    }
    system("pause");
    fclose(arq_estado);
}

void consultar_estado()
{
    int aux;
    char nome[20];
    FILE *arq_estado = fopen("estado.bin", "rb");
    if(arq_estado == NULL)
    {
        printf("Arquivo inexistente!\n");
        exit(1);
    }else {
        printf("\n-----------------------------------\n");
        printf("Digite a sigla do estado que procura: ");
        fflush(stdin);
        gets(nome);

        while (fread(&estado, sizeof(struct Estado), 1, arq_estado))
        {
            if (strstr(estado.codigo,nome))
            {
                printf("\n------------------------\n");
                printf("UF: %s - %s\n",estado.descricao, estado.codigo);
                printf("------------------------\n");
                aux = 1;
            }
        }
    }
    if(aux != 1)
    {
        printf("\n------------------------\n");
        printf("Estado nao cadastrado!\n");
        printf("------------------------\n");
        system("pause");
    }
    fclose(arq_estado);
}

unsigned long int posicao_estado(char nome[])
{
    FILE *arq_estado = fopen("estado.bin", "rb+");
    if(arq_estado == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }else{
        fseek(arq_estado, 0, SEEK_SET);
        unsigned long posicao = 0;

        while(fread(&estado, sizeof(struct Estado), 1, arq_estado))
        {
            if(strstr(estado.descricao, nome))
            {
                return posicao;
            }
            posicao += sizeof(struct Estado);
        }
    }
    fclose(arq_estado);
    return -1;
}

void alterar_estado()
{
    char nome[50];
    FILE *arq_estado= fopen("estado.bin", "rb+");
    if(arq_estado == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }else{
        printf("\n-----------------------------------\n");
        printf("Digite o estado que deseja alterar: ");
        fflush(stdin);
        gets(nome);

        unsigned long int pos = posicao_estado(nome);
        if(strstr(estado.descricao, nome)) {
            system("cls");
            printf("\n------------------------\n");
            printf("Estado: %s - %s\n", estado.descricao, estado.codigo);
            printf("------------------------\n");

            printf("\n------------------------\n");
            printf("Nova descricao: ");
            fflush(stdin);
            gets(estado.descricao);
            printf("Novo codigo: ");
            fflush(stdin);
            gets(estado.codigo);

            fseek(arq_estado, pos, SEEK_SET);
            fwrite(&estado, sizeof(struct Estado), 1, arq_estado);

            printf("\n------------------------\n");
            printf("   Cadastro alterado\n");
            printf("------------------------\n");
            printf("Nome: %s - %s\n", estado.descricao, estado.codigo);
            printf("------------------------\n");
            system("pause");
        }else{
            printf("\n Estado nao existe no sistema!\n");
            exit(0);
        }
    }
    fclose(arq_estado);
}

//excluindo certo
void excluir_estado()
{
    FILE* arq_estado = fopen("estado.bin","rb+");
    FILE* novoArquivo = fopen("exclusao.bin","wb+");
    char excluido[50];

    printf("Digite o estado que deseja excluir: ");
    fflush(stdin);
    gets(excluido);

    while((fread(&estado, sizeof(struct Estado), 1, arq_estado)) == 1){
        if(!(strcmp(excluido, estado.descricao))){
            printf("\n-------- Estado excluido ----------\n");
            printf("------------------------\n");
            printf("Nome: %s - %s\n", estado.descricao, estado.codigo);
            printf("------------------------\n");
        }
        else{
            fwrite(&estado, sizeof(struct Estado), 1, novoArquivo);
        }
    }
    fclose(arq_estado);
    fclose(novoArquivo);
    remove("estado.bin");
    rename("exclusao.bin", "estado.bin");
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
            inclusao_estado();
            break;
        case 2:
            listar_estado();
            break;
        case 3:
            consultar_estado();
            break;
        case 4:
            alterar_estado();
            break;
        case 5:
            excluir_estado();
            break;
        default:
            break;
    }
}
 */