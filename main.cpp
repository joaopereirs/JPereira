#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

struct Contact{
    std::string fname;
    std::string sname;
    std::string email;
    std::string pn;
};

std::string contact_to_s(Contact c){
    return "First Name: " + c.fname + ", Surname: " + c.sname + ", Email: "+ c.email + ", Phone number: "+ c.pn;
}
int main(){
    std::ifstream infile;
    infile.open("input.txt");

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<Contact> points;
    Contact tmp;

    while(infile >> tmp.fname >> tmp.sname >> tmp.email >> tmp.pn){
        points.push_back(tmp);
    }

    infile.close();

    std::cout<<"The contacts that you have entered are: "<<std::endl<<std::endl;
    for(int i=0; i<points.size(); i++) {
        std::cout << "Contact " << i << std::endl;
        std::cout<<contact_to_s(points[i])<<std::endl<<std::endl;
    }
}