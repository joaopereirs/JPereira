#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

struct IntListNode{
    int val;
    IntListNode* next;
};

bool search_value(const std::vector<int>& values, int s){
    for (int i = 0; i < values.size(); i++){
        if (values[i]==s){
            return true;
        }
    }
    return false;
}

int main(){
    IntListNode* l;
    l = NULL;
    IntListNode* tmp;
    int n;
    std::cout<<"Please enter a number:"<<std::endl;
    std::cin>>n;
    std::cout<<"Please enter "<<n<<" numbers:"<<std::endl;

    for (int i=0;i<n;i++){ //reads values
        int a;
        std::cin>>a;
        tmp = new IntListNode;
        tmp->val=a;
        tmp->next=l;
        l=tmp;
    }

    IntListNode* lit;
    lit = l;
    std::vector<int> values;
    std::cout<<"the list you entered was: "<<std::endl;
    while(lit != NULL){ //print all the values in the list (in reverse order)
        std::cout<<lit->val<<std::endl;
        values.push_back(lit->val);
        lit = lit->next;
    }

    std::cout<<"What number would you like to search for in the list?"<<std::endl;
    int s;
    std::cin>>s;
    if (search_value(values,s)){
        std::cout<<"the value is in the list!"<<std::endl;
    } else {
        std::cout<<"the value is NOT in the list..."<<std::endl;
    }

    lit = l;

    while(lit != NULL){ //deallocate the list
        tmp = (*lit).next;
        delete lit;
        lit = tmp;
    }

}