#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void mapa() {
    char mostrarMapa[5][5] = {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("[%c]", mostrarMapa[i][j]);
        }
        printf("\n");
    }
}

void inventario(int alterarEspaco) {
    char item1[8] = "Espada";
    char item2[9] = "Pocao";
    char item3[8] = "Escudo";
    char item4[7] = "Chave";
    char item5[6] = "Arco";
    char item6[9] = "Flechas";
    char item7[8] = "Tochas";
    char item8[7] = "Vazio";

    char* inventarioJogador[8] = {
        item1, item2, item3, item4,
        item5, item6, item7, item8
    };

    do {
        printf("\n=== SEU INVENTARIO ===\n");
        for (int i = 0; i < 8; i++) {
            printf("[%d] %s\n", i + 1, inventarioJogador[i]);
        }

        printf("\nDigite de 1 a 8 para alterar um item.\n");
        printf("Digite 9 ou 10 para voltar ao menu: ");
        scanf("%d", &alterarEspaco);
        getchar();

        if (alterarEspaco == 9 || alterarEspaco == 10) {
            break;
        }

        if (alterarEspaco >= 1 && alterarEspaco <= 8) {
            printf("Digite o nome do novo item: ");
        }

        switch (alterarEspaco) {
            case 1:
                fgets(item1, 8, stdin);
                break;
            case 2:
                fgets(item2, 9, stdin);
                break;
            case 3:
                fgets(item3, 8, stdin);
                break;
            case 4:
                fgets(item4, 7, stdin);
                break;
            case 5:
                fgets(item5, 6, stdin);
                break;
            case 6:
                fgets(item6, 9, stdin);
                break;
            case 7:
                fgets(item7, 8, stdin);
                break;
            case 8:
                fgets(item8, 7, stdin);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (alterarEspaco < 11);
}

void Menu(int selecionar) {
    while (selecionar != 2) {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Abrir Inventario\n");
        printf("2 - Sair e exibir mapa\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &selecionar);

        switch (selecionar) {
            case 1:
                inventario(selecionar);
                break;
            case 2:
                printf("Saindo do menu...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}

int main() {
    printf("Bem-vindo, Jogador!\n");

    int selecionar = 0;
    Menu(selecionar);

    printf("\n=== MAPA DO JOGO ===\n");
    mapa();

    return 0;
}
