/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
/***********Problema 22*************/
/***********************************/

/*Implementacao de     arvore binaria de busca */
/*Codigo baseado no codigo apresentado no livro*/
/*  "Introduction to Algorithms" - Cormen,     */
/*  Leiserson, Rivest e Stein                  */
/***********************************************/
#include<stdlib.h>
#include<stdio.h>

/*dados satelites*/
typedef long int key;
typedef struct item *Item;
struct item{
    key number;
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
Item criaItem(key number){
    Item z;
    z = (Item)malloc(sizeof(*z));
    z->number = number;
    return z;
}

/*getKey*/
key getKey(Item z){
    if(z != NULL)
        return z->number;
    printf("ERRO: getKey recebeu NULL\n");
    return 0;
}

/*funcoes auxiliares*/

/*inicializa*/
int inicializa(int n){
    int i;
    Node tmp = NULL;
    pool = NULL;
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
Node criaNode(Item z){
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
    if(x == NULL)
        return x;
    while(x->left != NULL)
        x = x->left;
    return x;
}

/*max*/
Node maximo(Node x){
    if(x == NULL)
        return x;
    while(x->right != NULL)
        x = x->right;
    return x;
}

/*sucessor*/
Node sucessor(Node x){
    Node y;

    if(x == NULL)
        return x;
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

    if(x == NULL)
        return x;
    if(x->left != NULL)
            return maximo(x->left);
    y = x->p;
    while(y != NULL && x == y->left){
        x = y;
        y = y->p;
    }
    return y;
}

/*busca*/
Node busca(Node x, key k){
    while(x != NULL && getKey(x->data) != k){
        if(k < getKey(x->data))
            x = x->left;
        else
            x = x->left;
    }
    return x;
}

/*remove*/
/*supoe tree->p = NULL*/
Node removeNode(Node tree, Node z){
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
int insereNode(Node z){
    Node y = NULL;
    Node x = tree;
    while(x != NULL){
        y = x;
        if(getKey(z->data) < getKey(x->data))
            x = x->left;
        else
            x = x->right;
    }
    z->p = y;
    if(y == NULL)
        tree = z;
    else if(getKey(z->data) < getKey(y->data))
        y->left = z;
    else
        y->right = z;
    return 0;
}

/*getItem*/
Item getItem(Node p){
    if(p != NULL)
        return p->data;
    return NULL;
}

/*get root*/
Node getRoot(){
    return tree;
}

/**********************************/
/*programa principal*/
int main(){
    Node p;
    Item num;
    long int n;
    long int armazenados;

    n = 5;
    
    inicializa(n / 2 + 1);
    
    num = criaItem(8);
    p = criaNode(num);
    insereNode(p);
    num = criaItem(18);
    p = criaNode(num);
    insereNode(p);
    num = criaItem(3);
    p = criaNode(num);
    insereNode(p);
    if(tree != NULL){
    printf("tree %p p-> %p; key-> %ld r-> %p(%ld); l-> %p(%ld)\n",
            getRoot(), tree->p, getKey(getItem(tree)),
            tree->right, getKey(getItem(tree->right)),
            tree->left, getKey(getItem(tree->left)));
    } 
    
    p = maximo(getRoot());
    printf("Maximo = %ld\n", getKey(getItem(p)));
    p = minimo(getRoot());
    printf("Minimo = %ld\n", getKey(getItem(p)));
    p = busca(getRoot(), 8);
    printf("Busca 8 = %ld\n", getKey(getItem(p)));
    p = maximo(getRoot());
    p = predecessor(p);
    printf("predecessor = %ld\n", getKey(getItem(p)));
    p = predecessor(p);
    printf("predecessor = %ld\n", getKey(getItem(p)));
    p = predecessor(p);
    printf("predecessor = %ld\n", getKey(getItem(p)));
    
    p = minimo(getRoot());
    p = sucessor(p);
    printf("sucessor = %ld\n", getKey(getItem(p)));
    p = sucessor(p);
    printf("sucessor = %ld\n", getKey(getItem(p)));
    p = sucessor(p);
    printf("sucessor = %ld\n", getKey(getItem(p)));


    return 0;
    }
