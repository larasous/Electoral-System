#include <stdio.h>
#include <stdlib.h>

struct Eleicao
{
    long int ano;

}eleicao;

void verificar_eleicao(long int aux)
{
    FILE *arq_eleicao = fopen("eleicao.bin", "rb+");
    if (arq_eleicao == NULL){
        printf("\nArquivo inexistente!\n");
        exit(1);
    }
    fseek(arq_eleicao, 0, SEEK_SET);
    while(fread(&eleicao, sizeof(struct Eleicao), 1, arq_eleicao))
    {
        if(aux == eleicao.ano)
        {
            printf("\n---------------------------------\n");
            printf("Ano de eleicao ja cadastrado!\n");
            printf("---------------------------------\n");
            system("pause");
            exit(1);
        }
    }
    eleicao.ano = aux;
    fseek(arq_eleicao, 0, SEEK_END);
    fwrite (&eleicao, sizeof(struct Eleicao), 1, arq_eleicao);
    printf("\n-------------------------------------\n");
    printf("Cadastro realizado com sucesso!\n");
    printf("--------------------------------------\n");
    printf("Ano da eleicao: %ld \n", eleicao.ano);
    printf("--------------------------------------\n");

    system("pause");
    fclose(arq_eleicao);
}

void inclusao_eleicao()
{
    long int aux;
    FILE *arq_eleicao = fopen("eleicao.bin", "ab");
    if (arq_eleicao == NULL){
        printf("\nErro ao abrir arquivo");
        return;
    }
    printf("\n---------------------------\n");
    printf("Digite o ano da eleicao: ");
    scanf("%ld", &aux);

    verificar_eleicao(aux);

    fclose(arq_eleicao);
}
void listar_eleicao()
{
    FILE *arq_eleicao = fopen("eleicao.bin", "rb");
    if (arq_eleicao == NULL){
        printf("\nArquivo inexistente!");
        return;
    }
    while(fread(&eleicao, sizeof(struct Eleicao), 1, arq_eleicao))
    {
        printf("\n------------------------\n");
        printf("Ano da eleicao: %ld \n", eleicao.ano);
        printf("------------------------\n");
    }
    system("pause");
    fclose(arq_eleicao);
}

void consultar_eleicao()
{
    int aux, num = 0;

    FILE *arq_eleicao = fopen("eleicao.bin", "rb");
    if(arq_eleicao == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }else {
        printf("\n-----------------------------------\n");
        printf("Digite o ano de eleicao que procura: ");
        scanf("%d", &num);

        while (fread(&eleicao, sizeof(struct Eleicao), 1, arq_eleicao))
        {
            if (num == eleicao.ano)
            {
                printf("\n------------------------\n");
                printf("Ano da eleicao: %i \n", eleicao.ano);
                printf("------------------------\n");
                aux = 1;
            }
        }
    }if(aux != 1){
        printf("\n--------------------------------\n");
        printf("Ano de eleicao nao cadastrado!\n");
        printf("---------------------------------\n");
    }
    system("pause");
    fclose(arq_eleicao);
}

unsigned long int posicao_eleicao(long int aux)
{
    FILE *arq_eleicao = fopen("eleicao.bin", "rb+");
    if(arq_eleicao == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }else{
        fseek(arq_eleicao, 0, SEEK_SET);
        unsigned long int posicao = 0;

        while(fread(&eleicao, sizeof(struct Eleicao), 1, arq_eleicao))
        {
            if(aux == eleicao.ano)
            {
                return posicao;
            }
            posicao += sizeof(struct Eleicao);
        }
    }
    fclose(arq_eleicao);
    return -1;
}

void alterar_eleicao()
{
    long int aux;
    unsigned long int pos;

    FILE *arq_eleicao= fopen("eleicao.bin", "rb+");
    if(arq_eleicao == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }else{
        printf("\n-----------------------------------------------\n");
        printf("Digite o ano de eleicao que deseja alterar: ");
        scanf("%ld", &aux);

        pos = posicao_eleicao(aux);

        if(aux == eleicao.ano) {
            system("cls");
            printf("\n------------------------\n");
            printf("Ano da eleicao: %ld \n", eleicao.ano);
            printf("------------------------\n");

            printf("\n------------------------\n");
            printf("Novo ano: ");
            scanf("%ld", &eleicao.ano);

            fseek(arq_eleicao, pos, SEEK_SET);
            fwrite(&eleicao, sizeof(struct Eleicao), 1, arq_eleicao);

            printf("\n------------------------\n");
            printf("   Cadastro alterado\n");
            printf("------------------------\n");
            printf("Ano da eleicao: %ld \n", eleicao.ano);
            printf("------------------------\n");
        }else{
            printf("\nAno de eleicao nao existe no sistema!\n");
            exit(1);
        }
    }
    system("pause");
    fclose(arq_eleicao);
}

void excluir_eleicao()
{
    FILE *arq_eleicao = fopen("eleicao.bin","rb+");
    FILE *novoArquivo = fopen("exclusao.bin","wb+");
    int excluido;

    printf("\n----------------------------------------------\n");
    printf("Digite o ano de eleicao que deseja excluir: ");
    scanf("%ld", &excluido);

    while((fread(&eleicao, sizeof(struct Eleicao), 1, arq_eleicao)) == 1){
        if(excluido == eleicao.ano){
            printf("\n-------- Ano de Eleicao excluido ----------\n");
        }
        else{
            fwrite(&eleicao, sizeof(struct Eleicao), 1, novoArquivo);
        }
    }
    fclose(arq_eleicao);
    fclose(novoArquivo);
    remove("eleicao.bin");
    rename("exclusao.bin", "eleicao.bin");
    system("pause");
}
/*
int menu(void)
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
    int op = menu();
    switch(op)
    {
        case 1:
            inclusao_eleicao();
            break;
        case 2:
            listar_eleicao();
            break;
        case 3:
            consultar_eleicao();
            break;
        case 4:
            alterar_eleicao();
            break;
        case 5:
            excluir_eleicao();
            break;
        default:
            break;
    }
}
*/