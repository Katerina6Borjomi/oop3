#ifndef OOP3_FUNCTIONS_H
#define OOP3_FUNCTIONS_H
using namespace std;

#include <cstring>
#include <cmath>


namespace oop3{

    class Vector_3{
        private:
            //int size = 1000;
            int fact;
            char vector [1000];
        public:
            Vector_3(int fact1 = 0, char* mass = nullptr): fact(fact1){
                if(fact1 == 0){
                    for(int i = 1; i < 1000; i++){
                        vector[i] = 0;
                    }
                }else if(mass == nullptr){
                    for(int i = 0; i < fact1; i++){
                        vector[i] = 'X';
                    }
                    for(int j = fact1; j < 1000; j++){
                        vector[j] = 0;
                    }
                }else{
                    for(int i = 0; i < strlen(mass); i++){
                        vector[i] = mass[i];
                    }
                }
            };

            int get_fact();
            void set_fact(int fact1);
            Vector_3 and_vectors(Vector_3* b);
            Vector_3 or_vectors(Vector_3* b);
            void print_vector();
            Vector_3 cmp_vectors_equel(Vector_3* b);
            Vector_3 cmp_vectors_bigger(Vector_3* b);
            Vector_3 cmp_vectors_smaller(Vector_3* b);
            Vector_3 cmp_vectors_sm_eq(Vector_3* b);
            Vector_3 cmp_vectors_bg_eq(Vector_3* b);
            Vector_3 invert_vector();
            int positiveness();
    };

}

#endif //OOP3_FUNCTIONS_H
