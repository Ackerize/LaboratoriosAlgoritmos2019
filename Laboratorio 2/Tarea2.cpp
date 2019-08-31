#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
}*inicioP, *inicioC, *fin;

class Pila{
    public:
        Pila(){
            inicioP=nullptr;
        }
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig = nullptr;
            return n;
        }
        void push(int valor){
            Nodo *n = crearNodo(valor);
            n->sig = inicioP;
            inicioP = n;
        }
        void pop(){
            Nodo *temp = inicioP;
            inicioP = inicioP->sig;
            free(temp);
        }
        void mostrarPila(){
            Nodo *temp = inicioP;
            if(!inicioP)
                cout << "Pila vacia" << endl;
            else
                while(temp){
                    cout << temp->dato << ",";
                    temp = temp->sig;
                }
        }

};

class Cola{
    public:
        Cola(){
            inicioC = nullptr;
        }
        
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig = nullptr;
            return n;
        }
        void push(int valor){
            Nodo *n = crearNodo(valor);
            if(!inicioC){
                inicioC = n;
                fin = n;
            }
            else{
                fin->sig = n;
                fin = n;
            }
        }
        int pop(){
            Nodo *temp = inicioC;
            int aux;
            inicioC = inicioC->sig;
            aux = temp->dato;
            free(temp);
            return aux;
        }
        void mostrarCola(){
            Nodo *temp = inicioC;
            if(!inicioC)
                cout << "Cola vacia" << endl;
            else
                while(temp){
                    cout << temp->dato<<",";
                    temp = temp->sig;
                }
        }
        void invertirCola(){
          Pila p;

          //Creando una pila

          while(inicioC){
            p.push(pop());
          }
          inicioC = nullptr;
          fin = nullptr;

          //Creando la cola con los datos invertidos

          while(inicioP){
            push(inicioP->dato);
            inicioP = inicioP->sig;
          }
          cout << "Cola invertida: ";
          mostrarCola();
          cout << endl;
          PilaFinal();
        }

        void PilaFinal(){
          Pila p;
          Nodo *aux = inicioC;
          while(inicioC){
            aux = inicioC;
            p.push(aux->dato);
            inicioC = aux->sig;
            free(aux);
          }
          cout << "Cola invertida a pila: ";
          p.mostrarPila();
        }
    
};




int main()
{
    Cola c;
    c.push(1);
    c.push(2);
    c.push(3);
    cout << "Cola original: ";
    c.mostrarCola();
    cout << endl;
    c.invertirCola();
    
    cout << endl;
    return 0;
}