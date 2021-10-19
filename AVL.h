#include <iostream>
#include <conio.h>

using namespace std;
template<typename  T>
class Nodo {
    public:
        T dato;
        int fe;  // factor de equilibrio
        Nodo<T>*   izquierdo;
        Nodo<T>*   derecho;

        Nodo<T>(T dato);
};
template<typename T>
class AVL {
    private:
        Nodo<T>* raiz;
    public:
        AVL();
        Nodo<T>* buscar(int dato, Nodo<T>* raiz);
        int   obtenerFE(Nodo<T>* nodo);
        Nodo<T>* rotacionIzquierda(Nodo<T>* nodo);
        Nodo<T>* rotacionDerecha(Nodo<T>* nodo);
        Nodo<T>* rotacionDobleIzquierda(Nodo<T>* nodo);
        Nodo<T>* rotacionDobleDerecha(Nodo<T>* nodo);
        Nodo<T>* insertarNodo(Nodo<T>* nuevo, Nodo<T>* subArbol);
        void  insertar(T dato);
        void  inOrden(Nodo<T>* nodo);
        void  preOrden(Nodo<T>* nodo );
        void  postOrden(Nodo<T>* nodo);
        void  inOrden();
        void  preOrden();
        void  postOrden();

        Nodo<T>* obtenerRaiz();
};
template<typename T>
Nodo<T>::Nodo(T dato) {
    this->dato = dato;
    this->fe = 0;
    this->izquierdo = NULL;
    this->derecho = NULL;
}
template<typename T>
AVL<T>::AVL() {
    this->raiz = NULL;
}
template<typename T>
Nodo<T>* AVL<T>::buscar(int dato, Nodo<T>* raiz) {
    if (raiz == NULL) {
        return NULL;
    } else if (raiz->dato == dato) {
        return raiz;
    } else if (raiz->dato < dato) {
        return buscar(dato, raiz->derecho);
    } else if (raiz->dato > dato) {
        return buscar(dato, raiz->izquierdo);
    }
}
template<typename T>
int AVL<T>::obtenerFE(Nodo<T>* nodo) {
    if (nodo == NULL) {
        return -1;
    } else {
        return nodo->fe;
    }
}
template<typename T>
Nodo<T>* AVL<T>::rotacionIzquierda(Nodo<T>* nodo) {
    Nodo<T>* aux = nodo->izquierdo;
    nodo->izquierdo = aux->derecho;

    aux->derecho = nodo;

    nodo->fe = max(this->obtenerFE(nodo->izquierdo), this->obtenerFE(nodo->derecho)) + 1;
    aux->fe  = max(this->obtenerFE(aux->izquierdo), this->obtenerFE(aux->derecho)) + 1;

    return aux;
}
template<typename T>
Nodo<T>* AVL<T>::rotacionDerecha(Nodo<T>* nodo) {
    Nodo<T>* aux = nodo->derecho;
    nodo->derecho = aux->izquierdo;

    aux->izquierdo = nodo;

    nodo->fe = max(this->obtenerFE(nodo->izquierdo), this->obtenerFE(nodo->derecho)) + 1;
    aux->fe  = max(this->obtenerFE(aux->izquierdo), this->obtenerFE(aux->derecho)) + 1;

    return aux;
}
template<typename T>
Nodo<T>* AVL<T>::rotacionDobleIzquierda(Nodo<T>* nodo) {
    Nodo<T>* aux;

    nodo->izquierdo = this->rotacionDerecha(nodo->izquierdo);
    aux = this->rotacionIzquierda(nodo);

    return aux;
}
template<typename T>
Nodo<T>* AVL<T>::rotacionDobleDerecha(Nodo<T>* nodo) {
    Nodo<T>* aux;

    nodo->derecho = this->rotacionIzquierda(nodo->derecho);
    aux = this->rotacionDerecha(nodo);

    return aux;
}
template<typename T>
Nodo<T>* AVL<T>::insertarNodo(Nodo<T>* nuevo, Nodo<T>* subArbol) {
    Nodo<T>* nuevoPadre = subArbol;

    if (nuevo->dato < subArbol->dato) {
        if (subArbol->izquierdo == NULL) {
            subArbol->izquierdo = nuevo;
        } else {
            subArbol->izquierdo = this->insertarNodo(nuevo, subArbol->izquierdo);

            int balance = this->obtenerFE(subArbol->izquierdo) - this->obtenerFE(subArbol->derecho);

            if (balance == 2) {
                if (nuevo->dato < subArbol->izquierdo->dato) {
                    nuevoPadre = this->rotacionIzquierda(subArbol);
                } else {
                    nuevoPadre = this->rotacionDobleIzquierda(subArbol);
                }
            }

        }
    } else if (nuevo->dato > subArbol->dato) {
        if (subArbol->derecho == NULL) {
            subArbol->derecho = nuevo;
        } else {
            subArbol->derecho = this->insertarNodo(nuevo, subArbol->derecho);

            int balance = this->obtenerFE(subArbol->derecho) - this->obtenerFE(subArbol->izquierdo);

            if (balance == 2) {
                if (nuevo->dato > subArbol->derecho->dato) {
                    nuevoPadre = this->rotacionDerecha(subArbol);
                } else {
                    nuevoPadre = this->rotacionDobleDerecha(subArbol);
                }
            }
        }
    } else {
        cout << "Nodo<T> duplicado!" << endl;
    }

    // Actualizando factor de equilibrio
    if ((subArbol->izquierdo == NULL) && (subArbol->derecho != NULL)) {
        subArbol->fe = subArbol->derecho->fe + 1;
    } else if ((subArbol->derecho == NULL) && (subArbol->izquierdo != NULL)) {
        subArbol->fe = subArbol->izquierdo->fe + 1;
    } else {
        subArbol->fe = max(this->obtenerFE(subArbol->izquierdo), this->obtenerFE(subArbol->derecho)) + 1;
    }

    return nuevoPadre;
}
template<typename T>
void AVL<T>::insertar(T dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);

    if (this->raiz == NULL) {
        this->raiz = nuevo;
    } else {
        this->raiz = this->insertarNodo(nuevo, raiz);
    }
}
template<typename T>
void AVL<T>::inOrden(Nodo<T>* nodo) {
    if (nodo != NULL) {
        this->inOrden(nodo->izquierdo);
        cout << nodo->dato << ", ";
        this->inOrden(nodo->derecho);
    }
}
template<typename T>
void AVL<T>::preOrden(Nodo<T>* nodo) {
    if (nodo != NULL) {
        cout << nodo->dato << ", ";
        this->preOrden(nodo->izquierdo);
        this->preOrden(nodo->derecho);
    }
}
template<typename T>
void AVL<T>::postOrden(Nodo<T>* nodo) {
    if (nodo!= NULL) {
        this->postOrden(nodo->izquierdo);
        this->postOrden(nodo->derecho);
        cout << nodo->dato << ", ";
    }
}
template<typename T>
void AVL<T>::inOrden(){
    inOrden(this->raiz);
    cout<<endl;
}
template<typename T>
void AVL<T>::preOrden(){
    preOrden(this->raiz);
    cout<<endl;
}
template<typename T>
void AVL<T>::postOrden(){
    postOrden(this->raiz);
    cout<<endl;
}

template<typename T>
Nodo<T>* AVL<T>::obtenerRaiz() {
    return this->raiz;
}
