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

int insertnode(AvlTree* arv);
int findInorder(AvlTree* node, int x);
int printInorder(AvlTree* node, int x);
void rotDireita(AvlTree* r);
void rotDDireita(AvlTree* r);
void rotDEsquerda(AvlTree* r);
void rotEsquerda(AvlTree* r);
void inserirAVL (AvlTree* r, int x);
int MAXIMO(int altDireita,int altEsquerda);
int altura(AvlTree *no);
int atualizaAltura(AvlTree *no);


int main() {
	AvlTree* arvore = (AvlTree*)malloc(sizeof(AvlTree));
	int input;
	scanf("%d", &input);
	for(int i = 0; i < input;i++){
		int input2;
		scanf("%d", &input2);
		if (input2 ==1){
				int nvfolha;
				scanf("%d", &nvfolha);	
			if (count == 0){
				count =1;
				arvore -> val = nvfolha;
				arvore -> direita = NULL;
				arvore -> esquerda = NULL;
				arvore -> altura = 0;
			
			} else{
			inserirAVL(arvore,nvfolha);	
			}	
		}
		if (input2 == 2){
			int v;
			c=0;
			achou = 0;
			scanf("%d", &v);
			v = findInorder(arvore, v);
			if (v == 0)
				printf("Data tidak ada"); 
			
		}
		if (input2 == 3)
			printInorder(arvore, 1);
	}

}

int insertnode(AvlTree* arv){
	int nvfolha;
	scanf("%d", &nvfolha);	
	
	AvlTree* atual = (AvlTree*)malloc(sizeof(AvlTree));
	atual -> val = nvfolha;
	atual -> direita = NULL;
	atual -> esquerda = NULL;
	atual -> altura = 0;
	while(1){
		if(arv -> val < nvfolha){
			arv -> altura = arv ->altura +1;
			if(arv -> direita == NULL){
				atual -> head = arv;						
				arv ->direita = atual;
				break;
			}
			arv = arv -> direita;
		}
		else{
			arv -> altura = arv ->altura -1;
			if(arv -> esquerda == NULL){
				atual -> head = arv;								
				arv ->esquerda = atual;
				break;
			}
			arv = arv -> esquerda;
		}	
		if(arv -> head ->altura == 2){
			if(arv -> altura == -1)
				rotDEsquerda(arv);	
			
			if(arv -> altura == 1)
				rotDireita(arv);	
			
		}	
		if(arv -> head ->altura == -2){
			if(arv -> altura == -1)
				rotEsquerda(arv);	
			
			if(arv -> altura == 1)
				rotDDireita(arv);	
			
		}
			
	}
		
}
int findInorder(AvlTree* node, int x) { 
	
	if (node == NULL || node -> val > x) { 
		if(achou == 1)
			return 1;
		return 0;
	}	
    	findInorder(node->esquerda,x); 
		
	if(node -> val == x){
		achou = 1;
		printf("%d", c);
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
void inserirAVL (AvlTree* r, int x){
	if(r  == NULL){
		r -> val = x;
		r -> esquerda = NULL;
		r -> direita = NULL;
		r -> altura =1 ;
	} else {
		if (x < r -> val){
			inserirAVL(r->esquerda, x);
		}	
		if ((altura(r->esquerda)) - altura(r->direita) == 2){
			if (x < r->esquerda->val){
				rotDireita(r);
			} 
			else {
				rotDDireita(r);			
			}
		}
		else {
			inserirAVL(r, x);
			if(altura(r -> direita)-altura(r -> esquerda) == 2){
				if(x > r -> direita -> val){
					rotDireita(r);
				}
				else {
					rotDEsquerda(r);
				}
			}
		}
	atualizaAltura(r);
	}
}
int atualizaAltura(AvlTree *no){
    int altDireita;
    int altEsquerda;

    if(no != NULL){
        altDireita <- altura(no->direita);
        altEsquerda<- altura(no->esquerda);
        no->altura <- MAXIMO(altDireita , altEsquerda) +1;

    }
}

int altura(AvlTree *no){
    if(no == NULL)
        return 0;
    else
        return no->altura;
}

int MAXIMO(int altDireita,int altEsquerda){
    if(altDireita>altEsquerda)
        return altDireita;
    else
        return altEsquerda;
}
