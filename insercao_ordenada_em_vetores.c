#include <stdio.h>
#include <stdlib.h>

void print_vetor (int* vetor,int tamanho) {
    for (int i = 0; i <= tamanho; i++) {
        printf("%d ", vetor[i]); 
    }
    printf("\n");

}
void insercao(int* vetor,int elemento,int posicao, int ultimo) {
    for (int i = ultimo; i >= posicao ; i--) {
        vetor[i+1] = vetor[i];
    }
    vetor[posicao] = elemento;

}

int main() {

    int QTD;
    int numero;
    int *numeros_ordenados;

    printf("digite a quantidade de numeros que serao inseridos: ");
    scanf("%d", &QTD);

    numeros_ordenados = malloc(QTD*sizeof(int));

    printf("insira os numeros a serem ordenados:\n");
    for (int i = 0; i < QTD; i++) {
        scanf("%d", &numero);
        int meio = i/2;
        if(i == 0){
            insercao (numeros_ordenados, numero, 0, i-1);

        } else if (numero < numeros_ordenados[meio]) {
            for (int j = meio; j >= 0; j--) {
                if (numero >= numeros_ordenados[j]) {
                    insercao (numeros_ordenados, numero, j+1, i-1);
                    break;
                } else if(j == 0) {
                    insercao (numeros_ordenados, numero, 0, i-1);
                    break;
                }
            }

        } else if (numero > numeros_ordenados[meio]) {
            int j;
            for (j = meio; j < i; j++) {
                if (numero <= numeros_ordenados[j]) {
                    insercao (numeros_ordenados, numero, j, i-1);
                    break;
                }
            }
            if(j == i) {
                insercao (numeros_ordenados, numero, i, i-1);
            }

        } else { //numero == numeros_ordenados[meio]
            insercao (numeros_ordenados, numero, meio+1, i-1);
        }
    }

    printf("\nNUMEROS ORDENADOS:\n");
    print_vetor (numeros_ordenados, QTD-1);

    return 0;
}