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

    printf("Código da Carta: ");
    fgets(carta1.codigo, sizeof(carta1.codigo), stdin);
    carta1.codigo[strcspn(carta1.codigo, "\n")] = '\0';

    printf("Nome da Cidade: ");
    fgets(carta1.nome, sizeof(carta1.nome), stdin);
    carta1.nome[strcspn(carta1.nome, "\n")] = '\0';

    printf("População: ");
    scanf("%d", &carta1.populacao);

    printf("Área (km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (R$): ");
    scanf("%f", &carta1.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    getchar();

    printf("\nCadastro da Carta 2:\n");
    printf("Estado: ");
    fgets(carta2.estado, sizeof(carta2.estado), stdin);
    carta2.estado[strcspn(carta2.estado, "\n")] = '\0';

    printf("Código da Carta: ");
    fgets(carta2.codigo, sizeof(carta2.codigo), stdin);
    carta2.codigo[strcspn(carta2.codigo, "\n")] = '\0';

    printf("Nome da Cidade: ");
    fgets(carta2.nome, sizeof(carta2.nome), stdin);
    carta2.nome[strcspn(carta2.nome, "\n")] = '\0';

    printf("População: ");
    scanf("%d", &carta2.populacao);

    printf("Área (km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (R$): ");
    scanf("%f", &carta2.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    calcularDados(&carta1);
    calcularDados(&carta2);

    printf("\n=== Dados das Cartas ===\n\n");
    printf("Carta 1:\n");
    exibirCarta(carta1);
    printf("Carta 2:\n");
    exibirCarta(carta2);

    printf("Comparação de cartas (Atributo: PIB per capita):\n");
    printf("%s: R$ %.2f\n", carta1.nome, carta1.pibPerCapita);
    printf("%s: R$ %.2f\n", carta2.nome, carta2.pibPerCapita);

    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
