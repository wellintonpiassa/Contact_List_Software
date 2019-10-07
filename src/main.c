#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define Q_contatos 2


typedef struct{
    char nome[50];
    char numero[2][15];
    char endereco[50];
    char email[20];
    int on;
}contatos;


typedef struct{
    contatos contato[Q_contatos];
    int contactsalreadyadded;
}contact_list;


void init_contacts(contact_list *Contact_List){
    for(int i = 0; i<Q_contatos; ++i)
        (*Contact_List).contato[i].on = 0;
}


void add(contact_list *Contact_List){
    int adding;
    int i = 0;
    
    while(1){
        system("cls");

        (*Contact_List).contactsalreadyadded = 0;
        
        for(int k = 0; k<Q_contatos; ++k){
            if((*Contact_List).contato[k].on == 1)
                ++(*Contact_List).contactsalreadyadded;
        }

        if((*Contact_List).contactsalreadyadded >= Q_contatos){
            system("cls");
            printf("-----------------------------------\n");
            printf("|          NOVO CONTATO:          |\n");
            printf("|---------------------------------|\n");
            printf("\n  Limite de contatos atingido!\n");
            system("pause");
            break;
        }

        if((*Contact_List).contato[i].on == 0){
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
            (*Contact_List).contato[i].on = 1;
            ++i;
                     

            printf("\n\nDeseja adicionar outro contato?\n1 - Sim.\n2 - Nao.\n");
            scanf("%d", &adding);

            if(adding == 2)
                break;
        }else
            ++i;
    }
 
}


void editar(contact_list *Contact_List){
    system("cls");
}


void excluir(contact_list *Contact_List){
    system("cls");
}


void listar(contact_list *Contact_List){
    system("cls");

}


void buscar(contact_list *Contact_List){
    system("cls");

}


void menu(contact_list *Contact_List){
    int option;

    while(1){
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
        setbuf(stdin, NULL);
        scanf("%d", &option);

        if(option == 0)
            break;

        switch (option){
            case 1:
                add(Contact_List);
                break;
            case 2:
                editar(Contact_List);
                break;
            case 3:
                excluir(Contact_List);
                break;
            case 4:
                listar(Contact_List);
                break;
            case 5:
                buscar(Contact_List);
                break;
            default:
                printf("\nOpcao Invalida!\n");
                system("pause");
                break;
        }
    }

}


int main (void){

    contact_list Contact_List;

    init_contacts(&Contact_List);

    menu(&Contact_List);

    return 0;
}