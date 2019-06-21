#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
   //head initially is a null pointer
   std::shared_ptr<Node> head;
   std::shared_ptr<Node> tail;

   //size of list is 0
   listSize = 0;
}

LinkedList::~LinkedList(){

   std::shared_ptr<Node> tail;
   clear();
}

//returns the size of the list
int LinkedList::size()
{
   return listSize;
}

void LinkedList::clear()
{
   //confirms that there are nodes in the list
   if (listSize!=0)
   {
      //otherwise sets the parameters to clear the list
      int count = 1;
      std::shared_ptr<Node> counter = head;

      //iterates through the list
      while(count<=listSize)
      {
         //stores the address of the next node
         counter=head->next;
   
         //moves onto the next
         head = counter;
         count++;
      }
      listSize=0;
   }
}

//adds a node at the nth(i) node
//Note that i must be greater than 0, or less than equal to
//the size of the linked list. Any variable outside of that
//range will have unpredictable results.
void LinkedList::addAt(int i, int data)
{
   //if the first node is requested
   if (i == 0)
      addFront(data);
   //if the back node is requested
   else if (i==(size()))
      addBack(data);
   else {

      //otherwise gets the node before the requested node
      std::shared_ptr<Node> node = getNode(i);
      
      //creates a new node with a pointer to the next node
      //from the retrieved node
      std::shared_ptr<Node> newNode (new Node(data, node));

      //increases the list size by 1
      ++listSize;

      //changes the pointer of the retrieved node to the new node
      node->next = newNode;
   }
}

//removes the nth(i) node
//Note that i must be greater than 0, or less than equal to
//the size of the linked list. Any variable outside of that
//range will have unpredictable results.
void LinkedList::deleteAt(int i)
{

   //if the first node is requested
   if (i==0)
     removeFront();

   //if the last node is requested (due to the need for the back pointer)
   else if(i==(size()-1))
     removeBack();
   else {
     //retrive the node prior to this selected node
     std::shared_ptr<Node> node = getNode(i);

     //sets the pointer to the node after the node to be deleted
     node->next = node->next->next;

     //decreases the list size by 1
     --listSize;
   }

}

//private method to get the node at the nth(i) position
std::shared_ptr<Node> LinkedList::getNode(int i)
{

   //sets up the search variables
   bool found = false;
   int count = 0;
   std::shared_ptr<Node> counter = head;

   //iterates through the list
   while(!found)
   {
      //if the node is equal to 1 less than the request
      if(count == (i-1))
      {
         //raises the found flag
         found = true;
      } else {
         
         //otherwise gets the next node
         count++;
         counter = counter->next;
      }
   }

   return counter;
}

//gets the data from the nth (i) node
//Note that i must be greater than 0, or less than equal to
//the size of the linked list. Any variable outside of that
//range will have unpredictable results.
int LinkedList::get(int i)
{
   //if the contents of the first node is requested
   if(i==0)
   {
      i = head->data;

   } else {

      //otherwise gets the node before the requested node
      std::shared_ptr<Node> counter = getNode(i);

      //retrieves the data from the requested node
      i = counter->next->data;
   }
  
  return i;
}

void LinkedList::addFront(int data)
{

   //create a new node and the node points to the head
   std::shared_ptr<Node> node (new Node(data,head));

   //The head now points to this node.
   head = node;

   //if the tail points to null, then this will be the first node
   //so the tail will point to this node
   if(tail == nullptr)
     tail = node;

   //the size of the list is increased by one
   listSize++;

}

void LinkedList::addBack(int data)
{
   //create a new node with the data and nullptr
   std::shared_ptr<Node> node (new Node(data,nullptr));

   //checks to see if there are any nodes in the list and if not
   //adds this node as the head and as the tail
   if(listSize == 0)
   {
     head = node;
     tail = node;
   }
   else
   {
     //otherwise points the tail to the new node
     tail->next = node;

     //and makes the new node the tail
     tail = node;
   }

   //increases the size of the list
   listSize++;
}

void LinkedList::removeFront()
{
	//checks to see if the size of the list is greater than 0
	//and executes the function if it is
	if(size()>0)
	{

	    //shifts the head to the next in line
	    head = head->next;

	    //decreases the size of the list by one.
	    listSize--;
	}
}

void LinkedList::removeBack()
{
	//checks to see if the size of the list is greater than 0, and executes the function
	//if it is
	if(size()>0)
	{
	   //creates a temporary pointer
	   std::shared_ptr<Node> node = head;

	   //iterates through the list until it finds the node before the tail
	   while(node != tail)
	      node = node->next;
  
	   //sets the previous node as the new tail
	   tail = node;

       //sets the next pointer on node to null
       node->next = nullptr;
	
	   //decreases the size of the list by one
	   listSize--;
	}
}
