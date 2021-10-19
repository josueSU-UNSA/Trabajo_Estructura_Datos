template<typename T>
class Node{
    private:

        Node<T>*m_pSig;
        T value;

    public:

        Node(T value){
            this->value=value;
            this->m_pSig=0;
        }

        Node<T>* getM_pSig(){
            return this->m_pSig;
        }

        void setM_pSig(Node<T>*m_pSig){
            this->m_pSig=m_pSig;
        }

        T getValue(){
            return this->value;
        }

        void setValue(T value){
            this->value=value;
        }
};
