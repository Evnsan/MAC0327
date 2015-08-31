/***********************************/
/*MAC0327 - Desafios de Programacao*/
/***********************************/
/***Evandro Augusto Nunes Sanches***/
/***********************************/
<<<<<<< HEAD
/***********Problema 04*************/
/***********************************/

#include<stdio.h>

int main(){
    int n;

    /*controle*/
    int i;

    /*Entrada*/

    /*Processamento*/

    /*Saida*/
=======
/***********Problema 22*************/
/***********************************/

/*Implementacao de     arvore binaria de busca */
/*Codigo baseado no codigo apresentado no livro*/
/*  "Introduction to Algorithms" - Cormen,     */
/*  Leiserson, Rivest e Stein                  */
/***********************************************/
#include<stdlib.h>
#include<stdio.h>

#define TESTE 0


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
int inicializa(long int n){
    long int i;
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
Node removeNode(Node z){
    Node x, y;
    /***definindo y para splice out***/
    if(z->left == NULL || z->right == NULL)
        y = z;
    else
        y = sucessor(z);
    
    /***/
    if(TESTE){
        printf("y %p (%ld)\n", y, getKey(y->data));
    }
    /***/

    /***definindo x = filho para remanejar ou x = NULL***/
    if(y->left != NULL)
        x = y->left;
    else
        x = y->right;
    
    /***/
    if(TESTE){
        printf("x %p (%ld)\n", x, getKey(x->data));
    }
    /***/
    
    /***splice out de y***/
    
    if(x != NULL)
        x->p = y->p;
    if(y->p == NULL)
        tree = x;
    else if(y == y->p->left)
        y->p->left = x;
    else
        y->p->right = x;
    
    /***/
    if(TESTE){
        printf("tree %p (%ld)\n", tree, getKey(tree->data));
    }
    /***/

    /***copiando z em y***/
    if( y != z)
        z->data = y->data;
    return y;
}

/*destroiNode*/
int destroiNode(Node x){
    if(x == NULL){
        printf("ERRO: destroiNode recebeu NULL");
        return 1;
    }
    if(pool == NULL)
        pool = x;
    x->p = pool;
    x->right = NULL;
    x->left = NULL;
    pool = x;
    return 0;
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
    long int entrada;
    float x, y;

    /*controle*/
    long int i;

    /*entrada*/
    scanf("%ld", &n);
    
    inicializa(n / 2 + 2);

    for(i = 0; i < n; i++){
        scanf("%ld", &entrada);
        num = criaItem(entrada);
        p = criaNode(num);
        insereNode(p);
        if(i > n/2 ){
            p = maximo(getRoot());
            /***/
            if(TESTE){
                printf("maximo %p (%ld)\n", p, getKey(getItem(p)));
            }
            /***/
            p = removeNode(p);
            /***/
            if(TESTE){
                printf("removido %p (%ld)\n", p, getKey(getItem(p)));
            }
            /***/
            destroiNode(p);
            /***/
            if(TESTE){
                printf("root = %p (%ld)\n", getRoot(),
                        getKey(getItem(getRoot())));
            }
            /***/
        }
    
    }
    /***/
    if(TESTE){
        if(tree != NULL){
            printf("tree %p, p-> %p, key-> %ld; r-> %p(%ld); l-> %p(%ld)\n",
                getRoot(), tree->p, getKey(getItem(tree)),
                tree->right, getKey(getItem(tree->right)),
                tree->left, getKey(getItem(tree->left)));
        }
    } 
    /***/

    if(n % 2 != 0)
        printf("%ld.0\n", getKey(getItem(maximo(getRoot()))));
    else{
        p = maximo(getRoot());
        x = (float)getKey(getItem(p));
        y = (float)getKey(getItem(predecessor(p)));
        /***/
        if(TESTE){
            printf("x = %ld = %f , y = %ld = %f\n", getKey(getItem(p)), x,
                    getKey(getItem(predecessor(p))), y);
        }
        /***/
        x /= 2;
        y /= 2;
        printf("%.1f\n", x + y);
    } 
>>>>>>> 037873402102ff5cbbff6d2fead3d77c2d3f6c88

    return 0;
}
