/*Definir uma estrutura "coordenada" que contenha valores x, y e z de um ponto. Instanciar os pontos p1 e p2. Criar uma função swap para trocar os valores dos dois pontos. Para isso, use passagem por referência. Exiba os valores de p1 e p2 antes e depois do swap. 
Utilize a estrutura: struct coordenada{ ... }; 
Utilize a função: void swap( ... ){ ... } */
#include <stdio.h>

struct coordenada{
    int x;
    int y;
    int z;
};
void swap (struct coordenada *p3, struct coordenada *p4);

int main(){
    struct coordenada p1, p2, *p3, *p4;
    p3 = &p1;
    p4 = &p2;
    printf("Digite x, y, z de P1:\n");
    scanf("%d", &p1.x);
    scanf("%d", &p1.y);
    scanf("%d", &p1.z);
    printf("Digite x, y, z de P2:\n");
    scanf("%d", &p2.x);
    scanf("%d", &p2.y);
    scanf("%d", &p2.z);
    printf("\n");
    printf("ANTES\n");
    printf("P1:(%d,%d,%d)  P2:(%d,%d,%d)\n", p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
    printf("\n");
    printf("DEPOIS\n");
    swap(p3,p4);
    printf("P1:(%d,%d,%d)  P2:(%d,%d,%d)", p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
    
}

void swap (struct coordenada *p3, struct coordenada *p4){
    int x, y, z;
     x = (*p3).x;
     y = (*p3).y;
     z = (*p3).z;
    (*p3).x = (*p4).x;
    (*p3).y = (*p4).y;
    (*p3).z = (*p4).z;
    (*p4).x = x;
    (*p4).y = y;
    (*p4).z = z;
}