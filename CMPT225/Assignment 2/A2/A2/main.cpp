/*
//
//  main.cpp
//  A2
//
//  Created by Mackenzie Higa on 2016-01-27.
//  Copyright © 2016 Mackenzie Higa. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <string>

#include "ccqueue.h"
#include "dlinkedlist.h"
#include "ticket.h"

using namespace std;

int main(int argc, const char * argv[]) {
    DLinkedList<string> ll;
    
    ll.InsertFront("The Middle");
    ll.InsertBack("The Back");
    ll.InsertFront("The Front");
    Node<string>* travel;

    
    
    DLinkedList<string> kk(ll);
    kk.InsertAt("The Second Middle", 2);
    

    for(travel = ll.front; travel ;travel= travel->next)
    {
        cout << travel->data << endl;
    }
    
    
    cout << "\n" << endl;
    //kk.RemoveAt(3);
    
    for(travel = kk.front; travel ;travel= travel->next)
    {
        cout << travel->data << endl;
    }
    
    cout << "\n" << endl;
    
    
    
    for(travel = kk.front; travel ;travel= travel->next)
    {
        cout << travel->data << endl;
    }
    
    kk = ll;
    
    cout << "\nPutting in operator overloaded LL\n" << endl;
    
    for(travel = kk.front; travel ;travel= travel->next)
    {
        cout << travel->data << endl;
    }
    
    cout << "\nsize of ll = " << ll.size << " and size of kk = " << kk.size << endl;

    return 0;
 
}*/
