#ifndef ARREGLO_LISTA_H
#define ARREGLO_LISTA_H

#include <iostream>

#define capacidad 10

using namespace std;


template <typename Objeto>
class arreglo_lista
{
    private:
        int last;//i: le cambie el nombre para tener una mejor comprension y referencia de su utilidad
        int cap;
        Objeto *arr;
	public:
        explicit arreglo_lista (int tam):last{tam},cap{last+capacidad	}{
            arr=new Objeto[cap];
        }
        arreglo_lista (const arreglo_lista &rhs):last{rhs.last},cap{rhs.cap}, arr{nullptr}{
            arr=new Objeto[cap];
            for(int k=0;k<last;k++)
            arr[k]=rhs.arr[k];
        }
        arreglo_lista(arreglo_lista &&rhs){
            rhs.last=0;
            rhs.cap=0;
            rhs.arr=nullptr;
        }
        arreglo_lista(){
            last=0;
            cap=capacidad;
            arr=new Objeto[capacidad];
        }
        ~arreglo_lista(){
            delete []arr;
        }
        arreglo_lista & operator = (const arreglo_lista &rhs){
            arreglo_lista copia=rhs;
            swap(*this, copia);
            return *this;
        }
        arreglo_lista & operator = (arreglo_lista &&rhs){
            swap(last, rhs.last);
            swap(cap, rhs.last);
            swap(arr, rhs.arr);
            return *this;
        }

        int getLastPos(){
            return last;
        }

        Objeto getElemento(int index){
            return arr[index];
        }

        void push_final(const Objeto &rhs){
            if(last==cap){
                cap=cap+1;
                nueva_capacidad(cap);
            }
            arr[last]=rhs;
            last++;
        }
        void push_final(Objeto &&rhs){
            if(last==cap){
                cap=cap+1;
                nueva_capacidad(cap);
            }
            arr[last]=move(rhs);
            last++;
        }

        void pushInicio(const Objeto &rhs){
            int i;
            if(last==cap){
                cap=cap+1;
                nueva_capacidad(cap);
            }
            for(i=last+1; i>0; i--){
                arr[i]=arr[i-1];
            }
            arr[i]=rhs;
            last++;
        }

        void pushInicio(Objeto &&rhs){
            int i;
            if(last==cap){
                cap=cap+1;
                nueva_capacidad(cap);
            }
            for(i=last+1; i>0; i--){
                arr[i]=arr[i-1];
            }
            arr[i]=move(rhs);
            last++;
        }



        void pop_final(){
            if(!vacia()){
                last--;
            }
        }

        void popInicio(){
            if(!vacia()){
                for(int i=0;i<last;i++){
                    arr[i]=arr[i+1];
                }
                last--;
            }
        }


        Objeto & operator [] (int indice){
            return arr[indice];
        }
        const Objeto & operator [](int indice)const{
            return arr[indice];
        }
        void nueva_capacidad(int nueva_cap){
            if(nueva_cap>cap){
                cap=nueva_cap;
                reservar(nueva_cap);
            }
        }
        void reservar(int nueva_capacidad){
            if(nueva_capacidad>cap){
                Objeto *nuevosDatos=new Objeto[nueva_capacidad];
                if(!vacia()){
                    for(int j=0; j<last; j++){
                        nuevosDatos[j]=move(arr[j]);
                        arr=nuevosDatos;
                        delete []nuevosDatos;
                    }
                }
            }
        }
        int vacia(){
            if(last==0)
            return 1;
            else
            return 0;
        }

        string toString(){
            string result;
            int i = 0;
            while(i<=last){
                result+= arr[i].toString()+ "\n";
                i++;
            }
            return result;
        }

};

#endif // ARREGLO_LISTA_H
