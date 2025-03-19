#include <stdio.h>
// Antonio Milton Garcia dos Santos - TURMA DE SISTEMAS DE INFORMAÇÃO - ALGORITMOS II

#define TAM 100

int main() {

    // Declaração das variáveis
    int encerrar = 0;
    char texto[TAM];
    char texto_criptografado[TAM];
    int i, contador;

    do {
        printf("\n\n[-----{Criptografador de texto}-----]\n");
        printf("Digite o texto que deseja criptografar (Para finalizar o envio, termine com ';'): ");

        // Lê o texto do solicitado
        fgets(texto, TAM, stdin);

        // Verifica se a mensagem termina com ';'
        int tamanho = 0;
        while (texto[tamanho] != '\0') {
            if (texto[tamanho] == '\n') {
                texto[tamanho] = '\0'; // Remove o '\n' do final
                break;
            }
            tamanho++;
        }

        if (texto[tamanho - 1] != ';') {
            printf("\nERRO: A mensagem deve terminar com o caractere ';' para ser enviada.\n");
            continue;  // Pede um novo texto ao usuário
        }

        // Remove o ';' antes da criptografia
        texto[tamanho - 1] = '\0';

        // Criptografa a mensagem
        contador = 0;
        for (i = 0; texto[i] != '\0'; i++) {
            texto_criptografado[i] = (5 * texto[i] + 100) % 256;
            contador++;
        }
        texto_criptografado[i] = '\0';  // Finaliza a string

        // Mostra o resultado
        printf("\nTexto com %d caracteres\n", contador);
        printf("Texto criptografado: %s\n", texto_criptografado);

        // Encerra o programa
        printf("\nDeseja encerrar o programa? (1 - Sim, 0 - Não): ");
        scanf("%d", &encerrar);
        getchar(); // Remove o '\n' do buffer para evitar problemas na próxima entrada

    } while (encerrar != 1);

    return 0;
}
