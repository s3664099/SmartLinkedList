#include "Node.h"
#include <memory>

class LinkedList {
public:
   LinkedList();
   ~LinkedList();

   int size();
   void clear();
   int get(int i);

   void addFront(int data);
   void addBack(int data);
   void removeFront();
   void removeBack();
   void addAt(int i, int data);
   void deleteAt(int i);

private:
   std::shared_ptr<Node> head;
   std::shared_ptr<Node> tail;
   int listSize;
   std::shared_ptr<Node> getNode(int i);
};
