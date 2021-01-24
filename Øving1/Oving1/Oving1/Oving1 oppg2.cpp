
#include <iostream>

int max(int a, int b){
    if (a>b){
        std::cout << "A is greater than B" << std::endl;
        return a;
    }
    else{
        std::cout << "B is greater than or equal til A" << std::endl;
        return b;
    }
}

int fibonacci(int n){
    int a = 0;
    int b = 1;
    std::cout << "Fibonacci numbers" << std::endl;
    for(int i=0; i<n; i++){
        std::cout << i << b << std::endl;
        int temp = b;
        b+=a;
        a=temp;
    }
    std::cout << "-----" << std::endl;
    return b;
}

int squareNumberSum(int n){
    int totalsum = 0;
    for(int i=0; i<n; i++){
        totalsum+=i*i;
        std::cout << i*i << std::endl;
    }
    std::cout << totalsum << std::endl;
    return totalsum;
}

void triangleNumbersBelow(int n){
    int acc =1;
    int num =2;
    std::cout << "Triangle numbers below " << n << ":" << " " << std::endl;
    while (acc < n){
        std::cout << acc << std::endl;
        acc += num;
        num +=1;
    }
    std::cout << std::endl;
}

bool isTriangleNumber(int number){
    int acc = 1;
    while (number > 0){
        number -= acc;
        acc += 1;
    }
    return number == 0;
}

bool isPrime(int n){
    bool primeness = true;
    for(int j=2; j<n; j++){
        if (n%j == 0){
            primeness = false;
            break;
        }
    }
    return primeness;
}

void naivePrimeNumberSearch(int n){
    for(int number = 2; number<n; number++){
        if (isPrime(number)){
            std::cout << number << "is a prime" << std::endl;
        }
    }
}

int findGreatestDivisor(int n){
    for (int divisor = n-1; divisor>0; divisor -=1){
        if (n%divisor == 0){
            return divisor;
        }
    }
    return 0;
}


int main(){
    std::cout << " Oppg a)" << std::endl;
    std::cout << max(5,6) << std::endl;
    std::cout << "fibonacci number:" << std::endl;
    std::cout << fibonacci(5) << std::endl;
    std::cout << squareNumberSum(5) << std::endl;
    std::cout << isTriangleNumber(5) << std::endl;
    std::cout << isPrime(5) << std::endl;
    naivePrimeNumberSearch(5);
    
}



