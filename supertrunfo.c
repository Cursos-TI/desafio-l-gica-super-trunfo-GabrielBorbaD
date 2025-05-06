#include <stdio.h>
#include <string.h>

struct CartaCidade {
    char estado[50];
    char codigo[20];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

void calcularDados(struct CartaCidade *cidade) {
    cidade->densidadePopulacional = cidade->populacao / cidade->area;
    cidade->pibPerCapita = cidade->pib / cidade->populacao;
}

void exibirCarta(struct CartaCidade cidade) {
    printf("Cidade: %s (%s)\n", cidade.nome, cidade.estado);
    printf("Código: %s\n", cidade.codigo);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: R$ %.2f\n", cidade.pib);
    printf("Pontos Turísticos: %d\n", cidade.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n\n", cidade.pibPerCapita);
}

int main() {
    struct CartaCidade carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    printf("Estado: ");
    fgets(carta1.estado, sizeof(carta1.estado), stdin);
    carta1.estado[strcspn(carta1.estado, "\n")] = '\0';

