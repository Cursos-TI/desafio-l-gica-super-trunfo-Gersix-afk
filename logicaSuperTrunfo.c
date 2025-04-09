#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado[3]; // Estado (sigla)
    char codigo[10]; // Código da carta
    char nome[50]; // Nome da cidade
    int populacao; // População
    float area; // Área
    float pib; // PIB
    int pontos_turisticos; // Número de pontos turísticos
} Carta;

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(int populacao, float area) {
    return populacao / area;
}

// Função principal
int main() {
    Carta carta1, carta2;

    // Cadastro da primeira carta
    printf("Cadastro da Carta 1:\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Código da carta: ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nome); // Lê string com espaços
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    // Cadastro da segunda carta
    printf("\nCadastro da Carta 2:\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Código da carta: ");
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nome); // Lê string com espaços
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    // Cálculo da densidade populacional
    float densidade1 = calcularDensidadePopulacional(carta1.populacao, carta1.area);
    float densidade2 = calcularDensidadePopulacional(carta2.populacao, carta2.area);

    int atributo1, atributo2;

    // Menu para escolher o primeiro atributo
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    // Menu para escolher o segundo atributo
    printf("\nEscolha o segundo atributo para comparação (não pode ser o mesmo que o primeiro):\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo2);

    // Verifica se o usuário escolheu o mesmo atributo
    while (atributo1 == atributo2) {
        printf("Você não pode escolher o mesmo atributo. Escolha um segundo atributo diferente:\n");
        printf("Opção: ");
        scanf("%d", &atributo2);
    }

    // Comparação dos atributos escolhidos
    float valor1_a, valor2_a, valor1_b, valor2_b;
    char* nome_atributo1;
    char* nome_atributo2;

    // Atributo 1
    switch (atributo1) {
        case 1: // População
            valor1_a = carta1.populacao;
            valor2_a = carta2.populacao;
            nome_atributo1 = "População";
            break;
        case 2: // Área
            valor1_a = carta1.area;
            valor2_a = carta2.area;
            nome_atributo1 = "Área";
            break;
        case 3: // PIB
            valor1_a = carta1.pib;
            valor2_a = carta2.pib;
            nome_atributo1 = "PIB";
            break;
        case 4: // Número de Pontos Turísticos
            valor1_a = carta1.pontos_turisticos;
            valor2_a = carta2.pontos_turisticos;
            nome_atributo1 = "Número de Pontos Turísticos";
            break;
        case 5: // Densidade Demográfica
            valor1_a = densidade1;
            valor2_a = densidade2;
            nome_atributo1 = "Densidade Demográfica";
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    // Atributo 2
    switch (atributo2) {
        case 1: // População
            valor1_b = carta1.populacao;
            valor2_b = carta2.populacao;
            nome_atributo2 = "População";
            break;
        case 2: // Área
            valor1_b = carta1.area;
            valor2_b = carta2.area;
            nome_atributo2 = "Área";
            break;
        case 3: // PIB
            valor1_b = carta1.pib;
            valor2_b = carta2.pib;
            nome_atributo2 = "PIB";
            break;
        case 4: // Número de Pontos Turísticos
            valor1_b = carta1.pontos_turisticos;
            valor2_b = carta2.pontos_turisticos;
            nome_atributo2 = "Número de Pontos Turísticos";
            break;
        case 5: // Densidade Demográfica
            valor1_b = densidade1;
            valor2_b = densidade2;
            nome_atributo2 = "Densidade Demográfica";
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    // Comparação dos atributos
    printf("\nComparação de cartas:\n");
    printf("Carta 1 - %s: %s = %.2f\n", carta1.nome, nome_atributo1, valor1_a);
    printf("Carta 2 - %s: %s = %.2f\n", carta2.nome, nome_atributo1, valor2_a);
    printf("Carta 1 - %s: %s = %.2f\n", carta1.nome, nome_atributo2, valor1_b);
    printf("Carta 2 - %s: %s = %.2f\n", carta2.nome, nome_atributo2, valor2_b);

    // Determinando o vencedor para cada atributo
    int vitoria1 = (atributo1 == 5) ? (valor1_a < valor2_a) : (valor1_a > valor2_a);
    int vitoria2 = (atributo2 == 5) ? (valor1_b < valor2_b) : (valor1_b > valor2_b);

    // Exibindo resultados
    if (vitoria1 && vitoria2) {
        printf("Resultado: Carta 1 (%s) venceu em ambos os atributos!\n", carta1.nome);
    } else if (!vitoria1 && !vitoria2) {
        printf("Resultado: Carta 2 (%s) venceu em ambos os atributos!\n", carta2.nome);
    } else if (vitoria1) {
        printf("Resultado: Carta 1 (%s) venceu no primeiro atributo e Carta 2 (%s) venceu no segundo atributo!\n", carta1.nome, carta2.nome);
    } else {
        printf("Resultado: Carta 2 (%s) venceu no primeiro atributo e Carta 1 (%s) venceu no segundo atributo!\n", carta2.nome, carta1.nome);
    }

    // Soma dos atributos
    float soma1 = valor1_a + valor1_b;
    float soma2 = valor2_a + valor2_b;

    printf("Soma dos atributos:\n");
    printf("Carta 1 (%s): %.2f\n", carta1.nome, soma1);
    printf("Carta 2 (%s): %.2f\n", carta2.nome, soma2);

    // Verificando empate na soma
    if (soma1 > soma2) {
        printf("Resultado final: Carta 1 (%s) venceu com a maior soma!\n", carta1.nome);
    } else if (soma1 < soma2) {
        printf("Resultado final: Carta 2 (%s) venceu com a maior soma!\n", carta2.nome);
    } else {
        printf("Resultado final: Empate na soma dos atributos!\n");
    }

    return 0;
}