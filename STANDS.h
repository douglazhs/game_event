void stands(){
	gamers participante;
	patrocinadores empresa;
	int totalR = 0, totalF = 0, totalE = 0, totalA = 0, totalL = 0, totalC = 0;
	int m = 20;//Limite
	FILE *arq = fopen("cad_participantes.dat", "rb");
	FILE *arqPAT = fopen("cad_patrocinadores.dat", "rb");
	
	while(fread(&participante, sizeof(participante), 1, arq)){
		switch(participante.stand){
			case 'F': totalF++; break;
			case 'R': totalR++; break;
			case 'E': totalE++; break;
			case 'A': totalA++; break;
			case 'L': totalL++; break;
			case 'C': totalC++; break;					
		}
	}
	system("cls");
	printf("\n\t\t\t\t\t\t\tSTANDS");
	printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様");
	printf("\n\t\t\t\t\t浜様様様様様曜様様様様様様僕様様様様様�%c", 187);
	printf("\n\t\t\t\t\t�  FPS       �  RPG       �  ESPORTE   �");
	printf("\n\t\t\t\t\t�            �            �            �");
	printf("\n\t\t\t\t\t�  vagas = %d�  vagas = %d�  vagas = %d�", m-totalF, m-totalR, m-totalE);
	printf("\n\t\t\t\t\t麺様様様様様洋様様様様様様陵様様様様様�%c", 185);
	printf("\n\t\t\t\t\t�  AVENTURA  �  LUTA      �  CORRIDA   �");
	printf("\n\t\t\t\t\t�            �            �            �");
	printf("\n\t\t\t\t\t�  vagas = %d�  vagas = %d�  vagas = %d�", m-totalA, m-totalL, m-totalC);
	printf("\n\t\t\t\t\t藩様様様様様擁様様様様様様瞥様様様様様夕");
	printf("\n\n\t\t\t\t\t");
	fclose(arq);
}

void stands_patrocinador(){
	system("cls");
	printf("\n\t\t\t\t\t\t\tSTANDS");
	printf("\n様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様");
	printf("\n\t\t\t\t\t浜様様様様様曜様様様様様様僕様様様様様�%c", 187);
	printf("\n\t\t\t\t\t�  FPS       �  RPG       �  ESPORTE   �");
	printf("\n\t\t\t\t\t�            �            �            �");
	printf("\n\t\t\t\t\t�            �            �            �");
	printf("\n\t\t\t\t\t麺様様様様様洋様様様様様様陵様様様様様�%c", 185);
	printf("\n\t\t\t\t\t�  AVENTURA  �  LUTA      �  CORRIDA   �");
	printf("\n\t\t\t\t\t�            �            �            �");
	printf("\n\t\t\t\t\t�            �            �            �");
	printf("\n\t\t\t\t\t藩様様様様様擁様様様様様様瞥様様様様様夕");
	printf("\n\n\t\t\t\t\t");
}
