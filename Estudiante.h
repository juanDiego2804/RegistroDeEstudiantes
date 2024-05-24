//Juan Diego Castro Mariscal
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
#include "Materia.h"

#define TAMANIO_POR_DEFECTO 100
using namespace std;

class Estudiante{
    private:
        string nombre;
        int codigo;
        string carrera;
        string estatus;
        int numMaterias;
        int cuentaMaterias;
        Materia materias[TAMANIO_POR_DEFECTO];
    public:
        void setNombre(string nombre);
        void setCodigo(int codigo);
        void setCarrera(string carrera);
        void setEstatus(string estatus);
        void setNumMaterias(int numMaterias);
        void setCuentaMaterias(int cuentaMaterias);
        void setMateria(string clave,string seccion,int nrc,string horario,
                        string profesor,string nombreMateria,int cuentaMaterias);

        Materia getMateria(int posicion);
        int getCuentaMaterias();
        string getNombre();
        int getCodigo();
        string getCarrera();
        string getEstatus();
        int getNumMaterias();

        string toString();

};

void Estudiante::setNombre(string nombre){
    this->nombre=nombre;
}

void Estudiante::setCodigo(int codigo){
    this->codigo=codigo;
}

void Estudiante::setCarrera(string carrera){
    this->carrera=carrera;
}

void Estudiante::setEstatus(string estatus){
    this->estatus=estatus;
}

void Estudiante::setNumMaterias(int numMaterias){
    this->numMaterias=numMaterias;
}
void Estudiante::setCuentaMaterias(int cuentaMaterias){
    cuentaMaterias=numMaterias-numMaterias+1;
}


void Estudiante::setMateria(string clave,string seccion,int nrc,string horario,
                            string profesor,string nombreMateria,int posicion){
    materias[posicion].setClave(clave);
    materias[posicion].setSeccion(seccion);
    materias[posicion].setNrc(nrc);
    materias[posicion].setHorario(horario);
    materias[posicion].setProfesor(profesor);
    materias[posicion].setNombreMateria(nombreMateria);
    cuentaMaterias++;
}


Materia Estudiante::getMateria(int posicion){
    return materias[posicion];
}
int Estudiante::getCuentaMaterias(){
    return cuentaMaterias;
}

string Estudiante::getNombre(){
    return nombre;
}

int Estudiante::getCodigo(){
    return codigo;
}

string Estudiante::getCarrera(){
    return carrera;
}
string Estudiante::getEstatus(){
    return estatus;
}

int Estudiante::getNumMaterias(){
    return numMaterias;
}


string Estudiante::toString(){
    string resultado;
    resultado= "Nombre: "+nombre+ "\n"+
        "Codigo: "+to_string(codigo)+"\n"+
        "Carrera: "+carrera+"\n"+
        "Estatus: "+estatus+"\n"+
        "Numero de materias: "+to_string(numMaterias)+"\n";
    for(int i=0; i<numMaterias; i++){
        resultado+=materias[i].toString();
    }
    resultado+="\n";
    return resultado;
}


#endif // ESTUDIANTE_H
