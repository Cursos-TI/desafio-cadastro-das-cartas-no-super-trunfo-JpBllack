    #include <stdio.h>
    #include <locale.h>
    #include <wchar.h>
    #include <string.h>

    #define MAX_CIDADES 32

    typedef struct
    {
        char codigoCidade[4];
        wchar_t nome[50];
        int populacao;
        float area;
        float pib;
        int pontosTuristicos;
    } Cidade;

    int main()
    {
        setlocale(LC_ALL, "Portuguese");

        Cidade cidades[MAX_CIDADES];

        wprintf(L"Super Trunfo - Cadastro de Cartas\n");
        wprintf(L"------------------------------------\n");

        for (int i = 0; i < MAX_CIDADES; i++)
        {
            wprintf(L"\nCadastro da cidade %d/%d:\n", i + 1, MAX_CIDADES);
            
            // Gerando código automaticamente (A01, A02, ..., H04)
            char estado = 'A' + (i / 4);
            int cidadeNum = (i % 4) + 1;
            sprintf(cidades[i].codigoCidade, "%c%02d", estado, cidadeNum);
            
            wprintf(L"Nome da Cidade: ");
            fgetws(cidades[i].nome,sizeof(cidades[i].nome) / sizeof(wchar_t),stdin);

            size_t len = wcslen(cidades[i].nome);
            if (len > 0 && cidades[i].nome[len - 1] == L'\n') 
            {
                cidades[i].nome[len - 1] = L'\0';
            }
            
            wprintf(L"Tamanho da População (EX: 2000000): ");
            scanf("%d", &cidades[i].populacao);

            wprintf(L"Tamanho da Área (em km²): ");
            scanf("%f", &cidades[i].area);

            wprintf(L"PIB da Cidade (em bilhões): ");
            scanf("%f", &cidades[i].pib);

            wprintf(L"Digite a Quantidade de Pontos Turísticos: ");
            scanf("%d", &cidades[i].pontosTuristicos);
            getchar();
        }

        // Exibição dos dados cadastrados
        wprintf(L"\n--- Cidades Cadastradas ---\n");
        for (int i = 0; i < MAX_CIDADES; i++)
        {
            wprintf(L"Código: %s\n", &cidades[i].codigoCidade);
            wprintf(L"Nome: %ls\n", &cidades[i].nome);
            wprintf(L"População: %d\n", &cidades[i].populacao);
            wprintf(L"Área: %.2f km²\n", &cidades[i].area);
            wprintf(L"PIB: %.2f bilhões\n", &cidades[i].pib);
            wprintf(L"Pontos Turísticos: %d\n", &cidades[i].pontosTuristicos);
            wprintf(L"------------------------------------------------------\n");
            
        }
        

        return 0;
    }
