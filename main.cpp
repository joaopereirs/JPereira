#include <iostream>
#include <vector>

void append_vectors(const std::vector<int>& vin1, const std::vector<int>& vin2, std::vector<int>& vout){
    for(int i=0; i<vin1.size(); i++){
        vout.push_back(vin1[i]);
    }
    for(int i=0; i<vin2.size(); i++){
        vout.push_back(vin2[i]);
    }
}
int main(){
    int n, tmp;
    std::vector<int>v1;
    std::vector<int>v2;
    std::vector<int>out;
    std::cout<<"how many values will be in the FIRST list?"<<std::endl;
    std::cin>>n;
    std::cout << "please enter a sequence of "<<n<<" numbers" << std::endl;
    for (int i=0; i<n; i++){
        std::cin>>tmp;
        v1.push_back(tmp);
    }
    std::cout<<"how many values will be in the SECOND list?"<<std::endl;
    std::cin>>n;
    std::cout << "please enter a sequence of "<<n<<" numbers" << std::endl;
    for (int i=0; i<n; i++){
        std::cin>>tmp;
        v2.push_back(tmp);
    }
    append_vectors(v1, v2, out);
    std::cout << "printing vector:" << std::endl;
    for(int i = 0; i < out.size(); i++){
        std::cout << out[i] << std::endl;
    }
}