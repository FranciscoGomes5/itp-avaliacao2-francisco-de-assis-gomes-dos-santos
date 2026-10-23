#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função 1: Calcula a média aritmética de cada estudante e preenche o vetor dinâmico
void calcular_medias(int n, float notas[10][3], float *medias) {
    for (int i = 0; i < n; i++) {
        float soma = 0;
        for (int j = 0; j < 3; j++) {
            soma += notas[i][j];
        }
        medias[i] = soma / 3.0f; // Evita divisão inteira (ponto flutuante)
    }
}

// Função 2: Calcula a média geral da turma e identifica a maior média
void calcular_estatisticas(int n, float *medias, float *media_geral, float *maior_media) {
    float soma_geral = 0;
    *maior_media = medias[0];

    for (int i = 0; i < n; i++) {
        soma_geral += medias[i];
        if (medias[i] > *maior_media) {
            *maior_media = medias[i];
        }
    }
    *media_geral = soma_geral / n;
}

// Função 3: Exibe a tabela formatada do boletim e o resumo estatístico da turma
void exibir_boletim(int n, char nomes[10][50], float notas[10][3], float *medias, float media_geral, float maior_media) {
    printf("\n=================================================================\n");
    printf("                       BOLETIM DA TURMA                          \n");
    printf("=================================================================\n");
    printf("%-20s | %-6s | %-6s | %-6s | %-6s | %-18s\n", "Nome", "Nota 1", "Nota 2", "Nota 3", "Media", "Situacao");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        char *situacao = (medias[i] >= 6.0f) ? "atingiu a meta" : "abaixo da meta";
        printf("%-20s | %6.2f | %6.2f | %6.2f | %6.2f | %-18s\n",
               nomes[i], notas[i][0], notas[i][1], notas[i][2], medias[i], situacao);
    }
    printf("=================================================================\n");

    printf("\nMedia geral da turma: %.2f\n", media_geral);

    printf("Estudante(s) com a maior media (%.2f):\n", maior_media);
    for (int i = 0; i < n; i++) {
        if (medias[i] == maior_media) {
            printf("- %s\n", nomes[i]);
        }
    }
}

int main() {
    int qtd_estudantes;

    // Validação do limite: quantidade de estudantes entre 1 e 10
    do {
        printf("Digite a quantidade de estudantes (1 a 10): ");
        if (scanf("%d", &qtd_estudantes) != 1) {
            printf("Entrada invalida.\n");
            while (getchar() != '\n');
            qtd_estudantes = 0;
        }
        if (qtd_estudantes < 1 || qtd_estudantes > 10) {
            printf("Quantidade invalida! Deve ser entre 1 e 10.\n");
        }
    } while (qtd_estudantes < 1 || qtd_estudantes > 10);

    while (getchar() != '\n'); // Limpar o buffer

    char nomes[10][50];
    float notas[10][3];

    // Leitura de nomes e notas com validações de capacidade e string vazia
    for (int i = 0; i < qtd_estudantes; i++) {
        printf("\n--- Cadastro do Estudante %d ---\n", i + 1);
        
        do {
            printf("Nome: ");
            fgets(nomes[i], 50, stdin);
            nomes[i][strcspn(nomes[i], "\n")] = '\0'; // Remove a quebra de linha
            
            if (strlen(nomes[i]) == 0) {
                printf("O nome nao pode estar vazio. Tente novamente.\n");
            }
        } while (strlen(nomes[i]) == 0);

        // Leitura e validação do intervalo de notas (0 a 10)
        for (int j = 0; j < 3; j++) {
            do {
                printf("Digite a nota %d (0 a 10) para %s: ", j + 1, nomes[i]);
                if (scanf("%f", &notas[i][j]) != 1) {
                    printf("Entrada invalida. Digite um numero.\n");
                    while (getchar() != '\n');
                    notas[i][j] = -1;
                } else if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Nota rejeitada! O valor deve estar entre 0 e 10.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
        while (getchar() != '\n');
    }

    // Alocação dinâmica do vetor de resultados com malloc, verificando o retorno
    float *medias = (float *)malloc(qtd_estudantes * sizeof(float));
    if (medias == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

    // Inicialização / preenchimento da memória alocada dinamicamente via ponteiro
    calcular_medias(qtd_estudantes, notas, medias);

    float media_geral, maior_media;
    calcular_estatisticas(qtd_estudantes, medias, &media_geral, &maior_media);

    exibir_boletim(qtd_estudantes, nomes, notas, medias, media_geral, maior_media);

    // Liberar a área alocada com free quando não for mais necessária
    free(medias);

    return 0;
}