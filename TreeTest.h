/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

#ifndef TREETEST_H
#define TREETEST_H
#include <string>
#include <iostream>
#include"BinarySearchTree.h"
#include "Visit.h"
#include"Pokemon.h"
using namespace std;

class TreeTest
{
  private:
  

  public:
    void testAdds(BinarySearchTree<Pokemon,string> bst);
    void testRemoves(BinarySearchTree<Pokemon, string> bst) ;
    void testWriteToFile(BinarySearchTree<Pokemon,string> bst);

};
#endif
