/**
 **************************************************************************************
 * @file    zlomky.h
 * @author  Matej Baliga (matej.baliga@spsehavirov.cz)
 * @version 1.0
 * @date    due 24-January-2023
 * @brief   deklarace tridy Zlomek a jeji funkci
 * 
 **************************************************************************************
 */

#ifndef _ZLOMKY_H
#define _ZLOMKY_H

#include <iostream>

/**
 * @brief trida pro praci se zlomky 
 * 
 */
class Zlomek {
private:
    int citatel;
    int jmenovatel;

    void zkrat(void);
public:
    Zlomek();	// zakaladni konstruktor, ktery nastavi hodnotu zlomku na 0

	// pristupove metody pomoci std::cout a std::cin pro tridu Zlomek
	friend std::ostream &operator << (std::ostream &output, Zlomek content);
	friend std::istream &operator >> (std::istream &input, Zlomek& content);

	// zakladni aritmeticke funkce pro praci se zlomky
	friend Zlomek operator - (const Zlomek& cislo1, const Zlomek& cislo2);
	friend Zlomek operator + (const Zlomek& cislo1, const Zlomek& cislo2);
	friend Zlomek operator * (const Zlomek& cislo1, const Zlomek& cislo2);
	friend Zlomek operator / (const Zlomek& cislo1, const Zlomek& cislo2);
	
	// porovnavani dvou zlomku
    	friend bool operator > (const Zlomek& zlomek1, const Zlomek& zlomek2); 
	friend bool operator < (const Zlomek& zlomek1, const Zlomek& zlomek2); 
	friend bool operator == (const Zlomek& zlomek1, const Zlomek& zlomek2); 

	// v budoucnu mozno dodelat dalsi funcke jako '<=' nebo '>=', ktere se daji pouzit mimo jednoduche porovnavani dvou hodnot 
	friend bool operator != (const Zlomek& zlomek1, const Zlomek& zlomek2); 
};

#endif
