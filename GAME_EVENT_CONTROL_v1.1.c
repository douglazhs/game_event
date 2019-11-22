//Programa de controle de stands de jogos em um evento de video games.
//Autores: Douglas Henrique de Souza Pereira|Joao Victor de Souza Portella.
//Matriculas: UC19107076|UC19100100.
//Instituicao de Ensino: Universidade Catolica de Brasilia.
//Data: 20 de Novembro de 2019.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include "STRUCTS.h"
#include "VALIDACOES.h"
#include "STANDS.h"
#include "MENUS.h"
//------ Teclas para utilizar na funcao gotoxy() ---------------------------------------------------------------------------------------------------------------------------------------------
#define ENTER 13
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ESC 27
//------ Estatisticas -----------------------------------------------------------------------------------------------------------------------------------------------------
void estatisticas();
void copia_nome(char [], char);
float maior_pat(char[]);
void coloca_bordas();
//------ Funcoes conio---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void gotoxy(int x, int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
void HideCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
//------ MENU PRINCIPAL ----------------------------------------------------------------------------------------------------------------------------------------------
int main(void){
	char tecla;
	int pos = 15, i = 1;

	HideCursor();
	do{	
		system("cls");
		printf("\n\t\t\t\t\tUCBG - UNIVERSIDADE CATOLICA DE BRASILIA GAMES\n\n");
		printf("\n\t\t\t\t\t       //   / / //   ) )  //   ) )  //   ) )"); 
		printf("\n\t\t\t\t\t      //   / / //        //___/ /  //");        
		printf("\n\t\t\t\t\t     //   / / //        / __  (   //  ____");   
		printf("\n\t\t\t\t\t    //   / / //        //    ) ) //    / /");  
		printf("\n\t\t\t\t\t   ((___/ / ((____/ / //____/ / ((____/ /");    
		printf("\n\n\n\n\t\t\t\t\t\t       %c O QUE VOCE E?", 254);
		printf("\n\t\t\t\t\t\t����������������������������%c", 187);
		gotoxy(49,15);printf("�    %c PARTICIPANTE         �", 254);
		printf("\n\t\t\t\t\t\t����������������������������%c", 185);
		gotoxy(49,17);printf("�    %c EMPRESA              �", 254);
		printf("\n\t\t\t\t\t\t����������������������������%c", 185);
		gotoxy(49,19);printf("�    %c PATROCINADOR         �", 254);
		printf("\n\t\t\t\t\t\t����������������������������%c", 185);
		gotoxy(49,21);printf("�    %c SOBRE O EVENTO       �", 254);
		printf("\n\t\t\t\t\t\t����������������������������%c", 185);
		gotoxy(49,23);printf("�    %c SAIR DO PROGRAMA     �", 254);
		printf("\n\t\t\t\t\t\t���������������������������ͼ");
		gotoxy(75, pos);printf("%c", 174);
		tecla = getch();
		if(tecla == DOWN)
			pos += 2;
		if(tecla == UP)
			pos -= 2;
		if(pos > 23)
			pos = 15;
		if(pos < 15)
			pos = 23;			 
	}while(tecla != ENTER);
	switch(pos){
		case 15: menu_participantes(); break;
		case 17: menu_organizadores(); break;
		case 19: menu_patrocinadores(); break;
		case 21: sobre();break;
		case 23: break;
	}

}
//------- ACESSAR DADOS -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
gamers acessar_dados_participante(){
	FILE *arq;
	gamers participante;
	int flag = 0, pos = 0;
	char user[50];
	
	arq = fopen("cad_participantes.dat", "rb");
	if(arq == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");	
		return;
	}
	do{
		system("cls");
		flag = 0;
		rewind(arq);
		gotoxy(52,10);printf("��������������������������%c", 187);
		gotoxy(52,11);printf("� USUARIO:                �");
		gotoxy(52,12);printf("�������������������������ͼ\n\t");
		gotoxy(63,11);
		fflush(stdin);
		gets(user);
		while(fread(&participante, sizeof(participante), 1, arq)){
			if(strcmp(user, participante.usuario) == 0){
				mostra_participante(participante);
				return participante;
			}
		}
		if(strcmp(user, participante.usuario) != 0){
			flag = 1;
			printf("\n\t\t\t\t   USUARIO NAO CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
			Sleep(500);
		}
	}while(flag == 1);
	fclose(arq);
}

patrocinadores acessar_dados_patrocinador(){
	char email[150];
	int flag = 0;
	patrocinadores empresa;
	FILE *arqPAT = fopen("cad_patrocinadores.dat", "rb");
	
	do{
		system("cls");
		flag = 0;
		rewind(arqPAT);
		gotoxy(52,10);printf("��������������������������%c", 187);
		gotoxy(52,11);printf("� EMAIL:                  �");
		gotoxy(52,12);printf("�������������������������ͼ\n\t");
		gotoxy(60,11);
		fflush(stdin);
		gets(email);
		while(fread(&empresa, sizeof(empresa), 1, arqPAT)){
			if(strcmp(email, empresa.email) == 0){
				mostra_patrocinador(empresa);
				return empresa;
			}
		}
		if(strcmp(email, empresa.email) > 0){
			flag = 1;
			printf("\n\tENDERECO DE EMAIL NAO CADASTRADO NO SISTEMA! TENTE NOVAMENTE!");
		}
	}while(flag == 1);
	fclose(arqPAT);
}
//------- MOSTRA DADOS -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void mostra_patrocinador(patrocinadores empresa){
	char nome[50];
	
	system("cls");
	copia_nome(nome, empresa.stand_escolhido);
	printf("\n\t�������������������������������%c", 187);
	printf("\n\t�   %c NOME %c                   �", 254, 175);
	printf("\n\t�������������������������������%c", 185);
	printf("\n\t�   %c EMAIL %c                  �", 254, 175);
	printf("\n\t�������������������������������%c", 185);
	printf("\n\t�   %c STAND %c                  �", 254, 175);
	printf("\n\t�������������������������������%c", 185);
	printf("\n\t�   %c PATROCINIO %c             �", 254, 175);
	printf("\n\t������������������������������ͼ");
	gotoxy(22,3);printf("%s", empresa.nome);
	gotoxy(23,5);printf("%s", empresa.email);
	gotoxy(23,7);printf(nome);
	gotoxy(28,9);printf("%.2f", empresa.quantia);
	printf("\n\n\t");
	system("pause");
}

void mostra_participante(gamers participante){
	char nome[50];
	
	copia_nome(nome, participante.stand);
	system("cls");
	printf("\n\t�������������������������������%c", 187);
	printf("\n\t�   %c USUARIO %c                �", 254, 175);
	printf("\n\t�������������������������������%c", 185);
	printf("\n\t�   %c NOME %c                   �", 254, 175);
	printf("\n\t�������������������������������%c", 185);
	printf("\n\t�   %c STAND %c                  �", 254, 175);
	printf("\n\t������������������������������ͼ");
	gotoxy(25,3);printf("%s", participante.usuario);
	gotoxy(23,5);printf("%s", participante.nome);
	gotoxy(23,7);printf("%s", nome);
	printf("\n\n\t");
	system("pause");
}

void mostra_participantes(){
	char nome[50];
	int pos = 5;
	gamers participante;
	FILE *arq = fopen("cad_participantes.dat", "rb");
	
	if(arq == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	system("cls");
	printf("\n\t\t\t\t\t\tUSUARIOS CADASTRADOS NO SISTEMA");
	printf("\n������������������������������������������������������������������������������������������������������������������������"); 
	while((fread(&participante, sizeof(participante), 1, arq)) && (participante.deletado != '*')){
		copia_nome(nome, participante.stand);
		printf("\n\t�������������������������������%c", 187);
		printf("\n\t�   %c USUARIO %c                �", 254, 175);
		printf("\n\t�������������������������������%c", 185);
		printf("\n\t�   %c NOME %c                   �", 254, 175);
		printf("\n\t�������������������������������%c", 185);
		printf("\n\t�   %c STAND %c                  �", 254, 175);
		printf("\n\t������������������������������ͼ");
		gotoxy(25,pos);printf("%s", participante.usuario);
		gotoxy(22,pos+2);printf("%s", participante.nome);
		gotoxy(23,pos+4);printf("%s", nome);
		printf("\n");
		pos+=7;
	}
	printf("\n\t");
	system("\n\tpause");
	fclose(arq);
}

void mostra_patrocinio(){
	float pat_total = 0;
	int pos = 5;
	patrocinadores empresa;
	FILE *arq = fopen("cad_patrocinadores.dat", "rb");
	
	system("cls");
	printf("\n\t\t\t\t\t\t\tPATROCINIOS\n");
	printf("������������������������������������������������������������������������������������������������������������������������");
	while(fread(&empresa, sizeof(empresa), 1, arq)){
		printf("\n\t�������������������������������%c", 187);
		printf("\n\t�   %c NOME %c                   �", 254, 175);
		printf("\n\t�������������������������������%c", 185);
		printf("\n\t�   %c PATROCINIO %c             �", 254, 175);
		printf("\n\t������������������������������ͼ");
		gotoxy(22,pos);printf("%s", empresa.nome);
		gotoxy(28,pos+2);printf("R$%.2f", empresa.quantia);
		printf("\n");
		pat_total += empresa.quantia;
		pos+=5;
	}
	printf("\n\n\t%c PATROCINIO TOTAL %c R$%.2f", 254, 175, pat_total);
	printf("\n\n\t");
	system("pause");
	fclose(arq);
}
//------- CADASTROS -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void cad_patrocinadores(){
	char email[150];
	patrocinadores empresa;
	FILE *arqPAT = fopen("cad_patrocinadores.dat", "ab+");
	
	if(arqPAT == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	system("cls");
	printf("\n\t\t\t\t\t\t\tCADASTRO DE PATROCINADOR");
	printf("\n������������������������������������������������������������������������������������������������������������������������");
	printf("\n\t%c NOME DA EMPRESA %c ", 254, 175);
	fflush(stdin);
	leValidaNome(empresa.nome);
	leValidaEmailPat(email);
	strcpy(empresa.email, email);
	empresa.stand_escolhido = leValidaStandPat();
	printf("\n\t%c PATROCINIO %c ", 254, 175);
	scanf("%f", &empresa.quantia);
	fwrite(&empresa, sizeof(empresa), 1, arqPAT);
	fclose(arqPAT);
}

void cad_participantes(int total_stands[]){
	char user[50], nome[100];
	gamers participante;
	FILE *arqPAR = fopen("cad_participantes.dat", "ab+");

	system("cls");
	if(arqPAR == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");	
		return;
	}
	printf("\n\t\t\t\t\t\t\tCADASTRO DE PARTICIPANTES");
	printf("\n������������������������������������������������������������������������������������������������������������������������");
	printf("\n\t%c BEM-VINDO, GAMER. DIGITE SEU NOME %c ", 254, 175);
	leValidaNome(participante.nome);
	printf("\n\tOLA, %s.", participante.nome);
	leValidaUsuario(user);
	strcpy(participante.usuario, user);
	participante.stand = leValidaStand();
	participante.deletado = ' ';
	fwrite(&participante, sizeof(participante), 1, arqPAR);
	fclose(arqPAR);
	gotoxy(47, 15);printf("CADASTRO REALIZADO COM SUCESSO!");
	Sleep(1000);
	menu_participantes();
}

void cad_empresas(){
	FILE *arqEMP;
	char email[150];
	int senha;
	organizadores empresa;
	
	srand(time(NULL));
	arqEMP = fopen("cad_organizadores.dat", "ab");
	if(arqEMP == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");	
		return;
	}
	system("cls");
	printf("\n\t\t\t\t\t\t  CADASTRO DE ORGANIZADOR");
	printf("\n������������������������������������������������������������������������������������������������������������������������"); 
	printf("\n\t%c NOME DA EMPRESA ORGANIZADORA %c ", 254, 175);
	fflush(stdin);
	leValidaNome(empresa.nome);
	leValidaEmailOrg(email);
	strcpy(empresa.email, email);
	senha = 1000 + (rand() % 1000);
	empresa.senha = senha;
	printf("\n\t%c SENHA DE ACESSO PARA INFORMACOES DO EVENTO %c %d", 254, 175, empresa.senha);
	fwrite(&empresa, sizeof(empresa), 1, arqEMP);
	fclose(arqEMP);
	printf("\n\n\t");
	system("pause");
}
//------- ALTERACAO DE DADOS -------------------------------------------------------------------------------------------------------------------------------------------------------------
void alterar_dados_participante(){
	int op, flag = 0, pos = 4;
	char stand, user[50], tecla;
	gamers participante;
	FILE *arqPAR = fopen("cad_participantes.dat", "r+b");
	
	if(arqPAR == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");	
		return;
	}
	do{
		system("cls");
		flag = 0;
		gotoxy(52,10);printf("��������������������������%c", 187);
		gotoxy(52,11);printf("� USUARIO:                �");
		gotoxy(52,12);printf("�������������������������ͼ\n\t");
		gotoxy(63,11);
		fflush(stdin);
		gets(user);
		while(fread(&participante, sizeof(participante), 1, arqPAR) && participante.deletado != '*');
		if(strcmp(user, participante.usuario) == 0){
			mostra_participante(participante);
			do{
				system("cls");
				printf("\n\tESCOLHA O QUE DESEJA ALTERAR\n", 175);
				printf("\n\t%c STAND", 254);
				printf("\n\t%c USUARIO", 254);
				gotoxy(19, pos);printf("%c", 174);
				tecla = getch();
				if(tecla == DOWN)
					pos += 1;
				if(tecla == UP)
					pos -= 1;
				if(pos > 5)
					pos = 4;
				if(pos < 4)
					pos = 5;
			}while(tecla != ENTER);
			switch(pos){
				case 4: 
					participante.stand = leValidaStand();
					break;
				case 5:
					leValidaUsuario(user);
					strcpy(participante.usuario, user);
					break;
			}
			fseek(arqPAR, -sizeof(participante), SEEK_CUR);
			fwrite(&participante, sizeof(participante), 1, arqPAR);
		}
		if(strcmp(user, participante.usuario) != 0){
			flag = 1;
			printf("\n\t\t\t\tUSUARIO NAO CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
			Sleep(200);
		}
	}while(flag == 1);
	fclose(arqPAR);
}

//------ EXCLUIR CADASTRO DE PARTICIPANTE ---------------------------------------------------------------------------------------------------------------------------------------
void excluir_cadastro_participante(){
	int flag = 0, pos = 4;
	char user[50], tecla;
	gamers participante;
	FILE  *arqPAR = fopen("cad_participantes.dat", "ab+");
	
	if(arqPAR == NULL){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	do{
		system("cls");
		printf("\n\t\t\t\t\t        EXCLUSAO DE CADASTROS");
		printf("\n������������������������������������������������������������������������������������������������������������������������");
		printf("\n\t%c EXCLUIR PARTICIPANTE", 254);
		printf("\n\t%c ORGANIZAR CADASTROS", 254);
		gotoxy(30, pos);printf("%c", 174);
		tecla = getch();
		if(tecla == DOWN)
			pos += 1;
		if(tecla == UP)
			pos -= 1;
		if(pos > 5)
			pos = 4;
		if(pos < 4)
			pos = 5;
	}while(tecla != ENTER);
	switch(pos){
		case 4:
			do{
				system("cls");
				flag = 0;
				gotoxy(52,10);printf("��������������������������%c", 187);
				gotoxy(52,11);printf("� USUARIO:                �");
				gotoxy(52,12);printf("�������������������������ͼ\n\t");
				gotoxy(63,11);
				fflush(stdin);
				gets(user);
				while(fread(&participante, sizeof(participante), 1, arqPAR));
				if(strcmp(user, participante.usuario) == 0){
					mostra_participante(participante);
					participante.deletado = '*';
					fseek(arqPAR, -sizeof(participante), SEEK_CUR);
					fwrite(&participante, sizeof(participante), 1, arqPAR);
				}
				if(strcmp(user, participante.usuario) != 0){
					flag = 1;
					printf("\n\t\t\t\tUSUARIO NAO CADASTRADO NO SISTEMA, TENTE NOVAMENTE!");
					Sleep(200);
				}
			}while(flag == 1);
			break;
		case 5:
			organizar_cads();
			break;
	}
	organizar_cads();	
	fclose(arqPAR);
}

void organizar_cads(){
	gamers participante;
	FILE *arq = fopen("cad_participantes.dat", "r+b");
	FILE *arq2 = fopen("cad_participantes.bak", "a+b");
	
	if ((arq == NULL) || (arq2 == NULL)){
		printf("\n\tERRO AO ABRIR O ARQUIVO!");
		return;
	}
	while(fread(&participante, sizeof(participante), 1, arq)){
		if(participante.deletado != '*')
			fwrite(&participante, sizeof(participante), 1, arq2);
	}
	remove("cad_participantes.dat");
	rename("cad_participantes.bak", "cad_participantes.dat");	
	fclose(arq);
	fclose(arq2);
}	
//------ SOBRE O EVENTO ---------------------------------------------------------------------------------------------------------------------------------------
void sobre(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSOBRE O EVENTO");
	printf("\n������������������������������������������������������������������������������������������������������������������������"); 
	printf("\n\t%c EVENTO DE GAMES PARA A COMUNIDADE DE ALUNOS DA UCB E ENTORNO.\n", 254);
	printf("\n\t%c QUALQUER ALUNO DE QUALQUER CURSO PODE PARTICIPAR.\n", 254);
	printf("\n\t%c OS PATROCINADORES PODEM SE CADASTRAR E ANALISAREMOS O CADASTRO.\n", 254);
	printf("\n\t%c AS EMPRESAS QUE DESEJAM SER ORGANIZADORAS DO EVENTO DEVEM FAZER O CADASTRO.\n", 254);
	printf("\n\t%c O EVENTO CONTERA 6 STANDS DE JOGOS, SENDO ELES: RPG, FPS, LUTA, CORRIDA, AVENTURA E ESPORTES.\n", 254);
	printf("\n\t%c CADA PARTICIPANTE PODE ESCOLHER APENAS UM STAND.\n", 254);
	printf("\n\t");
	system("pause");
	main();
}

void estatisticas(){
	char op, nome_maior_pat[50], tecla;
	int totalR = 0, totalF = 0, totalE = 0, totalA = 0, totalL = 0, totalC = 0, total = 0, pos = 10, totalS[6], i = 0, maior;
	int max = 120;//Maximo de participantes no evento
	float p1, p2, p3, p4, p5, p6, maior_patrocinio = 0;
	gamers participante;
	FILE *arq = fopen("cad_participantes.dat", "rb");
	FILE *arqPAT = fopen("cad_patrocinadores.dat", "rb");
	
	for(i = 0; i < 6; i++)
		totalS[i] = 0;
	while(fread(&participante, sizeof(participante), 1, arq)){
		total++;
		switch(participante.stand){
			case 'F': 
				//totalF++;
				totalS[0]++;
				break;
			case 'R': 
				//totalR++;
				totalS[1]++; 
				break;
			case 'E': 
				//totalE++;
				totalS[2]++; 
				break;
			case 'A': 
				//totalA++;
				totalS[3]++; 
				break;
			case 'L': 
				//totalL++;
				totalS[4]++; 
				break;
			case 'C': 
				//totalC++;
				totalS[5]++; 
				break;					
		}
	}
	do{
		do{
			system("cls");
			gotoxy(45,9);printf("����������������������������������������%c", 187);
			gotoxy(45,10);printf("�    %c TOTAL DE PARTICIPANTES           �", 254);
			gotoxy(45,11);printf("����������������������������������������%c", 185);
			gotoxy(45,12);printf("�    %c PORCENTAGEM DE CADA STAND        �", 254);
			gotoxy(45,13);printf("����������������������������������������%c", 185);
			gotoxy(45,14);printf("�    %c MAIS RENTAVEIS                   �", 254);
			gotoxy(45,15);printf("����������������������������������������%c", 185);
			gotoxy(45,16);printf("�    %c STAND COM MAIOR PATROCINIO       �", 254);
			gotoxy(45,17);printf("����������������������������������������%c", 185);
			gotoxy(45,18);printf("�    %c VOLTAR AO MENU DO ORGANIZADOR    �", 254);
			gotoxy(45,19);printf("���������������������������������������ͼ");
			gotoxy(82, pos);printf("%c", 174);
			tecla = getch();
			if(tecla == DOWN)
				pos += 2;
			if(tecla == UP)
				pos -= 2;
			if(pos > 18)
				pos = 10;
			if(pos < 10)
				pos = 18;
		}while(tecla != ENTER);
		switch(pos){
			case 10:
				system("cls");
				printf("\n\t��������������������������������������������%c", 187);
				printf("\n\t�   TOTAL DE PARTICIPANTES DO EVENTO %c  %d   �", 175, total);
				printf("\n\t�������������������������������������������ͼ\n\t");
				system("pause");
				break;
			case 12:
				system("cls");
				printf("\n\t��������������������������%c", 187);
				printf("\n\t�GENERO   � PORCENTAGEM   �");
				printf("\n\t��������������������������%c", 185);
				printf("\n\t�RPG      � %8.2f      �", p1 = (totalR*100)/max);
				printf("\n\t��������������������������%c", 185);
				printf("\n\t�FPS      � %8.2f      �", p2 = (totalF*100)/max);
				printf("\n\t��������������������������%c", 185);
				printf("\n\t�ESPORTES � %8.2f      �", p3 = (totalE*100)/max);
				printf("\n\t��������������������������%c", 185);
				printf("\n\t�AVENTURA � %8.2f      �", p4 = (totalA*100)/max);
				printf("\n\t��������������������������%c", 185);
				printf("\n\t�CORRIDA  � %8.2f      �", p5 = (totalC*100)/max);
				printf("\n\t��������������������������%c", 185);
				printf("\n\t�LUTA     � %8.2f      �", p6 = (totalL*100)/max);
				printf("\n\t�������������������������ͼ\n\t");
				system("pause");
				break;
			case 14:
				system("cls");
				printf("\n\t����������������������������������%c", 187);
				printf("\n\t�   MAIS RENTAVEL %c               �", 175);
				printf("\n\t���������������������������������ͼ\n");
				if(totalR > totalF && totalR > totalE && totalR > totalA && totalR > totalC && totalR > totalL){
					gotoxy(30,3);printf("RPG");
				}else if(totalF > totalR && totalF > totalE && totalF > totalA && totalF > totalC && totalF > totalL){
					gotoxy(30,3);printf("FPS");
				}else if(totalE > totalF && totalE > totalR && totalE > totalA && totalE > totalC && totalE > totalL){
					gotoxy(30,3);printf("ESPORTE");
				}else if(totalA > totalF && totalA > totalE && totalA > totalR && totalA > totalC && totalA > totalL){
					gotoxy(30,3);printf("AVENTURA");
				}else if(totalC > totalF && totalC > totalE && totalC > totalR && totalC > totalA && totalC > totalL){
					gotoxy(30,3);printf("CORRIDA");
				}else if(totalL > totalF && totalL > totalE && totalL > totalA && totalL > totalC && totalL > totalR){
					gotoxy(30,3);printf("LUTA");
				}
				printf("\n\n\t");	
				system("pause");				
				break;
			case 16:
				maior_patrocinio = maior_pat(nome_maior_pat);
				system("cls");
				printf("\n\t�������������������������������%c", 187);
				printf("\n\t�   %c PATROCINIO %c             �", 254, 175);
				printf("\n\t�������������������������������%c", 185);
				printf("\n\t�   %c STAND %c                  �", 254, 175);
				printf("\n\t������������������������������ͼ");
				gotoxy(28,3);printf("%.2f", maior_patrocinio);
				gotoxy(23,5);printf("%s", nome_maior_pat);
				printf("\n\n\t");
				system("pause");
				break;
			case 18:
				system("cls");
				menu_organizadores();
				break;			
		}
	}while(pos != 18);
}
//------ Mostrar o nome dos stands ----------------------------------------------------------------------------------------------------------------------------------------
void copia_nome(char nome[], char stand){
	switch(stand){
		case 'R':
			strcpy(nome, "RPG");
			break;
		case 'F':
			strcpy(nome, "FPS");
			break;
		case 'E':
			strcpy(nome, "ESPORTE");
			break;
		case 'A':
			strcpy(nome, "AVENTURA");
			break;
		case 'L':
			strcpy(nome, "LUTA");
			break;
		case 'C':
			strcpy(nome, "CORRIDA");
			break;				
	}
}
float maior_pat(char stand[]){
	FILE *arqPAT = fopen("cad_patrocinadores.dat", "rb");
	patrocinadores empresa;
	float patF = 0, patR = 0, patC = 0, patL = 0, patE = 0, patA = 0, maior = 0;
	
	while(fread(&empresa,sizeof(empresa), 1, arqPAT)){
		switch(empresa.stand_escolhido){
			case 'F':
				patF+=empresa.quantia;
			case 'R':
				patR+=empresa.quantia;
			case 'A':
				patA+=empresa.quantia;
			case 'E':
				patE+=empresa.quantia;
			case 'C':
				patC+=empresa.quantia;
			case 'L':
				patL+=empresa.quantia;		
		}
	}
	
	return maior;
}

void coloca_bordas(){
	int i;
	
	gotoxy(2, 29);printf("Versao 1.0 %c Todos os direitos reservados.", 175, 175);
	for(i = 0; i < 30; i++){
		gotoxy(1,i);printf("�");
		gotoxy(120,i);printf("�");
	}
	gotoxy(1,30);printf("�");
	gotoxy(120,30);printf("�");
	for(i = 0; i < 120; i++){
		gotoxy(i,1);printf("�");
		gotoxy(i,30);printf("�");
	}
	gotoxy(1,1);printf("�");
	gotoxy(120,1);printf("%c", 187);
}