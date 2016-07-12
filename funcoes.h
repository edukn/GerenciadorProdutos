/*Header file para distinguir o .c das funcoes principais*/
//Desenvolvido por EduardoKNeto
//structs para armazenar produtos
typedef struct produto{
	int id, quantidade, status;
	char nome[25];
	float preco;
}produto;

typedef struct estoque{
	produto produtos[200]; //maximo 200 produtos
}estoque;

void menuPrincipal()
{
	system("cls");
	printf("SISTEMA DE VENDAS\n\n");
	printf("Escolha uma opcao:\n-----------------\n\n1-Cadastrar Produto\n\n2-Informar Venda\n\n3-Visualizar Produtos\n\n");
	printf("4-Editar Produto\n\n");
	printf("5-Sair\n\n");
	printf("Opcao:");
}

//Cadastro de produtos
void cadastrar(estoque cat[], int posicao, int id, int tipo)
{
	//tipo 1 = cadastro, tipo 2 = editar
	produto p;
	fflush(stdin);
	printf("Digite o nome do produto: ");
	scanf("%s", &p.nome);
	printf("\n\nDigite a quantidade: ");
	scanf(" %d", &p.quantidade);
	printf("\n\nDigite o preco: ");
	scanf(" %f", &p.preco);
	if(tipo == 1)
	{
		p.id = id;
		p.status = 1;
		(*cat).produtos[posicao] = p;
		printf("\n\nCadastro concluido!");
	}
	else
	{
		p.id = posicao;
		p.status = 1;
		(*cat).produtos[posicao-1] = p;
		printf("\n\nEdicao concluida!");
	}
	getch();
}

//Visualizar produtos
void exibir(estoque cat[], int posicao)
{
	int i;
	for(i=0;i<=posicao-1;i++)
	{
		printf("------------------PRODUTO-----------------\n");
		printf("ID: %d", (*cat).produtos[i].id);
		printf("\nNome: %s", (*cat).produtos[i].nome);
		printf("\nQuantidade: %d", (*cat).produtos[i].quantidade);
		printf("\nPreco: %.2f", (*cat).produtos[i].preco);
		printf("\n------------------------------------------\n\n");
	}
}

//Vender produtos
void vender(estoque cat[], int posicao)
{
	int qtd, flag = 0;
	if((*cat).produtos[posicao].quantidade == 0)
	printf("\nProduto Esgotado!");
	else
	{
		do{
			printf("\nDigite a quantidade vendida: ");
			scanf("%d", &qtd);
			if((*cat).produtos[posicao].quantidade < qtd)
				flag = 1;
			else
			flag = 0;
		}while(flag == 1);
		if((*cat).produtos[posicao].quantidade > 0){
			(*cat).produtos[posicao].quantidade -= qtd;
			printf("\nProduto(s) Vendido(s)!");
		}else
			printf("PRODUTO ESGOTADO!");
	}
		getch();
		
}
