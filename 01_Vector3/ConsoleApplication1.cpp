// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Vec3.h"

int main()
{
    Vec3<int> a;
    Vec3<int> b (1,0,1);
    Vec3<int> c (b);
    Vec3<int> d = b + c;

    std::cout << "Normalize: " << d.normalize() << std::endl;
    std::cout << "Distance to: " <<  d.distance_to(b) << std::endl;
    std::cout << "Dot Product: " << d.dot_product(b) << std::endl;
    std::cout << "Cross Product: " << d.cross_product(b) << std::endl;
    std::cout << "Angle Between: " << d.angle_between(b) << std::endl;


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln