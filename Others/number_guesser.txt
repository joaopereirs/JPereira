#include <iostream>
#include <string>
 
int main(){
  int n,curmin,curmax;
  std::string yn;
  std::string hl;
  n=5;
  curmax=11;
  curmin=0;
  std::cout<<"Think of a number between 1 and 10 "<<std::endl;
  std::cout<<"is "<<n<<" your number?"<<std::endl;
  std::cin>>yn;
  for(;yn=="no";){
    std::cout<<"is the number higher or lower than "<<n<<" [h = higher, l=Lower]"<<std::endl;
    std::cin>>hl;
    if(hl=="h"){
      curmin=n;
      n=curmin+((curmax-curmin)/2);
      std::cout<<"is "<<n<<" your number?"<<std::endl;
    } if(hl=="l"){
      curmax=n;
      n=curmax-((curmax-curmin)/2);
      std::cout<<"is "<<n<<" your number?"<<std::endl;
    }
    std::cin>>yn;
  }
std::cout<<"Great!"<<std::endl;
}