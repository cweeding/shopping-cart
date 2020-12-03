/*************************************************************************
* SPECIFICATION FILE FOR THE ITEM CLASS
* This version has a constructor
* Used with file project2.cpp
*************************************************************************/

#ifndef ITEM_H
#define ITEM_H

#include <string> // Required to define input/output functions
using namespace std;

class item
{
  private:
    string name; // Member variable for item name
    double unitPrice; // Member variable for item unit price
    int qty; // Member variable for item quantity
    
  public:
    /************************* CONSTRUCTOR *************************/
    /****************************************************************
    * Uses default arguments
    * @parm int for numerator
    * @parm int for denominator
    * @pre none
    * @post sets fraction to a/b 
    ****************************************************************/
    item();

    /****************************************************************
    * Uses default arguments
    * @parm int for numerator
    * @parm int for denominator
    * @pre none
    * @post sets fraction to a/b 
    ****************************************************************/
    item(string, double, int);

    /**************** MODIFICATION MEMBER FUNCTIONS ****************/
    /****************************************************************
    * Sets numerator value for fraction
    * @parm int for numerator
    * @pre none
    * @post sets numerator to a
    ****************************************************************/
    void setName(string);

    /****************************************************************
    * Sets denominator value for fraction
    * @parm int for denominator
    * @pre none
    * @post sets denominator to b
    ****************************************************************/
    void setUnitPrice(double);

    /****************************************************************
    * Sets denominator value for fraction
    * @parm int for denominator
    * @pre none
    * @post sets denominator to b
    ****************************************************************/
    void setQty(int);

    /****************** CONSTANT MEMBER FUNCTIONS ******************/
    /****************************************************************
    * Returns numerator of the fraction
    * @pre none
    * @post value returned is the numerator of the fraction
    ****************************************************************/
    string getName() const
      { return name; }

    /****************************************************************
    * Returns denominator of the fraction
    * @pre none
    * @post value returned is the denominator of the fraction
    ****************************************************************/
    double getUnitPrice() const
      { return unitPrice; }
    
    /****************************************************************
    * Returns denominator of the fraction
    * @pre none
    * @post value returned is the denominator of the fraction
    ****************************************************************/
    int getQty() const
      { return qty; }

    friend istream& operator>> (istream&, item&); // Input operator
    friend ostream& operator<< (ostream&, const item&); // Output operator
    bool operator== (const item& aBag); // Sum operator
};

#include "item.cpp"
#endif
