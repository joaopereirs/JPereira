#include <iostream>

bool leap_year(int year){
    bool ly;
    if( (year % 4) == 0){
        if( (year % 100) == 0){
            if ((year % 400 == 0)){
                ly=true;
            } else{
                ly=false;
            }
        }
        else{
            ly=true;
        }
    }
    else{
        ly=false;
    }
    return ly;
}
void next_date(int d1, int m1, int y1, int& d2, int& m2, int& y2){
    d2=d1+1;
    m2=m1;
    y2=y1;
    if (m1==2 && d1>=28){
            if ((d1==28 && !leap_year(y1)) || (d1==29 && leap_year(y1))){
                m2=3;
                d2=1;
            }
    } if (d1==30 && (m1==4||m1==6||m1==9||m1==11)){
            m2=m1+1;
            d2=1;
    } if (d1==31) {
        if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10) {
            m2 = m1 + 1;
            d2 = 1;
        }
        if (m1 == 12) {
            d2 = 1;
            m2 = 1;
            y2 = y1 + 1;
        }
    }
}

int main(){
    // TODO: write a main that reads a date from the user,
    int d1, m1, y1, s1, s2, s3;
    std::cout<<"Please type in a date in the format DD MM YYYY"<<std::endl;
    std::cin>>d1>>m1>>y1;
    if (d1<=31 && d1>0 && m1<=12 && m1>0 && !(m1==2 && (d1==30 || d1==31)) && !(!leap_year(y1) && d1>28)){
        next_date(d1,m1,y1,s1,s2,s3);
        std::cout<<"The next day will be: "<<s1<<"."<<s2<<"."<<s3<<std::endl;
    } else {
        std::cout<<"These inputs are incorrect."<<std::endl;
    }
}
