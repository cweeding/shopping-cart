

#include "shoppingCart.h"

template<class ItemType>
shoppingCart<ItemType>::shoppingCart()
{
  Bag<ItemType>();
  totalPrice = 0;
} // end default constructor



template<class ItemType>
bool shoppingCart<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = Bag<ItemType>::add(newEntry);
	return hasRoomToAdd;
}  // end add



template<class ItemType>
bool shoppingCart<ItemType>::remove(const ItemType& anEntry)
{
	bool canRemoveItem = Bag<ItemType>::remove(anEntry);
	return canRemoveItem;
}  // end remove



template<class ItemType>
double shoppingCart<ItemType>::getTotalPrice(const ItemType& aPrice, const ItemType& aQty)
{
	return totalPrice = totalPrice + (aPrice * aQty);
}  // end getTotalPrice
