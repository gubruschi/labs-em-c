/*Exercício 5 - Crie um programa que gere um arquivo "exemplo.txt". Escreva "n" valores inteiros aleatórios na faixa entre 0~10 e feche o arquivo. Reabra o arquivo gerado, calcule a média dos valores lidos e feche novamente o arquivo.
Obs: Para gerar valores aleatoriamente utilizamos o procedimento rand() da biblioteca stdlib.h. Esse procedimento retorna um valor pseudo-aleatório. Por exemplo: 
Se usarmos "int x = rand()%10;", então x receberá um valor aleatório entre 0 e 9. 
Se o programa for executado múltiplas vezes, a sequência de valores aleatórios será sempre igual. Para controlar a geração de valores, é preciso definir uma semente usando o procedimento "srand(seed)". Faça com que o valor de seed seja forneceido pelo usuário, e então gere a matriz aleatória. Observe que com valores diferentes de seed, as matrizes em diferentes execuções terão diverentes valores.
Sobre o programa, pressupõe-se a seguinte estrutura: (i) abertura, escrita de dados e fechamento do arquivo; (ii) abertura, leitura dos dados e fechamento do arquivo. */
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>


int main(){
    FILE *escreve, *le;
    int n, seed, *p;
    printf("Digite a quantidade de números:\n");
    scanf("%d", &n);
    printf("Digite o valor da seed:\n");
    scanf("%d", &seed);
    srand(seed);
    p = malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        p[i] = rand()%11;
    }
    escreve = fopen("exemplo.txt", "w");
    for(int i=0; i<n; i++){
        fprintf(escreve, "%d ", p[i]);
    }
    fclose(escreve);
    le = fopen("exemplo.txt", "r");
    int aux;
    float soma;
    while(fscanf(le,"%d", &aux) != EOF){
        printf("%d ", aux);
        soma = soma + aux;
    }
    printf("\n");
    float media;
    media = soma/n;
    printf("Média = %.2f", media);
    fclose(le);
    
}