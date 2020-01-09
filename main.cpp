#include <iostream>
#include <tuple>
#include "vertex.h"
#include "trapez.h"
#include "rectangle.h"
#include "square.h"
#include "templates.h"

template<class T>
void running(std::istream& is, std::ostream& os) {
    if constexpr (is_figurelike_tuple<T>::value) {
        int ang;
        std::cout << "Input number of angles" << std::endl;
        std::cin >> ang;
        if (ang == 4) {
            point<double> A, B, C, D;
            is >> A >> B >> C >> D;
            auto object = std::make_tuple(A, B, C, D);
            print(os, object);
            os <<"area: "<<area(object) << std::endl;
            os << "center: "<<center(object) << std::endl;
        }else if(ang == 3){
            point<double> A, B, C;
            is >> A >> B >> C;
            auto object = std::make_tuple(A, B, C);
            print(os, object);
            os << "area: " <<area(object) << std::endl;
            os << "center: " <<center(object) << std::endl;
        }
    }else {
        T object(is);
        print(os, object);
        os << "area: "<< area(object) << std::endl;
        os << "center: "<<center(object) << std::endl;
    }
}

int main() {
    char obj_type;
    std::cout << "Input figure type: 1 - trapeze, 2 - square, 3 - rectangle, 4 - tuple or 'q' to quit" << std::endl;
    while (std::cin >> obj_type){
        if(obj_type == '4') {
            running<std::tuple<point<double>>> (std::cin, std::cout);
        }else if(obj_type == '1'){
            running<trapeze<double>>(std::cin, std::cout);
        }else if(obj_type == '2'){
            running<square<double>> (std::cin, std::cout);
        }else if(obj_type == '3'){
            running<rectangle<double>>(std::cin, std::cout);
        }else if(obj_type == 'q'){
            return 0;
        }else{
            std::cout << "Wrong. Try 1 - trapeze, 2 - square, 3 - rectangle, 4 - tuple or 'q' to quit" << std::endl;
        }
    }
}