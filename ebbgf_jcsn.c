#include <stdio.h>
#include <stdlib.h>
 
int ro = 0, count = 0, achou = 0;

typedef struct Tree {
	int val;
	struct Tree* esquerda;
	struct Tree* direita;
	struct Tree* head;
	int nodesD;
	int nodesE;
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
		//printf("%d - ", i);
		int input2;
		scanf("%d", &input2);
		if (input2 ==1){
			int x;
			scanf("%d", &x);	
			arvore = insertnode(arvore,x);
				
				
		} else if (input2 == 2){
			int v;
			achou = 0;
			scanf("%d", &v);
			
			v = findInorder(arvore, v);
			
			
			if (v == 0)
				printf("Data tidak ada\n"); 
			else
				printf("%d\n", v);
			
		}
	}

}
struct Tree* newnode(int nvfolha){

	AvlTree* atual = (AvlTree*)malloc(sizeof(AvlTree));
	atual-> val = nvfolha;
	atual -> direita = NULL;
	atual -> esquerda = NULL;
	atual -> nodesD = 0;
	atual -> nodesE = 0;
	return atual;
}

struct Tree* insertnode(AvlTree* arv, int nvfolha){
	
	
	if(arv == NULL){

		return newnode(nvfolha);
	}
	else{
		if(arv -> val < nvfolha){
		
			arv -> altura = arv ->altura +1;
			arv -> nodesD++;
			arv -> direita = insertnode(arv -> direita, nvfolha);
			}		
		
		if(arv -> head != NULL && arv -> head ->altura == 2){
			if(arv -> altura == -1)
				rotDEsquerda(arv);	
			if(arv -> altura == 1)
				rotDireita(arv);
			// atualiza altura
			arv -> altura = 0;
			arv -> direita -> altura =0;
			arv -> esquerda -> altura =0;
			arv -> nodesE--;	
			} 
		
		if (arv -> val > nvfolha) {
	
			arv -> altura = arv ->altura -1;
			arv -> nodesE++;
			arv -> esquerda = insertnode(arv -> esquerda, nvfolha);
			
			}
		
		if(arv -> head != NULL && arv -> head ->altura == -2){
			if(arv -> altura == -1)
					rotEsquerda(arv);	
				if(arv -> altura == 1)
					rotDDireita(arv);
			arv -> altura = 0;
			arv -> direita -> altura =0;
			arv -> esquerda -> altura =0;	
			arv -> nodesD--;	
		}	
	}
	return arv;
}
int findInorder(AvlTree* node, int x) { 
	
    
	if (node == NULL ) { 
		return 0;
		}
	
	else {			
    		if(node ->val == x){
    			return node -> nodesE+1;
			
			}
		else if(node -> val > x) {
			
   	 		return findInorder(node->esquerda,x); 
   	 		
  	  		}
 	   	else {
  	  		return node -> nodesE + 1 + findInorder(node->direita,x);
    			}
    			
    		}
    	
    		
	
	
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
