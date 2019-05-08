/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

#include"Pokemon.h"
Pokemon::Pokemon()
{
    m_AmericanName = "/0";
    m_JapaneseName = "/0";
    m_PokedexNumber = 0;
}

Pokemon::Pokemon(const Pokemon &otherPokemon)
{
    m_AmericanName = otherPokemon.m_AmericanName;
    m_JapaneseName = otherPokemon.m_JapaneseName;
    m_PokedexNumber = otherPokemon.m_PokedexNumber;
}

Pokemon::Pokemon(string AmericanName, string JapaneseName, int PokedexNumber)
{
    m_AmericanName = AmericanName;
    m_JapaneseName = JapaneseName;
    m_PokedexNumber = PokedexNumber;
}

string Pokemon::getAmericanName() const
{
    return m_AmericanName;
}
string Pokemon::getJapaneseName() const
{
    return m_JapaneseName;
}
int Pokemon::getPokedexNumber() const
{
    return m_PokedexNumber;
}

void Pokemon::setAmericanName(string AmericanName)
{
    m_AmericanName=AmericanName; 
}
void Pokemon::setJapaneseName(string JapaneseName)
{
    m_JapaneseName=JapaneseName;
}
void Pokemon::setPokedexNumber(int PokedexNumber)
{
    m_PokedexNumber=PokedexNumber;
}

bool Pokemon::operator==(const Pokemon rhs) const
{
    if (m_AmericanName== rhs.m_AmericanName)
    {return true;}
    else 
    {return false;}
}
bool Pokemon::operator<(const Pokemon rhs) const
{
    if (m_AmericanName < rhs.m_AmericanName)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Pokemon::operator>(const Pokemon rhs) const
{
    if (m_AmericanName > rhs.m_AmericanName)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Pokemon& Pokemon::operator=(const Pokemon &rhs)
{
    m_AmericanName = rhs.m_AmericanName ;
    m_JapaneseName = rhs.m_JapaneseName;
    m_PokedexNumber = rhs.m_PokedexNumber;
    return *(this);
}

bool Pokemon::operator==(const string key) const
{
    if (m_AmericanName == key)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Pokemon::operator<(const string key) const
{
    if (this->getAmericanName() < key)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Pokemon::operator>(const string key) const
{
    if (m_AmericanName > key)
    {
        return true;
    }
    else
    {
        return false;
    }
}

