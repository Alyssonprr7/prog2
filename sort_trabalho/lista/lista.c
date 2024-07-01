#include "lista.h"


/////////////////////////////////
lista_t *lista_inicia(void){
  return NULL;
}
/////////////////////////////////
void lista_termina( lista_t *l ){
  lista_t *aux;
  while ( l != NULL ){
    aux = l;
    l = l->prox;
    free(aux);
  }
}
/////////////////////////////////
void lista_imprime( lista_t *l ){
  lista_t *aux = l;
  while ( aux != NULL ){
    printf("%d ", aux->x);
    aux = aux->prox;
  }
}
/////////////////////////////////
void lista_imprime_recursivo( lista_t *l ){
  if ( l == NULL ) return;
  printf("%d ", l->x);
  lista_imprime_recursivo(l->prox);
}
/////////////////////////////////
void lista_imprime_inverso_recursivo( lista_t *l ){
  if ( l == NULL ) return;
  lista_imprime_inverso_recursivo(l->prox);
  printf("%d ", l->x);
}
/////////////////////////////////

/////////////////////////////////
lista_t *lista_append( lista_t *l, int d ){
  
  lista_t *novo = (lista_t *) malloc(sizeof(lista_t));
  novo->x = d;
  novo->prox = NULL;
  
  if ( l == NULL ) return novo;
  
  lista_t *aux = l;
  while ( aux->prox != NULL ){
    aux = aux->prox;
  }
  aux->prox = novo;
  return l;
}
/////////////////////////////////
// adiciona no inicio
lista_t *lista_push( lista_t *l, int d ){
  lista_t *novo = (lista_t *) malloc(sizeof(lista_t));
  novo->x = d;
  novo->prox = l;
  return novo;
}
/////////////////////////////////
// remove do inicio
lista_t *lista_pop( lista_t *l ){
  if ( l == NULL ) return NULL;
  
  lista_t *aux = l;
  l = l->prox;
  free(aux);

  return l;
}
/////////////////////////////////

/////////////////////////////////
lista_t *lista_remove( lista_t *l, int d ){
  
  // se lista vazia, nao ha o que remover
  if (l == NULL) return NULL;
  
  // ponteiros auxiliares
  lista_t *anterior;
  lista_t *aux;
  
  // checa se deve remover inicio da lista
  if (l->x == d){
    aux = l;
    l = l->prox;
    free(aux);
    return l;
  }
  
  // percorre a lista checando se encontra o dado "d" a remover
  // ponteiro "anterior" vem logo antes de "aux", para manter o encadeamento
  anterior = l;
  aux = l->prox;
  while ( aux != NULL ){
    if (aux->x == d){
      anterior->prox = aux->prox; // como "aux" sera removido, encadeia "anterior" ao proximo de "aux"
      free(aux);
      break;
    }
    anterior = aux;
    aux = aux->prox;
  }
  
  return l;
}
/////////////////////////////////
lista_t *lista_junta( lista_t *l1, lista_t *l2 ){
  
  if ( l1 == NULL && l2 == NULL ) return NULL;

  // ponteiro para inicio e fim da lista nova
  lista_t *l = lista_inicia();
  lista_t *fim;
  
  // ponteiro auxiliar
  lista_t *aux;
  
  // constroi primeira parte da lista. se l1 nao for vazia, comeca por l1. se nao, vai direto para l2
  if ( l1 != NULL ){
    l = lista_append( l , l1->x );
    aux = l1->prox;
  } else {
    l = lista_append( l , l2->x );
    aux = l2->prox;
  }
  fim = l;
  while ( aux != NULL ){
    fim->prox = lista_append( NULL , aux->x );
    fim = fim->prox;
    aux = aux->prox;
  }
  
  // se l1 nao era vazia, temos ainda que adicionar os dados de l2 em l
  if ( l1 != NULL ){
    aux = l2;
    while ( aux != NULL ){
      fim->prox = lista_append( NULL , aux->x );
      fim = fim->prox;
      aux = aux->prox;
    }
  }
  
  return l;
}
/////////////////////////////////

/////////////////////////////////
unsigned int lista_tamanho( lista_t *l ){
  unsigned int tam = 0;
  lista_t *aux = l;
  while ( aux != NULL ){
    tam++;
    aux = aux->prox;
  }
  return tam;
}
/////////////////////////////////

/////////////////////////////////
int lista_max( lista_t *l ){
  int max = 0;
  
  if ( l == NULL ){
    printf("Lista vazia, nao tem max.\n");
    return max;
  }
  
  max = l->x;
  lista_t *aux = l->prox;
  while ( aux != NULL ){
    if ( aux->x > max ){
      max = aux->x;
    }
    aux = aux->prox;
  }
  
  return max;
}
/////////////////////////////////
int lista_min( lista_t *l ){
  int min = 0;
  
  if ( l == NULL ){
    printf("Lista vazia, nao tem min.\n");
    return min;
  }
  
  min = l->x;
  lista_t *aux = l->prox;
  while ( aux != NULL ){
    if ( aux->x < min ){
      min = aux->x;
    }
    aux = aux->prox;
  }
  
  return min;
}
/////////////////////////////////

/////////////////////////////////
lista_t *lista_encontra_no( lista_t *l, int d ){
  lista_t *no = NULL;
  lista_t *aux = l;
  while ( aux != NULL ){
    if ( aux->x == d ){
      no = aux;
      break;
    }
    aux = aux->prox;
  }
  return no;
  
  // OBS: Dá pra fazer mais enxuto:
  //
  // while ( l != NULL ){
  //   if ( l->x == d ) return l;
  //   l = l->prox;
  // }
  // return NULL;
} 
/////////////////////////////////

/////////////////////////////////
lista_t *lista_inverte( lista_t *l ){
  
  // Ideia:
  // Se havia:    2 -> 3 -> 5 -> NULL
  // Invertido:   5 -> 3 -> 2 -> NULL
  
  // Se lista vazia, nao ha o que fazer
  if ( l == NULL ) return NULL;
  
  // se a lista tem apenas um item, a inversa de l é ela mesma.
  if ( l->prox == NULL ) return l;
  
  lista_t *aux = l->prox;
  lista_t *anterior = l;
  lista_t *atual;
  
  anterior->prox = NULL;
  while ( aux != NULL ){
    atual = aux;
    aux = aux->prox;
    atual->prox = anterior;
    anterior = atual;
  }
  l = atual;
  
  return l;
}
/////////////////////////////////
