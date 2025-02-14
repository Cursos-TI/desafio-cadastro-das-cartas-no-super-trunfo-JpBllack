#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int codigoCidade;
    wchar_t nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;

    wprintf(L"Super Trunfo - Cadastro de Cartas\n");
    wprintf(L"------------------------------------\n");

    wprintf(L"Digite o Código da Cidade: ");
    scanf("%d", &codigoCidade);
    getchar();

    wprintf(L"Digite o Nome da Cidade: ");
    fgetws(nome, sizeof(nome)/ sizeof(nome[0]), stdin);
    nome[wcslen(nome) - 1] = L'\0';

    wprintf(L"Digite o Tamanho da População (EX: 2000000): ");
    scanf("%d", &populacao);

    wprintf(L"Digite o Tamanho da Área (em km²): ");
    scanf("%f", &area);

    wprintf(L"Digite o PIB da Cidade (em bilhões): ");
    scanf("%f", &pib);

    wprintf(L"Digite a Quantidade de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos);

    // Exibição dos dados cadastrados
    wprintf(L"\nOs valores inseridos para cada atributo da cidade foram:\n");
    wprintf(L"Código da Cidade: %d\n", codigoCidade);
    wprintf(L"Nome: %ls\n", nome);
    wprintf(L"População: %d\n", populacao);
    wprintf(L"Área: %.2f km²\n", area);
    wprintf(L"PIB: %.2f bilhões\n", pib);
    wprintf(L"Pontos Turísticos: %d\n", pontosTuristicos);

    return 0;
}
