#ifndef __ME_NETWORK_TRAME_H__
#define __ME_NETWORK_TRAME_H__

#pragma once

#include <assert.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "me_network.h"
#include "me_graph.h"

typedef struct me_trame_ethernet {
    uint8_t preambule[7];
    uint8_t sfd;
    me_mac dest;
    me_mac src;  
    uint16_t type; 
    size_t data_length;
    uint8_t *data;
    uint8_t fcs[4];
} me_trame_ethernet;

me_trame_ethernet me_init_trame(me_mac mac_src, me_mac mac_dest, uint16_t type, const char* message);
void me_deinit_trame(me_trame_ethernet* t);

bool me_parcours_switch_recursif(me_subNetwork* net, me_machine* equip, me_sommet id_equip, me_trame_ethernet* t, uint port);

void me_afficher_trame(me_trame_ethernet* t);
void me_afficher_trame_hexa(me_trame_ethernet* t);
void me_type_to_str(char* protocole, uint16_t type);

void me_envoyer_trame(me_subNetwork* net, me_mac adr_src, me_mac adr_dst, const char* message, const char* protocole);

#endif