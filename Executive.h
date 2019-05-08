/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "BinarySearchTree.h"
#include "BNode.h"
#include "Pokemon.h"
#include "TreeTest.h"
#include "Visit.h"
#include <iostream>
#include <string>
#include <fstream>
#include "BinarySearchTree.h"
#include "TreeTest.h"
#include <vector>

using namespace std;

class Executive
{
public:
  Executive();
  void maketree(string fileName);
  void printMenu();
  void saveFile(string choice, string order);
  ~Executive();
  

private:
  BinarySearchTree<Pokemon,string> *BSTptr;
  BinarySearchTree<Pokemon, string> *BSTdeepCopyptr;
  TreeTest* treeTestptr;
  

};
#endif
/*
 CODE TO MAKE A STRING ALL LOWER CAPS
for (int i=0; i<trial.length(); i++)
        {
            if(trial.at(i)<96)
            {
                trial.at(i) = trial.at(i)+32;
            }
        }
*/