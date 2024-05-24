//Juan Diego Castro Mariscal
#include <iostream>
#include <string>

#include "arreglo_lista.h"
#include "Estudiante.h"
#include "Materia.h"
using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

enum{REGISTRAR=1,ELIMINAR,CONSULTAR_TODO,CONSULTAR_UNO,SALIR};

void pausa();
void registrarEstudiante(Estudiante &miEstudiante);

int main()
{
    arreglo_lista <Estudiante> estudiantes;
    int opcion;
    bool continuaPrograma=true;
    setlocale(LC_ALL,"");
    do{
        system(CLEAR);
        cout <<"MENU PRINCIPAL" << endl << endl;
        cout << "1.Registrar Estudiante" << endl;
        cout << "2.Eliminar Estudiante" << endl;
        cout << "3.Consultar todos los estudiantes" << endl;
        cout << "4.Consultar un estudiante" << endl;
        cout << "5.Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;
        cin.get();
        switch(opcion){
        case REGISTRAR:
            int opcionRegistrar;
            system(CLEAR);
            cout << "1.Registrar al inicio de la lista" << endl;
            cout << "2.Registrar al final de la lista" << endl;
            cout << "opción: ";
            cin >> opcionRegistrar;
            cin.get();
            if(opcionRegistrar==1){
                system(CLEAR);
                cout << "Registrar al inicio: " << endl << endl;
                Estudiante miEstudiante;
                registrarEstudiante(miEstudiante);
                estudiantes.pushInicio(miEstudiante);

            }
            else if(opcionRegistrar==2){
                system(CLEAR);
                cout << "Registrar al final: " << endl << endl;
                Estudiante miEstudiante;
                registrarEstudiante(miEstudiante);
                estudiantes.push_final(miEstudiante);

            }else{
                cout << "Opción no válida..." << endl;
                pausa();
            }
            break;

        case ELIMINAR:
            int opcionEliminar;
            system(CLEAR);
            cout << "ELIMINAR ESTUDIANTE" << endl << endl;
            if(estudiantes.vacia()){
                cout << "La lista esta vacía..." << endl;
                pausa();
            }else{
                cout << "1.Eliminar al inicio de la lista" << endl;
                cout << "2.Eliminar al final de la lista" << endl;
                cout << "opción: ";
                cin >> opcionEliminar;
                cin.get();
                if(opcionEliminar==1){
                    estudiantes.popInicio();
                    cout << "Se ha eliminado exitosamente..." << endl;
                    pausa();
                }
                else if(opcionEliminar==2){
                    estudiantes.pop_final();
                    cout << "Se ha eliminado exitosamente..." << endl;
                    pausa();

                }else{
                    cout << "Opción no válida..." << endl;
                    pausa();
                }

            }
            break;

        case CONSULTAR_TODO:
            system(CLEAR);
            cout << "CONSULTAR TODOS LOS ESTUDIANTES" << endl << endl;
            if(estudiantes.vacia()){
                cout << "La lista esta vacía." << endl;
            }else{
                for(int i=0; i<estudiantes.getLastPos(); i++){
                    cout << estudiantes.getElemento(i).toString();
                }
            }
            pausa();
            break;

        case CONSULTAR_UNO:
            system(CLEAR);
            cout << "CONSULTA DE UN ESTUDIANTE" << endl << endl;
            if(estudiantes.vacia()){
                cout << "La lista esta vacía." << endl;
            }else{
                int codigoABuscar;
                Estudiante estudianteABuscar;
                estudianteABuscar.setCodigo(0);//poner el codigo en 0 o nulo
                cout << "Ingresa el código del estudiante que quieres consultar: ";
                cin >> codigoABuscar;
                cin.get();
                for(int i=0; i<=estudiantes.getLastPos();i++){
                    if(estudiantes.getElemento(i).getCodigo()==codigoABuscar){
                        estudianteABuscar=estudiantes.getElemento(i);
                        break;
                    }//else seguir buscando
                }
                if(estudianteABuscar.getCodigo()==0){
                    cout<< "No hay estudiantes con ese código." << endl;
                }else{
                    cout << estudianteABuscar.toString();

                }

            }
            pausa();
            break;

        case SALIR:
            continuaPrograma=false;
            break;

        default:
            cout << "Opción no válida...Intentalo de nuevo" << endl;
            pausa();

        }
    }while(continuaPrograma);
    return 0;
}

void registrarEstudiante(Estudiante &miEstudiante){
    string nombre;
    int codigo;
    string carrera;
    string estatus;
    int numMaterias;
    int cuentaMaterias=0;
    cout << "Ingrese el nombre: ";
    getline(cin,nombre);
    cout << "Ingrese el código: ";
    cin >> codigo;
    cin.get();
    cout << "Ingrese la carrera: ";
    getline(cin,carrera);
    cout << "Ingrese el estatus: ";
    getline(cin,estatus);
    cout << "Ingrese el número de materias que cursa: ";
    cin >> numMaterias;
    cin.get();
    miEstudiante.setNombre(nombre);
    miEstudiante.setCodigo(codigo);
    miEstudiante.setCarrera(carrera);
    miEstudiante.setEstatus(estatus);
    miEstudiante.setNumMaterias(numMaterias);
    miEstudiante.setCuentaMaterias(cuentaMaterias);
    for(int i=0; i<numMaterias; i++){
        string clave;
        string seccion;
        int nrc;
        string horario;
        string profesor;
        string nombreMateria;
        cout << "Ingresa la clave de la materia " << (i+1) << ": ";
        getline(cin,clave);
        cout << "Ingresa la sección de la materia " << (i+1)<< ": ";
        getline(cin,seccion);
        cout << "Ingresa el NRC de la materia "<< (i+1)<< ": ";
        cin >> nrc;
        cin.get();
        cout << "Ingresa el horario de la materia "<< (i+1)<< ": ";
        getline(cin,horario);
        cout << "Ingresa el profesor de la materia "<< (i+1)<< ": ";
        getline(cin,profesor);
        cout << "Ingresa el nombre de la materia "<< (i+1)<< ": ";
        getline(cin,nombreMateria);
        miEstudiante.setMateria(clave,seccion,nrc,horario,profesor,nombreMateria,i);//setMateria ya aumenta cuentaMaterias en 1
    }
    cout << "Registro exitoso!!!" << endl;
    pausa();

}

void pausa(){
    cout << "Presiona entrar para continuar..." ;
    cin.get();
}
