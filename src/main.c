#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Q_contatos 5


typedef struct{
    char nome[50];
    char numero[2][15];
    char endereco[50];
    char email[20];
    int On;
}contatos;


typedef struct{
    contatos contato[Q_contatos];
    int contactsalreadyadded;
}contact_list;

void init_contatos(contact_list *Contact_List);
void add(contact_list *Contact_List);
void menu(contact_list *Contact_List);


int main (void){
    FILE *arq;

    contact_list Contact_List;

    init_contatos(&Contact_List);

    menu(&Contact_List);


    return 0;
}


void init_contatos(contact_list *Contact_List){
    for(int i; i<Q_contatos; ++i)
        (*Contact_List).contato[i].On = 0;
    
    (*Contact_List).contactsalreadyadded = 0;
}

void add(contact_list *Contact_List){
    int adding;

    for(int i = 0; i>=Q_contatos; ++i){

        for(int k = 0; k<Q_contatos; ++k){
            (*Contact_List).contactsalreadyadded = 0;
            
            if((*Contact_List).contato[k].On == 1)
                ++(*Contact_List).contactsalreadyadded;
        }

        if ((*Contact_List).contactsalreadyadded >= Q_contatos){
            system("cls");
            printf("-----------------------------------\n");
            printf("|          NOVO CONTATO:          |\n");
            printf("|---------------------------------|\n");
            printf("\n  Limite de contatos atingido!\n");
            getch();
            break;
        }

        if((*Contact_List).contato[i].On == 0){
            system("cls");
            printf("-----------------------------------\n");
            printf("|          NOVO CONTATO:          |\n");
            printf("|---------------------------------|\n");
            printf("Nome: \n");
            scanf(" %[^\n]s", (*Contact_List).contato[i].nome);
            printf("Numero (1): \n");
            scanf(" %s", (*Contact_List).contato[i].numero[0]);
            printf("Numero (2): \n");
            scanf(" %s", (*Contact_List).contato[i].numero[1]);
            printf("Endereco: \n");
            scanf(" %[^\n]s", (*Contact_List).contato[i].endereco);
            printf("Email: \n");
            scanf(" %s", (*Contact_List).contato[i].email);
            (*Contact_List).contato[i].On = 1; 
                     

            printf("\n\nDeseja adicionar outro contato?\n1 - Sim.\n2 - Nao.\n");
            scanf("%d", &adding);

            if(adding == 2)
                break;
                
        }
    
    }
    
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


void menu(contact_list *Contact_List){
    
    int option;

    do{
        system("cls");
        printf("-----------------------------------\n");
        printf("|       LISTA DE CONTATOS:        |\n");
        printf("|                                 |\n");
        printf("| 1 - Adicionar novo contato.     |\n");
        printf("| 2 - Editar.                     |\n");
        printf("| 3 - Excluir.                    |\n");
        printf("| 4 - Listar.                     |\n");
        printf("| 5 - Buscar.                     |\n");
        printf("| 0 - Sair                        |\n");
        printf("-----------------------------------\n");
        scanf("%d", &option);
        switch (option){
            case 1:
                add(Contact_List);
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