/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

#ifndef VISIT_H
#define VISIT_H
#include "Pokemon.h"
#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

template <typename ItemType>
class Visit
{
private:
  

public:
  //static string m_fileName;
  static void print(ItemType Value);
  static void save(ItemType Value);
};
#include "Visit.hpp"
#endif
