/*Neste laboratório, você deve criar um programa para gerenciar o cardápio de um restaurante. O restaurante possui um conjunto de pratos, e cada prato tem um preço associado.

O funcionamento básico do programa é o seguinte: lê-se um número do usuário, correspondendo à opção desejada, seguindo o esquema abaixo. Após ser executada a opção desejada, o programa deve voltar a ler uma opção do usuário para continuar a execução do programa, exceto se o usuário escolher a opção 0.

0: sair do programa.
1: inserir um prato no cardápio.
2: remove um prato do cardápio.
3: lista os pratos em ordem alfabética crescente de nome
4: lista os pratos em ordem crescente de preço
Para inserir um prato, o usuário deve digitar seu nome e preço.

Para remover um prato, o usuário deve digitar seu nome.

A listagem de pratos deve seguir o formato "nome preço", por ex., "feijoada 23.90", um prato por linha.

É importante observar que:

Você deve criar um registro (struct prato) com dois campos, um para nome e outro para preço.
Use um vetor do struct criado para armazenar os pratos.
Você pode armazenar nomes como vetores de 20 caracteres.
Use float para armazenar preços.
Os nomes dos pratos não podem possuir espaços, portanto pode-se usar scanf com %s para lê-los.
O seu programa pode assumir que serão cadastrados, no máximo, 100 pratos.
O seu programa pode assumir que o usuário digitará os nomes dos pratos em letras minúsculas.
Use o especificador %-20s para imprimir os nomes dos pratos e %6.2f para imprimir os preços.
Você pode pular uma linha (imprima um "\n") após imprimir a lista de pratos para facilitar a leitura da saída.
Seu programa deve detectar os seguintes erros e imprimir as seguintes mensagens. Note que seu programa não deverá encerrar após um erro; ele deve voltar a ler uma opção do usuário.

Usuário digitou uma opção inválida: "Erro: opcao invalida.\n"
Usuário pediu a lista de pratos, mas ela está vazia: "Erro: nenhum prato cadastrado.\n"
Usuário tentou remover um prato que não está cadastrado: "Erro: prato nao encontrado.\n"*/
#include <stdio.h>
#include <string.h>
#define max 100

struct prato{
    char nome[20];
    float preco;
};

int main(){
    struct prato prato[max];
    int n, j=0;
    char nome[20];
    do{
        fprintf(stderr, "Digite 0 para sair do programa\n");
        fprintf(stderr, "Digite 1 para inserir prato\n");
        fprintf(stderr, "Digite 2 para remover prato\n");
        fprintf(stderr, "Digite 3 para lista os pratos em ordem alfabética crescente de nome\n");
        fprintf(stderr, "Digite 4 para lista os pratos em ordem crescente de preço\n");
        scanf("%d", &n);
        if(n == 1){
            scanf("%s", prato[j].nome);
            scanf("%f", &prato[j].preco);
            j++;
        }else if(n == 2){
            fprintf(stderr, "Digite o prato pra remover\n");
            scanf("%s", nome);
            int indice = -1;
            for(int i=0; i < j; i++){
                if(strcmp(prato[i].nome, nome) == 0){
                    indice = i;
                    break;
                }
            }
            if(indice == -1){
                printf("Erro: prato nao encontrado.\n");
            }else{
                for(int i =indice; i<j-1; i++){
                    prato[i] = prato[i+1];
                }
                j--;
            }
        }else if(n == 3){
            if(j == 0){
                printf("Erro: nenhum prato cadastrado\n");
            }else{
            for(int i=0; i<j-1; i++){
                for(int k=0; k<j-i-1; k++){
                    if(strcmp(prato[k].nome, prato[k+1].nome)>0){
                        struct prato novo = prato[k];
                        prato[k] = prato[k+1];
                        prato[k+1] = novo;
                    }
                }
            }
            for(int i=0; i<j; i++){
                printf("%-20s %6.2f\n", prato[i].nome, prato[i].preco);
            }
            }
        }else if(n == 4){
            if(j == 0){
                printf("Erro: nenhum prato cadastrado\n");
            }else{
                for(int i=0; i<j-1; i++){
                for(int k=0; k<j-i-1; k++){
                    if(prato[k].preco > prato[k+1].preco){
                        struct prato novo = prato[k];
                        prato[k] = prato[k+1];
                        prato[k+1] = novo;
                    }
                }
            }
            for(int i=0; i<j; i++){
                printf("%-20s %6.2f\n", prato[i].nome, prato[i].preco);
            }
            }
            
        }else if(n!=0 && n!= 1 && n!=2 && n!=3 && n!=4){
            printf("Erro: opcao invalida.\n");
        }
    }while(n != 0);
}