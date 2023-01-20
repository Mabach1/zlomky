/**
 **************************************************************************************
 * @file    main.cpp
 * @author  Matej Baliga (matej.baliga@spsehavirov.cz)
 * @version 1.0
 * @date    due 24-January-2023
 * @brief   soubor pro testovani prace s tridou "Zlomek"
 * 
 **************************************************************************************
 */

#include ".\zlomky.h"   // hlavickovy soubor s definici tridy Zlomek a jejimi funkcemi

/**
 * @brief struct pro prehlednejsi zadavani dvou zlomku 
 * 
 */
struct user_input {
    Zlomek zlomek1;
    Zlomek zlomek2;
};
/**
 * @brief uzivatelska nabidka
 * 
 * @return volbu uzivatele
 */
int menu(void) {
    std::cout << "---------------------------\n";
    std::cout << "0 - UKONCI\n";
    std::cout << "1 - secti dva zlomky\n";
    std::cout << "2 - odecti dva zlomky\n";
    std::cout << "3 - vynasob dva zlomky\n";
    std::cout << "4 - vydel dva zlomky\n";

    int volba = 0;

    std::cout << "vyber: ";
    std::cin >> volba;

    return volba;
}
/**
 * @brief ziska a vrati dva zlomky 
 * 
 * @return struct user_input = dva zlomky 
 */
struct user_input get_user_input(void) {
    struct user_input us_input;
    
    std::cout << "zadejte 1. zlomek:\n";
    std::cin >> us_input.zlomek1;
    std::cout << "zadejte 2. zlomek:\n";
    std::cin >> us_input.zlomek2;

    return us_input;
}

int main(void) {
    bool running = true;

    Zlomek              vysledek;   // vysledek dane operace s dvema zlomky
    struct user_input   input;      // uzivatelem zadane dva zlomky

    while (running) {
        switch (menu()) {
            case 0: 
                return 0;

                break;
            case 1:
                input = get_user_input();     // nacteni dvou zlomku

                vysledek = input.zlomek1 + input.zlomek2;

                break;
            case 2:
                input = get_user_input();

                vysledek = input.zlomek1 - input.zlomek2;

                break;
            case 3:
                input = get_user_input();

                vysledek = input.zlomek1 * input.zlomek2;

                break;
            case 4:
                input = get_user_input();

                vysledek = input.zlomek1 / input.zlomek2;

                break;
        }

        std::cout << std::endl << vysledek;     // vypsani vysledku
    }
}