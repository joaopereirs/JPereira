#include <iostream>
#include <vector>

int search_vector(int n, const std::vector<int>& vin){
    int s=0;
    for(int i=0;i<vin.size();i++) {
        if (vin[i] == n) {
            s=s+1;
        }
    }
    return s;
}
void intersection_vector(const std::vector<int>& vin1, const std::vector<int>& vin2, std::vector<int>& vout){
    std::vector<int>vtmp;
    for (int i=0;i<vin1.size();i++){
        if (search_vector(vin1[i], vin1)==1){
            if(search_vector(vin1[i], vin2)>=1){
                vout.push_back(vin1[i]);
            }
        } else if (search_vector(vin1[i], vin1)>=2) {
            vtmp.push_back(vin1[i]);
            if (search_vector(vin1[i], vtmp) == 1 && search_vector(vin1[i], vin2) >= 1) {
                    vout.push_back(vin1[i]);
            }
        }
    }
}
int main(){
    int n, tmp;
    std::vector<int>v1;
    std::vector<int>v2;
    std::vector<int>out;
    std::cout<<"how many values will be in the FIRST sequence?"<<std::endl;
    std::cin>>n;
    std::cout << "please enter a sequence of "<<n<<" numbers" << std::endl;
    for (int i=0; i<n; i++){
        std::cin>>tmp;
        v1.push_back(tmp);
    }
    std::cout<<"how many values will be in the SECOND sequence?"<<std::endl;
    std::cin>>n;
    std::cout << "please enter a sequence of "<<n<<" numbers" << std::endl;
    for (int i=0; i<n; i++){
        std::cin>>tmp;
        v2.push_back(tmp);
    }
    intersection_vector(v1, v2, out);
    std::cout << "printing vector:" << std::endl;
    for(int i = 0; i < out.size(); i++){
        std::cout << out[i] << std::endl;
    }
}