/** @file Cjt_individus.hh
    @brief Especificació de la classe Conjunt d'individus (Cjt_individus).
*/

#ifndef CJT_INDIVIDUS_HH
#define CJT_INDIVIDUS_HH


#include "Individu.hh"
#ifndef NO_DIAGRAM 
#include <iostream>

#endif         

/** @class Cjt_individus
    @brief Representa els individus de l'experiment.
*/


class Cjt_individus {
	private:
	
	/** @brief Individus del experiment.*/

	vector<Individu> vind;
	 
		
	public:
	
		
	/** @brief Creadora per defecte. 

      S'executa automáticamente al declarar un conjunt d'individus.
      
      \pre <em>Cert</em>
      
      \post El resultat es un conjunt d'individus buit de tamany n.
  */   
	
	Cjt_individus();
	
	/** @brief Destructora de la classe.*/
	~Cjt_individus();
	
	/** @brief Retornadora del numero de cromosomes dels individus del conjunt. 

     
      \pre 0 < id <= n.
      
      \post Retorna el numero de cromosomes dels individus del conjunt.
  */  
	
	int retornar_tam() const;
	
	

	
	/** @brief Consultora d'un individu del conjunt. 

     
      \pre 0 < id <= n.
      
      \post S'escriurà pel canal estandard de sortida el parell de cromosomes 
      del individu y el nom dels seus trets per ordre alfabetic.
  */  
	
	void consulta_individu(int id) ;
	

	

	
	/** @brief Lectura d'un conjunt d'individus.
     
      \pre n > 0. m > 0.
      
      \post El paràmetre implícit conte el conjunt d'individus llegits
      pel canal estandard d'entrada, els seus parells de cromosomes i 
      l'arbre genealogic del conjunt d'individus.
  */ 
	
    void llegir(int n, int m);
	
	/** @brief Exportadora del parell de cromosomes. 

     
      \pre 0 < id <= n.
      
      \post aux passarà a contenir el parell de cromosomes de l'individu "id".
  */
	
	void exportar_ind_par_cromo(int id, vector<char>& aux) const;
       
};

#endif
