#include <iostream>
#include <thread>  // Para usar std::this_thread::sleep_for
#include <chrono>  // Para usar std::chrono::seconds

int main() {
    // Contar desde 1000 a 0 con un ciclo for
    std::cout << "Contando desde 1000 a 0 :\n";
    for (int i = 1000; i >= 0; --i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Contar hasta 100 lentamente con un ciclo while
    std::cout << "Contando hasta 100 lentamente :\n";
    int j = 0;
    while (j <= 100) {
        std::cout << j << " ";
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Pausa de 100 ms
        ++j;
    }
    std::cout << std::endl;

    // Contar hasta 10x10 con un ciclo do-while
    std::cout << "Contando hasta 10x10 :\n";
    int k = 0;
    do {
        std::cout << k << " ";
        ++k;
    } while (k <= 100);
    std::cout << std::endl;

    return 0;
}
