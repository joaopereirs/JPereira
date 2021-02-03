#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

typedef int list_t;

struct ListNode{
    list_t val;
    ListNode* next;
};

ListNode* cons_list(list_t e, ListNode* l){
    ListNode* tmp;
    tmp = new ListNode;
    tmp->val = e;
    tmp->next = l;
    return tmp;
}

void deallocate_list(ListNode* l){
    ListNode* tmp;
    while(l != NULL){
        tmp = l->next;
        delete l;
        l = tmp;
    }
}

bool search_list(list_t e, ListNode* l){
    while(l != NULL){
        if (l->val==e){
            return true;
        } else {
            l = l->next;
        }
    }
    return false;
}

bool replace_list(list_t e, list_t n, ListNode* l, bool all){
    while(l != NULL){
        if (l->val==e){
            if (!all){
                l->val = n; //replaces (only) the first instance
                return true;
            } else {
                // replaces all the instances

            }
            return true;
        } else {
            l = l->next;
        }
    }
    return false;
}

void replace_all_instances(list_t e, list_t n, ListNode* l){
    while (l != NULL){
        if (l->val == e){
            l->val = n;
            l = l->next;
        }
        else {
            l = l->next;
        }
    }
}

void print_list(ListNode* l){
    while(l != NULL){
        std::cout << l->val << std::endl;
        l = l->next;
    }
}

int main(){
    std::ifstream infile;
    infile.open("input.txt");

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    list_t tmp, e;
    ListNode* l = NULL;
    while(infile >> tmp){
        l = cons_list(tmp, l);
    }

    infile.close();

    std::cout<<"original list: "<<std::endl;
    //to do: print original list, then print final list to see the difference and make sure correct


    std::cout<<"what value would you like to replace in the list?"<<std::endl;
    std::cin>>e;

    //for which value?

    if (search_ordered_list(e,l)){
        std::cout<<"value is in the list!"<<std::endl;
    } else {
        std::cout<<"the value was NOT found in the list..."<<std::endl;
    }

    deallocate_list(l);
}