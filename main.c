#include <stdio.h>
#include <locale.h>

#define TAM 100

int main() {

    setlocale(LC_ALL, "Portuguese");
    
    int encerrar = 0;
    char texto[TAM];
    char texto_criptografado[TAM];
    int i;

    do {
        printf("\n\n[-----{Criptografador de texto}-----]\n");
        printf("Digite o texto que deseja criptografar: ");

        fgets(texto, TAM, stdin);

        for (i = 0; texto[i] != '\0'; i++) {
            if (texto[i] == '\n') {
                texto[i] = '\0';
                break;
            }
        }

        for (i = 0; texto[i] != '\0'; i++) {
            texto_criptografado[i] = (5 * texto[i] + 100) % 256;
        }
        texto_criptografado[i] = '\0';  

        printf("\nTexto criptografado: %s\n", texto_criptografado);

        printf("\n\nDeseja encerrar o programa? (1 - Sim, 0 - Não): ");
        scanf("%d", &encerrar);
        getchar();

    } while (encerrar != 1);

    return 0;
}
