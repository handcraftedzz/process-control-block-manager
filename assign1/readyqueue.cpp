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
     //TODO: add your code here
     for (int j = 0; j < 50; j++)
     {
        queue[j] = nullptr;
     }

     max = -1;//i set index with highest current priority because i don't want any function to maybe accidently think 
     //there is a pcb that has a priority that it doesn't. especially in the beginning when working with memory.
     counter = 0;

 }

/**
 *@brief Destructor
*/
ReadyQueue::~ReadyQueue() 
{
    //TODO: add your code to release dynamically allocate memory
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
    //queue->next = NULL; //common safe c++ practice for linked lists. since my queue (array) was made up of a linked list.
}

/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) 
{
    //TODO: add your code here
    // When adding a PCB to the queue, you must change its state to READY.
     //, wrong add the queue pcbPtr->setState(ProcState::READY); 
    //setting the parameter's state  (pcbPtr) to be ready. not NEW anymore. 

}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() 
{
    //TODO: add your code here
    // When removing a PCB from the queue, you must change its state to RUNNING.

    //you will remove the PCB from the readyqueue. by seeing  which one pcb from the readyQueue has the highest priority. (1-50).


    
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() 
{
    //TODO: add your code here

    /*
    //int sum = 0;
    
    while(queue->next != NULL)
    {
        sum++;
        queue->next = queue->next->next;
    }
    */

    return 1;
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() 
{
    //TODO: add your code here

    /*
    //queue->process->display();
    while(queue->next != NULL)
    {
        queue->process->display();
        queue->next = queue->next->next;
    }
    //queue->process->display();
    */

}