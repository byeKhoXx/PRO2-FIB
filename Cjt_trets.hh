/** @file Cjt_trets.hh
    @brief Especificació de la classe Conjunt de trets (Cjt_trets).
*/

#ifndef CJT_TRETS_HH
#define CJT_TRETS_HH

#include "Tret.hh"
#include "Cjt_individus.hh"
#include "BinTree.hh"
#ifndef NO_DIAGRAM 
#include <iostream>
#include <map>
#endif     

/** @class Cjt_trets
    @brief Representa els trets presents en els individus de l'experiment.
*/


class Cjt_trets {
	private:
	
	/** @brief Nom dels trets de l'experiment i el seu contingut.*/
	map<string,Tret> mtret;
	
	/** @brief Iterador del map amb clau string i contingut Tret.*/
	map<string, Tret>::iterator MIt;
	
	/** @brief Arbre genealogic dels individus de l'experiment.*/
	BinTree<int> arbre;
	
	/** @brief Lectora d'un arbre en preordre. 
  
      \pre <em>Cert</em>
      
      \post Retorna un arbre amb el contingut llegit en preordre pel canal estandard d'entrada.
  */
	static BinTree<int> read();
		

	
	public:
		
	/** @brief Creadora per defecte. 

      S'executa automáticamente al declarar un conjunt d'individus.
      
      \pre <em>Cert</em>
      
      \post El resultat es un conjunt de trets buit.
  */   
		
	Cjt_trets();
	
	/** @brief Destructora de la classe.*/
	~Cjt_trets();
	
	

	
	/** @brief Consultora d'un tret. 
      
      \pre t no es buit. p no es buit.
      
      \post  Si aquest tret no existeix s'escriurà "error". Si existeix aquest
      tret, s'escriurà la combinació que suposadament fa que es manifesti i 
      els identificadors dels individus que la manifestin per ordre creixent 
      d'identificadors.
  */  
	
	void consultar_tret(const string& t,  Cjt_individus& p) ;
	
	
	/** @brief Consultora de la distribucio d'un tret del experiment. 

     
      \pre t no es buit.
      
      \post  Si aquest tret no existeix s'escriura "error". Altrament, 
	  s'escriurà el subarbre resultant en inordre.
  */ 
	void distribucio_tret(string& t);
	
	/** @brief Consultora dels trets d'un individu. 
      
      \pre 0 < id <= n.
      
      \post S'escriurà pel canal estandard de sortida per ordre alfabetic 
      els trets que té el individu id.
  */  
	
	void trets_individu(int id) ;
	
	//Modificadores
	
	/** @brief Afegidora d'un tret a un individu. 
      
      \pre 0 < id <= n. p no es buit. t no es buit.
      
      \post Si el tret ja es al individu id, s'escriura "error" altrament,
	  quedarà constancia de que l'individu "id" té el tret "t" i es calcularà
	  la combinacio de parells de cromosomes que fan que es manifesti el tret 
	  "t".
  */  
	
	void afegir_tret(const int& id, const string& t, Cjt_individus& p);
	
	/** @brief Extractora d'un tret a un individu. 
      
      \pre 0 < id <= n. p no es buit. t no es buit.
      
      \post Si el tret no es al individu id, s'escriura "error" altrament,
	  quedarà constancia de que l'individu "id" té el tret "t"i es calcularà
	  la combinacio de parells de cromosomes que fan que es manifesti el tret
	  "t". Si l'individu id era l'únic que el manifestava, desapareixera 
	  qualsevol	informació sobre el tret t.
  */  
	
	void treure_tret(const int& id, const string& t, Cjt_individus& p);
	
	/** @brief Netejadora de trets. 
      
      \pre <em>Cert</em>
      
      \post Els trets del paramtre implicit desapareixen.
  */  
	
	void netejar_trets();
	
	/** @brief Impresora dels trets d'un individu. 
      
      \pre 0 < id <= n.
      
      \post Sortirà pel canal estandard de sortida els noms dels trets que manifesta l'individu amb identificador "id".
  */
	
	void consulta_trets_individu(int id);
	
	
	/** @brief Lectora d'un arbre. 
      
      \pre <em>Cert</em>
      
      \post LLegeix pel canal d'entrada un arbre en preordre.
  */
	void llegir_arbre();
	
	
    /** @brief Calculadora d'un arbre distribuit. 
      
      \pre t no es buit.
      
      \post Si el tret "t" no existeix s'exriurà "error", altrament, s'escriurà en inordre el arbre distribuit segons els individus que manifestan el tret "t".
  */

	BinTree<int> arbre_distribuit(const string& t, BinTree<int>& arbre);
	
	
		
	
	/** @brief Impresora d'un arbre. 
      
      \pre <em>Cert</em>
      
      \post S'imprimeix l'arbre passat com a parametre el inordre.
  */
	void imprimir_arbre(const BinTree<int>& a) const;
	
};

#endif
