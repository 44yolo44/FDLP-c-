#include <iostream>  // Para operaciones de entrada y salida estándar
#include <conio.h>   // Para funciones de consola como getch()
#include <iomanip>   // manipulación de entrada y salida, 
#include <fstream>   // Para manejo de archivos
#include <cstring>   // operaciones con cadenas de caracteres
#include <cstdlib>   // funciones generales como exit()
#include <thread>    // Para la función sleep
#include <chrono>    // Para gestionar el tiempo
#include <ctime>     // Para la función time()

using namespace std; 

// Function prototype
void escribir();
void generarEstadisticas(); // Declarar la nueva función

// Declare handball statistics
int saquesdebandarojo, saquesdebandaverde;
int saquesdecentrorojo, saquesdecentroverde;
int lanzamientosde7metrosrojo, lanzamientosde7metrosverde;
int tiroslibresrojo, tiroslibresverde;
int faltasrojo, faltasverde;
int sancionesrojo, sancionesverde;
int tirosapuertarojo, tirosapuertaverde;
int posesionrojo, posesionverde;
int marcadorrojo, marcadorverde;

void escribir(){
	ofstream archivo;
	archivo.open("estadisticas.txt", ios::app);
	if(archivo.fail()){
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	  archivo << "Estadisticas del Balon Mano:" << endl;
    archivo << "---------------------------------------------" << endl;
    archivo << left << setw(30) << "Categoria" << setw(10) << "Rojo" 
		        << "Verde" << endl;
    archivo << "---------------------------------------------" << endl;
    archivo << left << setw(30) << "Marcador" << setw(10) 
         << marcadorrojo << marcadorverde << endl;
    archivo << left << setw(30) << "Saques de Banda" << setw(10) 
		     << saquesdebandarojo << saquesdebandaverde << endl;
    archivo << left << setw(30) << "Saques de Centro" << setw(10) 
		     << saquesdecentrorojo << saquesdecentroverde << endl;
    archivo << left << setw(30) << "Lanzamientos 7  Metros" << setw(10) 
		     << lanzamientosde7metrosrojo << lanzamientosde7metrosverde << endl;
    archivo << left << setw(30) << "Tiros Libres" << setw(10) 
         << tiroslibresrojo << tiroslibresverde << endl;
    archivo << left << setw(30) << "Tiros Libres" << setw(10) 
		     << tiroslibresrojo << tiroslibresverde << endl;
    archivo << left << setw(30) << "Faltas" << setw(10)  
		     <<faltasrojo << faltasverde << endl;
    archivo << left << setw(30) << "Sanciones" << setw(10) 
		     << sancionesrojo << sancionesverde << endl;
    archivo << left << setw(30) << "Tiros a Puerta" << setw(10) 
		     << tirosapuertarojo << tirosapuertaverde << endl;
    if (marcadorrojo > marcadorverde) {
        cout << "El equipo rojo gana el partido" << endl;
    } else if (marcadorrojo < marcadorverde) {
        cout << "El equipo verde gana el partido" << endl;
    } else {
        cout << "El partido termina en empate" << endl;
    }
    archivo.close();
	
}

void leer(){
  ifstream archivo;
  archivo.open("estadisticas.txt", ios::in);
  if(archivo.fail()){
    cout << "No se pudo abrir el archivo";
    exit(1);
  }
  string linea;
  while(!archivo.eof()){
    getline(archivo, linea);
    cout << linea << endl;
  }
  archivo.close();
}

void agregar() {
  ofstream archivo;
  archivo.open("estadisticas.txt", ios::app);
  if (archivo.fail()) {
    cout << "No se pudo abrir el archivo";
    exit(1);
  }
	  archivo << "Estadisticas del Balon Mano:" << endl;
    archivo << "---------------------------------------------" << endl;
    archivo << left << setw(30) << "Categoria" << setw(10) << "Rojo" 
		        << "Verde" << endl;
    archivo << "---------------------------------------------" << endl;
    archivo << left << setw(30) << "Marcador" << setw(10) 
         << marcadorrojo << marcadorverde << endl;
    archivo << left << setw(30) << "Saques de Banda" << setw(10) 
		     << saquesdebandarojo << saquesdebandaverde << endl;
    archivo << left << setw(30) << "Saques de Centro" << setw(10) 
		     << saquesdecentrorojo << saquesdecentroverde << endl;
    archivo << left << setw(30) << "Lanzamientos 7  Metros" << setw(10) 
		     << lanzamientosde7metrosrojo << lanzamientosde7metrosverde << endl;
    archivo << left << setw(30) << "Tiros Libres" << setw(10) 
         << tiroslibresrojo << tiroslibresverde << endl;
    archivo << left << setw(30) << "Tiros Libres" << setw(10) 
		     << tiroslibresrojo << tiroslibresverde << endl;
    archivo << left << setw(30) << "Faltas" << setw(10)  
		     <<faltasrojo << faltasverde << endl;
    archivo << left << setw(30) << "Sanciones" << setw(10) 
		     << sancionesrojo << sancionesverde << endl;
    archivo << left << setw(30) << "Tiros a Puerta" << setw(10) 
		     << tirosapuertarojo << tirosapuertaverde << endl;
    if (marcadorrojo > marcadorverde) {
        cout << "El equipo rojo gana el partido" << endl;
    } else if (marcadorrojo < marcadorverde) {
        cout << "El equipo verde gana el partido" << endl;
    } else {
        cout << "El partido termina en empate" << endl;
    }
    archivo.close();
}

void borrar(){
  ofstream archivo;
  archivo.open("estadisticas.txt", ios::out);
  if(archivo.fail()){
    cout << "No se pudo abrir el archivo";
    exit(1);
  }
  archivo.close();
}

void generarEstadisticas(){
    // Inicializar el generador de números aleatorios
    srand(time(0));
    marcadorrojo = rand() % 20 + 20; // 20-40
    marcadorverde = rand() % 20 + 20; // 
    
    saquesdebandarojo = rand() % 31 + 20; // 20-50
    saquesdebandaverde = rand() % 31 + 20;
    
    saquesdecentrorojo = marcadorverde;
    saquesdecentroverde = marcadorrojo;
    
    lanzamientosde7metrosrojo = rand() % 21 + 10; // 10-30
    lanzamientosde7metrosverde = rand() % 21 + 10;
    
    tiroslibresrojo = rand() % 21 + 5; // 5-25
    tiroslibresverde = rand() % 21 + 5;
    
    faltasrojo = rand() % 11 + 5; // 5-15
    faltasverde = rand() % 11 + 5;
    
    sancionesrojo = rand() % 6 + 0; // 0-5
    sancionesverde = rand() % 6 + 0;
    
    tirosapuertarojo = marcadorrojo + rand() % 5  ; 
    tirosapuertaverde =marcadorverde + rand() % 5 ;
    
    posesionrojo = rand() % 21 + 40; // 40-60%
    posesionverde = 100 - posesionrojo;
}

int main() { 
    
    int opcion;

    cout << "********************************";
		cout<<"****************************" << endl;
    cout << "* " << setw(40) << "simulacion de las estadisticas de un juego"; 
		cout << " de balon mano" << " *" << endl;
    cout << "* " << setw(38) << "equipo rojo vs equipo " ;
		cout << "verde" << setw(15) << " *" << endl;
    cout << "********************************";
		cout<<"****************************" << endl;

    cout << setw(50) << "Presiona Enter para iniciar la simulacion" << endl;
    cin.ignore();

    cout << "[";
    for(int i = 0; i <= 50; ++i) {
        cout << "=";
        cout.flush();
        this_thread::sleep_for(100ms); // Retraso de 100 ms
    }
    cout << "]" << endl;

    generarEstadisticas(); // Llamar a la nueva función antes de imprimir

    cout << "Estadisticas del Balon Mano:" << endl;
    cout << "---------------------------------------------" << endl;
    cout << left << setw(30) << "Categoria" << setw(10) << "Rojo" 
		     << "Verde" << endl;
    cout << "---------------------------------------------" << endl;
    cout << left << setw(30) << "Marcador" << setw(10) 
         << marcadorrojo << marcadorverde << endl;
    cout << left << setw(30) << "Saques de Banda" << setw(10) 
		     << saquesdebandarojo << saquesdebandaverde << endl;
    cout << left << setw(30) << "Saques de Centro" << setw(10) 
		     << saquesdecentrorojo << saquesdecentroverde << endl;
    cout << left << setw(30) << "Lanzamientos 7  Metros" << setw(10) 
		     << lanzamientosde7metrosrojo << lanzamientosde7metrosverde << endl;
    cout << left << setw(30) << "Posesion" << setw(10) 
         << posesionrojo << posesionverde << endl;
    cout << left << setw(30) << "Tiros Libres" << setw(10) 
		     << tiroslibresrojo << tiroslibresverde << endl;
    cout << left << setw(30) << "Faltas" << setw(10)  
		     <<faltasrojo << faltasverde << endl;
    cout << left << setw(30) << "Sanciones" << setw(10) 
		     << sancionesrojo << sancionesverde << endl;
    cout << left << setw(30) << "Tiros a Puerta" << setw(10) 
		     << tirosapuertarojo << tirosapuertaverde << endl;
    cout << "---------------------------------------------" << endl;

    if (marcadorrojo > marcadorverde) {
        cout << "El equipo rojo gana el partido" << endl;
    } else if (marcadorrojo < marcadorverde) {
        cout << "El equipo verde gana el partido" << endl;
    } else {
        cout << "El partido termina en empate" << endl;
    }
  
		cout <<  "presione una tecla para abrir el registro" ;
		cin.ignore();
 //opciones de archivos 
  do {
    cout << "\nELIJA UNA OPCION:";
    cout << "\n1. Guardar datos en archivo(sobreescribir)";
    cout << "\n2. Leer datos del archivo";
    cout << "\n3. Borrar datos del archivo";
    cout << "\n4. Agregar datos al archivo";
    cout << "\n5. Salir";
    cout << "\nIngrese una opcion: ";
    cin >> opcion;

    switch(opcion) {
      case 1:
      system("cls");
      cout << "se escribio registro!";
      escribir();  
      break;
      case 2:
      system("cls");
      cout << "REGISTRO: ";	
      leer();  
      break;
      case 3:
      system("cls");
      cout << "se elimino el registro!";	
      borrar();
      break;
      case 4:
      system("cls");
      cout << "se agrego al registro!";
      agregar();  
      break;
      case 5:
      cout << "Saliendo del programa...\n";
      exit(1);
      default:
      cout << "Opcion invalida. Intente de nuevo.\n";
    }
    } while(opcion != 5);

  getch();
  return 0;
}

