#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream> //to read/write txt files
#include <cstdlib>
// we add headers vector, fstream, cstdlib


struct Point{
    double x;
    double y;
};

double distance_points(Point p1, Point p2){
    return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
}

std::string point_to_s(Point p){
    return "(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")";
}

int main(){
    std::ifstream infile;
    infile.open("points.txt");

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<Point> points;
    Point tmp;

    while(infile >> tmp.x >> tmp.y){
        points.push_back(tmp);
    }

    infile.close();

    for(int i=0; i<points.size(); i++){
        std::cout<<"("+std::to_string(points[i].x)+","+std::to_string(points[i].x)+")"<<std::endl; //vector is in point format, so it hs x and y component
        // we use std::to_string to convert from double to std::string
        // the + operator on std::string chains the text together
    }
}
