#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// --- FUNÇOES MODULARES ---

// 'const' indica que esta funçao apenas LE o mapa, nao o altera (Segurança)
void exibirMapa(const Territorio* mapa, int n) {
    printf("\nID\tNOME\t\tCOR\t\tTropas\n");
    for(int i=0; i<n; i++)
        printf("[%d]\t%-10s\t%d\n", i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);        
}

// Verificar vitoria com base na missao sorteada
int checarMissao(const Territorio* mapa, int missaoID, char* minhaCor) {
    int cont = 0;
    if (missaoID == 0) {// Missao: 3 terrritorios
        for(int i=0; i<5; i++)
        if(strcmp(mapa[i].cor, minhaCor) == 0) cont ++;
        return (cont >= 3);
        }
        // Outras missoes seriao add aqui...
        return 0;
}

int main() {
    srand(time(NULL));
    Territorio* mapa = (Territorio*) calloc(5, sizeof(Territorio));
    int missao = rand() % 2; // 0 ou 1
    int opcao;

    strcpy(mapa[0].nome, "Brasil"); strcpy(mapa[0].cor, "Verde"); mapa[0].tropas = 5;

    do {
        printf("\n1. Atacar | 2. Ver Missao | 0. Sair\nEscolha: ");
        scanf("%d", &opcao);
        
        if (opcao == 1) {
        void atacar(Territorio* atq, Territorio* def) {
            int dadoAtq = (rand() % 6) + 1;
            int dadoDef = (rand() % 6) + 1;

            printf("\nDado Atacante: %d | Dado Defensor: %d\n", dadoAtq, dadoDef);

            if (dadoAtq >= dadoDef) {
                printf("Atacante venceu o combate!\n");
                def->tropas--;

                if (def->tropas <= 0) {
                    printf("TERRITORIO CONQUISTADO! %s agora e %s.\n", def->nome, atq->cor);
                    sprintf(def->cor, "%s", atq->cor);
                    def->tropas = 1;
                } else if (opcao == 2) {
                    if (checarMissao(mapa, missao, "Verde")) printf("VOCE VENCEU O JOGO!\n");\
                    else printf("MISSAO AINDA NAO ACABOU.\n");
                }            
            }
        }    
        }
    } while (opcao != 0);
    
    free(mapa);
    return 0;
    
}