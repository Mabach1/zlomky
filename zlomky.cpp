/**
 **************************************************************************************
 * @file    zlomky.cpp
 * @author  Matej Baliga (matej.baliga@spsehavirov.cz)
 * @version 1.0
 * @date    due 24-January-2023
 * @brief   definice funkci tridy Zlomek a jinych pomocnych funkci
 * 
 **************************************************************************************
 */

#include ".\zlomky.h"

/**
 * @brief rutina pro absolutni hodnoty cisla 
 * 
 * @param cislo 
 * @return int   
 */
int abs(int cislo) {
    if (cislo < 0) { return cislo * -1; }

    return cislo;
}
/**
 * @brief Construct a new Zlomek:: Zlomek object
 * 
 */
Zlomek::Zlomek(void) {
    this->citatel = 0;
    this->jmenovatel = 1;
}
/**
 * @brief metoda, ktera najde spolecneho delitele
 * 
 * @param cislo1    --- citatel
 * @param cislo2    --- jmenovatel
 * @return spolecny delitel 
 */
int delitel(const int& cislo1,const int& cislo2) {
    int max = (abs(cislo1) > abs(cislo2)) ? abs(cislo1) : abs(cislo2);  // nastaveni maximalni hodnoty, do ktere pujde smycka for
    int found_delitel = 1;

    for (int i = 1; i < max; i++) {
        if ((abs(cislo1) % i == 0)  && (abs(cislo2) % i == 0)) {
            found_delitel = i;
        }
    }

    return found_delitel;
}
/**
 * @brief funkce upravi zlomek do zakladniho tvru 
 * 
 */
void Zlomek::zkrat(void) {
    int spolecny_delitel = delitel(this->citatel, this->jmenovatel);    // nalazeny spolecny delitel pomoci funkce delitel()

    this->citatel = this->citatel / spolecny_delitel;
    this->jmenovatel = this->jmenovatel / spolecny_delitel;

    // ji-li citatel i jmenovatel zporny, celkovy zlomek je kladny a muzeme se tedy zbavit znamenek
    if (this->citatel < 0 && this->jmenovatel < 0) { 
        this->citatel    *= -1; 
        this->jmenovatel *= -1; 
    } 
    
    if (this->jmenovatel < 0 && this->citatel > 0) {
        this->jmenovatel *= -1;
        this->citatel    *= -1;
    }
}
/**
 * @brief  friend metoda pro vypis objektu zlomku (vypis bude vypadata takto => (-)citatel/jmenovatel)
 * 
 * @param output 
 * @param content   -> zlomek, ktery chceme vytisknout 
 * @return std::ostream& 
 */
std::ostream &operator << (std::ostream &output, Zlomek content) {
    if (content.jmenovatel == 1) {
        output << content.citatel;
    }

    // v pripade, ze ve vysledek vysel nula
    if (content.citatel == 0 && content.jmenovatel == 0) {
        output << "0";

        return output;
    }

    // v pripade, ze vysledek vysel jedna 
    if (abs(content.citatel) == abs(content.jmenovatel)) {
        content.citatel > 0 ? output << "1" : output << "-1";

        return output;
    }

    output << content.citatel << "/" << content.jmenovatel;

    return output;
}
/**
 * @brief friend metoda pro ziskani objektu zlomku
 * 
 * @param input 
 * @param content   -> zlomek, ktery chceme nacist 
 * @return std::istream& 
 */
std::istream &operator >> (std::istream& input, Zlomek& content) {
    input >> content.citatel;
    do {
        input >> content.jmenovatel;

        if (content.jmenovatel == 0) { std::cout << "nelze delit nulou."; }

    } while (content.jmenovatel == 0);
}
/**
 * @brief friend metoda pro scitani dvou objektu tridy zlomek 
 * 
 * @param cislo1 
 * @param cislo2 
 * @return Zlomek 
 */
Zlomek operator + (const Zlomek& cislo1, const Zlomek& cislo2) {
    Zlomek vysledek;

    vysledek.citatel = (cislo1.citatel * cislo2.jmenovatel) + (cislo2.citatel * cislo1.jmenovatel);
    vysledek.jmenovatel = cislo1.jmenovatel * cislo2.jmenovatel;

    vysledek.zkrat();   // upraveni zlomku do zakladniho tvaru funkci zkrat()

    return vysledek;
}
/**
 * @brief  friend metoda pro odcitani dvou objektu tridy zlomek 
 * 
 * @param cislo1 
 * @param cislo2 
 * @return Zlomek 
 */
Zlomek operator - (const Zlomek& cislo1, const Zlomek& cislo2) {
    Zlomek vysledek;

    if (cislo1.citatel == cislo2.citatel && cislo1.jmenovatel == cislo2.jmenovatel) { 
        vysledek.citatel = 0;
        vysledek.jmenovatel = 0;

        return vysledek;
    }

    vysledek.citatel = (cislo1.citatel * cislo2.jmenovatel) - (cislo2.citatel * cislo1.jmenovatel);
    vysledek.jmenovatel = cislo1.jmenovatel * cislo2.jmenovatel;

    vysledek.zkrat();

    return vysledek;
}
/**
 * @brief  friend metoda pro nasobeni dvou objektu tridy zlomek 
 * 
 * @param cislo1 
 * @param cislo2 
 * @return Zlomek 
 */
Zlomek operator * (const Zlomek& cislo1, const Zlomek& cislo2) {
    Zlomek vysledek;

    vysledek.citatel = cislo1.citatel * cislo2.citatel;
    vysledek.jmenovatel = cislo1.jmenovatel * cislo2.jmenovatel;


    vysledek.zkrat();

    return vysledek;
}
/**
 * @brief  friend metoda pro deleni dvou objektu tridy zlomek 
 * 
 * @param cislo1 
 * @param cislo2 
 * @return Zlomek 
 */
Zlomek operator / (const Zlomek& cislo1, const Zlomek& cislo2) {
    Zlomek vysledek;

    vysledek.citatel = cislo1.citatel * cislo2.jmenovatel;
    vysledek.jmenovatel = cislo1.jmenovatel * cislo2.citatel;

    vysledek.zkrat();

    return vysledek;
}
/**
 * @brief friend funkce pro porovnani dvou zlomku
 * 
 * zlomek1 > zlomek2 => true
 * 
 * @param zlomek1 
 * @param zlomek2 
 * @return true 
 * @return false 
 */
bool operator > (const Zlomek& zlomek1, const Zlomek& zlomek2) {
    return ((zlomek2.jmenovatel * zlomek1.citatel) > (zlomek1.jmenovatel * zlomek2.citatel)) ? true : false;
}
/**
 * @brief friend funkce pro porovnani dvou zlomku
 * 
 * zlomek1 < zlomek2 => true
 * 
 * @param zlomek1 
 * @param zlomek2 
 * @return true 
 * @return false 
 */
bool operator < (const Zlomek& zlomek1, const Zlomek& zlomek2) {
    return ((zlomek2.jmenovatel * zlomek1.citatel) < (zlomek1.jmenovatel * zlomek2.citatel)) ? true : false;
}
/**
 * @brief friend funkce pro porovnani dvou zlomku
 * 
 * zlomek1 == zlomek2 => true
 * 
 * @param zlomek1 
 * @param zlomek2 
 * @return true 
 * @return false 
 */
bool operator == (const Zlomek& zlomek1, const Zlomek& zlomek2) {
    return ((zlomek2.jmenovatel * zlomek1.citatel) == (zlomek1.jmenovatel * zlomek2.citatel)) ? true : false;
}
/**
 * @brief friend funkce pro porovnani dvou zlomku
 * 
 * zlomek1 != zlomek2 => true
 * 
 * @param zlomek1 
 * @param zlomek2 
 * @return true 
 * @return false 
 */
bool operator != (const Zlomek& zlomek1, const Zlomek& zlomek2) {
    return ((zlomek2.jmenovatel * zlomek1.citatel) != (zlomek1.jmenovatel * zlomek2.citatel)) ? true : false;
}
