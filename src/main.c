#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Q_contatos 50

typedef struct{
    char nome[50];
    char numero[2][15];
    char endereco[50];
    char email[20];
    int On;
}contatos;

void add(){
    system("cls");
}

void editar(){
    system("cls");
}

void excluir(){
    system("cls");
}

void listar(){
    system("cls");

}

void buscar(){
    system("cls");

}


void menu(contatos *contato){
    system("cls");
    int option;

        do{
        printf("1 - Adicionar novo contato\n");
        printf("2 - Editar\n");
        printf("3 - Excluir\n");
        printf("4 - Listar\n");
        printf("5 - Buscar\n");
        printf("0 - Sair\n");
        scanf("%d", &option);
        switch (option){
            case 1:
                add();
                break;
            case 2:
                editar();
                break;
            case 3:
                excluir();
                break;
            case 4:
                listar();
                break;
            case 5:
                buscar();
                break;
        }
    }while(option != 0);

}


int main (void){
    contatos contato[Q_contatos];
    menu(contato);


    return 0;
}