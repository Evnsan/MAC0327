/*Implementacao de uma arvore binaria de busca */
/*Codigo baseado no codigo apresentado no livro
  "Introduction to Algorithms" - Cormen, 
  Leiserson, Rivest e Stein                    */
/***********************************************/
#include<stdlib.h>
#include<stdio.h>

/*dados satelites*/
typedef long int key;
typedef struct item *Item;
struct item{
    key left;
    key right;
    };

/*estrutura da arvore*/
typedef struct node *Node;
struct node{
    Item data;
    Node p;
    Node left;
    Node right;
    };

/*variaveis globais para tree*/
Node pool, tree;


/*funcoes especicas do problema*/
/*cria Item*/
Item criaitem(key left, key right){
    Item z;
    z = (Item)malloc(sizeof(*z));
    z->left = left;
    z->right = right;
    return z;
}

/*getkey*/
key getkey(Item z){
    return z->left;
}

/*funcoes auxiliares*/

/*inicializa*/
int inicializa(int n){
    int i;
    Node tmp = NULL, pool = NULL;
    for(i = 0; i < n; i++){
        tmp = malloc(sizeof(*tmp));
        tmp->right = NULL;
        tmp->left = NULL;
        tmp->p = pool;
        pool = tmp;
    }
    return 0;
}

/*cria Node*/
Node crianode(Item z){
    Node x;
    if(pool == NULL){
        printf("ERRO:Pool vazia\n");
        return NULL;
    }
    x = pool;
    pool = pool->p;
    x->p = NULL;
    x->data = z;
    return x;
}

/*mim*/
Node minimo(Node x){
    while(x != NULL)
        x = x->left;
    return x;
}

/*max*/
Node maximo(Node x){
    while(x != NULL)
        x = x->right;
    return x;
}

/*sucessor*/
Node sucessor(Node x){
    Node y;

    if(x->right != NULL)
            return minimo(x->right);
    y = x->p;
    while(y != NULL && x == y->right){
        x = y;
        y = y->p;
    }
    return y;
}

/*predecessor*/
Node predecessor(Node x){
    Node y;

    if(x->left != NULL)
            return maximo(x->left);
    y = x->p;
    while(y != NULL && x == y->left){
        x = y;
        y = y->p;
    }
    return y;
}
1
/*busca*/
Node busca(Node x, key k){
    while(x == NULL || getkey(x) == k){
        if(k < getkey(x))
            x = x->left;
        else
            x = x->left;
    }
    return x;
}

/*remove*/
/*supoe tree->p = NULL*/
Node remove(Node tree, Node z){
    Node x, y;
    /***definindo y para splice out***/
    if(z->left == NULL || z->right == NULL)
        y = z;
    else
        y = sucessor(z);
    /***definindo x = filho para remanejar ou x = NULL***/
    if(y->left != NULL)
        x = y->left;
    else
        x = y->right;
    /***splice out de y***/
    if(x != NULL)
        x->p = y->p;
    if(y->p == NULL)
        tree = x;
    else if(y == y->p->left)
        y->p->left = x;
    else
        y->p->right = x;
    /***copiando z em y***/
    if( y != z)
        z->data = y->data;
    return y;
}
        
/*insere*/
int insere(Node z){
    Node y = NULL;
    Node x = tree;
    while(x != NULL){
        y = x;
        if(getkey(z->data) < getkey(x->data))
            x = x->left;
        else
            x = x->right;
    }
    z->p = y;
    if(y == NULL)
        tree = z;
    else if(getkey(z->data) < getkey(y->data))
        y->left = z;
    else
        y->right = z;
    return 0;
}

/**********************************/
/*programa principal*/
int main(){
    return 0;
    }
