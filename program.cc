/**
 * @mainpage Aplicació per a un laboratori de biologia.
 
*/

/** @file program.cc
    @brief Experiment genètic sobre la modificació del genoma d'individus y dels trets que manifesten <em>Aplicació per a un laboratori de biologia</em>.
*/


#include "Cjt_individus.hh" 
#include "Cjt_trets.hh"
#ifndef NO_DIAGRAM 
#include <string>
#include <iostream>
#endif

/** @brief Programa principal per a la aplicació <em>Aplicació per a un laboratori de biologia</em>.
*/
int main ()
{
    
     
     Cjt_individus p;
     Cjt_trets trets;
	 
    
    string instruccion;
    cin >> instruccion;
    while (instruccion != "fi") {
        
        if (instruccion == "experiment") {
           
			cout << "experiment ";
           int n, m;
		   cin >> n >> m;
		   cout << n << ' ' << m << endl;
		   trets.netejar_trets();
		   trets.llegir_arbre();
		   
		   p.llegir(n,m);
		   
            
        }
        else if (instruccion == "afegir"){

			string t;
            cin >> t;
            int id;
            cin >> id;
			cout << "afegir " << t << ' ' << id << endl;
            trets.afegir_tret(id, t, p);
	
        }
        else if (instruccion == "treure"){ 
			
			string t;
            cin >> t;
            int id;
            cin >> id;
			
			cout << "treure " << t << ' ' << id << endl;
            
             trets.treure_tret(id, t, p);
			
		}
        else if (instruccion == "consulta_tret"){ 
			
			string t;
			cin >> t;
			cout << "consulta_tret " << t << endl;
			trets.consultar_tret(t, p);
			
		}
        else if (instruccion == "consulta_individu"){ 
            
            int id;
            cin >> id;
            cout << "consulta_individu " << id << endl; 
            p.consulta_individu(id);
			trets.consulta_trets_individu(id);
            
        }
        else if (instruccion == "distribucio_tret") { 
			
			string t;
			cin >> t;
			cout << "distribucio_tret " << t << endl;
			trets.distribucio_tret(t);
			
		}
        
        cin >> instruccion;
        
    }

	cout << "fi" << endl;
}
