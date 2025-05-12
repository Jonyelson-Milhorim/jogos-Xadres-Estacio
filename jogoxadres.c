#include <stdio.h>
#include <stdbool.h>

// Constantes para os movimentos das peças
#define MOV_BISPO 5       // Bispo move 5 casas na diagonal
#define MOV_TORRE 5       // Torre move 5 casas horizontal/vertical
#define MOV_RAINHA 8      // Rainha move 8 casas em qualquer direção
#define TAM_TABULEIRO 8   // Tabuleiro 8x8

// Constantes para direções
#define DIAGONAL_SUP_DIR 1
#define DIREITA 2
#define ESQUERDA 3

// Função para limpar o buffer do teclado
void limparBuffer() {
    while (getchar() != '\n');
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n  a b c d e f g h\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(". ");
            } else if (tabuleiro[i][j] == 1) {
                printf("B "); // Bispo
            } else if (tabuleiro[i][j] == 2) {
                printf("T "); // Torre
            } else if (tabuleiro[i][j] == 3) {
                printf("R "); // Rainha
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Função para mover o Bispo na diagonal superior direita
void moverBispo(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    printf("\nMovendo Bispo %d casas na diagonal superior direita:\n", MOV_BISPO);
    
    // Verifica se a posição inicial é válida
    if (linha < 0 || linha >= TAM_TABULEIRO || coluna < 0 || coluna >= TAM_TABULEIRO) {
        printf("Posição inicial inválida!\n");
        return;
    }
    
    // Limpa a posição atual
    tabuleiro[linha][coluna] = 0;
    
    // Usando estrutura de repetição for para o movimento
    for (int i = 1; i <= MOV_BISPO; i++) {
        int novaLinha = linha - i;
        int novaColuna = coluna + i;
        
        // Verifica os limites do tabuleiro
        if (novaLinha >= 0 && novaColuna < TAM_TABULEIRO) {
            printf("Movimento %d: linha %d, coluna %d\n", i, 8 - novaLinha, novaColuna + 1);
            tabuleiro[novaLinha][novaColuna] = 1;
        } else {
            printf("Movimento interrompido no passo %d - limite do tabuleiro alcançado.\n", i);
            break;
        }
    }
}

// Função para mover a Torre para a direita
void moverTorre(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    printf("\nMovendo Torre %d casas para a direita:\n", MOV_TORRE);
    
    if (linha < 0 || linha >= TAM_TABULEIRO || coluna < 0 || coluna >= TAM_TABULEIRO) {
        printf("Posição inicial inválida!\n");
        return;
    }
    
    tabuleiro[linha][coluna] = 0;
    
    // Usando estrutura de repetição while para o movimento
    int i = 1;
    while (i <= MOV_TORRE) {
        int novaColuna = coluna + i;
        
        if (novaColuna < TAM_TABULEIRO) {
            printf("Movimento %d: linha %d, coluna %d\n", i, 8 - linha, novaColuna + 1);
            tabuleiro[linha][novaColuna] = 2;
            i++;
        } else {
            printf("Movimento interrompido no passo %d - limite do tabuleiro alcançado.\n", i);
            break;
        }
    }
}

// Função para mover a Rainha para a esquerda
void moverRainha(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    printf("\nMovendo Rainha %d casas para a esquerda:\n", MOV_RAINHA);
    
    if (linha < 0 || linha >= TAM_TABULEIRO || coluna < 0 || coluna >= TAM_TABULEIRO) {
        printf("Posição inicial inválida!\n");
        return;
    }
    
    tabuleiro[linha][coluna] = 0;
    
    // Usando estrutura de repetição do-while para o movimento
    int i = 1;
    do {
        int novaColuna = coluna - i;
        
        if (novaColuna >= 0) {
            printf("Movimento %d: linha %d, coluna %d\n", i, 8 - linha, novaColuna + 1);
            tabuleiro[linha][novaColuna] = 3;
            i++;
        } else {
            printf("Movimento interrompido no passo %d - limite do tabuleiro alcançado.\n", i);
            break;
        }
    } while (i <= MOV_RAINHA);
}

// Função principal
int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0}; // Inicializa o tabuleiro vazio
    int escolha, linha, coluna;
    char colunaChar;
    bool sair = false;
    
    printf("Bem-vindo ao MateCheck - Simulador de Movimentos de Xadrez\n");
    
    while (!sair) {
        printf("\nMenu Principal:\n");
        printf("1. Mover Bispo\n");
        printf("2. Mover Torre\n");
        printf("3. Mover Rainha\n");
        printf("4. Exibir Tabuleiro\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        limparBuffer();
        
        switch (escolha) {
            case 1: // Mover Bispo
                printf("\nPosição inicial do Bispo (ex: e4): ");
                scanf("%c%d", &colunaChar, &linha);
                limparBuffer();
                
                // Converter entrada para índices da matriz
                coluna = colunaChar - 'a';
                linha = TAM_TABULEIRO - linha;
                
                // Verificar se a posição é válida
                if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                    moverBispo(tabuleiro, linha, coluna);
                } else {
                    printf("Posição inválida!\n");
                }
                break;
                
            case 2: // Mover Torre
                printf("\nPosição inicial da Torre (ex: a1): ");
                scanf("%c%d", &colunaChar, &linha);
                limparBuffer();
                
                coluna = colunaChar - 'a';
                linha = TAM_TABULEIRO - linha;
                
                if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                    moverTorre(tabuleiro, linha, coluna);
                } else {
                    printf("Posição inválida!\n");
                }
                break;
                
            case 3: // Mover Rainha
                printf("\nPosição inicial da Rainha (ex: h8): ");
                scanf("%c%d", &colunaChar, &linha);
                limparBuffer();
                
                coluna = colunaChar - 'a';
                linha = TAM_TABULEIRO - linha;
                
                if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                    moverRainha(tabuleiro, linha, coluna);
                } else {
                    printf("Posição inválida!\n");
                }
                break;
                
            case 4: // Exibir Tabuleiro
                exibirTabuleiro(tabuleiro);
                break;
                
            case 5: // Sair
                sair = true;
                printf("Obrigado por usar o MateCheck!\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }
    
    return 0;
}