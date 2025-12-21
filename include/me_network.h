#ifndef __me_subNetwork_H__
#define __me_subNetwork_H__


#pragma once

#include "me_graph.h"

// Passage en parametre comme ici !
typedef uint8_t me_mac[6];

typedef struct 
{
	// uint8_t mac[6] : liée à l'accès !
	uint8_t *me_mac;

} ME_MAC_Network_Address_t;


typedef struct 
{
	uint32_t *ip;

} ME_IP_Network_Address_t;

typedef struct 
{
	uint *port;

} me_subNetwork_Port_t;



typedef struct me_association {
    me_subNetwork_Port_t num_port;
    me_mac adr_mac;
} me_association;


typedef struct me_etat_port {
  int etat;  //par defaut en mode designé // 0 root - 1 désigné - 2 bloqué
  me_sommet id_connecte;  // id de la machine qui est connecte en face
} me_etat_port;


// A ANALYSER AVEC L'ID UNIQUEMENT ==> PUIS PAR LA TABLE PUIS LE COUT
typedef struct me_machine {
    unsigned int type;
    char nom[32];
    me_mac adr_mac;
    ME_IP_Network_Address_t adr_ip;
    int nb_ports;
    unsigned int priorite;
    uint64_t stp_root; // C'est quoi ??
    me_association *table;
    size_t nbAsso;

    me_sommet id;
    me_sommet id_root;
    int cout;
    me_subNetwork_Port_t port_root;
    me_etat_port *etat_ports;
} me_machine;



typedef struct me_subNetwork {
    me_graphe* g;
    me_machine* equipements;
    size_t nbEquipements;
} me_subNetwork; 


typedef struct {

} ME_Network;


me_subNetwork* me_creation_reseau();
void deinit_reseau(me_subNetwork* reseau);
void afficher(me_subNetwork* reseau);
char *mac_to_string(const me_mac m);
char *mac_to_string_hexa(const me_mac m);
void me_string_to_mac(const char *adr, ME_MAC_Network_Address_t * mac);
void me_string_to_ip(const char *adr, ME_IP_Network_Address_t *ip);
char * me_ip_to_string(ME_IP_Network_Address_t ip);

size_t me_degre(me_graphe const *g, me_sommet s);

bool me_existe_machine(me_subNetwork* net, const me_mac adr);

int me_existe_asso(me_machine* sw, me_mac adr_mac);
void me_ajout_asso(me_machine* sw, me_mac adr_mac, me_subNetwork_Port_t port);


void me_affiche_table_commutation(me_machine* sw);
void me_affiche_port_switch(me_machine* sw);
void me_affiche_infos_station(me_machine* station);
void me_affiche_infos_switch(me_machine* sw);


#endif