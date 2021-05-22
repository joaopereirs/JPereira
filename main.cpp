#include <iostream>
#include <vector>
#include <string>
#include <bitset> //allows us to convert from integers to bit arrays

// you can include other headers
// you need for your code a
// you can use any headers from the C++ standard library

// do not alter this structured data type definition


struct BNode{
    std::string val;
    // this will contain
    // "x1", "x2"... "xn" in non-leaf nodes
    // "0" or "1" in leaf nodes

    BNode* left; // this will conventionally represent the 0 branch
    BNode* right; // this will conventionally represent the 1 branch

    // (as usual leaf nodes will have both left and right pointing to NULL)
};

BNode* tree_node(std::string e, BNode* l, BNode* r){
    BNode* tmp;
    tmp = new BNode;
    tmp->val = e;
    tmp->left = l;
    tmp->right = r;
    return tmp;
}


BNode* tree_structure(int n, int i){ //sets up the tree with all leaves as zero
    std::string s;
    if (i==n){ //n is the number of bits (not including the output --> thus 11 => n=2). When i==n it means we are at the leaf (output)
        s="0"; //s is zero because we want to fill the skeleton leaves just with zeros
        return tree_node(s, NULL, NULL); //since it is the leaf we just fill it with zeros for now
    } else {
        s = "x"; //when it is not a leaf (AKA i!=n) we want to name the nodes x1 x2 etc
        i++;
        s = s + std::to_string(i); //creating the x1 x2 x3 depending on the bit
        return tree_node(s, tree_structure(n,i),tree_structure(n, i)); //almost recursive to do the same thing over and over until we reach the leaf (n==i)
    }
}




void ordered_insertion(std::string e,BNode* B, int n){ //fills skeleton with functions that have output of 1. "e" is the function (no output)
    std::string s;
    s.push_back(e[n]);
    if (n==e.size()){ //when you are at the leaf
        B->val="1";
    } else if (s=="1"){ //if the bit is 1 you move right
        n++;
        ordered_insertion(e,B->right,n); //by starting with n=0 and here moving up n++ we allow a sort of consistent counter to occur
    } else { //if bit is 0 you move left
        n++;
        ordered_insertion(e, B->left, n);
    }
}

void deallocate_tree(BNode* t){
    if (t != NULL){
        deallocate_tree(t->left);
        deallocate_tree(t->right);
        delete t;
    }
}

class Counter{

public:

    Counter(){
        c = 4;
    }

    void inc(){
        c++;
    }

    int get_count() const {
        return c;
    }

private:

    int c;

};

int compare_vector(std::vector<std::string> v, std::string s){
    std::string s_nolsb = s;
    s_nolsb.erase(s.size()-1); //so that we discard LSB, while maintaining s as original
    for (int i = 0; i < v.size(); ++i) {
        std::string tmp = v[i];
        tmp.erase(v[i].size()-1); //doing the same for each value in vector
        if (s_nolsb == tmp){ //if all bits but LSB are the same (remembering the original value is also in there
            if (s[s.size()-1] != v[i][v[i].size()-1]){ //making sure LSBs arent equal (if not it is the original)
                return i;
            }
        }
    }
    return -1;
}

void remove_node(BNode* bt, std::string s){

}


void reduce_bt(BNode* bt, std::vector<std::string>& fvalues_one, const int len){ //len is the number of bits without output
    //1. set up vector of functions that output 0 (because we should in theory have a vector of functions that output 1 -- fvalues1) -- non optimized
    std::vector<std::string> fvalues_zero;
    if (len == 2){
        for (int i = 0; i < pow(2,len); ++i) {
            int tmp=0; //means that bit array does not exist in the vector of output-1 functions
            for (int j = 0; j < fvalues_one.size(); ++j) {
                if (std::bitset<2>(i).to_string() == fvalues_one[j]){
                    tmp=1; //means that array exists as an output-1 function
                }
            }
            if (tmp == 0){
                fvalues_one.push_back(std::bitset<2>(i).to_string());
            }
        }
    } else if (len == 3){ //when you have 3 bit
        for (int i = 0; i < pow(2,len); ++i) {
            int tmp=0; //means that bit array does not exist in the vector of output-1 functions
            for (int j = 0; j < fvalues_one.size(); ++j) {
                if (std::bitset<3>(i).to_string() == fvalues_one[j]){
                    tmp=1; //means that array exists as an output-1 function
                }
            }
            if (tmp == 0){
                fvalues_one.push_back(std::bitset<3>(i).to_string());
            }
        }
    } else if (len == 4){ //when you have 4 bit
        for (int i = 0; i < pow(2,len); ++i) {
            int tmp=0; //means that bit array does not exist in the vector of output-1 functions
            for (int j = 0; j < fvalues_one.size(); ++j) {
                if (std::bitset<4>(i).to_string() == fvalues_one[j]){
                    tmp=1; //means that array exists as an output-1 function
                }
            }
            if (tmp == 0){
                fvalues_one.push_back(std::bitset<4>(i).to_string());
            }
        }
    } else if (len == 5){ //when you have 5 bit
        for (int i = 0; i < pow(2,len); ++i) {
            int tmp=0; //means that bit array does not exist in the vector of output-1 functions
            for (int j = 0; j < fvalues_one.size(); ++j) {
                if (std::bitset<5>(i).to_string() == fvalues_one[j]){
                    tmp=1; //means that array exists as an output-1 function
                }
            }
            if (tmp == 0){
                fvalues_one.push_back(std::bitset<5>(i).to_string());
            }
        }
    } else if (len == 6){ //when you have 6 bit
        for (int i = 0; i < pow(2,len); ++i) {
            int tmp=0; //means that bit array does not exist in the vector of output-1 functions
            for (int j = 0; j < fvalues_one.size(); ++j) {
                if (std::bitset<6>(i).to_string() == fvalues_one[j]){
                    tmp=1; //means that array exists as an output-1 function
                }
            }
            if (tmp == 0){
                fvalues_one.push_back(std::bitset<6>(i).to_string());
            }
        }
    }
    //now we have a vector of all the inputs giving 1 and giving 0
    for (int i = 0; i < fvalues_one.size(); ++i) { //doing it first for the vector of 1
        if (compare_vector(fvalues_one,fvalues_one[i]) != -1){ //will yield the index if exists, else -1
            remove_node(bt, fvalues_one[i]);
        }
    }





//    if (bt->left != NULL && bt->right != NULL) {
//        if (bt->left == bt->right) { //i think the nodes (non-leaves will also have the same name
//            std::cout<<"value going left: "<<bt->left<<std::endl;
//            std::cout<<"value going right: "<<bt->right<<std::endl;
//            bt->val = (bt->right)->val; //which is the same as bt->left->val
//            bt->right = bt->left = NULL;
//            std::cout<<"we've reduced a node"<<std::endl;
//        } else {
//            reduce_bt(bt->left);
//            reduce_bt(bt->right);
//            std::cout << "gay" << std::endl;
//        }
//    } else {
//        std::cout<<"YAY"<<std::endl;
//    }
//    std::cout<<"this shouldnt appear"<<std::endl;
}

BNode* build_bt(const std::vector<std::string>& fvalues) {
    BNode* B;
    int len = fvalues[0].size(); //first we figure out how many bits there are (not including output)
    B = tree_structure(len,0); //then we make an empty tree (structure) that is the size of the number of bits
    for (int i = 0; i < fvalues.size(); ++i) { //(fvalues.size() is the number of different combinations that have an output of 1) once the structure is made, we need to substitute the appropriate leaves with 1s
        ordered_insertion(fvalues[i],B,0);
    }
//    reduce_bt(B);
    return B;
}


// do not alter the following line that begins the function eval_bt
std::string eval_bt(BNode* bt, const std::string& input) {
    std::string tmp;
    for (int i = 1; i < input.size(); ++i) { //so that we discard the previous MSB
        tmp.push_back(input[i]);
    }
    if (input[0] == '0') {
        return eval_bt(bt->left, tmp);
    } else if (input[0] == '1') {
        return eval_bt(bt->right, tmp);
    } else {
        if(bt->val=="1"){
            return "1";
        } else if(bt->val=="0"){
            return "0";
        } else {
            return "error";
        }
    }
}

int main (){
    std::vector<std::string> fvalues;
    std::string row;

    row = "000010";
    fvalues.push_back(row);
    row = "010010";
    fvalues.push_back(row);
    row = "110011";
    fvalues.push_back(row);

    BNode* bt = build_bt(fvalues);

    std::cout << eval_bt(bt, "000100") << std::endl;
    // should print "1"

    std::cout << eval_bt(bt, "110011") << std::endl;
    // should print "0"
}