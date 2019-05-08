/* File Name: main.cpp
 * Author: Paul Negedu
 * EECS 268 - Lab 9
 * Description:  The main.cpp file that hands control to the Executive file
 * Last edited - April 28th, 2019
 *------------------------------------------------------------------------*/

template <typename ItemType>
void Visit<ItemType>::print(ItemType Value)
{
    cout << Value.getAmericanName();
    cout<<" ";
    cout << Value.getPokedexNumber();
    cout<<" ";
    cout << Value.getJapaneseName();
    cout<<" ";
    cout<<endl;
}

template <typename ItemType>
void Visit<ItemType>::save(ItemType Value)
{
  //cout<< (Visit<Pokemon>::m_fileName);
  static bool firstRun = true;
  static string fileName = "";
  if (firstRun == true)
  {
    cout << "What is the name of the output file(end with '.txt'): ";
    cin>> fileName;
    firstRun = false;
  }

  ofstream outFile;
  outFile.open(fileName, ofstream::app);

  outFile << Value.getAmericanName();
  outFile << " ";
  outFile << Value.getPokedexNumber();
  outFile << " ";
  outFile << Value.getJapaneseName();
  outFile << " ";
  outFile << endl;
  outFile.close();
}
