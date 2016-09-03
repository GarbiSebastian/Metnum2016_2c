#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>


#include <iostream>
#include <string>
#include <sstream>
//#include <queue>
#include <stdio.h>
//#include <windows.h>




using namespace std;

void crearCavezeraArchivo();




int main(int argc, char *argv[])
{
    
    int radioInterno = 20;  
    int radioExterno = 100;
    int mMasUnoRadios = 0;
    int nAngulos = 0;
    int isoterma = 500;
    int cantDeInstermas = 1;

    int temperaturaInterna = 1500;
    int temperaturaExterna = 0;


    
    for(int radio = 8; radio < 108; radio+=5){
        //for(int angulo = 0; angulo < 97; angulo++){
		int angulo = 6;

            string pathSalida = "./test_egvlu1i/radios-" ;        
            stringstream radioActual;
            radioActual << radio + 2 ;
            stringstream anguloActual;
            anguloActual << angulo + 4 ;
            pathSalida = pathSalida + radioActual.str() + "-angulos-" + anguloActual.str() + ".in";

            ofstream archivoDeSalida;
            archivoDeSalida.open(pathSalida.c_str());
         

            archivoDeSalida << radioInterno << " ";
            archivoDeSalida << radioExterno << " ";
            archivoDeSalida << radioActual.str() << " ";//mMasUnoRadios;
            archivoDeSalida << anguloActual.str() << " ";//nAngulos;
            archivoDeSalida << isoterma << " ";
            archivoDeSalida << cantDeInstermas << endl;
            
            temperaturaExterna = 0;
            for(int inst = 0; inst < cantDeInstermas; inst++){
                for(int i = 0; i < (angulo + 4); i++){
                     archivoDeSalida << temperaturaInterna << " ";   
                }
                for(int j = 0; j < (angulo + 4); j++){
                     archivoDeSalida << temperaturaExterna << " ";   
                }
                temperaturaExterna = temperaturaExterna + 50;
                archivoDeSalida << endl;                   
            }
            archivoDeSalida.close(); 
            
        //}
    }
//
//    cout << "Escriviendo archivos con temperaturas externas variando en +/- 10 grados ..." << endl;
//    srand(time(0));
//    for(int radio = 0; radio < 99; radio++){
//        for(int angulo = 0; angulo < 97; angulo++){
//
//            string pathSalida = "./test_VariandoCantRadiosAngulos_TempExternaMasMenos10/radios-" ;        
//            stringstream radioActual;
//            radioActual << radio + 2 ;
//            stringstream anguloActual;
//            anguloActual << angulo + 4 ;
//            pathSalida = pathSalida + radioActual.str() + "_angulos-" + anguloActual.str() + "_tempRand.in";
//
//            ofstream archivoDeSalida;
//            archivoDeSalida.open(pathSalida.c_str());
//         
//
//            archivoDeSalida << radioInterno << " ";
//            archivoDeSalida << radioExterno << " ";
//            archivoDeSalida << radioActual.str() << " ";//mMasUnoRadios;
//            archivoDeSalida << anguloActual.str() << " ";//nAngulos;
//            archivoDeSalida << isoterma << " ";
//            archivoDeSalida << cantDeInstermas << endl;
//            
//            temperaturaExterna = 0;
//            for(int inst = 0; inst < cantDeInstermas; inst++){
//                for(int i = 0; i < (angulo + 4); i++){
//                     archivoDeSalida << temperaturaInterna << " ";   
//                }
//                for(int j = 0; j < (angulo + 4); j++){
//                    int difTemp = rand()%20;
//                    int aux = temperaturaExterna + (difTemp-10);
//                    if(aux < 0) aux = 0;
//                    archivoDeSalida << aux << " "; 
//                }
//                temperaturaExterna = temperaturaExterna + 50;
//                archivoDeSalida << endl;                   
//            }
//            archivoDeSalida.close(); 
//            
//        }
//    }


    
    //system("PAUSE");
    return EXIT_SUCCESS;
}
