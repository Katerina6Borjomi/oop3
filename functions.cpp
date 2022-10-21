#include <iostream>
#include "functions.h"

namespace oop3{

    double get_d(string string1){
        getline(cin, string1);
        double d = 0;
        try {
            d = stod(string1);
        }
        catch (invalid_argument &e) {
            return -1;
        }
        return d;
    }

    int input_int(){
        int a = 0;
        while(!(cin >> a).good()){
            cout << "Неправильно введено число. Попробуйте ещё раз.\n";
            //std::cin.clear();
            //std::cin.ignore(1000, '\n');
        }
        cin.clear();
        cin.ignore(1000, '\n');
        return a;
    }

    int Vector_3::get_fact(){
        return this->fact;
    }

    void Vector_3::set_fact(int fact1){
        this->fact = fact1;
    }

    void Vector_3::print_vector(){
        for(int i = 0; i < this->fact; i++){
            cout<< this->vector[i];
        }
        cout<<endl;
    }

    int Vector_3::positiveness(){
        int f = 0;
        for(int i = 0; i < this->fact; i++){
            if(vector[i] == 'X'){
                f = 1;
            }
        }
        return f;//1 - X; 0 - нет
    }

    void printf_flag(int f){
        if(f == 1){
            cout<<"В векторе присутствуют неопределённые элементы"<<endl;
        }else{
            cout << "В векторе отсутствуют неопределённые элементы"<<endl;
        }
    }

    Vector_3 Vector_3::and_vectors(oop3::Vector_3* b){
        Vector_3 res_vec;
        int n1, n2, n;
        n1 = this->fact;
        n2 = b->fact;
        if(n1 > n2){
            n = n1;
        }else{
            n = n2;
        }
        char a;
        char c;
        res_vec.set_fact(n);
        for(int i = 0; i < n; i++){
            if((n2 > n1) && (i > n1)){
                a = 'X';
                c = b->vector[i];
            }else if((n1 > n2) && (i > n2)){
                c = 'X';
                a = this->vector[i];
            }else{
                a = this->vector[i];
                c = b->vector[i];
            }
            if(a == '1'){
                res_vec.vector[i] = c;
            }else if(a == '0'){
                res_vec.vector[i] = '0';
            }else{
                if(c == '1'){
                    res_vec.vector[i] = 'X';
                }else if(c == '0'){
                    res_vec.vector[i] = '0';
                }else{
                    res_vec.vector[i] = 'X';
                }
            }
        }
        return res_vec;
    }

    Vector_3 Vector_3::or_vectors(oop3::Vector_3* b){
        Vector_3 res_vec;
        int n1, n2, n;
        n1 = this->fact;
        n2 = b->fact;
        if(n1 > n2){
            n = n1;
        }else{
            n = n2;
        }
        char a;
        char c;
        res_vec.set_fact(n);
        for(int i = 0; i < n; i++){
            if((n2 > n1) && (i > n1)){
                a = 'X';
                c = b->vector[i];
            }else if((n1 > n2) && (i > n2)){
                c = 'X';
                a = this->vector[i];
            }else{
                a = this->vector[i];
                c = b->vector[i];
            }
            if(a == '0'){
                res_vec.vector[i] = c;
            }else if(a == '1'){
                res_vec.vector[i] = '1';
            }else{
                if(c == '1'){
                    res_vec.vector[i] = '1';
                }else{
                    res_vec.vector[i] = 'X';
                }
            }
        }
        return res_vec;
    }

    Vector_3 Vector_3::invert_vector(){
        Vector_3 res_vec;
        res_vec.set_fact(this->fact);
        for(int i = 0; i < this->fact; i++){
            if(this->vector[i] == '1'){
                res_vec.vector[i] = '0';
            }else if(this->vector[i] == '0'){
                res_vec.vector[i] = '1';
            }else{
                res_vec.vector[i] = 'X';
            }
        }
        return res_vec;
    }

    Vector_3 Vector_3::cmp_vectors_equel(oop3::Vector_3 *b){
        Vector_3 res_vec;
        int n, n1, n2;
        n1 = this->fact;
        n2 = b->fact;
        if(this->fact > b->fact){
            n = this->fact;
        }else{
            n = b->fact;
        }
        res_vec.set_fact(n);
        char a;
        char c;
        for(int i = 0; i < n; i++){
            if((n2 > n1) && (i > n1)){
                a = '1';
                c = '0';
            }else if((n1 > n2) && (i > n2)){
                c = '1';
                a = '0';
            }else{
                a = this->vector[i];
                c = b->vector[i];
            }
            if(a == c){
                res_vec.vector[i] = '1';
            }else{
                res_vec.vector[i] = '0';
            }
        }
        return res_vec;
    }

    Vector_3 Vector_3::cmp_vectors_bigger(oop3::Vector_3 *b){
        Vector_3 res_vec;
        int n, n1, n2;
        n1 = this->fact;
        n2 = b->fact;
        if(this->fact > b->fact){
            n = this->fact;
        }else{
            n = b->fact;
        }
        res_vec.set_fact(n);
        char a;
        char c;
        for(int i = 0; i < n; i++){
            if((n2 > n1) && (i > n1)){
                a = '0';
                c = '0';
            }else if((n1 > n2) && (i > n2)){
                c = '0';
                a = '0';
            }else{
                a = this->vector[i];
                c = b->vector[i];
            }
            if((a == '1') && (c == '0')){
                res_vec.vector[i] = '1';
            }else if(((a == '1') && (c == 'X')) ||((a == 'X') && (c == '0')) || ((a == 'X') && (c == 'X'))){
                res_vec.vector[i] = 'X';
            }else{
                res_vec.vector[i] = '0';
            }
        }
        return res_vec;
    }

    Vector_3 Vector_3::cmp_vectors_smaller(oop3::Vector_3 *b){
        Vector_3 res_vec;
        int n, n1, n2;
        n1 = this->fact;
        n2 = b->fact;
        if(this->fact > b->fact){
            n = this->fact;
        }else{
            n = b->fact;
        }
        res_vec.set_fact(n);
        char a;
        char c;
        for(int i = 0; i < n; i++){
            if((n2 > n1) && (i > n1)){
                a = '0';
                c = '0';
            }else if((n1 > n2) && (i > n2)){
                c = '0';
                a = '0';
            }else{
                a = this->vector[i];
                c = b->vector[i];
            }
            if((a == '0') && (c == '1')){
                res_vec.vector[i] = '1';
            }else if(((a == '0') && (c == 'X')) || ((a == 'X') && (c == '1')) || ((a == 'X') && (c == 'X'))){
                res_vec.vector[i] = 'X';
            }else{
                res_vec.vector[i] = '0';
            }
        }
        return res_vec;
    }

    Vector_3 Vector_3::cmp_vectors_bg_eq(oop3::Vector_3 *b){
        Vector_3 res_vec;
        int n, n1, n2;
        n1 = this->fact;
        n2 = b->fact;
        if(this->fact > b->fact){
            n = this->fact;
        }else{
            n = b->fact;
        }
        res_vec.set_fact(n);
        char a;
        char c;
        for(int i = 0; i < n; i++){
            if((n2 > n1) && (i > n1)){
                a = '0';
                c = '1';
            }else if((n1 > n2) && (i > n2)){
                c = '1';
                a = '0';
            }else{
                a = this->vector[i];
                c = b->vector[i];
            }
            if(((a == '1') && (c == '0')) || (a == c)){
                res_vec.vector[i] = '1';
            }else if((a == 'X') || (c == 'X')){
                res_vec.vector[i] = 'X';
            }else{
                res_vec.vector[i] = '0';
            }
        }
        return res_vec;
    }

    Vector_3 Vector_3::cmp_vectors_sm_eq(oop3::Vector_3 *b){
        Vector_3 res_vec;
        int n, n1, n2;
        n1 = this->fact;
        n2 = b->fact;
        if(this->fact > b->fact){
            n = this->fact;
        }else{
            n = b->fact;
        }
        res_vec.set_fact(n);
        char a;
        char c;
        for(int i = 0; i < n; i++){
            if((n2 > n1) && (i > n1)){
                a = '1';
                c = '0';
            }else if((n1 > n2) && (i > n2)){
                c = '0';
                a = '1';
            }else{
                a = this->vector[i];
                c = b->vector[i];
            }
            if(((a == '0') && (c == '1')) || (a == c)){
                res_vec.vector[i] = '1';
            }else if((a == 'X') || (c == 'X')){
                res_vec.vector[i] = 'X';
            }else{
                res_vec.vector[i] = '0';
            }
        }
        return res_vec;
    }

}