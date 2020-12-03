/*************************************************************************
* Name: Codie Weeding
* StarID: vx3094oa
* Class: CSCI 301
* Section: 054
* File Name: project2.cpp
* File Location: CourseFiles\Fall2019\jhu\CSCI301s54\
*                StudentWorkFolder\vx3094oa\Project2-CodieWeeding
* Due Date: 9/24/2019
* Instructor: Jie Hu Meichsner
*
* Description: 
*              
*************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "item.h"
#include "Bag.h"
#include "shoppingCart.h"
using namespace std;

// template<class ItemType>
// void displayBagItems(const Bag<ItemType>& aBag, const Bag<ItemType>& bBag, const Bag<ItemType>& cBag);

int main()
{
  // Variables
  string name; // Local variable for item name
  double unitPrice; // Local variable for item unit price
  int qty; // Local variable for item quantity
  char option; // Local variable for option to add more items
  int menuOption; // Local variable for add or remove option
  double totalPrice;
  int indexName;
  int indexPrice;
  int indexQty;
  
  // Constructors
  item aItem; // Define a new item object by the default constructor
  shoppingCart<string> nameBag; // Define a new shoppingCart object by the default constructor
  shoppingCart<double> priceBag; // Define a new shoppingCart object by the default constructor
  shoppingCart<int> qtyBag; // Define a new shoppingCart object by the default constructor
  shoppingCart<double> totalBag; // Define a new shoppingCart object by the default constructor
  
  // Gets item information from the user
  cout << "\nWelcome to ABC SHOPPING CENTER!" << endl;
  cout << "\nEnter the item you selected in the following order:";
  cout << "\nname unitPrice qty";
  cout << "\n(Note: Name can not contain any spaces, else error.)" << endl;
  cout << "--> ";
  cin >> aItem; // Stores input as aItem object

/******************************** ITEM CLASS TEST ********************************/
  // item bItem;
  // string bname;
  // double bunitPrice;
  // int bqty;

  // cout << "\nEnter the item you selected in the following order:";
  // cout << "\nname unitPrice qty";
  // cout << "\n(Note: Name can not contain any spaces, else error.)" << endl;
  // cout << "--> ";
  // cin >> bname >> bunitPrice >> bqty;
  // bItem.setName(bname);
  // bItem.setUnitPrice(bunitPrice);
  // bItem.setQty(bqty);

  // cout << "\n" << aItem << endl;
  // cout << bItem.getName() << " ";
  // cout << bItem.getUnitPrice() << " ";
  // cout << bItem.getQty() << endl;
  
  // bool equal = bItem.operator==(aItem);
  // if (equal)
  //   cout << "\nSame Items" << "\n" << endl;
  // else
  //   cout << "\nDifferent Items" << "\n" << endl;
/********************************************************************************/
  
  nameBag.add(aItem.getName());
  priceBag.add(aItem.getUnitPrice());
  qtyBag.add(aItem.getQty());
  totalPrice = totalBag.getTotalPrice(aItem.getUnitPrice(), aItem.getQty());

  cout << "Do you want to continue? y/n: ";
  cin >> option;
  
  while (option != 'n')
  {
    cout << "\n--> ";
    cin >> aItem;
    nameBag.add(aItem.getName());
    priceBag.add(aItem.getUnitPrice());
    qtyBag.add(aItem.getQty());
    totalPrice = totalBag.getTotalPrice(aItem.getUnitPrice(), aItem.getQty());
    cout << "Do you want to continue? y/n: ";
    cin >> option;
  }
  
 /********************************************************************************/ 
  // Display all items in the bag
  cout << "\nHere is your order:" << endl;
  vector<string> bagNames;
	vector<double> bagPrices;
	vector<int> bagQtys;
	bagNames = nameBag.toVector();
	bagPrices = priceBag.toVector();
	bagQtys = qtyBag.toVector();
	int numOfItems = bagNames.size();

  cout << "--------------------------------------------------" << endl;
  cout << setw(20) << left << "Name" << setw(20) << left << "unitPrice" << "Quantity" << endl;
	for(int i = 0; i < numOfItems; ++i)
  {
		cout << setw(20) << left << bagNames[i] << setw(20) << left << bagPrices[i] << bagQtys[i] << endl;
  }
  cout << "\nThe total is " << totalPrice << endl;
  cout << "--------------------------------------------------" << endl;

/********************************************************************************/
  // Modify Order
  option = 'y';
  while (option != 'n')
  {
    cout << "\nDo you want to modify your order? y/n: ";
    cin >> option;

    if (option == 'y')
    {
      cout << "Enter 1: add 2: remove" << endl;
      cout << "--> ";
      cin >> menuOption;

      if (menuOption == 1)
      {
        cout << "\nEnter the item you selected in the following order:";
        cout << "\nname unitPrice qty";
        cout << "\n(Note: Name can not contain any spaces, else error.)" << endl;
        cout << "--> ";
        cin >> aItem; // Stores input as aItem object
        nameBag.add(aItem.getName());
        priceBag.add(aItem.getUnitPrice());
        qtyBag.add(aItem.getQty());
        totalPrice = totalBag.getTotalPrice(aItem.getUnitPrice(), aItem.getQty());
        cout << "\nThe item was added to the cart\n" << endl;
      }

      else
      {
        cout << "\nEnter the item to remove in the following order:";
        cout << "\nname unitPrice qty" << endl;
        cout << "--> ";
        cin >> aItem; // Stores input as aItem object

        if (nameBag.contains(aItem.getName()) 
            && priceBag.contains(aItem.getUnitPrice())
            && qtyBag.contains(aItem.getQty()))
        {
          nameBag.remove(aItem.getName());
          priceBag.remove(aItem.getUnitPrice());
          qtyBag.remove(aItem.getQty());
          totalPrice = totalPrice - (aItem.getUnitPrice() * aItem.getQty());
          cout << "\nThe item has been removed\n" << endl;
        }

        else
        {
          cout << "\nNo such item in shopping cart\n" << endl;
        }
      }
    }

    else
    {
      // Display all items in the bag
      cout << "\nHere is your updated order:" << endl;
      vector<string> bagNames;
      vector<double> bagPrices;
      vector<int> bagQtys;
      bagNames = nameBag.toVector();
      bagPrices = priceBag.toVector();
      bagQtys = qtyBag.toVector();
      int numOfItems = bagNames.size();

      cout << "--------------------------------------------------" << endl;
      cout << setw(20) << left << "Name" << setw(20) << left << "unitPrice" << "Quantity" << endl;
      for(int i = 0; i < numOfItems; ++i)
      {
        cout << setw(20) << left << bagNames[i] << setw(20) << left << bagPrices[i] << bagQtys[i] << endl;
      }
      cout << "\nThe total is " << totalPrice << endl;
      cout << "--------------------------------------------------" << endl;
    }
  }

  cout << "\nThanks for shoppping ABC SHOPPING CENTER!\n" << endl;
  return 0;
}
