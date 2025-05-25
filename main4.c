/*Exercício 4 - Crie um programa que armazene o resultado de uma  operação aritmética em uma união "value". O programa principal deve pedir que sejam digitados os operandos inteiros x e y. A opção da operação também deve ser digitada, sendo 1-Adição, 2-Subtração, 3-Multiplicação e 4-Divisão. Para adição, subtração e multiplicação, o resultado é armazenado como inteiro na união. Para a divisão, o resultado é armazenado como um vetor de 2 posições, sendo 1 inteiro para o quociente e 1 inteiro para o resto. Ainda para a divisão, caso o divisor for 0, o resultado é armazenado como a string "Erro". O resultado deve então ser exibido em uma mensagem. 
Utilize a união: union value{ ... };*/
#include <stdio.h>
#include <string.h>

union value{
    int a;
    int v[2];
    char nome[80];
};

int main(){
    int x, y, n;
    union value value;
    printf("Digite os operandos x e y\n");
    scanf("%d", &x);
    scanf("%d", &y);
    printf("Digite a operação: 1 - Adição, 2 - Subtração, 3 - Multiplicação , 4 - Divisão\n");
    scanf("%d", &n);
    if(n == 1){
        value.a = x + y;
        printf("Resultado: %d", value.a);
    }else if(n == 2){
        value.a = x - y;
        printf("Resultado: %d", value.a);
    }else if(n == 3){
        value.a = x * y;
        printf("Resultado: %d", value.a);
    }else if(n == 4){
        if (y == 0){
            strcpy(value.nome, "Erro");
            printf("%s", value.nome);
        }else{
        value.v[0] = x / y;
        value.v[1] = x % y;
        printf("Resultado: quociente %d, resto %d", value.v[0], value.v[1]);
        }
    }
    
}