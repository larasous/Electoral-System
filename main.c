#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*---------incluindo os arquivos--------*/
#include "estado.c"
#include "municipio.c"
#include "candidato.c"
#include "partido.c"
#include "zona.c"
#include "eleitor.c"
#include "secao.c"
#include "eleicao.c"

void cabecalho(){
    int aux = 0;
    system("color F0");
    system("cls");

    printf("---------------------------------------------------\n");
    printf("----------- Bem vindo(a) ao sistema! --------------\n");
    printf("---------------------------------------------------\n");
    printf("------ Selecione a opcao que deseja acessar: ------\n");
    printf("---------------------------------------------------\n");
    printf("1 - UFs\n");
    printf("2 - Municipios\n");
    printf("3 - Zonas Eleitorais\n");
    printf("4 - Sessoes Eleitorais\n");
    printf("5 - Eleitores\n");
    printf("6 - Eleicao\n");
    printf("7 - Partidos\n");
    printf("8 - Candidatos\n");
    printf("9 - Sair do programa\n");
    printf("----------------------------------------------------\n");
    printf("-> Qual opcao deseja acessar?\n");
}

int menu (void){
    int opcao;
    do {
        printf("-------------- MENU --------------\n");
        printf("1. Incluir\n");
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

int main(void) {
    int op = 0;
    int aux = 0;
    do {
        cabecalho();
        scanf("%d", &aux);
        switch (aux) {
            case 1: // cadastro de UFs
                system("cls");
                do {
                    op = menu();
                    switch (op) {
                        case 1:
                            printf("Cadastrar UFs\n");
                            inclusao_estado();
                            break;
                        case 2:
                            printf("Listar UFs\n");
                            listar_estado();
                            break;
                        case 3:
                            printf("Consultar UFs\n");
                            consultar_estado();
                            break;
                        case 4:
                            printf("Alterar UFs\n");
                            alterar_estado();
                            break;
                        case 5:
                            printf("Excluir UFs\n");
                            excluir_estado();
                            break;
                        case 6:
                            system("cls");
                            return main();
                            break;
                        default:
                            system("color F4");
                            printf("Opcao invalida!\n");
                            break;
                    }
                } while (op != 0);
                {
                    system("pause");
                    return 0;
                }
            case 2:
                system("cls");
                do {
                    op = menu();
                    switch (op) {
                        case 1:
                            printf("Cadastrar Municipios\n");
                            inclusao_municipio();
                            break;
                        case 2:
                            printf("Listar Municipios\n");
                            listar_municipio();
                            break;
                        case 3:
                            printf("Consultar Municipios\n");
                            consultar_municipio();
                            break;
                        case 4:
                            printf("Alterar Municipios\n");
                            alterar_municipio();
                            break;
                        case 5:
                            printf("Excluir Municipios\n");
                            excluir_municipio();
                            break;
                        case 6:
                            system("cls");
                            return main();
                    }
                } while (op != 0);
                {
                    system("pause");
                    return 0;
                }
            case 3:
                system("cls");
                do {
                    op = menu();
                    switch (op) {
                        case 1:
                            printf("Cadastrar Zonas \n");
                            inclusao_zona();
                            break;
                        case 2:
                            printf("Listar Zonas \n");
                            listar_zona();
                            break;
                        case 3:
                            printf("Consultar Zonas \n");
                            consultar_zona();
                            break;
                        case 4:
                            printf("Alterar Zonas \n");
                            alterar_zona();
                            break;
                        case 5:
                            printf("Excluir Zonas \n");
                            excluir_zona();
                            break;
                        case 6:
                            system("cls");
                            return main();
                    }
                } while (op != 0);
                {
                    system("pause");
                    return 0;
                }
            case 4:
                system("cls");
                do {
                    op = menu();
                    switch (op) { //Crud de Sessoes Eleitorais
                        case 1:
                            printf("Cadastrar Sessoes \n");
                            inclusao_secao();
                            break;
                        case 2:
                            printf("Listar Sessoes \n");
                            listar_secao();
                            break;
                        case 3:
                            printf("Consultar Sessoes \n");
                            consultar_secao();
                            break;
                        case 4:
                            printf("Alterar Sessoes \n");
                            alterar_secao();
                            break;
                        case 5:
                            printf("Excluir Sessoes \n");
                            excluir_secao();
                            break;
                        case 6:
                            system("cls");
                            return main();
                    }
                } while (op != 0);
                {
                    system("pause");
                    return 0;
                }
            case 5:
                system("cls");
                do {
                    op = menu();
                    switch (op) { // Crud Eleitores
                        case 1:
                            printf("Cadastrar Eleitores\n");
                            inclusao_eleitor();
                            break;
                        case 2:
                            printf("Listar Eleitores\n");
                            listar_eleitor();
                            break;
                        case 3:
                            printf("Consultar Eleitores\n");
                            consultar_eleitor();
                            break;
                        case 4:
                            printf("Alterar Eleitores\n");
                            alterar_eleitor();
                            break;
                        case 5:
                            printf("Excluir Eleitores\n");
                            excluir_eleitor();
                            break;
                        case 6:
                            system("cls");
                            return main();
                    }
                } while (op != 0);
                {
                    system("pause");
                    return 0;
                }
            case 6:
                system("cls");
                do {
                    op = menu();
                    switch (op) { // Crud Eleicao
                        case 1:
                            printf("Cadastrar Eleicao\n");
                            inclusao_eleicao();
                            break;

                        case 2:
                            printf("Listar Eleicao\n");
                            listar_eleicao();
                            break;
                        case 3:
                            printf("Consultar Eleicao\n");
                            consultar_eleicao();
                            break;
                        case 4:
                            printf("Alterar Eleicao\n");
                            alterar_eleicao();
                            break;
                        case 5:
                            printf("Excluir Eleicao\n");
                            excluir_eleicao();
                            break;
                        case 6:
                            system("cls");
                            return main();
                    }
                } while (op != 0);
                {
                    system("pause");
                    return 0;
                }
            case 7:
                system("cls");
                do {
                    op = menu();
                    switch (op) {  //Crud Partidos
                        case 1:
                            printf("Cadastrar Partidos \n");
                            inclusao_partido();
                            break;
                        case 2:
                            printf("Listar Partidos \n");
                            listar_partido();
                            break;
                        case 3:
                            printf("Consultar Partidos \n");
                            consultar_partido();
                            break;
                        case 4:
                            printf("Alterar Partidos \n");
                            alterar_partido();
                            break;
                        case 5:
                            printf("Excluir Partidos \n");
                            excluir_partido();
                            break;
                        case 6:
                            system("cls");
                            return main();
                    }
                } while (op != 0);
                {
                    system("pause");
                    return 0;
                }
            case 8:
                system("cls");
                do {
                    op = menu();
                    switch (op) {  //Crud Candidatos
                        case 1:
                            printf("Cadastrar Candidatos\n");
                            inclusao_candidato();
                            break;
                        case 2:
                            printf("Listar Candidatos\n");
                            listar_candidato();
                            break;
                        case 3:
                            printf("Consultar Candidatos\n");
                            consultar_candidato();
                            break;
                        case 4:
                            printf("Alterar Candidatos\n");
                            alterar_candidato();
                            break;
                        case 5:
                            printf("Excluir Candidatos\n");
                            excluir_candidato();
                            break;
                        case 6:
                            system("cls");
                            return main();
                    }
                } while (op != 0);
                {
                    system("pause");
                    return 0;
                }
            case 9:
                system("cls");
                do {
                    op = menu();
                    switch (op) {
                        case 1:
                            break;
                    }
                } while (op != 0);
                {
                    system("pause");
                    return 0;
                }
        }
    }while (op != 0);
}

