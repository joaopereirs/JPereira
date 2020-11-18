#include <iostream>
#include <string>
 
int main(){
    std::string
    
    int n1, n2;
 
    std::cout << "please enter two values" << std::endl;
    std::cin >> n1 >> n2;
 
    std::cout << "you entered:" << std::endl;
    std::cout << "n1: " << n1 << std::endl;
    std::cout << "n2: " << n2 << std::endl;
 
    // we swap the values
    // in order to do so we need to use
    // a third temporary variable
 
    int tmp;
 
    tmp = n1;
    n1 = n2;
    n2 = tmp;
 
    std::cout << "after swapping the values:" << std::endl;
    std::cout << "n1: " << n1 << std::endl;
    std::cout << "n2: " << n2 << std::endl;
 
}