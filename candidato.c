#include <stdlib.h>
#include <stdio.h>

struct Candidato
{
    char nome[100];
    char nome_urna[100];
    char cargo[50];
    int numero;
    long int num_voto;
}candidato;

void verificar_candidato(int numero)
{
    FILE *arq_candidato = fopen("candidato.bin", "rb+");
    if(arq_candidato == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }
    while(fread(&candidato, sizeof(struct Candidato), 1, arq_candidato))
    {
        if(numero == candidato.numero)
        {
            printf("\n----------------------\n");
            printf("Candidato ja cadastrado!\n");
            printf("----------------------\n");
            system("pause");
            exit(1);
        }
    }
    system("cls");
    printf("\n-----------------------------------\n");
    printf("      Prossiga o cadastro:\n");
    printf("-----------------------------------\n");
    printf("Digite o nome e sobrenome do candidato: ");
    fflush(stdin);
    gets(candidato.nome);
    printf("Digite o nome da urna: ");
    fflush(stdin);
    gets(candidato.nome_urna);
    printf("Digite o cargo do candidato: ");
    fflush(stdin);
    gets(candidato.cargo);
    candidato.numero = numero;


    fwrite(&candidato, sizeof(struct Candidato), 1, arq_candidato);

    system("cls");
    printf("---------------------------------------------------\n");
    printf("\tCadastro realizado com sucesso!\n");
    printf("---------------------------------------------------\n");
    printf("Nome completo: %s\n", candidato.nome);
    printf("Nome na Urna: %s\n", candidato.nome_urna);
    printf("Cargo: %s\n", candidato.cargo);
    printf("Numero: %d\n", candidato.numero);
    printf("---------------------------------------------------\n");
    system("pause");

    fclose(arq_candidato);
}

void inclusao_candidato()
{
    int numero;
    FILE *arq_candidato = fopen("candidato.bin", "ab");
    if (arq_candidato == NULL){
        printf("Erro ao abrir arquivo");
        return;
    }
    system("cls");
    printf("\n-----------------------------------\n");
    printf("Digite seu numero do candidato: ");
    scanf("%d",&numero);

    verificar_candidato(numero);

    fclose(arq_candidato);
}
void listar_candidato()
{
    FILE *arq_candidato = fopen("candidato.bin", "rb");
    if (arq_candidato == NULL){
        printf("\nArquivo inexistente!");
        return;
    }

    while((fread(&candidato, sizeof(struct Candidato), 1, arq_candidato))==1)
    {
        printf("\n---------------------------------------------------\n");
        printf("Nome completo: %s\n", candidato.nome);
        printf("Nome na Urna: %s\n", candidato.nome_urna);
        printf("Cargo: %s\n", candidato.cargo);
        printf("Numero: %d\n", candidato.numero);
        printf("---------------------------------------------------\n");
    }
    system("pause");
    fclose(arq_candidato);
}

void consultar_candidato()
{
    int aux;
    FILE *arq_candidato = fopen("candidato.bin", "rb");
    if(arq_candidato == NULL)
    {
        printf("\nArquivo inexistente!\n");
        return;
    }else{
        printf("\n--------------------------------------------\n");
        printf("Digite o numero do candidato que procura: ");
        scanf("%d",&aux);

        while (fread(&candidato, sizeof(struct Candidato), 1, arq_candidato)){
            if (aux == candidato.numero){
                printf("\n------------------------\n");
                printf("Nome completo: %s\n", candidato.nome);
                printf("Nome na Urna: %s\n", candidato.nome_urna);
                printf("Cargo: %s\n", candidato.cargo);
                printf("Numero: %d\n", candidato.numero);
                printf("------------------------\n");
                aux = 1;
            }
        }
        if(aux != 1)
        {
            printf("\n------------------------\n");
            printf("Candidato nao cadastrado!\n");
            printf("--------------------------\n");
        }
    }
    system("pause");
    fclose(arq_candidato);
}

unsigned long int posicao_candidato(long int aux)
{
    FILE *arq_candidato = fopen("candidato.bin", "rb+");
    if(arq_candidato == NULL)
    {
        printf("\nErro ao abrir arquivo!\n");
        exit(1);
    }else{
        fseek(arq_candidato, 0, SEEK_SET);
        unsigned long int posicao = 0;

        while(fread(&candidato, sizeof(struct Candidato), 1, arq_candidato))
        {
            if(aux == candidato.numero)
            {
                return posicao;
            }
            posicao += sizeof(struct Candidato);
        }
    }
    fclose(arq_candidato);
    return -1;
}

void alterar_candidato()
{
    long int aux;
    FILE *arq_candidato = fopen("candidato.bin", "rb+");
    if(arq_candidato == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }else{
        printf("\n--------------------------------------\n");
        printf("Digite o numero do candidato que deseja alterar: ");
        scanf("%ld", &aux);

        unsigned long int pos = posicao_candidato(aux);

        if(aux == candidato.numero) {
            system("cls");
            printf("\n---------------------------------------------------\n");
            printf("Nome completo: %s\n", candidato.nome);
            printf("Nome na Urna: %s\n", candidato.nome_urna);
            printf("Cargo: %s\n", candidato.cargo);
            printf("Numero: %d\n", candidato.numero);
            printf("---------------------------------------------------\n");

            printf("\n---------------------------------------------------\n");
            printf("Novo nome completo: ");
            fflush(stdin);
            gets(candidato.nome);
            printf("Novo nome na Urna: ");
            fflush(stdin);
            gets(candidato.nome_urna);
            printf("Novo cargo: ");
            fflush(stdin);
            gets(candidato.cargo);
            printf("Novo numero:");
            scanf("%d", &candidato.numero);

            fseek(arq_candidato, pos, SEEK_SET);
            fwrite(&candidato, sizeof(struct Candidato), 1, arq_candidato);

            printf("\n---------------------------------------------------\n");
            printf("   Cadastro alterado\n");
            printf("---------------------------------------------------\n");
            printf("Nome completo: %s\n", candidato.nome);
            printf("Nome na Urna: %s\n", candidato.nome_urna);
            printf("Cargo: %s\n", candidato.cargo);
            printf("Numero: %d\n", candidato.numero);
            printf("---------------------------------------------------\n");
        }else{
            printf("\nCandidato nao existe no sistema!\n");
            exit(1);
        }

    }
    system("pause");
    fclose(arq_candidato);
}

//Não está excluindo o primeiro cadastro, como se a struct não ler
void excluir_candidato()
{
    FILE* arq_partido = fopen("candidato.bin","rb+");
    FILE* novoArquivo = fopen("exclusao.bin","wb+");
    int excluido;

    printf("Digite o numero do candidato que deseja excluir: ");
    scanf("%d",&excluido);

    while((fread(&candidato, sizeof(struct Candidato), 1, arq_partido)) == 1){
        if(excluido == candidato.numero){
            printf("\n-------- Candidato excluido ----------\n");
            printf("Nome completo: %s\n", candidato.nome);
            printf("Nome na Urna: %s\n", candidato.nome_urna);
            printf("Cargo: %s\n", candidato.cargo);
            printf("Numero: %d\n", candidato.numero);
            printf("---------------------------------------------------\n");
        }
        else{
            fwrite(&candidato, sizeof(struct Candidato), 1, novoArquivo);
        }
    }
    fclose(arq_partido);
    fclose(novoArquivo);
    remove("candidato.bin");
    rename("exclusao.bin", "candidato.bin");
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
    int op = menu();
    switch(op)
    {
        case 1:
            inclusao_candidato();
            break;
        case 2:
            listar_candidato();
            break;
        case 3:
            consultar_candidato();
            break;
        case 4:
            alterar_candidato();
            break;
        case 5:
            excluir_candidato();
            break;
        default:
            break;
    }
    return 0;
}
*/