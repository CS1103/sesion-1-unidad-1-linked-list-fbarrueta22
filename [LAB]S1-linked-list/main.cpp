#include <iostream>
#include<cassert>
#include<string>
#include "linked_list.h"
using namespace std;
int main() {
    //Linked list listas enlazadas que apuntan a cada una (add,remover,traverse)
    //add: push_back(value), push_front(value), insert(index,value)
    //remove pop_back(value), pop_front(value), erase(index)
    //traverse item(index) dar valores,

    utec::linked_list_t ll;

    //probar metodo push_front
    //9 8 7 6 5 4 3 2 1 0
    for(int i=0; i<10;++i){
        ll.push_front(i);
    }
    //verifico el tamaño
    assert(ll.size() == 10);
    string result;
    for(int i=0; i<10;++i){
        result+=to_string(ll.item(i))+ " ";
    }
    assert(result=="9 8 7 6 5 4 3 2 1 0 ");
    cout<<result<<endl;


    //probar push_back
    //9 8 7 6 5 4 3 2 1 0 0 1 2 3 4
    for(int i=0; i<5;++i){
        ll.push_back(i);
    }
    //verifico el tamaño
    assert(ll.size() == 15);
    string result2;
    for(int i=0; i<15;++i){
        result2+=to_string(ll.item(i))+ " ";
    }
    assert(result2=="9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 ");
    cout<<result2<<endl;


    //pop_front
    //probar metodo pop_front;
    //4 3 2 1 0 0 1 2 3 4
    for(int i=0;i<5;++i) {
        ll.pop_front();
    }
    //verifico tamaño
    assert(ll.size()==10);
    string result3;
    for(int i=0; i<10;++i){
        result3+=to_string(ll.item(i))+ " ";
    }
    assert(result3=="4 3 2 1 0 0 1 2 3 4 ");
    cout<<result3<<endl;


    //probar pop_back
    //4 3 2 1 0 0 1
    for(int i=0;i<3;++i){
        ll.pop_back();
    }
    //verifico tamaño
    assert(ll.size()==7);
    string result4;
    for(int i=0; i<7;++i){
        result4+=to_string(ll.item(i))+ " ";
    }
    assert(result4=="4 3 2 1 0 0 1 ");
    cout<<result4<<endl;


    //probar erase
    //4 3 1 0 0 1
    ll.erase(2);
    //verifico tamaño
    assert(ll.size()==6);
    string result5;
    for(int i=0; i<6;++i){
        result5+=to_string(ll.item(i))+ " ";
    }
    assert(result5=="4 3 1 0 0 1 ");
    cout<<result5<<endl;


    //probat insert
    //4 3 11 1 0 0 1
    ll.insert(2,11);
    //verifico tamaño
    assert(ll.size()==7);
    string result6;
    for(int i=0; i<7;++i){
        result6+=to_string(ll.item(i))+ " ";
    }
    assert(result6=="4 3 11 1 0 0 1 ");
    cout<<result6<<endl;

    cout<<"Hello";
    return 0;
}
