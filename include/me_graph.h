#ifndef __ME_GRAPH_H__
#define __ME_GRAPH_H__

#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "stdint.h"

typedef size_t me_sommet;

typedef struct me_arete
{
  me_sommet s1;
  me_sommet s2;
  uint poids;
} me_arete;

typedef struct me_graphe
{
  size_t ordre;
  me_arete* aretes;
  size_t aretes_capacite;
  size_t nb_aretes;
} me_graphe;

static const size_t UNKNOWN_INDEX = -1;

void me_init_graphe(me_graphe *g);
void me_deinit_graphe(me_graphe *g);

size_t me_ordre(me_graphe const *g);
size_t me_nb_aretes(me_graphe const *g);

void me_ajouter_sommet(me_graphe *g);
size_t me_index_sommet(me_graphe const *g, me_sommet s);

bool me_existe_arete(me_graphe const *g, me_arete a);
bool me_ajouter_arete(me_graphe *g, me_arete a);
size_t me_index_arete(me_graphe const *g, me_arete a);
uint me_poids_arete(me_graphe const *g, me_sommet s1, me_sommet s2);

size_t me_sommets_adjacents(me_graphe const *g, me_sommet s,me_sommet sa[]);

#endif
