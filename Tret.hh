/** @file Tret.hh
    @brief Especificació de la classe Tret.
*/


#ifndef TRET_HH
#define TRET_HH
#include "Cjt_individus.hh"
#ifndef NO_DIAGRAM 
#include <iostream>
#include <vector> 
#include <set>
#endif     

using namespace std;

/** @class Tret
    @brief Representa un tret amb la seva secuencia de cromosomes i els noms dels individus que el manifestan.
*/

class Tret {
    private:
		
	/** @brief Seqüencia de parell de cromosomes que fa que el tret es manifesti. */
    vector<char> sec_tret;
    
	/** @brief Noms dels individus que manifesan el tret.*/
	set<int> nom_ind;
	
	/** @brief Iterador per moure'ns a través dels noms dels individus que manifestan el tret. */
    set<int>::iterator NI_It;
	
	
	


	public:

		
	/** @brief Creadora per defecte. 

      S'executa automàticament al declarar un conjunt d'individus.
      
      \pre <em>Cert</em>
      
      \post El resultat es un tret buit.
  */ 
	Tret();
	
 	/** @brief Destructora de la classe.*/
	~Tret();
	
	/** @brief Impresora dels individus que manifestan un tret. 

      \pre <em>Cert</em>
      
      \post S'escriurà pel canal estandard de sortida els identificadors
      dels individus per ordre creixent que manifestan el paràmetre implícit.
  */ 
	void imprimir_nom_individus_tret();
	
	
	
	/** @brief Afegidora d'un identificador a un tret. 
      
      \pre 0 < id <= n.
      
      \post Queda constancia que el tret parametre implicit es manifestat per individu "id".
  */ 
	
	
	void afegir_nom_ind_tret(int id);
	
	
	/** @brief Consultora d'individus que manifestan un tret. 
      
      \pre 0 < id <= n.
      
      \post Retorna true si el tret parametre implicit es manifestan per l'individu identificat amb l'identificador "id", altrament, retorna false.
  */
	
	bool buscar_individu(int id); 
	
	
	
	/** @brief Retornadora d'un tret actualitzat. 
      
      \pre p no es buit.
      
      \post Retorna un tret amb la seqüència de parell de cromosomes aactualitzada i identificadors del parametre implicit.
  */
	
	
	Tret retornar_Tret(Cjt_individus& p);
	
	//Consultores
	
	/** @brief Impresora de la seqüència d'un tret. 

      \pre m > 0.
      
      \post S'escriurà pel canal estandard de sortida la seqüència que fa que
      es manifesti el tret t del paràmetre implícit.
  */ 
	
	void imprimir_secuencia_tret(int m) const;
	

	/** @brief Retornadora de la quantitat d'individus que manifestan el tret parametre implicit. 

      \pre <em>Cert</em>
      
      \post Retorna el numero d'individus que manifestan el tret parametre implicit.
  */ 
	
	
	int mida_nom_ind()const;
	
	

	
	/** @brief Afegidora d'un individu a la seqüència que manifesta un tret. 

      \pre El tret paràmetre implícit ja el manifesta algun individu. 0 < id <= n. p no es buit.
      
      \post La seqüència del tret paràmetre implícit serà actualitzada amb 
      el parell de cromosomes de "id". Es tindrà constància que "id" manifesta
      el tret paràmetre implícit.
  */ 
	
	bool afegir_ind_secuencia_tret(int id, Cjt_individus& p);

	/** @brief Extractora d'un individu a la seqüència que manifesta un tret. 

      \pre El tret paràmetre implícit ja el manifesta algún individu. 0 < id <= n.
      
      \post Si l'individu id era l'únic que manifestava el tret paràmetre 
      implícit, retornara false, sino, retornarà true i es calcularà la nova 
      seqüència que el manifesta.

  */
	
	bool treure_ind_secuencia_tret(int id);
	
	/** @brief Copiadora de parell de cromosomes. 

      S'executa automàticament al declarar un conjunt d'individus.
      
      \pre <em>Cert</em>
      
      \post La component sec_tret del parametre implicit passa a tenir el contingut d'aux.
  */ 
	void insertar_secuencia_tret(const vector<char>& aux);
};

#endif
