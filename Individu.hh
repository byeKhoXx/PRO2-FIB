/** @file Individu.hh
    @brief Especificació de la classe Individu.
*/


#ifndef INDIVIDU_HH
#define INDIVIDU_HH

#ifndef NO_DIAGRAM 
#include<iostream>
#include<vector> 
#endif     

using namespace std;

/** @class Individu
    @brief Representa un individu amb el seu parell de cromosomes.
*/


class Individu {
    private:
    
	/** @brief Parell de cromosomes de l'individu.*/
     vector<char> par_cromo;
        
	public:
	
	
	/** @brief Creadora per defecte. 

      S'executa automáticamente al declarar un conjunt d'individus.
      
      \pre <em>Cert</em>
      
      \post El resultat es un individu buit.
  */ 
    Individu();
	
	/** @brief Destructora de la classe.*/

	~Individu();
        
	/** @brief Modificadora del tamany del contenidor de parells de cromosomes. 
      
      \pre m > 0.
      
      \post El parametre implicit passa a estar llest per contenir m parells de cromosomes.
  */ 
	void donar_mida(int m);
	
	
	/** @brief Retornadora del tamany del parell de cromosomes. 
      
      \pre <em>Cert</em>
      
      \post Retorna la quantitat de cromosomes que pot guardar el paramtre implicit.
  */ 
	
	int retornar_mida_par_cromo() const;
	
	
	
	

	/** @brief Lectora de parell de cromosomes. 
      
      \pre  <em>Cert</em>
      
      \post S'afegeix a l'individu paràmetre implícit el parell de
      cromosomes llegit pel canal d'entrada.
  */ 
	void llegir_par_cromo ();
	
	
	/** @brief Impresora de parell de cromosomes. 
      
      \pre  <em>Cert</em>
      
      \post S'escriurà pel canal estandard de sortida el parell de cromosomes del paramtre implicit.
      */
	
	void escriure_par_cromo()const;
    
	
	/** @brief Afegidora de parell de cromosomes a un individu. 
      
      \pre  <em>Cert</em>
      
      \post S'afegeix a l'individu paràmetre implícit el parell de
      cromosomes passat com a paràmetre.
  */ 
	void exportar_par_cromo(vector<char>& aux) const;
	
	
		
};

#endif
