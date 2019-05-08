/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <iostream>

using namespace std;

class Pokemon
{
  private:
    string m_AmericanName;
    string m_JapaneseName;
    int m_PokedexNumber;

  public:
    Pokemon();
    Pokemon(const Pokemon& otherPokemon);
    Pokemon(string AmericanName, string JapaneseName, int PokedexNumber);
    ~Pokemon(){};

    string getAmericanName() const;
    string getJapaneseName() const;
    int getPokedexNumber() const;

    void setAmericanName(string AmericanName);
    void setJapaneseName(string JapaneseName);
    void setPokedexNumber(int PokedexNumber);

    bool operator==(const Pokemon rhs)const;
    bool operator<(const Pokemon rhs) const;
    bool operator>(const Pokemon rhs) const;
    Pokemon& operator=(const Pokemon& rhs);

    bool operator==(const string key) const;
    bool operator<(const string key) const;
    bool operator>(const string key) const;

    
   
};
#endif
