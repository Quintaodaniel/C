// Score Tracker System
// Trains: file I/O, pointer usage, basic menu
// Functions: initialize_score, display_score, save_history, display_history, play_game
// Features: track scores for 2 players, save results to a history file, display history of games
// Max: unlimited game results saved (limited only by available storage)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializa_placar(int *p1, int *p2) {
    *p1 = 0;
    *p2 = 0;
}

void exibe_placar(int p1, int p2) {
    printf("\nPlacar atual:\nJogador 1: %d | Jogador 2: %d\n", p1, p2);
}

void salva_historico(int p1, int p2) {
    FILE *f = fopen("historico.txt", "a");
    if (f) {
        fprintf(f, "Resultado: Jogador1 = %d, Jogador2 = %d\n", p1, p2);
        fclose(f);
    } else {
        printf("Erro ao abrir o arquivo!\n");
    }
}

void exibe_historico() {
    FILE *f = fopen("historico.txt", "r");
    if (!f) {
        printf("\nNenhum histórico encontrado.\n");
        return;
    }
    printf("\n-- HISTÓRICO --\n");
    char linha[100];
    while (fgets(linha, sizeof(linha), f))
        printf("%s", linha);
    fclose(f);
}

void joga() {
    int p1, p2, ponto;
    inicializa_placar(&p1, &p2);

    while (1) {
        exibe_placar(p1, p2);
        printf("\nQuem marcou?\n[1] Jogador 1\n[2] Jogador 2\n[0] Finalizar\n> ");
        scanf("%d", &ponto);

        if (ponto == 0) {
            salva_historico(p1, p2);
            printf("Jogo finalizado e registrado!\n");
            break;
        } else if (ponto == 1) {
            p1++;
        } else if (ponto == 2) {
            p2++;
        } else {
            printf("Opção inválida, tente de novo!\n");
        }
    }
}

int main() {
    int escolha;

    while (1) {
        printf("\n--- MENU ---\n");
        puts("[1] Começar um novo jogo");
        puts("[2] Ver histórico");
        puts("[0] Encerrar programa");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                joga();
                break;

            case 2:
                exibe_historico();
                break;

            case 0:
                printf("Encerrando programa...\n");
                exit(0);

            default:
                printf("Opção inválida, tente de novo!\n");
                break;
        }
    }

    return 0;
}
