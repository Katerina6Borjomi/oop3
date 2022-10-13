#include <iostream>
#include "functions.h"

namespace oop3{

    double get_d(string string1) {
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


}