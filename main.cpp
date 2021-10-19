//Nombres 1: Josue Gabriel Sumare Uscca++
//Nombres 2:Freddy Leonel Humpiri Valdivia+
//Nombres 3:MIGUEL ANGEL DEZA CUELA
//Fecha:18/10/2021
#include"BinaryTree.h"
#include"SimpleLinkedList.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include"AVL.h"

using namespace std;

int main()
{

    string ubicacion_input ="ENTRADA.TXT";
    string palabra;
    ifstream input(ubicacion_input.c_str());
    SimpleLinkedList<string>test;
    BinaryTree<string>tree;
    AVL<string>arbolAVL;
    long long counter=0;
    while(!input.eof()) {
        input >> palabra;
        arbolAVL.insertar(palabra);
        counter++;
        //counter++;
        //cout<<"Hello";
        //test.pushFront(palabra);//Insertando en lista Simplemente enlazaada
        //tree.insert(palabra);//Insertando en arbol binario
    }
    input.close();
    //arbolAVL.preOrden();

    //test.printIterative();
    //tree.printInorden();
    cout<<"the counter is "<<counter<<endl;

}
