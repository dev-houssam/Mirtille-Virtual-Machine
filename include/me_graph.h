#ifndef __ME_GRAPH_H__
#define __ME_GRAPH_H__

#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "stdint.h"

typedef size_t me_sommet;

typedef struct arete
{
 me_sommet s1;
 me_sommet s2;
  uint poids;
} arete;

typedef struct me_graphe
{
  size_t ordre;
  arete* aretes;
  size_t aretes_capacite;
  size_t nb_aretes;
} me_graphe;

static const size_t UNKNOWN_INDEX = -1;

void init_graphe(me_graphe *g);
void deinit_graphe(me_graphe *g);

size_t ordre(me_graphe const *g);
size_t nb_aretes(me_graphe const *g);

void ajouter_sommet(me_graphe *g);
size_t index_sommet(me_graphe const *g, me_sommet s);

bool existe_arete(me_graphe const *g, arete a);
bool ajouter_arete(me_graphe *g, arete a);
size_t index_arete(me_graphe const *g, arete a);
uint poids_arete(me_graphe const *g,me_sommet s1,me_sommet s2);

size_tme_sommets_adjacents(me_graphe const *g,me_sommet s,me_sommet sa[]);

#endif
