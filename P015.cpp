#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
#include <vector>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

struct Pokemon {
    std::string nombre;
    int vida;
    std::string ataque1Nombre;
    int ataque1Danio;
    std::string ataque2Nombre;
    int ataque2Danio;
};

void mostrarVida(const Pokemon &p) {
    std::cout << p.nombre << " - Vida restante: " << p.vida << std::endl;
}

void atacar(Pokemon &atacante, Pokemon &defensor, const std::string &nombreAtaque, int danio) {
    defensor.vida -= danio;
    std::cout << atacante.nombre << " usa " << nombreAtaque << " contra " << defensor.nombre 
              << " y causa " << danio << " puntos de daño." << std::endl;
}

void usarItem(Pokemon &p) {
    int curacion = 20;
    p.vida += curacion;
    std::cout << p.nombre << " usa un ítem de curación y recupera " << curacion << " puntos de vida." << std::endl;
}

int elegirAccionEnemiga() {
    return std::rand() % 3;  // 0 para ataque1, 1 para ataque2, 2 para curación
}

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    // Definir los Pokémon
    Pokemon pikachu = {"Pikachu", 100, "Impactrueno", 15, "Rayo", 20};
    Pokemon charmander = {"Charmander", 100, "Ascuas", 12, "Lanzallamas", 25};
    Pokemon squirtle = {"Squirtle", 100, "Pistola Agua", 10, "Hidrobomba", 22};
    
    Pokemon enemigo = {"Bulbasaur", 100, "Latigazo", 15, "Hoja Afilada", 20};

    // Selección del Pokémon
    Pokemon jugador;
    int opcion;
    do {
        std::cout << "Elige tu Pokémon:\n1. Pikachu\n2. Charmander\n3. Squirtle\n";
        std::cin >> opcion;

        switch(opcion) {
            case 1: jugador = pikachu; break;
            case 2: jugador = charmander; break;
            case 3: jugador = squirtle; break;
            default: 
                std::cout << "Opción inválida. Por favor, elige una opción válida.\n";
                opcion = 0;  // Para seguir en el bucle
        }
    } while(opcion < 1 || opcion > 3);

    std::cout << "¡Comienza la batalla entre " << jugador.nombre << " y " << enemigo.nombre << "!\n";

    // Bucle de batalla
    while (jugador.vida > 0 && enemigo.vida > 0) {
        int accion;
        do {
            std::cout << "\nTurno de " << jugador.nombre << ". ¿Qué deseas hacer?\n";
            std::cout << "1. " << jugador.ataque1Nombre << " (Daño: " << jugador.ataque1Danio << ")\n";
            std::cout << "2. " << jugador.ataque2Nombre << " (Daño: " << jugador.ataque2Danio << ")\n";
            std::cout << "3. Usar ítem de curación\n";
            std::cin >> accion;

            if (accion < 1 || accion > 3) {
                std::cout << "Opción inválida. Por favor, elige una opción válida.\n";
            }
        } while(accion < 1 || accion > 3);

        switch(accion) {
            case 1:
                atacar(jugador, enemigo, jugador.ataque1Nombre, jugador.ataque1Danio);
                break;
            case 2:
                atacar(jugador, enemigo, jugador.ataque2Nombre, jugador.ataque2Danio);
                break;
            case 3:
                usarItem(jugador);
                break;
        }

        if (enemigo.vida <= 0) break;

        // Turno de la computadora (ataque o curación aleatoria)
        int accionEnemiga = elegirAccionEnemiga();
        if (accionEnemiga == 0) {
            atacar(enemigo, jugador, enemigo.ataque1Nombre, enemigo.ataque1Danio);
        } else if (accionEnemiga == 1) {
            atacar(enemigo, jugador, enemigo.ataque2Nombre, enemigo.ataque2Danio);
        } else {
            usarItem(enemigo);
        }

        mostrarVida(jugador);
        mostrarVida(enemigo);
    }

    // Resultado de la batalla
    if (jugador.vida > 0) {
        std::cout << "\n¡Ganaste! Tu Pokémon " << jugador.nombre << " ha derrotado a " << enemigo.nombre << "!\n";
    } else {
        std::cout << "\n¡Perdiste! Nooob\n";
    }

    return 0;
}
