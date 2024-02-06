#include <stdio.h> //biblioteca de comunicação com o usúario
#include <stdlib.h> // biblioteca de alocação de espaço em memória 
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro () // Função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/stings
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis
	
	
	printf ("Digite o CPF a ser cadastrado:\n");// solicitando a informação pro usuário
	scanf ("%s", &cpf);// scaneia o que o usuário digitar %s=string %d=int ?
	
	strcpy (arquivo, cpf); // copia o valor do cpf p arquivo
	
	FILE *file;
	file=fopen (arquivo, "w"); // w=writer // r=read // a=atualizar 
	fprintf (file,cpf);
	fclose (file);
	
	file=fopen (arquivo, "a");
	fprintf (file, ",");
	fclose (file);
	
	
	printf ("Digite o nome a ser cadastrado:\n");
	scanf ("%s", &nome);
	
	file=fopen (arquivo, "a");
	fprintf (file,nome );
	fclose (file);
	
	file=fopen (arquivo, "a");
	fprintf (file, ",");
	fclose (file);
	
	
	printf ("Digite o sobrenome:\n");
	scanf ("%s", &sobrenome);
	
	file=fopen (arquivo, "a");
	fprintf (file, sobrenome);
	fclose (file);
	
	file=fopen (arquivo, "a");
	fprintf (file, ",");
	fclose (file);
	
	
	printf ("Digite o cargo:\n");
	scanf ("%s", &cargo);
	
	file=fopen (arquivo, "a");
	fprintf (file, cargo);
	fclose (file);
	
	file=fopen (arquivo, "a");
	fprintf (file, ".");
	fclose (file);
	
	
	system ("pause"); // da um pequeno pause no sistema
	
	
}

int consulta ()
{
	setlocale (LC_ALL, "Portuguese");
	
	char cpf [40]; // cria a variável cpf novamente, pois cada função só enxerga as próprias variáveis
	char conteudo [200]; // cria a variável cpf novamente, pois cada função só enxerga as próprias variáveis
	
	printf ("Digite o CPF a ser consultado.\n");
	scanf ("%s" ,&cpf);
	system ("cls");
	
	FILE *file;
	file=fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf ("CPF não encontrado.\n\n");
		system ("pause");
	}
	
	while (fgets(conteudo,200,file)!= NULL)
	{
	printf ("Essa são as informações do usuário.\n\n");
	printf ("%s", &conteudo);
	printf ("\n\n");
	
	system ("Pause");
}
}

int deletar ()
{
	
	char cpf [40]; // cria a variável cpf novamente, pois cada função só enxerga as próprias variáveis
	
	printf ("Digite o CPF a ser deletado.\n\n");
	scanf ("%s",&cpf);
	
	remove(cpf); // comando para remover do banco de dados o (cpf)
	
	FILE *file;
	file= fopen (cpf,"r");
	
	
	
	if (file == NULL); // comando if else // se == NULL -> comando. Se não {comando}
	{
		printf ("\nCPF não existe na base de dados ou já foi deletado, obrigado.\n\n");	
}
	
	
		
	system ("pause");
}


int nao ()
{
	printf ("Essa opção não existe.");
	system("pause");
}




int main ()
{
	
	int laco=1;
	for (laco=1;laco=1;)
	
{
	system("cls");
	int opcao=0;

	setlocale (LC_ALL, "Portuguese");
	
	printf ("\t### Bem vindo ao menu ###\n\n");
	printf ("Escolha uma opção do menu:\n\n");
	printf ("\t1- Registrar nomes\n");
	printf ("\t2- Consultar nomes\n");
	printf ("\t3- Deletar nomes\n");
	printf ("Opção:");
	
	scanf ("%d", &opcao);
	system ("cls");
	
	switch (opcao) // seleção, parecido com o if
	
{
	
	case 1: // caso escolha 1
		registro (); // comando, printf ("lala"); ou qualquer outro, como a função registro (); sendo puxada caso o usuário digite 1
	break; // fecha o case 1
	
	case 2:
		consulta ();
	break;
	
	case 3:
		deletar ();
	break;
	
	default:
		nao ();
	break;
}
	
}
	
}
