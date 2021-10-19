#include <iostream>
using namespace std;
#include "NodeBT.h"
template<typename T>
class BinaryTree{
    private:
        NodeBT<T>*m_pRoot;
    public:
        BinaryTree(){
            this->m_pRoot=0;
        }

        void insert(T value){
            if(!this->m_pRoot){
                this->m_pRoot=new NodeBT<T>(value);
                return;
            }
            else{
                NodeBT<T>*pAux=this->m_pRoot;
                NodeBT<T>*pAuxAntes;
                while(pAux){
                    if(pAux->value==value)return;
                    pAuxAntes=pAux;
                    pAux=pAux->m_pSon[pAux->value<value];
                }
                pAuxAntes->m_pSon[pAuxAntes->value<value]=new NodeBT<T>(value);


            }
        }
        void insertRecursive(T value,NodeBT<T>*&pAux){
            if(!pAux){
                pAux=new NodeBT<T>(value);
                return;
            }
            else{
                insertRecursive(value,pAux->m_pSon[pAux->value<value]);
            }
        }
        void insertRecursive(T value){
            insertRecursive(value,this->m_pRoot);
        }
        void printPreorden(NodeBT<T>*pAux){
            if(!pAux)return;
            cout<<pAux->value<<endl;
            printPreorden(pAux->m_pSon[0]);
            printPreorden(pAux->m_pSon[1]);
        }
        void printPreorden(){
            printPreorden(this->m_pRoot);
        }
        void printInorden(NodeBT<T>*pAux){
            if(!pAux)return;
            printInorden(pAux->m_pSon[0]);
            cout<<pAux->value<<endl;
            printInorden(pAux->m_pSon[1]);
        }
        void printInorden(){
            printInorden(this->m_pRoot);
        }
        void printPostorden(NodeBT<T>*pAux){
            if(!pAux)return;
            printPostorden(pAux->m_pSon[0]);
            printPostorden(pAux->m_pSon[1]);
            cout<<pAux->value<<endl;
        }
        void printPostorden(){
            printPostorden(this->m_pRoot);
        }
        bool findRecursive(T value,NodeBT<T>*pAux){
            if(!pAux)return false;
            if(pAux->value==value)return true;
            else findRecursive(value,pAux->m_pSon[pAux->value<value]);
        }
        bool findRecursive(T value){
            return findRecursive(value,this->m_pRoot);
        }
        bool findIterative(T value){
            NodeBT<T>*pAux=this->m_pRoot;
            while(pAux){
                if(pAux->value==value)return true;
                pAux=pAux->m_pSon[pAux->value<value];
            }
            return false;
        }
        T getPadre(T value){
            if(!this->m_pRoot||value==-1||value==this->m_pRoot->value)return -1;
            NodeBT<T>*pAux=this->m_pRoot;
            NodeBT<T>*pAuxAntes;
            while(pAux){
                pAuxAntes=pAux;
                pAux=pAux->m_pSon[pAux->value<value];
                if(pAux->value==value)return pAuxAntes->value;
            }
            return -1;
        }
        /*
        T getPadreRecursive(T value,Node<T>*pAux){
            if(!this->m_pRoot||value==-1||value==this->m_pRoot->value)return -1;


        }*/
        T getHermano(T value){
            if(!this->m_pRoot||value==-1||value==this->m_pRoot->value)return -1;
            NodeBT<T>*pAux=this->m_pRoot;

            while(pAux){
                if(pAux->m_pSon[pAux->value<value]->value==value && pAux->m_pSon[pAux->value>value]){
                    return pAux->m_pSon[pAux->value>value]->value;

                }
                else if(!pAux->m_pSon[pAux->value>value]&& pAux->m_pSon[pAux->value<value]->value==value) return -1;
                pAux=pAux->m_pSon[pAux->value<value];
            }
            return -1;
        }
        /*
        T getHermanoRecursivo(T value,Node<T>*pAux){
            if(!pAux||value==-1||value==this->m_pRoot->value)return -1;

        }
        */
        NodeBT<T>*getRoot(){
            return this->m_pRoot;
        }
        T getTio(T value){
            return getHermano(getPadre(value));
        }
        T getAbuelo(T value){
            return getPadre(getPadre(value));
        }

};
