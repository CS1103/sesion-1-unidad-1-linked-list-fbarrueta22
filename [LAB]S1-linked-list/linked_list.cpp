//
// Created by fbarrueta on 11/04/20.
//
#include<iostream>
#include "linked_list.h"
using namespace std;

utec::first::linked_list_t::linked_list_t(const utec::linked_list_t &other) {
    for(int i=0; i<size_;++i){
        pop_front();
    }
    for(int i=0;i<other.size_;++i){
        push_back(other.item(i));
    }
    size_=other.size_;
}



utec::linked_list_t &utec::first::linked_list_t::operator=(const utec::linked_list_t &other) {
    if(this==&other){ return *this; }
    for(int i=0;i<size_;++i){
        pop_front();
    }
    for(int i=0;i<other.size_;++i){
        push_back(other.item(i));
    }
    size_=other.size_;
    return *this;
}

utec::first::linked_list_t::linked_list_t(utec::linked_list_t &&other) noexcept {
    for(int i=0; i<size_;++i){
        pop_front();
    }
    head_=other.head_;
    tail_=other.tail_;
    size_=other.size_;
    other.head_=nullptr;
    other.tail_= nullptr;
    other.size_=0;
}

utec::linked_list_t &utec::first::linked_list_t::operator=(utec::linked_list_t &&other) noexcept {
    for(int i=0; i<size_;++i){
        pop_front();
    }
    head_=other.head_;
    tail_=other.tail_;
    size_=other.size_;
    other.head_=nullptr;
    other.tail_= nullptr;
    other.size_=0;
    return *this;
}

utec::first::linked_list_t::~linked_list_t() { //listo //pop a todo para destructor pop front
    for(int i=0;i<size_;++i){
        linked_list_t().pop_back();
    }
    size_=0;
    delete [] head_; delete [] tail_;
}

void utec::first::linked_list_t::push_front(int value) { //listo
    /*auto node= new node_t{value, head_};
    head_= node; */
    head_= new node_t{value, head_};
    //tail apunta al vacio pq es nullptr
    if(tail_== nullptr) tail_=head_;
    size_++;
}

void utec::first::linked_list_t::push_back(int value) { //listo
    auto node= new node_t{value, tail_};
    tail_->next_=node;
    tail_=node;
    //head_ apunta al vacio pq es nullptr
    if(head_== nullptr) head_=tail_;
    size_++;
}

void utec::first::linked_list_t::insert(size_t index, int value) { //listo
    node_t* temp =new node_t();
    node_t* temp1=head_;
    temp->value=value;
    if(index==0){ head_= new node_t{value, head_}; }
    else{
        for (int i = 0; i < index; i++){
            temp1 = temp1->next_;
        }
        temp->next_ = temp1;
        temp1 = head_;
        for (int i = 0; i < index - 1; i++){
            temp1 = temp1->next_;
        }
        temp1->next_ = temp;}
    size_++;
}

void utec::first::linked_list_t::pop_front() { //listo
    if(head_==tail_){
        delete [] head_;
        head_=tail_=nullptr; size_=0 ;}
    else{
        auto next= head_ ->next_;
        delete head_;
        head_=next;
        size_--;
    }
}

void utec::first::linked_list_t::pop_back() { //listo
    if(tail_==head_){
        delete [] tail_;
        tail_=head_=nullptr; size_=0;}
    else{
        auto next = head_;
        while ( next->next_ != tail_){ next = next->next_; }
        delete [] tail_;
        tail_=next;
        tail_->next_= nullptr;
        size_--;
        }
}

void utec::first::linked_list_t::erase(size_t index) { //listo
    node_t* temp=head_;
    node_t* temp1=temp->next_;
    if(index==0){ head_=temp->next_; size_--;}
    else{
        for(int i=1; i<=index;++i){
            if(i==index){
                node_t* aux_node=temp1;
                temp->next_=temp1->next_;
                delete aux_node;
                size_--;
            }
            temp=temp->next_;
            temp1=temp1->next_;
        }
    }
}

int &utec::first::linked_list_t::item(size_t index) { //listo
    auto actual=head_;
    while(index--){
        actual=actual->next_;
    }
    return actual->value;
}

const int &utec::first::linked_list_t::item(size_t index) const { //listo
    auto actual=head_;
    while(index--){
        actual=actual->next_;
    }
    return actual->value;
}

size_t utec::first::linked_list_t::size() const { //listo
    return size_;
}
