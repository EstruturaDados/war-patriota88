#include <stdio.h>
#include <string.h>

// Definição da estrutura (ficha cadastral do território)
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    // Vetor estático: reserva espaço para exatamente 5 territórios na memória
    struct Territorio mapa[5]; 

    printf("--- CADASTRO DE TERRITORIOS (NOVATO) ---\n");

    for (int i = 0; i < 5; i++) {
        printf("\nTerritorio %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", mapa[i].nome); // Salva o texto no campo 'nome' da struct
        printf("Cor do Exercito: ");
        scanf("%s", mapa[i].cor);
        printf("Tropas: ");
        scanf("%d", &mapa[i].tropas); // O '&' é necessário para salvar o número no endereço de 'tropas'
    }

    // Exibição simples percorrendo o vetor
    printf("\n--- ESTADO DO MAPA ---\n");
    for (int i = 0; i < 5; i++) {
        printf("%s [%s] - %d tropas\n", mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }

    return 0;
}