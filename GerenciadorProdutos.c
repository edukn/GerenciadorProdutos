//Desenvolvido por EduardoKNeto
#include <stdio.h>
#include "funcoes.h"

main()
{
	char op;
	int id = 1, n, vend, posicao = 0;
	estoque catalogo;
	do{
		menuPrincipal();
		scanf("%d",&n);
		if(n<1 || n>5)
		{
			printf("Opcao Invalida!");
			getch();
		}
		system("cls");
		switch(n)
		{
			case 1:
				cadastrar(&catalogo, posicao, id, 1);
				posicao++;
				id++;
			break;
			case 2:
				if(id == 1)
				{
					printf("\nNao ha produtos cadastrados!");
					getch();
					break;
				}
				do{
					exibir(&catalogo, posicao);
					printf("\nDigite a ID do produto vendido: ");
					scanf("%d", &vend);
					if(vend < 1 || vend > id-1) { printf("\nID inexistente!"); getch(); system("cls"); }
				}while(vend < 1 || vend > id-1);
				vender(&catalogo, vend-1);
			break;
			case 3:
				exibir(&catalogo, posicao);
				getch();
			break;
			case 4:
				if(id == 1)
				{
					printf("\nNao ha produtos cadastrados!");
					getch();
					break;
				}
				do{
					exibir(&catalogo, posicao);
					printf("\nDigite a ID do produto a ser editado: ");
					scanf("%d", &vend);
					printf("\n");
					if(vend < 1 || vend > id-1) { printf("\nID inexistente!"); getch(); system("cls"); }
				}while(vend < 1 || vend > id-1);
				cadastrar(&catalogo, vend, id, 2);
			break;
			case 5:
				exit(1);
			break;
		}
	}while(1);
	
}
