/*************************************************************************
* IMPLEMENTATION FILE FOR THE NEWFRACTION1 CLASS
* This version has a constructor
* Used with file project1_task2.cpp
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "item.h" // Required for the Complex class
using namespace std;

/***************************************************************
* The constructor accepts arguments for all inputs.
***************************************************************/

item::item()
{
}

/***************************************************************
* The constructor accepts arguments for all inputs.
***************************************************************/

item::item(string itemName, double itemUnitPrice, int itemQty)
{
  name = itemName;
  unitPrice = itemUnitPrice;
  qty = itemQty;
}

/***************************************************************
* setNumerator sets value of member numerator.
***************************************************************/

void item::setName(string itemName)
{
  name = itemName;
}

/***************************************************************
* setDenominator sets value of member variable denominator.
***************************************************************/

void item::setUnitPrice(double itemUnitPrice)
{
  unitPrice = itemUnitPrice;
}

/***************************************************************
* setDenominator sets value of member variable denominator.
***************************************************************/

void item::setQty(int itemQty)
{
  qty = itemQty;
}

/***************************************************************
* operator>> reads user's data from keyboard or file
***************************************************************/

istream &operator>>(istream &cartItem, item &aItem)
{
  cartItem >> aItem.name >> aItem.unitPrice >> aItem.qty;

  return cartItem;
}

/***************************************************************
* operator<< writes data to screen or file
***************************************************************/
ostream &operator<<(ostream &cartItem, const item &aItem)
{
  cartItem << aItem.name << " " << aItem.unitPrice << " " << aItem.qty;

  return cartItem;
}

/***************************************************************
* operator== checks if two complex numbers are equal
***************************************************************/

bool item::operator==(const item& aItem)
{
  if (name == aItem.name && unitPrice == aItem.unitPrice)
    return true;
  else
    return false;
}
