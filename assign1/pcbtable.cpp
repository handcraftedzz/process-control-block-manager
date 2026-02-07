/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author Andrew M
 * @brief This is the implementation file for the PCBTable class.
 * //You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
 * // Remember to add sufficient comments to your code
 */

#include "pcbtable.h"

/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) //resize member funciton of the vector class to make room for the parameter's size
{
   this->pcbVec.resize(size);
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable() 
{
   // TODO: add your code here
   
  for (PCB* p : pcbVec) //automatic for lop, deletes pcb one by one until there's none left. 
  {
    delete p;//gone from heap
  }

}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
PCB* PCBTable::getPCB(unsigned int idx) 
{
   PCB* returning = nullptr; //var goes to the return data type

    if (idx >= pcbVec.size()) //check if the index will go out of bounds, if it does
    { 
        return nullptr;
    }

    /*
   if (pcbVec[idx] == nullptr) //if the pcb at this index empty, set the variable to nullptr
   {
      returning = nullptr;
   }
    */
   else //otherwise, good
   {
       returning = pcbVec[idx];
   }

    return returning;
}

/**
 * @brief Add a PCB pointer to the PCBTable at index idx.
 *
 * @param pcb: the PCB to add
 */
void PCBTable::addPCB(PCB *pcb, unsigned int idx) 
{
    // TODO: add your code here
    // Add a PCB pointer to the PCBTable at index idx.

    if (idx >= pcbVec.size())
    {
        return;
    }

   // if (pcbVec[idx] != nullptr)
    //{
     // /  //delete pcbVec[idx];
       // return;
    //}

    /*
    else if (idx < pcbVec.size())
    {
        pcbVec[idx] = pcb;
    }
    */

   pcbVec[idx] = pcb;
}
