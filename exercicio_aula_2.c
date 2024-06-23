/*
Aluno: Matheus Vicente Santos Almeida
Disciplina: estrutura de dados 2

Atividade sobre lista circular 
*/


#include <stdio.h>
#include <stdlib.h>

// Criando o No
typedef struct no No;
struct no
{
	int valor; // tipo do valor da lista
	No *prox;  // nó que aponta para o proximo elemento da lista
	No *ante;  // nó que aponta para o elemnto anterior da lista
};

No *inicio; // nó aloca elementos no inicio da lista
No *fim;	// nó que aloca elementos no final da lista

// Criando a lista com os parâmetros iniciais nulos
void criaLista()
{
	inicio = NULL;
	fim = NULL;
}

// Método de inserir valores no inicio da lista
void insereInicio(int novoValor)
{
	// Verifica se um valor já está na lista
	No *aux = inicio;
	while (aux != NULL)
	{
		if (aux->valor == novoValor) // Faz a verificação se o novo valor inserido é igual a algum valor já existente na lista
		{
			printf("Valor %d ja esta na lista. Nao foi inserido novamente.\n", novoValor);
			return;
		}
		aux = aux->prox;
	}

	// Cria um novo nó no inicio da lista.
	No *novoNo = (No *)malloc(sizeof(No));
	novoNo->valor = novoValor;
	novoNo->prox = NULL;
	novoNo->ante = NULL;
	if (inicio == NULL) //Quando o inicio é nulo ele adiciona o novo nó ao inicio e fim da lista
	{
		inicio = novoNo;
		fim = novoNo;
	}
	else //Se a lista não estiver vazia o novo nó é inserido na posição correta e que os outros nós sejam ajustados para acomodar o novo nó no inicio da lista.
	{
		No *aux = inicio;
		novoNo->prox = aux;
		novoNo->prox->ante = novoNo;
		inicio = novoNo;
	}
}

//Insere os elementos no final da lista 
void insereFim(int novoValor)
{
	// Verifica se um valor já está na lista
	No *aux = inicio;
	while (aux != NULL)
	{
		if (aux->valor == novoValor) // Faz a verificação se o novo valor inserido é igual a algum valor já existente na lista
		{
			printf("Valor %d ja esta na lista. Nao foi inserido novamente.\n", novoValor);
			return;
		}
		aux = aux->prox;
	}
	// Cria um novo nó no fim da lista.
	No *novoNo = (No *)malloc(sizeof(No));
	novoNo->valor = novoValor;
	novoNo->prox = NULL;
	novoNo->ante = NULL;
	if (fim == NULL) //Quando o fim é nulo ele adiciona o novo nó ao inicio e fim da lista
	{
		fim = novoNo;
		inicio = novoNo;
	}
	else //Se a lista não estiver vazia o novo nó é inserido na posição correta e que os outros nós sejam ajustados para acomodar o novo nó no fim da lista.
	{
		No *aux = fim;
		novoNo->ante = aux;
		novoNo->ante->prox = novoNo;
		fim = novoNo;
	}
}

//Imprime o resultado 
void imprime()
{
	No *aux;
	aux = inicio; //o nó auxiliar aponta para o nó de inicio 

	//Percorre o nó até serem exibidos todod od valores armazenados em valor
	while (aux)
	{
		printf("[%i] ", aux->valor); //imprime os valores armazenados em valor
		aux = aux->prox;
	}
}

//Imprime a lista a partir do ultimo valor dela 
void imprimeReverso()
{
	No *aux;
	aux = fim; //o nó auxiliar é igual ao fim da lista 
	//Percorre a lista apartir do seu fim 
	while (aux)
	{
		printf("[%i] ", aux->valor); //imprime os valores
		aux = aux->ante;
	}
}

//Exibe os valores de forma recursiva 
void exibirRecursivamente(No *noAtual)
{
	if (noAtual == NULL)
		return;

	exibirRecursivamente(noAtual->prox);
	printf("[%d] ", noAtual->valor);
}

//Busca valores na lista 
No *buscarNaLista(int valorBuscado)
{
	No *aux = inicio;

	while (aux != NULL) //enquanto o nó auxiliar não for nulo vai ocorrer a busca do valor 
	{
		if (aux->valor == valorBuscado)  
			return aux; //retorna o ponteiro para o nó com o valor buscado
		aux = aux->prox;
	}

	return NULL; //retorna nulo se o valor não for encontrado 
}

int main()
{
	criaLista();
	//Inserção dos elementos 
	insereInicio(4);
	insereInicio(2);
	insereInicio(6);
	insereInicio(6);
	insereFim(5);
	insereFim(5);
	insereFim(3);
	insereFim(8);
	
	//Mostra na tela os valores adicionados com diferentes métodos de exibição
	imprime();
	printf("\n");
	imprimeReverso();
	printf("\n");
	exibirRecursivamente(inicio);
	printf("\n");

	//Essa função deveria receber o valor e buscalo na lista só que ela não está fazendo a busca de forma adequada
	int valorBuscado;
	printf("Insira o valor que deseja buscar: \n");
	scanf("%i", valorBuscado);

	No *resultadoBusca = buscarNaLista(valorBuscado);

	if (resultadoBusca != NULL)
		printf("\nValor %i encontrado na lista!\n", valorBuscado);
	else
		printf("\nValor %i nao encontrado na lista.\n", valorBuscado);
}
