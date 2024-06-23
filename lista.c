#include <stdio.h>
#include <stdlib.h>

// aqui se criou um novo tipo de dado
typedef struct no No;
struct no {
	int valor;
	No* prox;
	No* ante;
};

// aqui foi criado dois ponteiros que apontam para o inicio da lista e um outro para o fim
No *inicio;
No *fim;

// aqui é o metodo costrutor
void criaLista() {
	inicio = NULL;
	fim = NULL;
}

// Metodo para inserir dados no lista duplamente encadeada pelo inicio 
void insereInicio(int novoValor) {
	//Aqui se trata o primeiro caso
	No *novoNo = (No*) malloc(sizeof(No));// aqui se atribuio o tamanho da lista 
	novoNo->valor = novoValor;// o novoNo está apontando para o valor
	novoNo->prox = NULL;// definindo que os outros nos são nulos
	novoNo->ante = NULL;// definindo que os outros nos são nulos
	//Aqui se trata do segundo caso
	if (inicio == NULL) {
		inicio = novoNo;
		fim = novoNo;
	//aqui se trata do terceiro caso
	} else {
		No* aux = inicio;
		novoNo->prox = aux;
		novoNo->prox->ante = novoNo;
		inicio = novoNo;
	}
}
// Metodo para inserir dados no lista duplamente encadeada pelo fim
void insereFim(int novoValor) {
	//Aqui se trata o primeiro caso
	No *novoNo = (No*) malloc(sizeof(No));// aqui se atribuio o tamanho da lista 
	novoNo->valor = novoValor;// o novoNo está apontando para o valor
	novoNo->prox = NULL;// definindo que os outros nos são nulos
	novoNo->ante = NULL;// definindo que os outros nos são nulos
	//Aqui se trata do segundo caso
	if (fim == NULL) {
		inicio = novoNo;
		fim = novoNo;
	//aqui se trata do terceiro caso
	} else {
		No* aux = fim;
		novoNo->ante = aux;
		novoNo->ante->prox = novoNo;
		fim = novoNo;
	}
}

//Aqui é o metodo para se imprimir na tela
void imprimeApartirInicio() {
	No* auxiliar;
	auxiliar = inicio;
	while(auxiliar) {
		printf("[%i]", auxiliar->valor);
		auxiliar = auxiliar->prox;
	}
}

// Função que recebe um valor


void busca(No* no, int varValor){
	No* auxiliar;
	auxiliar = inicio;
	if(fim == NULL){
		return;
	}
	if (auxiliar->valor == varValor){
		printf("O valor estar na lista");
		return;
	}
	busca(auxiliar->prox, varValor);
}

//Aqui é o metodo para se imprimir de forma reversa o dado
void imprimeReverso() {
	No* auxiliar;
	auxiliar = fim;
	while(auxiliar) {
		printf("[%i]", auxiliar->valor);
		auxiliar = auxiliar->ante;
	}
}
// metodo que imprime de forma recursiva
void imprimeRecursivo(No* no){
	if (fim == NULL ){
		return;
	}
	printf("[%d]", no->valor);
	imprimeRecursivo(no->prox);	
}
// A classe que executa os metodos
int main() {
	int dado;
    printf("informe um valor para verificar os valores\n");
    scanf("%d", &dado);

	// Criando a lista e populando ela. 
	criaLista();
	insereInicio(4);
	insereInicio(2);
	insereInicio(6);
	insereFim(5);
	insereFim(8);

	//Implementando as impressões
	imprimeApartirInicio();
	printf("\n");
	imprimeReverso();
	printf("\n");
	imprimeRecursivo(inicio);
	
	//Implementação
	busca(inicio, dado);
}