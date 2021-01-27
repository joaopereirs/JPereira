#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

int factorial(int x){
    int fac=1;
    for (int i = x; i>0; i--){
        fac=fac*i;
    }
    return fac;
}

double EEEBugSin(double x, int k){
    double sum=0;
    for (int n = 0; n <= k; n++) {
        sum = sum + ((std::pow(-1,n)/(factorial((2*n)+1)))*(std::pow(x,(2*n)+1)));
    }
    return sum;
}

int main(){
    double y;
    int k;
    std::cout<<"please enter a number for k"<<std::endl;
    std::cin>>k;
    for (int x = -128; x<128; x++){
        y= (127*EEEBugSin((3.1415/128)*x, k)+128);
        std::cout<<"x= "<<x<<std::endl;
        std::cout<<"y= "<<y<<std::endl<<std::endl;
    }
}