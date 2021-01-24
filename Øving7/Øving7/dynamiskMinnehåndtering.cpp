
#include "dynamiskMinnehåndtering.hpp"

void fillInFibonacciNumbers(int result[], int length){
    
    if (length>1){
        result[0]=0;
        result[1]=1;
    }
    else if (length>0){
        result[0]=0;
    }
    for (int i=2; i<length; i++) {
        
        result[i]= result[i-2]+result[i-1];
    }
}
void printArray(int arr[], int length){
    for (int i=0; i<length; i++) {
        cout << arr[i] << endl;
    }
}
void createFibonacci(){
    cout << "Hvor mange tall skal genereres? " << endl;
    int n=0;
    cin >> n;
    int *fibonacci=new int[n]{};
    fillInFibonacciNumbers(fibonacci, n);
    printArray(fibonacci, n);
    delete []fibonacci;
    fibonacci=nullptr;
    
}

