#include "../include/me_graph.h"

#define INITIAL_CAPACITY 8

void me_normaliser_arete(me_arete *arete);
void me_swap_sommets(me_arete *a);

void me_init_graphe(me_graphe *g)
{
    // initialise les champs internes du graphe g
    // - allocation d'un tableau d'arêtes de capacité initiale 8
    // - le graphe ne contient initialement ni sommet ni arête

    g->ordre = 0;
    g->nb_aretes = 0;
    g->aretes_capacite = INITIAL_CAPACITY;
    g->aretes = malloc(g->aretes_capacite * sizeof(me_arete));

    if(g->aretes == NULL){
      fprintf(stderr, "Erreur d'allocation mémoire\n"); //Sortie erreur
      exit(EXIT_FAILURE);
    }
}

void me_deinit_graphe(me_graphe *g)
{
    // libère la mémoire qui avait été allouée dans la fonction init_graphe
    // réinitialise les champs internes du graphe g
    g->ordre = 0;
    g->nb_aretes = 0;
    g->aretes_capacite = 0;
    free(g->aretes);
    g->aretes = NULL;
}

size_t me_ordre(me_graphe const *g)
{
    return g->ordre;
}

size_t me_nb_aretes(me_graphe const *g)
{
    return g->nb_aretes;
}

void me_ajouter_sommet(me_graphe *g)
{
  g->ordre += 1;
}

size_t me_index_sommet(me_graphe const *g, me_sommet s)
{
    // retourne l'index du sommet s dans le graphe g
    // la valeur UNKNOWN_INDEX si le sommet n'existe pas dans g)

    if(s >= me_ordre(g)){
      return UNKNOWN_INDEX;
    }

    return s;
}



// une fonction locale "static arete swap_sommets(arete a)" pourra être utile
// cette fonction retourne une nouvelle arête dont les sommets sont les même que l'arête reçue mais inversés

void me_swap_sommets(me_arete *a){
  me_sommet temp = a->s2;
  a->s2 = a->s1;
  a->s1 = temp;
}

void me_normaliser_arete(me_arete *arete){
  if(arete->s2 < arete->s1){
    me_swap_sommets(arete);
  }
}


bool me_existe_arete(me_graphe const *g, me_arete a)
{
    // retourne true si l'arête a est contenue dans le graphe g, false sinon
    // /!\ l'arête (s1,s2) et l'arête (s2,s1) sont considérées équivalentes

    me_normaliser_arete(&a);
    for(size_t i=0; i<g->nb_aretes; i++){
      me_arete b = g->aretes[i];
      me_normaliser_arete(&b);
      if((a.s1 == b.s1 && a.s2 == b.s2)){
        return true;
      }
    }

    return false;
}

bool me_ajouter_arete(me_graphe *g, me_arete a)
{
    me_normaliser_arete(&a);

    //Si les deux sommets de l'arête sont les mêmes
    if(a.s1 == a.s2){
      return false;
    }

    //Si les sommets n'existent pas dans g (s1 étant le plus petit, s'il n'est pas contenu s2 ne peut pas l'être)
    if(me_index_sommet(g, a.s1) == UNKNOWN_INDEX){
      return false;
    }

    if(me_existe_arete(g, a)){
      return false;
    }

    if(g->nb_aretes == g->aretes_capacite){
      me_arete* newTab = malloc(sizeof(me_arete) * g->aretes_capacite * 2);
      if(newTab == NULL){
        return false;
      }
      g->aretes_capacite *= 2;
      memcpy(newTab, g->aretes, sizeof(me_arete) * g->nb_aretes);  //OU REALLOC : malloc + copie + free    g->aretes = realloc(g->aretes, g->aretes_capacite*2); PUIS VERIFIER g->aretes != NULL
      free(g->aretes);
      g->aretes = newTab;
      g->aretes[g->nb_aretes] = a;
      g->nb_aretes++;
      return true;
    }

    g->aretes[g->nb_aretes] = a;
    g->nb_aretes++;
    return true;
}

size_t me_index_arete(me_graphe const *g, me_arete a)
{
    // retourne l'index de l'arête au sein du tableau d'arêtes de g si l'arête a existe dans g,
    // la valeur UNKNOWN_INDEX sinon

    me_normaliser_arete(&a);
    if(me_existe_arete(g, a)){
      for(size_t i=0; i<g->nb_aretes; i++){
        me_arete b = g->aretes[i];
        me_normaliser_arete(&b);
        if(a.s1 == b.s1 && a.s2 == b.s2){
          return i;
        }
      }
    }

    return UNKNOWN_INDEX;
}

uint me_poids_arete(me_graphe const *g, me_sommet s1, me_sommet s2){
  me_arete a = {s1, s2};
  size_t index = me_index_arete(g, a);

  return g->aretes[index].poids;

}

size_t me_sommets_adjacents(me_graphe const *g, me_sommet s, me_sommet sa[])
{
    // remplit le tableau sa avec les sommets adjacents de s dans g
    // et retourne le nombre de sommets ainsi stockés
    // (on suppose que s fait bien partie du graphe g)
    // (le tableau sa est supposé assez grand pour contenir les sommets adjacents de s)

    size_t degre = 0;
    for(size_t i = 0; i<g->nb_aretes; i++){
      me_arete a = g->aretes[i];
      me_normaliser_arete(&a);
      if(a.s1 == s){
        sa[degre] = a.s2;
        degre++;
      }
      else if(a.s2 == s){
        sa[degre] = a.s1;
        degre++;
        // on peut écrire sa[degre++] = a.s1          le degré sera incrémenté après l'affectation
        // si on fait sa[++degre] = a.s1              l'incrémentation est faite avant
      }
    }

    return degre;
}

