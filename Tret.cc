/** @file Tret.cc
    @brief Codi de la classe Tret
*/


#include "Tret.hh"
using namespace std;


Tret::Tret() {
   NI_It = nom_ind.begin();
}

Tret::~Tret() {}

void Tret::afegir_nom_ind_tret(int id) {
	nom_ind.insert(id);
}

void Tret::insertar_secuencia_tret(const vector<char>& aux) {
	sec_tret = aux;
}

void Tret::imprimir_nom_individus_tret(){
		
	for(NI_It = nom_ind.begin(); NI_It != nom_ind.end(); ++NI_It)
		cout <<"  " <<  *NI_It << endl;
}
	
bool Tret::buscar_individu(int id){
		
	bool esta;
	
		
		NI_It=nom_ind.find(id);
		if (NI_It != nom_ind.end()) {
			esta = true;
		}
		else esta = false;

		return esta;
}





void Tret::imprimir_secuencia_tret(int m) const{
  cout << "  ";
   
   for (int i = 0; i < m; ++i) {
	   cout << sec_tret[i];
	   if(i == (m/2)-1) cout << endl << "  ";
   }
   cout << endl;
   
}


bool Tret::afegir_ind_secuencia_tret(int id, Cjt_individus& p) {
   bool esta = false;
	vector<int> pos;
   
	for (NI_It = nom_ind.begin(); NI_It != nom_ind.end(); ++NI_It)
	if (id == *NI_It) esta = true;
    
    if(not esta) {
            
		nom_ind.insert(id);
		vector<char> aux;
		p.exportar_ind_par_cromo(id-1, aux);
		int tam = aux.size()/2;
			
		for (int i = 0; i < tam; ++i) {
				
			if(sec_tret[i] != '-' and (aux[i] != sec_tret[i] or aux[i+tam] != sec_tret[i+tam])) {
					sec_tret[i] = '-';
					sec_tret[i+tam] = '-';
			}
		}
		
	}
    return esta;
}
    
bool Tret::treure_ind_secuencia_tret(int id) {
    
    bool esta = false;
    bool vacio = false;
	
    if (not vacio) {
        for (NI_It = nom_ind.begin(); NI_It != nom_ind.end(); ++NI_It)
            if (id == *NI_It) esta = true;
     
        if (esta) nom_ind.erase(id);
    }

	return esta;
}

Tret Tret::retornar_Tret(Cjt_individus& p) {
	
              
	Tret ex;
				
	NI_It = nom_ind.begin();
		
	vector<char> aux;
	p.exportar_ind_par_cromo(*NI_It-1, aux);
		
	ex.insertar_secuencia_tret(aux);
	ex.nom_ind.insert(*NI_It);
	NI_It++;
				
    for (int i = 1; i < nom_ind.size(); ++i) {
					
		ex.afegir_ind_secuencia_tret(*NI_It, p);    
		++NI_It;
	}
			
	return ex;
}

int Tret::mida_nom_ind() const{
	return nom_ind.size();
}