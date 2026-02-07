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
     for (int j = 0; j < 50; j++)
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
        Node* head = queue[i];
        while (head != nullptr)
        {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;
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

    pcbPtr->setState(ProcState::READY);
    int num = pcbPtr->priority - 1;

    if (num < 0 || num >= 50) //in case the index is out of bounds, u only acccess valid indices for the array of nodes
    {
        return;
    }


    Node *addHead = new Node;
    addHead->process = pcbPtr;
    addHead->next = queue[num];
 
    queue[num] = addHead;


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

    PCB* returning = nullptr;

    if (this->counter == 0 || this->max == -1) //if the counter is 0, that means there are 0 pcbs in the queue
    ///if the max priority is -1, that means there is no pcb with a priority. 
    {
        return nullptr;
    }
    else
    {

        while (max >= 0 && queue[max] == nullptr)
        {
            max--;
        }

        if (this->max < 0)
        {
            return nullptr;
        }

        Node* head = queue[max];
        returning = head->process;

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
        Node* head = queue[i];
        while (head != nullptr)
        {
            head->process->display();
            head = head->next;
        }
    }


}