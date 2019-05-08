# Binary-Search-Trees-II
lab09
Overview
This lab is a continuation on your BST data structure. We will be adding feature to it and the program as a whole.

Binary Search Tree: Phase 2
In addition to the old functionality, your menu must also allow the user to ...

Copy	Creates a deep copy of the BST. Once the user makes a copy, they can only edit the copy. 
The user can only select this option once. If the user tries to make multiple copies, display copy already made. NOTE: This is separate from the test functions. Each of those is passing a BST by-value, hence it will make a copy on the call.
Remove	Remove a Pokemon from the BST. Obtain an American name (case insensitive) and remove that entry from the BST. This can only be done to the copy. If the Pokemon is not in the BST, inform the user.
Save	Prompt the user for the following:
Output file name
Which pokedex they want to save (original or copy)
Traversal order; The user can choose for the pokedex to be written in in, pre, or post order.
Test	

You will make a TreeTest class that you will use to test your copy constructor and destructor. When the user enters test mode, ask them which test they want to run.

void testAdds(BinarySearchTree<PokedexEntry, std::string> bst) // NOTE: Passed by value!!!
Pass in the original pokedex
Prompts the user for a word and definition to add (seperate prompts)
Prints the remaining tree to the screen in in-order
void testRemoves(BinarySearchTree<PokedexEntry, std::string> bst) // NOTE: Passed by value!!!
Pass in the original pokedex
Prompts the user for a word to remove
Prints the remaining tree to the screen in in-order
void testWriteToFile(BinarySearchTree<PokedexEntry, std::string> bst) // NOTE: Passed by value!!!
Pass in the original pokedex
Prompt the user for an output file name
Writes the contents of the pokedex to the file in in-order
Quit	Exits the program.
BST Interface (Updated)
#include <functional>
tempate <typename ItemType, typename KeyType>
class BinarySearchTreeInterface
{
    public:
    virtual ~BinarySearchTreeInterface(){}
    virtual void add(ItemType entry) = 0; //throws std::runtime_error if duplicate added
    virtual ItemType search(KeyType key) const = 0; //throws std::runtime_error if not in tree
    virtual void clear() = 0;
    virtual void remove(KeyType key) = 0; //throws std::runtime_error if not in tree
    virtual void visitPreOrder(std::function<void(ItemType)> visit) const = 0; //Visits each node in pre order
    virtual void visitInOrder(std::function<void(ItemType)> visit) const = 0; //Visits each node in in order
    virtual void visitPostOrder(std::function<void(ItemType)> visit) const = 0; //Visits each node in post order
};
Rubric
45% Pokedex Interaction
5% Searching
5% Adding entry
15% Deep copying of BST
20% Removing entry
20% File output
10% proper traversal order
10% well formatted output
15% Test methods (5% each)
10% Program stability
5% Logical user interface
5% Needed Operators overloaded
