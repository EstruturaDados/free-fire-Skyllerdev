#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

#define TAM_STRINGS 100
#define MAX_ITENS 10

typedef struct{
    char nome[TAM_STRINGS];
    char tipo[TAM_STRINGS];
    int quantidade;
} mochila;

void limparLinha() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // Menu principal com opções:
    int opcao = 0;
    int qtd = 0;
    
    mochila inventario[10];
    while (opcao != 4) {
        printf("O que deseja fazer na mochila?\n 1 Adicionar um item \n 2 Remover um item \n 3 Listar os itens\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        limparLinha();
        int encontrado = -1;
        switch(opcao){
            case 1:
            // 1. Adicionar um item
                printf("Adicione um item!\n");
                printf("Nome do item: ");
                fgets(inventario[qtd].nome, sizeof(inventario[qtd].nome), stdin);
                printf("\nTipo do item: ");
                fgets(inventario[qtd].tipo, sizeof(inventario[qtd].tipo), stdin);
                printf("\nQuantidade do item: ");
                scanf("%d", &inventario[qtd].quantidade);
                qtd++;
                break;
            case 2:
            // 2. Remover um item
                printf("Remova um item!\n");
                if (qtd == 0) {
                    printf("Nenhum item para remover!\n");
                }
                char nomeRemover[TAM_STRINGS];
                printf("Digite o nome do item que deseja remover: ");
                fgets(nomeRemover, sizeof(nomeRemover), stdin);

                //Achando o item
                for (int i = 0; i < qtd; i++) {
                    if (strcmp(inventario[i].nome, nomeRemover) == 0) {
                        encontrado = i;
                        break;
                    }
                }
                if (encontrado == -1) {
                    printf("Item não encontrado.\n");
                    break;
                }

                for (int i = encontrado; i < qtd - 1; i++) {
                    inventario[i] = inventario[i + 1];
                }
                qtd--;
                printf("Item removido!\n");
                
                break;
            case 3:
            // 3. Listar todos os itens
                printf("Itens na mochila!\n\n");
                for (int i = 0; i < qtd; i++)
                {
                    printf("Item %d\n", i);
                    printf("Nome: %s", inventario[i].nome);
                    printf("Tipo: %s", inventario[i].tipo);
                    printf("Quantidade: %d", inventario[i].quantidade);
                    printf("\n\n");
                }
                break;

            case 4:
                break;

            default:
                printf("Número desconhecido.\n");
                break;

        }
    
    }
    // 0. Sair
    printf("\nObrigado por usar o programa.");
    
    
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.

    return 0;
}

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
