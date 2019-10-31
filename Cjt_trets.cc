/** @file Cjt_trets.cc
    @brief Codi de la classe Conjunt de trets(Cjt_trets).
*/

#include"Cjt_trets.hh"


Cjt_trets::Cjt_trets() {}

Cjt_trets::~Cjt_trets() {}

BinTree<int> Cjt_trets::read() {
  int x;
  cin >> x;
  if (x != 0) { 
    BinTree<int> a1 = read();
    BinTree<int> a2 = read();
    return BinTree<int>(x,a1,a2);
  }
  else return BinTree<int>();
}


void Cjt_trets::afegir_tret(const int& id, const string& t, Cjt_individus& p) {
	
	if(mtret.find(t) != mtret.end()) {	
		
		if(mtret[t].afegir_ind_secuencia_tret(id, p)) cout << "  error" << endl;

	}else {
		
		Tret ex;
		
		vector<char> aux;
		p.exportar_ind_par_cromo(id-1, aux);
		
		ex.insertar_secuencia_tret(aux);
		ex.afegir_nom_ind_tret(id);
		
		mtret.insert(make_pair(t, ex));
	}
	
}


void Cjt_trets::treure_tret(const int& id, const string& t, Cjt_individus& p) {
	
	if(not mtret[t].treure_ind_secuencia_tret(id)) cout << "  error" << endl;
	
	if (mtret[t].mida_nom_ind() == 0)
		mtret.erase(t);
	else {
		Tret op = mtret[t].retornar_Tret(p);
	
		mtret.erase(t);
		mtret.insert(make_pair(t, op));
	}
	
}

void Cjt_trets::consultar_tret(const string& t,  Cjt_individus& p) {
	
	
	
	MIt = mtret.find(t);
	if (MIt != mtret.end()){
		cout << "  " << t << endl;
		mtret[t].imprimir_secuencia_tret(p.retornar_tam());
		mtret[t].imprimir_nom_individus_tret();
	}
	else cout << "  error" << endl;
}
	   
void Cjt_trets::trets_individu(int id) {
	
	
	
	for(MIt = mtret.begin(); MIt != mtret.end(); ++MIt) {
		if(MIt->second.buscar_individu(id))
			cout << MIt->first << endl;
	}
}
	
	

void Cjt_trets::netejar_trets() {
	
	mtret.clear();
}

void Cjt_trets::consulta_trets_individu(int id) {
	
	
	
	for(MIt = mtret.begin(); MIt != mtret.end(); ++MIt) {
		if(mtret[MIt->first].buscar_individu(id))
			cout << "  " << MIt->first << endl;
	}
}

void Cjt_trets::llegir_arbre() {

	arbre = read();	
}




void Cjt_trets::imprimir_arbre(const BinTree<int>& a) const{
 
	if (not a.empty()) {
		imprimir_arbre(a.left());
		cout << " " << a.value(); 
		imprimir_arbre(a.right());
	}
}


void Cjt_trets::distribucio_tret(string& t) {

	MIt = mtret.find(t);
	if (MIt == mtret.end()) cout << "  error" << endl;
	else {
	
	
	BinTree<int> arb_dist = arbre_distribuit(t, arbre);
	
	cout << ' ';
	imprimir_arbre(arb_dist);
	cout << endl;
		
	}
	
}

BinTree<int> Cjt_trets::arbre_distribuit(const string& t, BinTree<int>& arbre) {
	
	if (arbre.empty() or arbre.value() == 0) return BinTree<int>();
	else {
		
		BinTree<int> subl = arbre.left();
		BinTree<int> subr = arbre.right();		
		BinTree<int> al = arbre_distribuit(t,subl);
		BinTree<int> ar = arbre_distribuit(t,subr);
		int val = arbre.value();
		if(mtret[t].buscar_individu(val)) return BinTree<int>(val,al,ar);
		else if((al.empty() or al.value() == 0) and (ar.empty() or ar.value() == 0)) return BinTree<int>();
		else return BinTree<int>(-val, al, ar);
	}

	return BinTree<int>();
}
		