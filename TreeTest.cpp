/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

#include "TreeTest.h"

void TreeTest::testAdds(BinarySearchTree<Pokemon, string> bst)
{
    string AmericanName = "";
    int PokedexNumber = 0;
    string JapaneseName = "";
    Pokemon *temp = nullptr;

    cout << "What is the American name for the Pokemon: ";
    cin >> AmericanName;
    cout << "What is the PokedexNumber for the Pokemon: ";
    cin >> PokedexNumber;
    cout << "What is the Japanese name for the Pokemon: ";
    cin >> JapaneseName;

    temp = new Pokemon(AmericanName, JapaneseName, PokedexNumber);

    try
    {
        bst.add(*temp);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    delete temp;
    temp = nullptr;
    //print updates bst's binary search tree
    bst.visitInOrder(Visit<Pokemon>::print);
}
void TreeTest::testRemoves(BinarySearchTree<Pokemon, string> bst)
{
    string key = "";
    cout << "What is the American name to be removed from the BST: ";
    cin >> key;

    try
    {
        bst.remove(key);
        cout<<endl;
        cout<<"Sucessfully removed!";
        cout<<endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    //print updates bst's binary search tree
    bst.visitInOrder(Visit<Pokemon>::print);
}

void TreeTest::testWriteToFile(BinarySearchTree<Pokemon, string> bst)
{
    bst.visitInOrder(Visit<Pokemon>::save);
}
