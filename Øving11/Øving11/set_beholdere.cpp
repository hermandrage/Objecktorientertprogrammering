
#include "set_beholdere.hpp"
#include <iostream> 
#include <set> 
using namespace std;

SimpleSet::SimpleSet():currentSize(0),maxSize(0),data(nullptr){}
SimpleSet::~SimpleSet(){
    delete[] data;
    data=nullptr;
}

bool SimpleSet::exists(int i){
    if (find(i)!=-1) {
        return true;
    }
    return false;
}

bool SimpleSet::insert(int i){
    if (exists(i)) {
        return false;
    }
    data[currentSize+1]=i;
    currentSize++;
    return true;
}

bool SimpleSet::remove(int i){
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
int SimpleSet::find(int i){
    for (int j=0; j<currentSize; j++){
        if (data[j]==i) {
            return j;
        }
    }
    return -1;
}
void SimpleSet::resize(int n){
    int* newData=new int[n];
    for (int j=0; j<currentSize; j++) {
        newData[j]=data[j];
    }
    delete[] data;
    data=newData;
    delete[] newData;
    newData=nullptr;
    maxSize=n;
}
