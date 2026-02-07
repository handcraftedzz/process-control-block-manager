#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue()  
 {
     for (int j = 0; j < 50; j++) //every single head of the linked list (bucket ) needs to get set to nullptr before it can go to their ready and running
     //states
     {
        queue[j] = nullptr;
     }

     max = -1;  //intilaized my member fields here in the constructor, max to -1 since the queue is empty. -1 is temp.

     counter = 0; //0 pcbs so far, 
 }

/**
 *@brief Destructor
*/
ReadyQueue::~ReadyQueue() 
{
    //manually delete each one at each index;

    for (int i = 49; i >= 0; i--)
    {
        Node* head = queue[i]; //traversal is needed in c++ when working with LINKED lists. the readyqueue class doesn't own the pcb class
        //so accesing the pcbs via the linked list nodes is how it's done.
        while (head != nullptr) //while loop keeps on going until head points to nothing in heap.
        {
            Node* nextNode = head->next; //nextNode is a node object that points to the memory address of the next head.
            delete head; //delete in order to free up memory that was dyncamilly allocated in headp.
            head = nextNode; //update the head now, 
        }
        queue[i] = nullptr;
    }

    max = -1;
    counter = 0;    


}

/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) 
{

    pcbPtr->setState(ProcState::READY); //setting state now via member function
    int num = pcbPtr->priority - 1;

    if (num < 0 || num >= 50) //in case the index is out of bounds, u only acccess valid indices for the array of nodes
    {
        return;
    }


    Node *addHead = new Node;
    addHead->process = pcbPtr; //have addhead proces point to the the memory address of pcb ptr.
    addHead->next = queue[num]; //make sure this next is updated before this step is forgotten
 
    queue[num] = addHead; //now the index has the head's memmory address (node(s))


    counter++;
    if (num > max)
    {
        max = num;
    }
    // When adding a PCB to the queue, you must change its state to READY.
    //setting the parameter's state  (pcbPtr) to be ready. not NEW anymore. 
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() 
{
    // When removing a PCB from the queue, you must change its state to RUNNING.

    PCB* returning = nullptr; //initiliazed to nullptr, the pcb pointer

    if (this->counter == 0 || this->max == -1) //if the counter is 0, that means there are 0 pcbs in the queue
    ///if the max priority is -1, that means there is no pcb with a priority. 
    {
        return nullptr;
    }
    else
    {

        while (max >= 0 && queue[max] == nullptr) //while you don't come across an already filled node., keep looking . 
        {
            max--;
        }

        if (this->max < 0)
        {
            return nullptr;
        }

        Node* head = queue[max];
        returning = head->process; //similar to previous function

        queue[max] = head->next;
        delete head;

        returning->setState(ProcState::RUNNING);
        counter--;

        //now time for the max to get updated if the head of the linked list got removed
         while (max >= 0 && queue[max] == nullptr)
         {
            max--;
         }
    }

    return returning;
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() 
{
    //private data member counter in header says counter has the number of pcbs saved

    
    return this->counter;
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() 
{
    for (int i = max; i >= 0; i--)
    {
        Node* head = queue[i]; //start from the hgihest priority and go down to the lower ones.
        while (head != nullptr)
        {
            head->process->display(); //use the display function to display all more smoothyl.
            head = head->next; //same as updating the index, but for nodes
        }
    }


}