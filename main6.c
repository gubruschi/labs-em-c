/*Criar um programa que gere automaticamente uma matriz 10x5 com inteiros entre 0 e 9. O programa deve então criar uma segunda matriz 5x10 que será a transposta da primeira. Ambas as matrizes devem ser exibidas usando a função desenvolvida no exercício anterior.
Observações:
1 - O tamanho das matrizes pode ser fixado por constantes. Isto pode ser feiro usando a instrução "define" fora da função main. Exemplo: #define M 10
2 - Digitar multiplos valores dá trabalho. Por isso, é útil saber como gerar valores aleatoriamente. O procedimento rand() da biblioteca stdlib.h retorna um valor pseudo-aleatório. Se usarmos "int x = rand()%10;", então x receberá um valor aleatório entre 0 e 9. Esta mesma abordagem deverá ser usada na geração da matriz.
3 - Se o programa for executado múltiplas vezes, a sequência de valores aleatórios será sempre igual. Para controlar a geração de valores, é preciso definir uma semente usando o procedimento "srand(seed)". Faça com que o valor de seed seja forneceido pelo usuário, e então gere a matriz aleatória. Observe que com valores diferentes de seed, as matrizes em diferentes execuções terão diverentes valores.*/
#include <stdio.h>
#include <stdlib.h>
#define a 10
#define b 5
void exibeMatriz (int w, int x, int m[100][100]);

int main(){
    int seed, i, j, m[100][100], trans[100][100];
    printf("Digite o valor da seed :\n");
    scanf("%d", &seed);
    srand(seed);
    for (i=0; i < a; i++){
        for (j=0; j<b; j++){
            m[i][j] = rand()%10;
        }
    }
    printf("A matriz é:\n");
    exibeMatriz (a, b, m);
    for (i=0; i<a; i++){
        for (j=0; j<b; j++){
            trans[j][i] = m[i][j];
        }
    }
    printf("A transposta é:\n");
    exibeMatriz(b,a,trans);
    
    
}

void exibeMatriz (int w, int x, int m[100][100]){
    int k, l;
    for (k=0; k<w; k++){
        for (l=0; l<x; l++){
            printf("%d ", m[k][l]);
        }
        printf("\n");
    }
}