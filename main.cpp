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
#include <string>

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
    std::cout << "4 - podel dva zlomky\n";
    std::cout << "5 - porovnani dvou zloku\n";

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
/**
 * @brief funkce porovna dva zlomky a vrati celociselnou hodnotu na zaklade vypoctu 
 * 
 * @param us_input - dva uzivatelem zadane zlomky 
 * @return int 
 */
int compare_zlomky(const struct user_input& us_input) {
    if (us_input.zlomek1 > us_input.zlomek2) { return -1; }

    if (us_input.zlomek1 == us_input.zlomek2) { return 0; }
    
    if (us_input.zlomek1 < us_input.zlomek2) { return 1; }
}
/**
 * @brief funkce prehledne vypise vysledek porovnavani dvout zlomku
 * 
 * @param compare_output    - vysledek porovnavani pomoci funkce compare_zlomky() 
 * @param us_input          - dva, uzivatelem zadane zlomky
 */
void print_compare_output(const int& compare_output, const struct user_input& us_input) {
    switch (compare_output) {
        case -1:
            std::cout << std::endl << us_input.zlomek1 << " > " << us_input.zlomek2 << std::endl;

            return;
        case 0:
            std::cout << std::endl << us_input.zlomek1 << " = " << us_input.zlomek2 << std::endl;

            return;
        case 1:
            std::cout << std::endl << us_input.zlomek1 << " < " << us_input.zlomek2 << std::endl;

            return;
    }
}

int main(void) {
    bool running = true;

    while (running) {
        Zlomek              vysledek;           // vysledek dane operace s dvema zlomky
        struct user_input   input;              // uzivatelem zadane dva zlomky
        bool                comparing = false;  // promena, pomocna u vypisu vysledku
        std::string         operace;            // promenna pouzita k prehlednejsimu vypisu vysledku

        switch (menu()) {
            case 0: 
                return 0;

                break;
            case 1:
                input = get_user_input();     // nacteni dvou zlomku

                vysledek = input.zlomek1 + input.zlomek2;

                operace = " + ";

                break;
            case 2:
                input = get_user_input();

                vysledek = input.zlomek1 - input.zlomek2;

                operace = " - ";

                break;
            case 3:
                input = get_user_input();

                vysledek = input.zlomek1 * input.zlomek2;

                operace = " * ";

                break;
            case 4:
                input = get_user_input();

                vysledek = input.zlomek1 / input.zlomek2;

                operace = " / ";

                break;
            case 5:
                input = get_user_input();
                
                print_compare_output(compare_zlomky(input), input);

                comparing = true;
                break;
        }   
       
        // vypsani vysledku pokud se zrovna neporovnavalo
        if (!comparing) { std::cout << std::endl << input.zlomek1 << operace << input.zlomek2 << " = " << vysledek << std::endl; }    
    }
}
