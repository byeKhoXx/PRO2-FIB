/** @file Cjt_individus.cc
    @brief Codi de la classe Conjunt d'individus(Cjt_individus).
*/

#include"Cjt_individus.hh"


Cjt_individus::Cjt_individus() {};

Cjt_individus::~Cjt_individus() {};

void Cjt_individus::consulta_individu(int id) {
	
	vind[id-1].escriure_par_cromo();	
}

void Cjt_individus::exportar_ind_par_cromo(int id, vector<char>& aux) const {
	
	vind[id].exportar_par_cromo(aux);
}

void Cjt_individus::llegir(int n, int m) {
	
	vind.resize(n);

	for (int i = 0; i < n; ++i) {
		
		vind[i].donar_mida(m);
		vind[i].llegir_par_cromo();
	}
}

int Cjt_individus::retornar_tam() const{
	
	return vind[0].retornar_mida_par_cromo();
}