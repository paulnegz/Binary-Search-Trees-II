/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

#include "Executive.h"

using namespace std;

Executive::Executive()
{
  BSTptr = new BinarySearchTree<Pokemon, string>();
  BSTdeepCopyptr=nullptr;
  treeTestptr=nullptr;
}

void Executive::maketree(string fileName)
{
  ifstream inFile;
  inFile.open(fileName);
  if (!(inFile.good()))
  {
    throw(runtime_error("File does not exist!\n"));
    cout << "Does not exist" << endl;
  }
  else
  {
    string AmericanName = "\0";
    int PokedexNumber = 0;
    string JapaneseName = "\0";
    Pokemon* temp = nullptr;
    do
    {
      inFile >> AmericanName;
      for (int i = 0; i < AmericanName.length(); i++)
      {
        if (AmericanName.at(i) < 96)
        {
          AmericanName.at(i) = AmericanName.at(i) + 32;
        }
      }
      inFile >> PokedexNumber;
      inFile >> JapaneseName;
      for (int i = 0; i < JapaneseName.length(); i++)
      {
        if (JapaneseName.at(i) < 96)
        {
          JapaneseName.at(i) = JapaneseName.at(i) + 32;
        }
      }
      temp = new Pokemon(AmericanName, JapaneseName, PokedexNumber);

      try
      {
        BSTptr->add(*temp);
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }


      delete temp;
      temp = nullptr;
    } while (!inFile.eof());
  }
  inFile.close();

}



void Executive::printMenu()
{
  string option= "/0";
  cout<<endl;

  cout<<"Type in 'search' to get the Japanese and Pokedex of a Pokemon"<<endl;
  cout<<"Type in 'add' to add a pokemon to this tree"<<endl;
  cout << "Type in 'copy' to creates a deep copy of the BST. Once  a copy is made, all edits are made on copy" << endl;
  cout << "Type in 'remove' to remove a Pokemon from the BST." << endl;
  cout << "Type in 'save' the BST" << endl;
  cout << "Type in 'test' to enter test mode" << endl;
  cout << "Type in 'quit' to end program" << endl;
  cout<<"Choice: ";
  cin>>option;
  for (int i = 0; i < option.length(); i++)
  {
    if (option.at(i) < 96)
    {
      option.at(i) = option.at(i) + 32;
    }
  }

  if (option == "search" )
  {
    if (BSTdeepCopyptr==nullptr)
    {
      string AmericanName = "/0";
      cout << "Type the American name of the Pokemon:";
      cin>>AmericanName;
      for (int i = 0; i < AmericanName.length(); i++)
      {
        if (AmericanName.at(i) < 96)
        {
          AmericanName.at(i) = AmericanName.at(i) + 32;
        }
      }

      cout<<endl;
      try
      {
        Pokemon found = (BSTptr->search(AmericanName));
        cout << "The Japanese name for " << found.getAmericanName();
        cout << " is: " << found.getJapaneseName() << endl;
        cout << "The Pokedex number for " << found.getAmericanName();
        cout << " is: " << found.getPokedexNumber() << endl;
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
      }
      cout<<endl;
  }

  else
  {
    string AmericanName = "/0";
    cout << "Type the American name of the Pokemon:";
    cin >> AmericanName;
    for (int i = 0; i < AmericanName.length(); i++)
    {
      if (AmericanName.at(i) < 96)
      {
        AmericanName.at(i) = AmericanName.at(i) + 32;
      }
    }
    cout << endl;
    try
    {
      Pokemon found = (BSTdeepCopyptr->search(AmericanName));
      cout << "The Japanese name for " << found.getAmericanName();
      cout << " is: " << found.getJapaneseName() << endl;
      cout << "The Pokedex number for " << found.getAmericanName();
      cout << " is: " << found.getPokedexNumber() << endl;
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
    }
    cout << endl;
  }

}
  else if (option == "add")
  {
    if(BSTdeepCopyptr==nullptr)
    {
    string AmericanName = "\0";
    int PokedexNumber = 0;
    string JapaneseName = "\0";
    Pokemon *temp = nullptr;

    cout<<"What is the American name for the Pokemon: ";
    cin >> AmericanName;
    for (int i = 0; i < AmericanName.length(); i++)
    {
      if (AmericanName.at(i) < 96)
      {
        AmericanName.at(i) = AmericanName.at(i) + 32;
      }
    }
    cout << "What is the PokedexNumber for the Pokemon: ";
    cin >> PokedexNumber;
    cout << "What is the Japanese name for the Pokemon: ";
    cin >> JapaneseName;
    for (int i = 0; i < JapaneseName.length(); i++)
    {
      if (JapaneseName.at(i) < 96)
      {
        JapaneseName.at(i) = JapaneseName.at(i) + 32;
      }
    }

    temp = new Pokemon(AmericanName, JapaneseName, PokedexNumber);

    try
    {
      BSTptr->add(*temp);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }


    delete temp;
    temp = nullptr;

    }
    else
    {
      string AmericanName = "\0";
      int PokedexNumber = 0;
      string JapaneseName = "\0";
      Pokemon *temp = nullptr;

      cout << "What is the American name for the Pokemon: ";
      cin >> AmericanName;
      for (int i = 0; i < AmericanName.length(); i++)
      {
        if (AmericanName.at(i) < 96)
        {
          AmericanName.at(i) = AmericanName.at(i) + 32;
        }
      }
      cout << "What is the PokedexNumber for the Pokemon: ";
      cin >> PokedexNumber;
      cout << "What is the Japanese name for the Pokemon: ";
      cin >> JapaneseName;
      for (int i = 0; i < JapaneseName.length(); i++)
      {
        if (JapaneseName.at(i) < 96)
        {
          JapaneseName.at(i) = JapaneseName.at(i) + 32;
        }
      }

      temp = new Pokemon(AmericanName, JapaneseName, PokedexNumber);

      try
      {
        BSTdeepCopyptr->add(*temp);
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
      }

      delete temp;
      temp = nullptr;
    }

  }

  else if (option == "copy")
  {
    if(BSTdeepCopyptr!=nullptr)
    {
      cout<<endl;
      cout<< "Deep copy has already been made"<<endl;
    }
    else
    {
      BSTdeepCopyptr = new BinarySearchTree<Pokemon, string>(*BSTptr);
      cout<<endl;
      cout << "A deep copy has been made" << endl;
    }

  }

  else if (option == "remove")
  {
    if(BSTdeepCopyptr==nullptr)
    {
      cout << "Can only remove from a copy. Make copy first" << endl;
    }
    else
    {
      string key = "\0";
      cout << "What is the American name to be removed from the BST: ";
      cin>>key;
      for (int i = 0; i < key.length(); i++)
      {
        if (key.at(i) < 96)
        {
          key.at(i) = key.at(i) + 32;
        }
      }

      try
      {
        BSTdeepCopyptr->remove(key);
        cout << "Sucessfully removed" << endl;
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
      }


    }
  }




  else if (option == "save")
  {
    //string outputFile = "\0";
    string choice = "\0";
    string order = "\0";
  //cout << "What is the name of the output file(end with '.txt'): ";
    //cin >> outputFile;
    cout << "Which pokedex is to be saved (original or copy): ";
    cin>>choice;
    for (int i = 0; i < choice.length(); i++)
    {
      if (choice.at(i) < 96)
      {
        choice.at(i) = choice.at(i) + 32;
      }
    }
    cout << "Traversal order; in, pre, or post: " << endl;
    cin>>order;
    for (int i = 0; i < order.length(); i++)
    {
      if (order.at(i) < 96)
      {
        order.at(i) = order.at(i) + 32;
      }
    }
    saveFile(choice,order);
  }

  else if (option == "test")
  {
    treeTestptr = new TreeTest();
    string test = "\0";
    cout << "\t***********************************" << endl;
    cout << "\t\tTEST MODE HAS BEGIN" << endl;
    cout << "\t***********************************" << endl;
    cout<< "type 'add' to test add" <<endl;
    cout<< "type 'remove' to test remove" <<endl;
    cout<< "type 'save' to save" <<endl;
    cout << "Which test do you want to run: ";
    cin>>test;
    for (int i = 0; i < test.length(); i++)
    {
      if (test.at(i) < 96)
      {
        test.at(i) = test.at(i) + 32;
      }
    }
    if (test == "add")
    {
      treeTestptr->testAdds(*BSTptr);
    }
    else if (test=="remove")
    {
      treeTestptr->testRemoves(*BSTptr);
    }
    else
    {
      treeTestptr->testWriteToFile(*BSTptr);
    }
    delete treeTestptr;
    treeTestptr=nullptr;
  }

  else if (option == "quit")
    {
      return;
    }
  else
  {
    cout<<"Wrong option"<<endl;
  }

  cout<<endl<<endl;
  printMenu();

}


Executive::~Executive()
{
  delete BSTptr;
  BSTptr = nullptr;
  delete BSTdeepCopyptr;
  BSTdeepCopyptr = nullptr;
  delete treeTestptr;
  treeTestptr =nullptr
  
  ;}
void Executive::saveFile( string choice, string order)
{
  //Open file object
  //ofstream outFile;
  //outFile.open(fileName);
  //template<typename ItemType>
  //Visit<Pokemon> Paul;
  //Visit<Pokemon>::m_fileName = fileName; //
  //Visit<Pokemon>::m_fileName = fileName;

  if (choice=="original")
  {
    if (order == "pre")
    {
      BSTptr->visitPreOrder(Visit<Pokemon>::save);
    }
    else if (order == "in")
    {
      BSTptr->visitInOrder(Visit<Pokemon>::save);
    }
    else
    {
      BSTptr->visitPostOrder(Visit<Pokemon>::save);
    }

  }
  else
  {
    if (order == "pre")
    {
      BSTdeepCopyptr->visitPreOrder(Visit<Pokemon>::save);
    }
    else if (order == "in")
    {
      BSTdeepCopyptr->visitInOrder(Visit<Pokemon>::save);
    }
    else
    {
      BSTdeepCopyptr->visitPostOrder(Visit<Pokemon>::save);
    }
  }

}
