
#ifndef TemplateKlasser_hpp
#define TemplateKlasser_hpp

#include <stdio.h> 
#include <iostream>
#include <set> 
#include <cstdlib>
#include <string>
using namespace std;

template<typename T>
class SimpleSetTemp{
public:
    SimpleSetTemp();
    ~SimpleSetTemp();
    bool insert(T i);
    bool exists(T i);
    bool remove(T i);
private:
    T *data;
    int currentSize;
    int maxSize;
    int find(T);
    void resize(T n);
};
template<typename T>
SimpleSetTemp<T>::SimpleSetTemp():currentSize(0),maxSize(0),data(nullptr){}

template<typename T>
SimpleSetTemp<T>::~SimpleSetTemp(){
    T data;
    data=nullptr;
}

template<typename T>
bool SimpleSetTemp<T>::exists(T i){
    if (find(i)!=-1) {
        return true;
    }
    return false;
}
template<typename T>
bool SimpleSetTemp<T>::insert(T i){
    if (exists(i)) {
        return false;
    }
    data[currentSize+1]=i;
    currentSize++;
    return true;
}
template<typename T>
bool SimpleSetTemp<T>::remove(T i){
    int index=find(i);
    if (index==-1) {
        return false;
    }
    if (index!=currentSize-1) {
        data[index]=data[currentSize-1];
    }
    currentSize--;
    return false;
}
template<typename T>
int SimpleSetTemp<T>::find(T i){
    for (int j=0; j<currentSize; j++){
        if (data[j]==i) {
            return j;
        }
    }
    return -1;
}
template<typename T>
void SimpleSetTemp<T>::resize(T n){
    T* newData=new T[n];
    for (int j=0; j<currentSize; j++) {
        newData[j]=data[j];
    }
    delete[] data;
    data=newData;
    delete[] newData;
    newData=nullptr;
    maxSize=n;
}

#endif /* TemplateKlasser_hpp */
