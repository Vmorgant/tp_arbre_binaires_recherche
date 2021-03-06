#include <abr_fonctions.h>

/*
 * Affichage des ancetres d'un noeud
 */

extern
void abr_ancetres_afficher( const abr_t * arbre , 
			    noeud_t * noeud ,
			    void (*afficher)(const void *) )
{
  /* Test d'arret */
  while( noeud_existe(noeud) )
    {
      noeud_afficher( noeud , afficher,0 ) ;
      printf(" / " ) ; 
      noeud = abr_pere_rechercher( arbre , noeud ) ;
    }
  
  return ; 
}

/* 
 * Creation d'un arbre binaire de travail par dichotomie 
 * a partir d'une liste d'elements generiques
 */



extern
err_t abr_dicho_creer( abr_t ** arbre , 
		       err_t (*fonction_affectation)( void * e1 , void * e2 ) ,	
		       err_t (*fonction_destruction)( void * e) ,			
		       int (*fonction_comparaison) ( const void * e1 , const void * e2) ,
		       liste_t * liste )
{ 
  
  int i;
  *arbre=abr_creer(fonction_affectation,fonction_destruction,fonction_comparaison);
  for (i=0;i<liste_nb_lire(liste);i++){
  	 
      void *elem=NULL;
      elem=liste_elem_lire( liste ,i );
      abr_inserer(*arbre,elem);
  }   
  return(OK) ; 
}

