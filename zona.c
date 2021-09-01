#include <stdio.h>
#include <stdlib.h>

struct Zona
{
    long int zona_num;
    char endereco[200];
    long int cep;
    char bairro[50];
    long int total_zona;
}zona;


void verificar_zona(long int aux)
{
    FILE *arq_zona = fopen("zona.bin", "rb+");
    if (arq_zona == NULL){
        printf("\nArquivo inexistente!\n");
        exit(1);
    }
    while(fread(&zona, sizeof(struct Zona), 1, arq_zona))
    {
        if(aux == zona.zona_num)
        {
            printf("\n-----------------------\n");
            printf("Zona ja cadastrada!\n");
            printf("-----------------------\n");
            system("pause");
            exit(1);

        }
    }
    system("cls");
    printf("\n-----------------------------------\n");
    printf("      Prossiga o cadastro:\n");
    printf("-----------------------------------\n");
    printf("Digite o total de zonas da zona: ");
    scanf("%ld", &zona.total_zona);
    printf("Digite o endereco da zona: ");
    fflush(stdin);
    gets(zona.endereco);
    printf("Digite o bairro de zona: ");
    fflush(stdin);
    gets(zona.bairro);
    printf("Digite o cep da zona: ");
    scanf("%ld", &zona.cep);
    zona.zona_num = aux;

    fwrite(&zona, sizeof(struct Zona), 1, arq_zona);

    printf("\n---------------------------------------------------\n");
    printf("\tCadastro realizado com sucesso!\n");
    printf("---------------------------------------------------\n");
    printf("Zona: %ld\n", zona.zona_num);
    printf("Totais de zonas: %ld\n", zona.total_zona);
    printf("Endereco: %s\n", zona.endereco);
    printf("CEP: %ld\n", zona.cep);
    printf("Bairro: %s\n", zona.bairro);
    printf("---------------------------------------------------\n");

    system("pause");
    fclose(arq_zona);
}

void inclusao_zona()
{
    long int aux;
    FILE *arq_zona = fopen("zona.bin", "ab");
    if (arq_zona == NULL){
        printf("Erro ao abrir arquivo");
        return;
    }
    printf("\n-----------------------------\n");
    printf("Digite o numero da zona: ");
    scanf("%ld", &aux);

    verificar_zona(aux);

    fclose(arq_zona);
}

void listar_zona() // mostrar todos os municipios cadastrados
{
    FILE *arq_zona = fopen("zona.bin", "rb");
    if (arq_zona == NULL){
        printf("\nArquivo inexistente!");
        return;
    }

    while(fread(&zona, sizeof(struct Zona), 1, arq_zona))
    {
        printf("\n------------------------\n");
        printf("Zona: %ld\n", zona.zona_num);
        printf("Totais de zonas: %ld\n", zona.total_zona);
        printf("Endereco: %s\n", zona.endereco);
        printf("CEP: %ld\n", zona.cep);
        printf("Bairro: %s\n", zona.bairro);
        printf("------------------------\n");
    }
    system("pause");
    fclose(arq_zona);
}

void consultar_zona()
{
    int num = 0, aux;

    FILE *arq_zona = fopen("zona.bin", "rb");
    if(arq_zona == NULL)
    {
        printf("Arquivo inexistente!\n");
        exit(1);
    }else{
        printf("-----------------------------------\n");
        printf("Digite o numero da zona que deseja: ");
        scanf("%d", &num);

        while(fread(&zona, sizeof(struct Zona), 1, arq_zona))
        {
            if (num == zona.zona_num){
                printf("\n---------------------------------------------------\n");
                printf("Zona: %ld\n", zona.zona_num);
                printf("Totais de zonas: %ld\n", zona.total_zona);
                printf("Endereco: %s\n", zona.endereco);
                printf("CEP: %ld\n", zona.cep);
                printf("Bairro: %s\n", zona.bairro);
                printf("---------------------------------------------------\n");
                aux = 1;
            }
        }
        if(aux != 1)
        {
            printf("\n-------------------------\n");
            printf("Zona nao cadastrada\n");
            printf("--------------------------\n");
        }
    }
    system("pause");
    fclose(arq_zona);
}

unsigned long int posicao_zona(long int aux)
{
    FILE *arq_zona = fopen("zona.bin", "rb+");
    if(arq_zona == NULL)
    {
        printf("\nErro ao abrir arquivo!\n");
        exit(1);
    }else{
        fseek(arq_zona, 0, SEEK_SET);
        unsigned long int posicao = 0;

        while(fread(&zona, sizeof(struct Zona), 1, arq_zona))
        {
            if(aux == zona.zona_num)
            {
                return posicao;
            }
            posicao += sizeof(struct Zona);
        }
    }
    fclose(arq_zona);
    return -1;
}

void alterar_zona()
{
    long int aux;
    FILE *arq_zona = fopen("zona.bin", "rb+");
    if(arq_zona == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }else{
        printf("\n--------------------------------------\n");
        printf("Digite a zona que deseja alterar: ");
        scanf("%ld", &aux);

        unsigned long int pos = posicao_zona(aux);

        if(aux == zona.zona_num) {
            system("cls");
            printf("\n---------------------------------------------------\n");
            printf("Zona: %ld\n", zona.zona_num);
            printf("Totais de zonas: %ld\n", zona.total_zona);
            printf("Endereco: %s\n", zona.endereco);
            printf("CEP: %ld\n", zona.cep);
            printf("Bairro: %s\n", zona.bairro);
            printf("---------------------------------------------------\n");

            printf("\n---------------------------------------------------\n");
            printf("Nova zona: ");
            scanf("%ld", &zona.zona_num);
            printf("Novo total de zonas: ");
            scanf("%ld", &zona.total_zona);
            printf("Novo endereco: ");
            fflush(stdin);
            gets(zona.endereco);
            printf("Novo bairro: ");
            fflush(stdin);
            gets(zona.bairro);
            printf("Novo CEP: ");
            scanf("%ld", &zona.cep);

            fseek(arq_zona, pos, SEEK_SET);
            fwrite(&zona, sizeof(struct Zona), 1, arq_zona);

            printf("\n---------------------------------------------------\n");
            printf("   Cadastro alterado\n");
            printf("---------------------------------------------------\n");
            printf("Zona: %ld\n", zona.zona_num);
            printf("Totais de zonas: %ld\n", zona.total_zona);
            printf("Endereco: %s\n", zona.endereco);
            printf("CEP: %ld\n", zona.cep);
            printf("Bairro: %s\n", zona.bairro);
            printf("---------------------------------------------------\n");
        }else{
            printf("\nZona nao existe no sistema!\n");
            exit(1);
        }

    }
    system("pause");
    fclose(arq_zona);
}

void excluir_zona()
{
    FILE* arq_zona = fopen("zona.bin","rb+");
    FILE* novoArquivo = fopen("exclusao.bin","wb+");
    int excluido;

    printf("Digite a zona que deseja excluir: ");
    scanf("%d", &excluido);

    while((fread(&zona, sizeof(struct Zona), 1, arq_zona)) == 1){
        if(excluido == zona.zona_num){
            printf("\n-------- Zona excluida ----------\n");
            printf("------------------------------------\n");
            printf("Zona: %ld\n", zona.zona_num);
            printf("Totais de zonas: %ld\n", zona.total_zona);
            printf("Endereco: %s\n", zona.endereco);
            printf("CEP: %ld\n", zona.cep);
            printf("Bairro: %s\n", zona.bairro);
            printf("------------------------------------\n");
        }
        else{
            fwrite(&zona, sizeof(struct Zona), 1, novoArquivo);
        }
    }
    fclose(arq_zona);
    fclose(novoArquivo);
    remove("zona.bin");
    rename("exclusao.bin", "zona.bin");
}

/*
 int menu() // menu CRUD
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
            inclusao_zona();
            break;
        case 2:
            listar_zona();
            break;
        case 3:
            consultar_zona();
            break;
        case 4:
            alterar_zona();
            break;
        case 5:
            excluir_zona();
            break;
        default:
            break;
    }
}
*/