/**
 * Assignment 1: priority queue of processes
 * @file readyqueue.h
 * @author Andrew Mendez
 * @brief ReadyQueue is a queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code
#pragma once

#include "pcb.h"

/**
 * @brief A queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 */


    struct Node { //linked list
        PCB* process = nullptr; //the process object points to a nullptr
        Node* next = nullptr; //the next node
    };



class ReadyQueue 
{
private:
    //an array of linked lists,  counter is for how many pcbs are in a linked list. 
    //for this bucket queue, which index in the queue holds the highest priority, = max.



    int counter; //counts how many pcbs are in the LL.
    int max;    //max = index highest priority in thre queue

    Node* queue[50]; ///a queue of linked lists (bucket queue). the size of the array (50), (for 1-50 in priority) must be known at compilation time
    //(object code) because c++ is an explicit language. likes to know in advance. if i try a variable, a variable in [size] for queue is 
    //calculated at run time. (which happens after compilation time.)

    // choose a data structure for the ReadyQueue. No STL class is allowed.

public:
    /**
     * @brief Construct a new ReadyQueue object
     *
     */
    ReadyQueue();

    /**
     * @brief Destructor
     */
    ~ReadyQueue();

	// You may add additional member functions, but don't change the definitions of the following four member functions.

    /**
     * @brief Add a PCB representing a process into the ready queue.
     *
     * @param pcbPtr: the pointer to the PCB to be added
     */
	void addPCB(PCB* pcbPtr);

    /**
     * @brief Remove and return the PCB with the highest priority from the queue
     *
     * @return PCB*: the pointer to the PCB with the highest priority
     */
	PCB* removePCB();

    /**
     * @brief Returns the number of elements in the queue.
     *
     * @return int: the number of PCBs in the queue
     */
	int size();

     /**
      * @brief Display the PCBs in the queue.
      */
	void displayAll();
};