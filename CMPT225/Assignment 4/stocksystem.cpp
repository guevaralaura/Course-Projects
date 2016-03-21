//
//  stocksystem.cpp
//  Assign 4
//
//  Created by Mackenzie Higa on 2016-03-18.
//  Copyright © 2016 Mackenzie Higa. All rights reserved.
//
#include "stocksystem.h"


// default constructor;
// begin with a balance of $100,000.00
StockSystem::StockSystem()
{
    balance = 100000.00;
}

// returns the balance member
double StockSystem::GetBalance()
{
    return balance;
}

// Add a new SKU to the system. Do not allow insertion of duplicate sku
bool StockSystem::StockNewItem(StockItem item)
{
    return records.Insert(item);
}

// Locate the item with key itemsku and update its description field.
// Return false if itemsku is not found.
bool StockSystem::EditStockItemDescription(int itemsku, string desc)
{
    StockItem* newitem = new StockItem(itemsku, desc, 0);
    
    StockItem* founditem = records.Retrieve(*newitem);
    
    if(!founditem)
        return false;
    
    founditem->SetDescription(desc);
    
    return true;
    
}

// Locate the item with key itemsku and update its description field.
// Return false if itemsku is not found or retailprice is negative.
bool StockSystem::EditStockItemPrice(int itemsku, double retailprice)
{
    StockItem* newitem = new StockItem(itemsku, "", retailprice);
    
    StockItem* founditem = records.Retrieve(*newitem);
    
    if(!founditem || retailprice<0)
        return false;
    
    founditem->SetPrice(retailprice);
    
    return true;
}

// Purchase quantity of item at unitprice each, to reach a maximum (post-purchase) on-hand stock quantity of 1000.
// Return false if balance is not sufficient to make the purchase,
//   or if SKU does not exist, or if quantity or unitprice are negative.
// Otherwise, return true and increase the item's on-hand stock by quantity,
//   and reduce balance by quantity*unitprice.
bool StockSystem::Restock(int itemsku, int quantity, double unitprice)
{
    
    StockItem* newitem = new StockItem(itemsku, "", unitprice);
    
    if(quantity<0 || unitprice<0 || !(records.Search(*newitem)) )
        return false;
    
    

    StockItem* founditem = records.Retrieve(*newitem); //just looks at SKU ID and points to founditem


    if(founditem->GetStock()+quantity>1000)
        quantity = 1000-founditem->GetStock();

    
    if(quantity*unitprice>balance || quantity<0) //make sure int*double becomes a double
        return false;
    
    founditem->SetStock(founditem->GetStock()+quantity);
    
    balance = balance - (quantity*unitprice);
    
    return true;
    

    
    
    
}

// Sell an item to a customer, if quantity of stock is available and SKU exists.
// Reduce stock by quantity, increase balance by quantity*price, and return true if stock available.
// If partial stock (less than quantity) available, sell the available stock and return true.
// If no stock, sku does not exist, or quantity is negative, return false.
bool StockSystem::Sell(int itemsku, int quantity)
{
    
    StockItem* newitem = new StockItem(itemsku, "", 0);
    if( !records.Search(*newitem) || quantity<0 || records.Retrieve(*newitem)->GetStock()<=0 )
        return false;
    
    newitem = records.Retrieve(*newitem);
    
    if( quantity > newitem->GetStock() )
        quantity = newitem->GetStock();
    
    balance = balance + ( quantity*newitem->GetPrice() );
    
    newitem->SetStock( newitem->GetStock() - quantity);
    
    
    
    return true;
}
















