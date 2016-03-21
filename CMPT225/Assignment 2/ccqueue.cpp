//
//  ccqueue.cpp
//  A2
//
//  Created by Mackenzie Higa on 2016-02-01.
//  Copyright © 2016 Mackenzie Higa. All rights reserved.
//
#include <iostream>
#include "ccqueue.h"


//private:
//DLinkedList<Ticket> tickets; // collection of ticket objects
//unsigned int maxticketid;    // largest-valued ticketid. Used to generate new tickets to insert



// default constructor
// maxticketid begins at 0
// note that tickets does not need to be re-declared

//ticket attributes (Below)

//unsigned int ticketid;
//string customername;
//string complaint;

CCQueue::CCQueue()
{
    maxticketid = 0;
}

// MUTATORS

// enqueues a new ticket at the back of the ticket queue and returns true
// ticketid is assigned automatically as 1+maxticketid if enqueueing is possible
// does not enqueue and returns false if either parameter is empty string
// POST:  new ticket with supplied parameters is added to back of tickets,
//        maxticketid is incremented
// PARAM: customer and complaint fields to pass to Ticket constructor
bool CCQueue::Add(string customer, string complaint)
{
    if(customer=="" || complaint == "")
        return false;
    
    Ticket new_one(maxticketid+1, customer, complaint);
    tickets.InsertBack(new_one);
    
    maxticketid++;
    
    return true;
}

// removes and returns an item from the front of the ticket queue
// throws a logic_error if the ticket queue is empty
// POST:  first item of the ticket queue is removed
Ticket CCQueue::Service()
{
    if(tickets.Size()==0)
        throw logic_error("ticket queue is empty");
    
    Ticket first_complaint = tickets.RemoveAt(0);
    
    return first_complaint;
}

// moves an item towards the front of the queue by 1 position and returns true
// returns false if supplied index is 0 (first item) or outside the list boundaries
// POST:  DLinkedList items at position and position-1 swap spots in the list
// PARAM: initial index of item to move up
bool CCQueue::MoveUp(int index)
{
    if( index<=0 || index >= tickets.Size() )
        return false;
    
    Ticket removed_item = tickets.RemoveAt(index);
    tickets.InsertAt(removed_item, index-1);
    
    return true;
    
}

// moves an item towards the back of the queue by 1 position and returns true
// returns false if supplied index is the last item or outside the list boundaries
// POST:  DLinkedList items at position and position+1 swap spots in the list
// PARAM: initial index of item to move down
bool CCQueue::MoveDown(int index)
{
    if( index<0 || index >= tickets.Size() )
        return false;
    
    Ticket removed_item = tickets.RemoveAt(index);
    tickets.InsertAt(removed_item, index+1);
    
    return true;
}
// ACCESSORS

// returns the number of tickets
int CCQueue::Size() const
{
    
    return tickets.Size();
    
}

