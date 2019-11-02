//Programa de controle de stands de jogos em um evento de video games.
//Autores: Douglas Henrique de Souza Pereira|João Victor de Souza Portella.
//Matrículas: UC19107076|          .
//Instituição de Ensino: Universidade Católica de Brasília.
//Data: 02 de Novembro de 2019.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[100];
	int CNPJ;
}empresas;

typedef struct{
	char nome[100];
	char tipo_stand;
	int identidade;
}gamers;

typedef struct{
	char nome[100];
	int CNPJ;
}patrocinadores;

void menu_participantes();
void menu_organizadores();
void cadastrar();
void stands();
void backup();
void restore();
void vagas();
void sobre();

int main(void){
	char escolha;
	do{
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tO QUE VOCE E? [P]PARTICIPANTE/[O]ORGANIZADOR");
		printf("\n\t\t\t\t\t      APERTE A RESPECTIVA LETRA>> ");
		escolha = getch();
		escolha = toupper(escolha);
		if(escolha != 'P' && escolha != 'O'){
			printf("\n\t\t\t\t\t\t  CARACTER INVALIDO!");
			Sleep(800);
		}
		system("cls");
	}while(escolha != 'P' && escolha != 'O');
	
	switch(escolha){
		case 'P':
			menu_participantes();
			break;
		case 'O':
			menu_organizadores();	
			break;
	}
}

void menu_participantes(){
	int opcao;
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\n                                          ÚÄÄÄÄÄÄÄÄ MENU PARTICIPANTE ÄÄÄÄÄÄÄÄ¿\n");
		printf("                                          ³                                   ³\n");
		printf("                                          ³           #1[CADASTRAR]           ³\n");
		printf("                                          ³           #2[STANDS]              ³\n");
		printf("                                          ³           #3[SOBRE O EVENTO]      ³\n");
		printf("                                          ³           #0[FECHAR]              ³\n");
		printf("                                          ³                                   ³\n");
		printf("                                          ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		printf("\n\t\t\t\t\t\t\t#OPCAO>> ");
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0'){
			printf("\n\t\t\t\t\t\t    OPCAO INVALIDA!");
			Sleep(800);
		}
		switch(opcao){
			case '1':
				cadastrar();
				break;
			case '2':
				stands();
				break;
			case '3':
				sobre();
				break;		
		}
	}while(opcao != '0');
}

void menu_organizadores(){
	int opcao;
	do{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\n                                          ÚÄÄÄÄÄÄÄÄ MENU ORGANIZADOR ÄÄÄÄÄÄÄÄ¿\n");
		printf("                                          ³                                  ³\n");
		printf("                                          ³           #1[VAGAS]              ³\n");
		printf("                                          ³           #2[BACKUP DE DADOS]    ³\n");
		printf("                                          ³           #3[RECUPERAR DADOS]    ³\n");
		printf("                                          ³           #0[FECHAR]             ³\n");
		printf("                                          ³                                  ³\n");
		printf("                                          ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		printf("\n\t\t\t\t\t\t\t#OPCAO>> ");
		opcao = getch();
		if(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '0'){
			printf("\n\t\t\t\t\t\t  OPCAO INVALIDA!");
			Sleep(800);
		}
		switch(opcao){
			case '1':
				vagas();
				break;
			case '2':
				system("cls");
				printf("\n\t\t\t\t\t\t\tBACKUP DE DADOS");
				printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				backup();
				printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
				getch();
				break;
			case '3':
				system("cls");
				printf("\n\t\t\t\t\t\t\tRESTAURAR DADOS");
				printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
				restore();
				printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
				getch();
				break;		
		}
	}while(opcao != '0');
}

void cadastrar(){
	gamers participante;
	system("cls");
	printf("\n\t\t\t\t\t\t\tCADASTRAR");
	printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	printf("\nBEM-VINDO GAMER, DIGITE SEU NOME>> ");
	fflush(stdin);
	gets(participante.nome);
	printf("\nOLA %s,", strcat(participante.nome, " GAMER"));
	printf("\nESCOLHA O STAND DE JOGO QUE IRA PARTICIPAR>> ");
	printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

void stands(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSTANDS");
	printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

void backup(){

} 

void restore(){
	
}

void vagas(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tVAGAS");
	printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}

void sobre(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSOBRE O EVENTO");
	printf("\nÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ");
	printf("PRESSIONE UMA TECLA PARA CONTINUAR...");
	getch();
}
