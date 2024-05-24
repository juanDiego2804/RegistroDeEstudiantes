//Juan Diego Castro Mariscal
#ifndef MATERIA_H
#define MATERIA_H

#include <iostream>

using namespace std;

class Materia{
    private:
        string clave;
        string seccion;
        int nrc;
        string horario;
        string profesor;
        string nombreMateria;
    public:
        void setClave(string clave);
        void setSeccion(string seccion);
        void setNrc(int nrc);
        void setHorario(string horario);
        void setProfesor(string profesor);
        void setNombreMateria(string nombreMateria);

        Materia(string clave,string seccion,int nrc,string horario,string profesor,string nombreMateria);

        Materia(){};

        string getClave();
        string getSeccion();
        int getNrc();
        string getHorario();
        string getProfesor();
        string getNombreMateria();

        string toString();

};

Materia::Materia(string clave,string seccion,int nrc,string horario,string profesor,string nombreMateria){
    setClave(clave);
    setSeccion(seccion);
    setNrc(nrc);
    setHorario(horario);
    setProfesor(profesor);
    setNombreMateria(nombreMateria);

}
void Materia::setClave(string clave){
    this->clave=clave;
}

void Materia::setSeccion(string seccion){
    this->seccion=seccion;
}

void Materia::setNrc(int nrc){
    this->nrc=nrc;
}

void Materia::setHorario(string horario){
    this->horario=horario;
}

void Materia::setProfesor(string profesor){
    this->profesor=profesor;

}
void Materia::setNombreMateria(string nombreMateria){
    this->nombreMateria=nombreMateria;
}

string Materia::getClave(){
    return clave;
}

string Materia::getSeccion(){
    return seccion;
}

int Materia::getNrc(){
    return nrc;
}

string Materia::getHorario(){
    return horario;
}
string Materia::getProfesor(){
    return profesor;
}
string Materia::getNombreMateria(){
    return nombreMateria;
}

string Materia::toString(){
    return ("Clave: " + clave+ "\n" +
        "Seccion: "+seccion+"\n"+
        "NRC: "+to_string(nrc)+"\n"+
        "Horario: "+horario+"\n"+
        "Profesor: "+profesor+"\n"+
        "Nombre de la materia: "+nombreMateria+"\n");

}


#endif // MATERIA_H
