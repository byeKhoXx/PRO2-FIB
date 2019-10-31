/** @file Individu.cc
    @brief Codi de la classe Individu
*/

#include "Individu.hh"

Individu::Individu () {}

Individu::~Individu () {}

void Individu::donar_mida(int m) {
	par_cromo.resize(2*m);
}

void Individu::llegir_par_cromo() {
    for (int i = 0; i < par_cromo.size(); ++i)
        cin >> par_cromo[i];
}

void Individu::escriure_par_cromo()const {
    
	cout << "  ";
	for (int i = 0; i < par_cromo.size(); i++) {
        cout << par_cromo[i];
		if(i == (par_cromo.size()/2)-1) cout << endl << "  ";
	}
	cout << endl;
		
}

void Individu::exportar_par_cromo(vector<char>& aux) const {
	aux = par_cromo;
}

int Individu::retornar_mida_par_cromo() const{
	
	return par_cromo.size();
}