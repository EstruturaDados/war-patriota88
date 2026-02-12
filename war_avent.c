#include <stdio.h>
#include <stdlib.h> // Necessária para calloc e free
#include <time.h>   // Necessária para o rand()

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função de ataque: usa ponteiros (*) para alterar os dados originais na memória
void atacar(Territorio* atq, Territorio* def) {
    int dadoAtq = (rand() % 6) + 1; // Sorteia de 1 a 6
    int dadoDef = (rand() % 6) + 1;

    printf("\nDado Atacante: %d | Dado Defensor: %d\n", dadoAtq, dadoDef);

    if (dadoAtq >= dadoDef) { // Empate favorece atacante (regra do desafio)
        printf("Atacante venceu o combate!\n");
        def->tropas--; // Altera o valor original através do ponteiro
        
        if (def->tropas <= 0) {
            printf("TERRITORIO CONQUISTADO! %s agora e %s.\n", def->nome, atq->cor);
            sprintf(def->cor, "%s", atq->cor); // Atualiza a cor do dono
            def->tropas = 1; // Inicia com 1 tropa da conquista
        }
    } else {
        printf("Defesa resistiu!\n");
    }
}

int main() {
    srand(time(NULL)); // Alimenta a semente do sorteio
    
    // Alocação Dinâmica: reserva memória apenas para o que o usuário pedir
    Territorio* mapa = (Territorio*) calloc(5, sizeof(Territorio));

    // ... (Cadastro igual ao nível novato, mas usando mapa[i]) ...

    int a, d;
    printf("\nEscolha o ID do atacante (0-4) e defensor (0-4): ");
    scanf("%d %d", &a, &d);

    atacar(&mapa[a], &mapa[d]); // '&' passa o ENDEREÇO para o ponteiro da função

    free(mapa); // REQUISITO: Devolve a memória ao sistema
    return 0;
}