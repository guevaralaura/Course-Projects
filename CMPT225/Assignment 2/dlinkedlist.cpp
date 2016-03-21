#ifdef _DLINKEDLIST_H_

#include <stdexcept>
using namespace std;

//constructor
template <class T>
DLinkedList<T>::DLinkedList()
{
    size = 0;
    front = NULL;
    back = NULL;
}

// copy constructor, performs deep copy of list elements
template <class T>
DLinkedList<T>::DLinkedList(const DLinkedList& ll)
{
    front=NULL;
    back=NULL;
    size=0;
    this->CopyList(ll);
}




//copy list
template <class T>
void DLinkedList<T>::CopyList(const DLinkedList& ll)
{
    Node<T>* travel;
    for(travel = ll.front ; travel!=NULL ; travel=travel->next)
    {
        this->InsertBack(travel->data);
    }
}



//deconstructor
template <class T>
DLinkedList<T>::~DLinkedList()
{
    this->DeleteList();
    front = NULL;
    back = NULL;
    
}


// helper function for deep delete
// Used by destructor and copy/assignment
template <class T>
void DLinkedList<T>::DeleteList(){
    Node<T>* extra = front;
    
    for(front = front->next; front!=NULL ; front = front->next)
    {
        delete extra;
        extra = front;
    }
    
}


//insert in front
template <class T>
void DLinkedList<T>::InsertFront(T item)
{
    Node<T>* travel = new Node<T>(item);
    
    
    if(front==NULL)
    {
        front = travel;
        back = travel;
        size++;
        return;
    }
    
    front->prev = travel;
    travel->next = front;
    front = travel;
    
    size++;
    
    return;
}

//insert in back
template <class T>
void DLinkedList<T>::InsertBack(T item)
{
    Node<T>* travel = new Node<T>(item);
    
    if(front==NULL)
    {
        front = travel;
        back = travel;
        size++;
        return;
    }

    
    back->next = travel;
    travel->prev = back;
    back = travel;
    
    size++;
    
    
}

//insert at
template <class T>
void DLinkedList<T>::InsertAt(T item, int p)
{
    if(p>size || p<0)
        throw out_of_range("invalid index");
    
    int counter = 0;
    
    
    if(p==0)
    {
        InsertFront(item);
        return;
    }
    
    if(p==size){
        InsertBack(item);
        return;
    }
    
    Node<T>* tmp = new Node<T>(item);
    Node<T>* travel = front;
    
    for(counter=0; travel!=NULL ; travel=travel->next)
    {
        if(p==counter)
        {
            tmp->next = travel;
            tmp->prev = travel->prev;
            travel->prev->next = tmp;
            travel->prev = tmp;
        }
        counter++;
    }
    
    size++;
    return;
    
 
    
}


// Removes and returns an item from position p (0-indexed)
// Throws exception if list is empty or index invalid
template <class T>
T DLinkedList<T>::RemoveAt(int p)
{
    
    if( p > this->Size()-1 || p < 0 )
        throw std::out_of_range ("invalid index");
    
    T data;
    int counter =0;
    Node<T>* travel;
    
    if ( p==0){
        travel = front;
        data = front->data;
        front = front->next;
        delete travel;
        front->prev = NULL;
        size--;
        return data;
    }
    
    if ( p==(size-1)){
        travel = back;
        data = back->data;
        back = back->prev;
        delete travel;
        back->next = NULL;
        size--;
        return data;
    }
    
    for ( travel = front; counter<(size-1); travel = travel->next)
    {
        if(p==counter)
        {
            data=travel->data;
            travel->prev->next = travel->next;
            travel->next->prev = travel->prev;
            delete travel;
            size--;
            return data;
        }
        counter++;
    }
    return data;
}



//gets size
template <class T>
int DLinkedList<T>::Size() const
{
    return size;
}


//find if empty
template <class T>
bool DLinkedList<T>::IsEmpty() const
{
    if(size==0)
        return true;
    
    return false;
}


// Returns existence of item
template <class T>
bool DLinkedList<T>::Contains(T item) const
{
    Node<T>* travel;
    
    for(travel = front; travel != NULL; travel=travel->next)
    {
        if(travel->data== item)
            return true;
    }
    
    return false;
    
    
    
    
}

// Returns item at index (0-indexed)
// Throws exception for invalid index
template <class T>
T DLinkedList<T>::ElementAt(int p) const
{
    if(p<0 || p>=size)
        throw std::out_of_range ("invalid index");
    
    T data;
    int count = 0;
    Node<T>* travel;
    for(travel = front; travel!=NULL ; travel = travel->next)
    {
        if(p==count)
            data = travel->data;
        
        count++;
    }

    return data; //should never reach this but makes compiler happy
}


// overloaded assignment operator
// must work in the following cases:
// list2 = list1 -> general case
// list2 = list2 -> should do nothing
template <class T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T>& ll)
{
    
    if(front==ll.front && back==ll.back)
        return *this;
    
    DLinkedList<T>* new_ll = new DLinkedList(ll);

    size = new_ll->size;
    front = new_ll->front;
    back = new_ll->back;
    
    
    return *new_ll;

}

template <class T>
void DLinkedList<T>::RemoveDuplicates()
{
    
    if (front == NULL || back == NULL) {
        return;
    }
    
    Node<T>* travel;
    Node<T>* test;
    int i=0;
    for (travel = front; travel != NULL ; travel = travel->next)
    {
        int count =i+1;
        for(test = travel->next; test!=NULL ; test=test->next)
        {
            if (test->data == travel->data) {
                this->RemoveAt(count);
                count--;
            }
            count++;
        }
        i++;
        
        
    }
}


#endif