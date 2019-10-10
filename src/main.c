#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define Q_contatos 5


typedef struct{
    char nome[50];
    char numero[2][20];
    char endereco[60];
    char email[30];
    int on;
}contatos;


typedef struct{
    contatos contato[Q_contatos];
    int contactsalreadyadded;
    bool listFunctionControlVar;
}contact_list;


void init_contacts(contact_list *Contact_List){

    for(int i = 0; i<Q_contatos; ++i)
        (*Contact_List).contato[i].on = 0;

    (*Contact_List).listFunctionControlVar = false;
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
            setbuf(stdin, NULL);
            fgets((*Contact_List).contato[i].nome, 50, stdin);
            printf("Numero (1): \n");
            fgets((*Contact_List).contato[i].numero[0], 20, stdin);
            printf("Numero (2): \n");
            fgets((*Contact_List).contato[i].numero[1], 20, stdin);
            printf("Endereco: \n");
            fgets((*Contact_List).contato[i].endereco, 60, stdin);
            printf("Email: \n");
            fgets((*Contact_List).contato[i].email,50, stdin);
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


int listar(contact_list *Contact_List){
    
    //VARIAVEIS USADAS NA FUNCAO 
    char exitlistar;
    char exitinformacoes;
    char menor[50];
    int contador = 0;
    int selecao;

    //LOOPING PRINCIPAL DA FUNCAO
    while(exitlistar != 'v' || exitlistar != 'V')
    {
        system("cls");

        //LOOPING ORDENANDO OS CONTATOS POR ORDEM ALFABETICA
        while(contador <= Contact_List -> contactsalreadyadded)
        {
            for(int j = 0; j < Contact_List -> contactsalreadyadded; j++)
            {
                if (strcmp (Contact_List -> contato[j].nome, Contact_List -> contato[j+1].nome) > 0)
                {
                    strcpy(menor, Contact_List -> contato[j].nome);
                    strcpy(Contact_List -> contato[j].nome, Contact_List -> contato[j+1].nome);
                    strcpy(Contact_List -> contato[j+1].nome, menor);
                }
            }

            contador++;
        }

        //PRINTANDO A LISTA DE CONTATOS
        for (int i = 0; i <= Contact_List -> contactsalreadyadded; i++)
        {
            printf("%d - ", i+1);
            printf("%s\n",Contact_List -> contato[i].nome);
        }

        //SELECIONANDO CONTATO
        
        printf("Digite o numero do contato: ");
        scanf("%d", &selecao);
        system("cls");
        
        //PRINTANDO INFORMACOES DO CONTATO
        while (exitinformacoes != 's' || exitinformacoes != 'S')
        {
            
            printf("Nome: %s\n", Contact_List -> contato[selecao-1].nome);

            for(int i = 0; i < 2; i++)
            {
                printf("Telefone %d: %s\n", i+1, Contact_List -> contato[selecao-1].numero[i]);
            }
                
                
            printf("Endereco: %s\n", Contact_List -> contato[selecao-1].endereco);
            printf("Email: %s\n", Contact_List -> contato[selecao-1].email);
            
            
            printf(" --------------------------\n");
            printf("  S - Sair das informacoes\n");
            printf(" --------------------------\n");

            setbuf(stdin, NULL);
            scanf("%c", &exitinformacoes);

            //CONDICAO PARA VOLTAR AO MENU PRINCIPAL
            if(exitinformacoes == 's' || exitinformacoes == 'S')
                return 0;
        }
        

        //PRINT DA OPCAO DE VOLTAR AO MENU 
        printf(" --------------------\n");
        printf("  V - Voltar ao menu\n");
        printf(" --------------------\n");
        
        //RECEBENDO OPCAO DE RETORNAR AO MENU
        setbuf(stdin, NULL);
        scanf("%c", &exitlistar);
    
        switch (exitlistar)
        {
            case 'V':
                return 0;
                break;

            case 'v':
                return 0;
                break;
        
            default:
                printf("Opcao invalida, por favor digite novamente: ");
                scanf("%c", &exitlistar);
                break;
        }
    }
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
                (*Contact_List).listFunctionControlVar = true;
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