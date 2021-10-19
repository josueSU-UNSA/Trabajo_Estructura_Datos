#include <iostream>
using namespace std;
template<typename T>
class NodeBT{
    public:
        T value;
        NodeBT<T>*m_pSon[2];
    public:
        NodeBT(T value){
            this->value=value;
            this->m_pSon[0]=0;
            this->m_pSon[1]=0;
        }
};
