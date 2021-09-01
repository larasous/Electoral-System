#include <stdio.h>
#include <stdlib.h>

struct Secao
{
    long int num_secao;
    char local_votacao[100];
    char endereco_votacao[100];
    char bairro_votacao[100];
    long int cep_votacao;
}secao;

void verificar_secao(long int aux)
{
    FILE *arq_secao = fopen("secao.bin", "rb+");
    if (arq_secao == NULL){
        printf("\nArquivo inexistente!\n");
        exit(1);
    }
    fseek(arq_secao, 0, SEEK_SET);
    while(fread(&secao, sizeof(struct Secao), 1, arq_secao))
    {
        if(aux == secao.num_secao)
        {
            printf("\n-----------------------\n");
            printf("Secao ja cadastrada!\n");
            printf("-----------------------\n");
            system("pause");
            exit(1);

        }
    }
    system("cls");
    printf("\n-----------------------------------\n");
    printf("      Prossiga o cadastro:\n");
    printf("-----------------------------------\n");
    secao.num_secao = aux;
    printf("Digite o nome da escola/local de votacao: ");
    fflush(stdin);
    gets(secao.local_votacao);
    printf("Digite o bairro de votacao: ");
    fflush(stdin);
    gets(secao.bairro_votacao);
    printf("Digite o CEP do local de votacao: ");
    scanf("%ld", &secao.cep_votacao);
    printf("Digite o endereco de votacao: ");
    fflush(stdin);
    gets(secao.endereco_votacao);

    fseek(arq_secao, 0, SEEK_END);
    fwrite(&secao, sizeof(struct Secao), 1, arq_secao);

    printf("---------------------------------------------------\n");
    printf("\tCadastro realizado com sucesso!\n");
    printf("---------------------------------------------------\n");
    printf("Secao: %ld\n", secao.num_secao);
    printf("Local de votacao: %s\n", secao.local_votacao);
    printf("Endereco de votacao: %s\n", secao.endereco_votacao);
    printf("Bairro: %s\n", secao.bairro_votacao);
    printf("CEP: %ld\n", secao.cep_votacao);
    printf("---------------------------------------------------\n");

    system("pause");
    fclose(arq_secao);
}

void inclusao_secao()
{
    long int aux;
    FILE *arq_secao = fopen("secao.bin", "ab");
    if (arq_secao == NULL){
        printf("Erro ao abrir arquivo");
        return;
    }
    printf("\n-----------------------------\n");
    printf("Digite o numero da secao: ");
    scanf("%ld", &aux);

    verificar_secao(aux);

    fclose(arq_secao);
}
void listar_secao()
{
    FILE *arq_secao = fopen("secao.bin", "rb");
    if (arq_secao == NULL){
        printf("\nArquivo inexistente!");
        return;
    }

    while(fread(&secao, sizeof(struct Secao), 1, arq_secao))
    {
        printf("\n---------------------------------------------------\n");
        printf("Secao: %ld\n", secao.num_secao);
        printf("Local de votacao: %s\n", secao.local_votacao);
        printf("Endereco de votacao: %s\n", secao.endereco_votacao);
        printf("Bairro: %s\n", secao.bairro_votacao);
        printf("CEP: %ld\n", secao.cep_votacao);
        printf("---------------------------------------------------\n");
    }
    system("pause");
    fclose(arq_secao);
}

void consultar_secao()
{
    long int aux, num = 0;

    FILE *arq_secao = fopen("secao.bin", "rb");
    if(arq_secao == NULL)
    {
        printf("Arquivo inexistente!\n");
        exit(1);
    }else {
        printf("\n-----------------------------------------\n");
        printf("Digite o numero da secao que procura: ");
        scanf("%ld", &num);

        while (fread(&secao, sizeof(struct Secao), 1, arq_secao))
        {
            if (num == secao.num_secao)
            {
                printf("\n---------------------------------------------------\n");
                printf("Secao: %ld\n", secao.num_secao);
                printf("Local de votacao: %s\n", secao.local_votacao);
                printf("Endereco de votacao: %s\n", secao.endereco_votacao);
                printf("Bairro: %s\n", secao.bairro_votacao);
                printf("CEP: %ld\n", secao.cep_votacao);
                printf("---------------------------------------------------\n");
                aux = 1;
            }
        }
        if(aux != 1)
        {
            printf("\n------------------------\n");
            printf("Secao nao cadastrada!\n");
            printf("------------------------\n");
        }
    }
    system("pause");
    fclose(arq_secao);
}

unsigned long int posicao_secao(long int aux)
{
    FILE *arq_secao = fopen("secao.bin", "rb+");
    if(arq_secao == NULL)
    {
        printf("\nErro ao abrir arquivo!\n");
        exit(1);
    }else{
        fseek(arq_secao, 0, SEEK_SET);
        unsigned long posicao = 0;

        while(fread(&secao, sizeof(struct Secao), 1, arq_secao))
        {
            if(aux == secao.num_secao)
            {
                return posicao;
            }
            posicao += sizeof(struct Secao);
        }
    }
    fclose(arq_secao);
    return -1;
}

void alterar_secao()
{
    long int aux;
    FILE *arq_secao= fopen("secao.bin", "rb+");
    if(arq_secao == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }else{
        printf("\n-----------------------------------\n");
        printf("Digite a secao que deseja alterar: ");
        scanf("%ld", &aux);

        unsigned long int pos = posicao_secao(aux);

        if(aux == secao.num_secao) {
            system("cls");
            printf("\n---------------------------------------------------\n");
            printf("Secao: %ld\n", secao.num_secao);
            printf("Local de votacao: %s\n", secao.local_votacao);
            printf("Endereco de votacao: %s\n", secao.endereco_votacao);
            printf("Bairro: %s\n", secao.bairro_votacao);
            printf("CEP: %ld\n", secao.cep_votacao);
            printf("---------------------------------------------------\n");

            printf("\n---------------------------------------------------\n");;
            printf("Novo numero da secao: ");
            scanf("%ld", &secao.num_secao);
            printf("Novo local de votacao: ");
            fflush(stdin);
            gets(secao.local_votacao);
            printf("Novo endereco de votacao: ");
            fflush(stdin);
            gets(secao.endereco_votacao);
            printf("Novo bairro: ");
            fflush(stdin);
            gets(secao.bairro_votacao);
            printf("Novo CEP: ");
            scanf("%ld", &secao.cep_votacao);

            fseek(arq_secao, pos, SEEK_SET);
            fwrite(&secao, sizeof(struct Secao), 1, arq_secao);

            printf("\n---------------------------------------------------\n");
            printf("\tCadastro alterado\n");
            printf("---------------------------------------------------\n");
            printf("Secao: %ld\n", secao.num_secao);
            printf("Local de votacao: %s\n", secao.local_votacao);
            printf("Endereco de votacao: %s\n", secao.endereco_votacao);
            printf("Bairro: %s\n", secao.bairro_votacao);
            printf("CEP: %ld\n", secao.cep_votacao);
            printf("---------------------------------------------------\n");
        }else{
            printf("\nSecao nao existe no sistema!\n");
            exit(1);
        }
    }
    system("pause");
    fclose(arq_secao);
}

void excluir_secao()
{
    FILE* arq_secao = fopen("secao.bin","rb+");
    FILE* novoArquivo = fopen("exclusao.bin","wb+");
    int excluido;

    printf("\n------------------------------------\n");
    printf("Digite a secao que deseja excluir: ");
    scanf("%ld", &excluido);

    while((fread(&secao, sizeof(struct Secao), 1, arq_secao)) == 1){
        if(excluido == secao.num_secao){
            printf("\n------------ Secao excluida ------------\n");
            printf("\n----------------------------------------\n");
            printf("Secao: %ld\n", secao.num_secao);
            printf("Local de votacao: %s\n", secao.local_votacao);
            printf("Endereco de votacao: %s\n", secao.endereco_votacao);
            printf("Bairro: %s\n", secao.bairro_votacao);
            printf("CEP: %ld\n", secao.cep_votacao);
            printf("\n----------------------------------------\n");
        }
        else{
            fwrite(&secao, sizeof(struct Secao), 1, novoArquivo);
        }
    }
    fclose(arq_secao);
    fclose(novoArquivo);
    remove("secao.bin");
    rename("exclusao.bin", "secao.bin");
    system("pause");
}

/*
int menu()
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
            inclusao_secao();
            break;
        case 2:
            listar_secao();
            break;
        case 3:
            consultar_secao();
            break;
        case 4:
            alterar_secao();
            break;
        case 5:
            excluir_secao();
            break;
        default:
            break;
    }
}
*/