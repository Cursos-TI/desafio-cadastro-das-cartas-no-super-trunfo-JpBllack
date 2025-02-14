#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    int codigoCidade;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;

    printf("Super Trunfo - Cadastro de Cartas\n");

    printf("Digite o Codigo da Cidade:");
    printf("%d", &codigoCidade);

    printf("Digite o Nome da Cidade:");
    scanf("%[^\n]", nome);

    printf("Digite o Tamanho da população(EX:2000000):");
    scanf("%d",&populacao);

    printf("Digite o Tamanho da Aréa:");
    scanf("%f", &area);
    printf("Digite o PIB da Cidade:");
    scanf("%f", &pib);
    printf("Digite a quantidade de pontos Turisticos:");
    scanf("%d", &pontosTuristicos);

     
    printf("\nOs valores inseridos para cada atributo da cidade foram:\n");
    printf("Código da Cidade: %d\n", codigoCidade);
    printf("Nome: %s\n", nome);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões\n", pib);
    printf("Pontos Turísticos: %d\n", pontosTuristicos);
    


    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
