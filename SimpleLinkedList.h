#include<iostream>
#include "Node.h"
using namespace std;
template <typename T>
class SimpleLinkedList{

    private:

        Node<T>*m_pHead;
        int longitud;

    public:
        SimpleLinkedList(){
            this->m_pHead=0;
            this->longitud=0;
        }
        int getLongitud(){
            return this->longitud;
        }
        void pushBackIterative(T value){
            if(!this->m_pHead){
                this->m_pHead=new Node<T>(value);
                this->longitud++;
                return;
            }
            Node<T>*pAux=this->m_pHead;

            while(pAux->getM_pSig()){
                pAux=pAux->getM_pSig();
            }

            pAux->setM_pSig(new Node<T>(value));
            this->longitud++;
        }

        void pushBackRecursive(T value,Node<T>*pAux){
            if(!this->m_pHead){
                this->m_pHead=new Node<T>(value);
                this->longitud++;
                return;
            }
            if(!pAux->getM_pSig()){
                pAux->setM_pSig(new Node<T>(value));
                this->longitud++;
                return;
            }
            else pushBackRecursive(value,pAux->getM_pSig());
        }

        void pushBackRecursive(T value){
            pushBackRecursive(value,this->m_pHead);
        }

        void pushFront(T value){
            Node<T>*pAux=new Node<T>(value);
            pAux->setM_pSig(this->m_pHead);
            this->m_pHead=pAux;
            this->longitud++;
        }

        void printIterative(){
            Node<T>*pAux=this->m_pHead;
            while(pAux){
                cout<<pAux->getValue()<<" -> ";
                pAux=pAux->getM_pSig();
            }
            cout<<endl;
        }

        void printRecursive(Node<T>*pAux){
            if(!pAux) return;
            else{
                cout<<pAux->getValue()<<" -> ";
                printRecursive(pAux->getM_pSig());
            }

        }

        void printRecursive(){
            printRecursive(this->m_pHead);
            cout<<endl;
        }

        void popBackIterative(){

            if(!this->m_pHead)return;
            if(!this->m_pHead->getM_pSig()){
                delete this->m_pHead;
                this->m_pHead=0;
            }
            Node<T>*pAux=this->m_pHead;
            while(pAux->getM_pSig()->getM_pSig()){
                pAux=pAux->getM_pSig();
            }
            delete pAux->getM_pSig();
            pAux->setM_pSig(0);
            this->longitud--;

        }
        void popBackRecursive(Node<T>*pAux){
            if(!this->m_pHead) return;
            if(!this->m_pHead->getM_pSig()){
                delete this->m_pHead;
                this->m_pHead=0;
            }
            if(!pAux->getM_pSig()->getM_pSig()){
                delete pAux->getM_pSig();
                pAux->setM_pSig(0);
                this->longitud--;
            }
            else popBackRecursive(pAux->getM_pSig());

        }
        void popBackRecursive(){
            popBackRecursive(this->m_pHead);

        }
        void popFront(){
            if(!this->m_pHead)return;
            else{
                Node<T>*pAux=this->m_pHead->getM_pSig();
                delete this->m_pHead;
                this->m_pHead=pAux;
                this->longitud--;
            }
        }

        bool findIterative(T value){

            Node<T>*pAux=this->m_pHead;
            while(pAux){

                if(pAux->getValue()==value) return true;
                pAux=pAux->getM_pSig();

            }
            return false;

        }

        bool findRecursive(T value,Node<T>*pAux){

            if(!pAux) return false;
            if(pAux->getValue()==value) return true;
            else return findRecursive(value,pAux->getM_pSig());

        }
        bool findRecursive(T value){
            return findRecursive(value,this->m_pHead);
        }

        void printReverseRecursive(Node<T>*pAux){
            if(!pAux)return;
            else{
                printReverseRecursive(pAux->getM_pSig());
                cout<<pAux->getValue()<<" -> ";
            }
        }

        void printReverseRecursive(){
            printReverseRecursive(this->m_pHead);
            cout<<endl;
        }

        void reverse(){
            Node<T>*pAux=this->m_pHead;
            Node<T>*pAuxSig;
            //int count=0;
            while(pAux){
                pushFront(pAux->getValue());
                this->longitud--;
                pAuxSig=pAux->getM_pSig();
                delete pAux;
                if(pAux==this->m_pHead->getM_pSig())this->m_pHead->setM_pSig(0);
                pAux=pAuxSig;
            }
        }
        void reverseRecursive(Node<T>*pAux){
            if(!pAux)return;
            else{
                Node<T>*pAuxSig;
                pushFront(pAux->getValue());
                this->longitud--;
                pAuxSig=pAux->getM_pSig();
                delete pAux;
                if(pAux==this->m_pHead->getM_pSig())this->m_pHead->setM_pSig(0);
                reverseRecursive(pAuxSig);
            }
        }
        void reverseRecursive(){
            reverseRecursive(this->m_pHead);
        }
        Node<T>*begin(){
            return this->m_pHead;
        }
        Node<T>*end(){
            Node<T>*pAux=this->m_pHead;
            if(!this->m_pHead)return 0;
            else{
                while (pAux->getM_pSig())
                {
                    pAux=pAux->getM_pSig();
                }
                return pAux;
            }

        }
        bool isEmpty(){
            return(!this->m_pHead);
        }
        void addPos(int pos,T value){
            int count=0;
            Node<T>*pAuxR=this->m_pHead;
            Node<T>*pAuxL;
            if(pos==0 ||!this->m_pHead)pushFront(value);
            else{
                while (count<pos)
                {
                    pAuxL=pAuxR;
                    pAuxR=pAuxR->getM_pSig();
                    count++;
                }
                pAuxL->setM_pSig(new Node<T>(value));
                pAuxL->getM_pSig()->setM_pSig(pAuxR);
                this->longitud++;
            }
        }
        /*
        void united(SimpleLinkedList <T>temp){


        }
        */
        ~SimpleLinkedList(){
            Node<T>*pAuxL;
            Node<T>*pAuxR=this->m_pHead;
            while(pAuxR){
                pAuxL=pAuxR;
                pAuxR=pAuxR->getM_pSig();
                delete pAuxL;
            }
            this->longitud=0;
            this->m_pHead=0;
        }
        /*
        void sort(){
            Node<T>*pAuxl,*pAuxR;
            while(pAuxR){
                while(){

                }
            }
        }*/
};
