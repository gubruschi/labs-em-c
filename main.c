/*Os antigos gregos são conhecidos por sua superstição e busca pela perfeição. Um belo exemplo disso é que, na antiguidade, os seus generais estudavam a geometria de uma cidade alvo antes de atacá-la. Os seus meticulosos matemáticos analisavam cada uma das coordenadas que demarcavam o território da cidade alvo, calculavam seu perímetro e, de acordo com o valor obtido, decidiam se esta cidade deveria ou não ser atacada.

Para os antigos gregos, o perímetro (arredondado) de uma cidade indicava se ela havia sido ou nao construída com o auxílio dos deuses. Assim,

se número obtido no cálculo do perímetro fosse um número perfeito ou triangular, a cidade não era atacada;
caso contrário, como não havia influência dos deuses, eles atacavam a cidade.
Sabidamente, um número inteiro positivo é dito triangular se é igual à soma de todos os inteiros positivos menores que um dado inteiro positivo m. Por exemplo, 6 = 1 + 2 + 3 e 10 = 1 + 2 + 3 + 4 são números triangulares.

Um número inteiro positivo, por sua vez, é dito perfeito se a soma de seus divisores próprios (isto é, os divisores menores que ele mesmo) é igual ao próprio número. Por exemplo, 6 é um número perfeito, pois seus divisores próprios são 1, 2 e 3 e 1 + 2 + 3 = 6.

Tarefa:
Neste laboratório, seu objetivo é ajudar os generais gregos (que não são tão meticulosos com cálculos) durante a greve dos matemáticos impulsionada pela crise. Para tanto, você deve escrever um programa em linguagem C, que avalia se uma determinada cidade deve ou não ser atacada. Seu programa receberá um número inteiro com o valor do perímetro da cidade alvo e deve determinar se seu perímetro é triangular e/ou perfeito.

A entrada consiste de um número inteiro representando o perímetro de uma possível cidade alvo. Todos os números da entrada serão representados com o tipo de dado int

A saída do programa deve ser:

"Paz", quando o perímetro é perfeito e triangular ao mesmo tempo;
"Pensar", quando o perímetro não é perfeito mas é triangular ou quando este perímetro é perfeito mas não é triangular;
"Atacar", quando o perímetro não é triangular, nem perfeito.*/

#include <stdio.h>
int main(){
    int num, soma_1, soma_2, i, j;
    printf("Digite o perimetro: \n");
    scanf("%d", &num);
    for(i=1; soma_1 < num; i++){
        soma_1 = soma_1 + i;
    }
    for(j=1; soma_2 < num; j++){
        if(num % j == 0 )
        soma_2 = soma_2 + j;
    }
    if(soma_2 == num && soma_1 == num)
        printf("Paz");
        
    else if(soma_2 == num || soma_1 == num)
        printf("Pensar");
    
    else if(soma_2 != num && soma_1 != num)
        printf("Atacar");
}