#include <stdio.h>
#include <stdlib.h>
 
int r = 0, count = 0, c, achou = 0;

typedef struct Tree {
	int val;
	struct Tree* esquerda;
	struct Tree* direita;
	struct Tree* head;
	int altura;
} AvlTree;

struct Tree* newnode(int nvfolha);
struct Tree* insertnode(AvlTree* arv, int nvfolha);

int findInorder(AvlTree* node, int x);
int printInorder(AvlTree* node, int x);

void rotDireita(AvlTree* r);
void rotDDireita(AvlTree* r);
void rotDEsquerda(AvlTree* r);
void rotEsquerda(AvlTree* r);


int main() {
	AvlTree* arvore = NULL;
	int input;
	scanf("%d", &input);
	
	for(int i = 0; i < input;i++){
		int input2;
		scanf("%d", &input2);
		if (input2 ==1){
				int x;
				scanf("%d", &x);	
				arvore = insertnode(arvore,x);
				
				
		}
		if (input2 == 2){
			int v;
			c=1;
			achou = 0;
			scanf("%d", &v);
			v = findInorder(arvore, v);
			if (v == 0)
				printf("Data tidak ada\n"); 
			
		}
		if (input2 == 3)
			printInorder(arvore, 1);
	}

}
struct Tree* newnode(int nvfolha){

	AvlTree* atual = (AvlTree*)malloc(sizeof(AvlTree));
	atual-> val = nvfolha;
	atual -> direita = NULL;
	atual -> esquerda = NULL;
	atual -> altura = 0;
	return atual;
}

struct Tree* insertnode(AvlTree* arv, int nvfolha){
	
	
	if(arv == NULL){

		return newnode(nvfolha);
	}
	else{
		if(arv -> val < nvfolha){
		
			arv -> altura = arv ->altura +1;
			arv -> direita = insertnode(arv -> direita, nvfolha);
		
		}		
		if(arv -> head != NULL && arv -> head ->altura == 2){ //NÃO TA PEGANDO
			if(arv -> altura == -1)
				rotDEsquerda(arv);	
			if(arv -> altura == 1)
				rotDireita(arv);	
		} 
		if (arv -> val > nvfolha) {
	
			arv -> altura = arv ->altura -1;
			arv -> esquerda = insertnode(arv -> esquerda, nvfolha);
			
		}
		if(arv -> head != NULL && arv -> head ->altura == -2){//NÃO TA PEGANDO
			if(arv -> altura == -1)
					rotEsquerda(arv);	
				if(arv -> altura == 1)
					rotDDireita(arv);	
		}	
	}
	return arv;
}
int findInorder(AvlTree* node, int x) { 
	
	if (node == NULL ) { 
		if(achou == 1)
			return 1;
		return 0;
	}		
    
    findInorder(node->esquerda,x); 
    if(node -> val > x)
    	return 0;
	if(node -> val == x){
		achou = 1;
		printf("%d\n", c);
		return 1;
	}
	c++;
	findInorder(node->direita,x);
	
	
} 
int printInorder(AvlTree* node, int x) 
{ 
	if (node == NULL) {
		return 0;
	}  	
   	printInorder(node->esquerda,x); 
	printf("%d\n", node -> val);
	printInorder(node->direita,x); 
}

void rotDireita(AvlTree* r){
	AvlTree *noA;
	noA = r;
	noA->direita = (r)->head;
	noA->esquerda = (r)->esquerda;
	r = noA;
	noA -> head = r;
}

void rotEsquerda(AvlTree* r){
	AvlTree *noA;
	noA = r;
	noA->esquerda = (r)->head;
	noA->direita = (r)->direita;
	r = noA;
	noA -> head = r;
}

void rotDDireita(AvlTree* r){
	AvlTree *noA;
	noA = (r)->esquerda;
	noA->direita = r;
	noA->head = (r)->head;
	rotEsquerda(noA);
}

void rotDEsquerda(AvlTree* r){
	AvlTree *noA;
	noA = (r)->direita;
	noA->esquerda = r;
	noA->head = (r)->head;
	rotDireita(noA);
}
