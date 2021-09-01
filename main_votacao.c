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
struct Candidato
{
    char nome[100];
    char nome_urna[100];
    char cargo[50];
    long int numero;
    int num_voto;
}candidato;
struct Eleicao
{
    unsigned long int ano;

}eleicao;
struct Voto_nulo{
    int vt_nulo;
}voto_n;

int menu()
{
    printf("\t\tMENU\n");
    printf("----------------------------------\n");
    printf("1. REALIZAR VOTACAO\n");
    printf("2. MOSTRAR RESULTADOS DA VOTACAO\n");
    printf("0. SAIR DO SISTEMA\n");
    printf("-----------------------------------\n");
    printf("Selecione a opcao desejada: ");
}

void cabecalho_vot()
{
    printf("\n------------------------\n");
    printf("1. VOTAR NO CANDIDATO\n");
    printf("2. VOTAR NULO\n");
    printf("-------------------------\n");
    printf("Tecle a acao que deseja: ");
}

int verificar_cand(int cod)
{
    long int dist = 0;
    candidato.num_voto = 0;
    FILE *arq_candidato = fopen("candidato.bin", "rb+");
    if(arq_candidato == NULL)
    {
        printf("\nArquivo inexistente!\n");
        exit(1);
    }
    while(fread(&candidato, sizeof(struct Candidato), 1, arq_candidato) == 1){
        if(cod == candidato.numero){
            printf("\nVOCE VOTOU NO CANDIDATO %s - %ld\n", candidato.nome_urna, candidato.numero);
            candidato.num_voto += candidato.num_voto;
            fseek(arq_candidato, dist, SEEK_SET);
            fwrite(&candidato, sizeof(struct Candidato), 1, arq_candidato);
            return 1;
        }
        dist = sizeof(struct Candidato) + dist;
    }

    fclose(arq_candidato);
    system("pause");
}

unsigned long int posicao_candidato(long int aux) {
    FILE *arq_candidato = fopen("candidato.bin", "rb+");
    if (arq_candidato == NULL) {
        printf("\nErro ao abrir arquivo!\n");
        exit(1);
    } else {
        fseek(arq_candidato, 0, SEEK_SET);
        unsigned long int posicao = 0;

        while (fread(&candidato, sizeof(struct Candidato), 1, arq_candidato)) {
            if (aux == candidato.numero) {
                return posicao;
            }
            posicao += sizeof(struct Candidato);
        }
    }
    fclose(arq_candidato);
    return -1;
}

void verif_tit(long int aux)
{
    int a;
    FILE *arq_eleitor = fopen("eleitor.bin", "rb");
    if(arq_eleitor == NULL)
    {
        printf("\nErro ao abrir arquivo!\n");
    }else{
        while(fread(&eleitores, sizeof(struct Eleitores), 1, arq_eleitor)){
            if(aux == eleitores.titulo_eleitor)
            {
                printf("========================\n");
                printf(" Eleitor cadastrado!\n");
                printf(" Prossiga com seu voto\n");
                printf("========================\n");
                a = 1;
            }
        }
        if(a != 1){
            printf("========================\n");
            printf("Eleitor nao cadastrado!\n");
            printf("Voce nao podera votar!\n");
            printf("========================\n");
            exit(1);
        }
    }
    system("pause");
    fclose(arq_eleitor);
}

int nulo_voto()
{
    FILE *voto_nulo = fopen("nulo.bin", "rb+");
    if(voto_nulo == NULL)
    {
        voto_nulo = fopen("nulo.bin", "wb+");
        if(voto_nulo == NULL){
        exit(1);}
    }
    fread(&voto_n, sizeof(struct Voto_nulo), 1, voto_nulo);

    voto_n.vt_nulo += voto_n.vt_nulo;
    fseek(voto_nulo, 0, SEEK_SET);
    fwrite(&voto_n, sizeof(struct Voto_nulo), 1, voto_nulo);
    printf("\nVOTO COMPUTADO!\n");

    fclose(voto_nulo);
    return 0;
}

int main(){
    int op;
    menu();
    scanf("%d", &op);
    switch (op){
        case 1:
            system("cls");
            long int aux;
            printf("\n******************\n");
            printf("INSIRA SEU TITULO ELEITORAL (SOMENTE NUMEROS): ");
            scanf("%ld", &aux);
            verif_tit(aux);
            cabecalho_vot();
            int a;
            scanf("%d", &a);
            switch (a){
                case 1:
                    system("cls");
                    int cod;
                    printf("DIGITE O NUMERO DO CANDIDATO: ");
                    scanf("%d", &cod);
                    verificar_cand(cod);
                    main();
                case 2:
                    nulo_voto();
                    main();
                default:
                    printf("\nOpcao invalida!\n");
                    printf("Tente novamente\n");
                    main();
            }
            break;
        case 2:
            system("cls");
            FILE *arq_candidato = fopen("candidato.bin", "rb");
            if(arq_candidato == NULL){
                printf("\nERRO AO ABRIR ARQUIVO!\n");}

            FILE *voto_nulo = fopen("nulo.bin", "rb");
            if(voto_nulo == NULL){
                printf("\nERRO AO ABRIR ARQUIVO!\n");}
            while(fread(&candidato, sizeof(struct Candidato), 1, arq_candidato))
            {
                printf("Candidato %s recebeu %ld\n", candidato.nome_urna, candidato.num_voto);
            }
            while(fread(&voto_n, sizeof(struct Voto_nulo), 1, voto_nulo))
            {
                printf("VOTOS NULOS %d\n", voto_n.vt_nulo);
            }
            break;
        case 0:
            exit(1);
        default:
            printf("\nOpcao invalida\n");
            main();
            break;
    }
    system("pause");
}