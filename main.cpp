#include <iostream>
#include <vector>
#include <string>

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

void ordered_insertion(std::string e,BNode* B, int n){
    std::string s;
    s.push_back(e[n]);
    if (n==e.size()){
        B->val="1";
    } else if (s=="1"){
        n++;
        ordered_insertion(e,B->right,n);
    } else {
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

BNode* build_bt(const std::vector<std::string>& fvalues) {
    BNode* B;
    int len = fvalues[0].size(); //first we figure out how many bits there are (not including output)
    B = tree_structure(len,0); //then we make an empty tree (structure) that is the size of the number of bits
    for (int i = 0; i < fvalues.size(); ++i) { //(fvalues.size() is the number of different combinations that have an output of 1) once the structure is made, we need to substitute the appropriate leaves with 1s
        ordered_insertion(fvalues[i],B,0);
    }
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
