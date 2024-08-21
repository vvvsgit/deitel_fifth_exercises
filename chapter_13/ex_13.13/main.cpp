#include <iostream>
#include <vector>
#include <typeinfo>

#include "headers/Shape.hpp"
#include "headers/Shape2D.hpp"
#include "headers/Shape3D.hpp"
#include "headers/Circle.hpp"
#include "headers/Square.hpp"
#include "headers/Triangle.hpp"
#include "headers/Sphere.hpp"
#include "headers/Cube.hpp"
#include "headers/Tetrahedron.hpp"

int
main()
{
    std::cout << std::endl;

    const int size = 6;
    std::vector <Shape *> shapes(size);
    
    Circle shape0(2.0);
    Square shape1(3.0);
    Triangle shape2(4.0, 5.0, 3.0);
    Sphere shape3(5.0);
    Cube shape4(6.0);
    Tetrahedron shape5(3.0, 4.0, 5.0, 5.0, 4.0, 3.0);

    shapes[0] = &shape0;
    shapes[1] = &shape1;
    shapes[2] = &shape2;
    shapes[3] = &shape3;
    shapes[4] = &shape4;
    shapes[5] = &shape5;

    for (int i = 0; i < size; ++i) {
        std::string name = typeid(*shapes[i]).name();
        for (int i = 0; i < name.size(); ++i) {
            if (name[i] >= '0' && name[i] <= '9') {
                continue;
            }
            std::cout << name[i];
        }
        std::cout << std::endl;
        std::cout << "Area is " << shapes[i]->getArea() << std::endl;
        const Shape3D * derivedPtr = dynamic_cast<Shape3D *>(shapes[i]);
        if (derivedPtr != nullptr) {
            std::cout << "Volume is " << derivedPtr->getVolume() << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

