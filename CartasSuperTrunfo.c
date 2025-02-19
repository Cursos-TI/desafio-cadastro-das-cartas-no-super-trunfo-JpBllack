#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CIDADES 32

typedef struct {
    char codigoCidade[4];
    wchar_t nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Cidade;

// Função para calcular o Super Poder
void calcularSuperPoder(Cidade *c) {
    c->superPoder = c->populacao + c->area + c->pib + c->pontosTuristicos + c->densidadePopulacional + c->pibPerCapita;
}

// Função para comparar duas cidades
void compararCidades(Cidade c1, Cidade c2) {
    wprintf(L"\n--- Comparação de Cartas ---\n");
    
    wprintf(L"Densidade Populacional: ");
    if (c1.densidadePopulacional < c2.densidadePopulacional) {
        wprintf(L"%ls vence!\n", c1.nome);
    } else if (c1.densidadePopulacional > c2.densidadePopulacional) {
        wprintf(L"%ls vence!\n", c2.nome);
    } else {
        wprintf(L"Empate!\n");
    }

    wprintf(L"População: %ls\n", (c1.populacao > c2.populacao) ? c1.nome : c2.nome);
    wprintf(L"Área: %ls\n", (c1.area > c2.area) ? c1.nome : c2.nome);
    wprintf(L"PIB: %ls\n", (c1.pib > c2.pib) ? c1.nome : c2.nome);
    wprintf(L"Pontos Turísticos: %ls\n", (c1.pontosTuristicos > c2.pontosTuristicos) ? c1.nome : c2.nome);
    wprintf(L"PIB per Capita: %ls\n", (c1.pibPerCapita > c2.pibPerCapita) ? c1.nome : c2.nome);

    wprintf(L"Super Poder: ");
    if (c1.superPoder > c2.superPoder) {
        wprintf(L"%ls vence!\n", c1.nome);
    } else if (c1.superPoder < c2.superPoder) {
        wprintf(L"%ls vence!\n", c2.nome);
    } else {
        wprintf(L"Empate!\n");
    }
}

// Função para gerar valores aleatórios
void preencherAutomaticamente(Cidade *c, int index) {
    char nomes[][20] = { "Cidade Alpha", "Cidade Beta", "Cidade Gama", "Cidade Delta",
                         "Cidade Epsilon", "Cidade Zeta", "Cidade Eta", "Cidade Teta",
                         "Cidade Iota", "Cidade Kappa", "Cidade Lambda", "Cidade Sigma" };

    // Código da cidade (A01, A02, etc.)
    char estado = 'A' + (index / 4);
    int cidadeNum = (index % 4) + 1;
    sprintf(c->codigoCidade, "%c%02d", estado, cidadeNum);

    // Nome gerado automaticamente
    mbstowcs(c->nome, nomes[index % 12], 50);


    // Atributos aleatórios
    c->populacao = rand() % 1000000 + 100000;     // Entre 100 mil e 1 milhão
    c->area = (rand() % 9000) + 100;             // Entre 100 km² e 9000 km²
    c->pib = (rand() % 900) + 100;               // Entre 100 bi e 1000 bi
    c->pontosTuristicos = rand() % 20 + 1;       // Entre 1 e 20 pontos turísticos

    // Calcula atributos derivados
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
    calcularSuperPoder(c);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    Cidade cidades[MAX_CIDADES];

    wprintf(L"Super Trunfo - Cadastro de Cartas\n");
    wprintf(L"------------------------------------\n");

    // Usuário cadastra a primeira cidade
    wprintf(L"\nCadastro da primeira cidade:\n");

    sprintf(cidades[0].codigoCidade, "A01");
    
    wprintf(L"Nome da Cidade: ");
    fgetws(cidades[0].nome, sizeof(cidades[0].nome) / sizeof(wchar_t), stdin);

    size_t len = wcslen(cidades[0].nome);
    if (len > 0 && cidades[0].nome[len - 1] == L'\n') {
        cidades[0].nome[len - 1] = L'\0';
    }

    wprintf(L"Tamanho da População: ");
    scanf("%d", &cidades[0].populacao);

    wprintf(L"Tamanho da Área (km²): ");
    scanf("%f", &cidades[0].area);

    wprintf(L"PIB da Cidade (bilhões): ");
    scanf("%f", &cidades[0].pib);

    wprintf(L"Quantidade de Pontos Turísticos: ");
    scanf("%d", &cidades[0].pontosTuristicos);
    getchar();

    cidades[0].densidadePopulacional = cidades[0].populacao / cidades[0].area;
    cidades[0].pibPerCapita = cidades[0].pib / cidades[0].populacao;
    calcularSuperPoder(&cidades[0]);

    // Preencher automaticamente as outras 31 cidades
    for (int i = 1; i < MAX_CIDADES; i++) {
        preencherAutomaticamente(&cidades[i], i);
    }

    int opcao1, opcao2;
    wprintf(L"\nEscolha duas cidades para comparar (0 a %d): ", MAX_CIDADES - 1);
    scanf("%d %d", &opcao1, &opcao2);

    if (opcao1 >= 0 && opcao1 < MAX_CIDADES && opcao2 >= 0 && opcao2 < MAX_CIDADES) {
        compararCidades(cidades[opcao1], cidades[opcao2]);
    } else {
        wprintf(L"Opção inválida!\n");
    }

    return 0;
}
