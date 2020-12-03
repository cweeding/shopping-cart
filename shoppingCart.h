

#ifndef _SHOPPING_CART
#define _SHOPPING_CART
#include "Bag.h"

template<class ItemType>
class shoppingCart : public Bag<ItemType>
{
private:
  double totalPrice; // Member variable for shopping cart total price
   
public:
  shoppingCart();
  bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
  double getTotalPrice(const ItemType& aPrice, const ItemType& aQty);
}; // end shoppingCart

#include "shoppingCart.cpp"
#endif
