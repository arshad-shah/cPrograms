/*
  @Author: Arshad Shah
  @Date:   Tuesday, October 20, 2020 11:23 AM
  @Email:  C19485866@mytudublin.ie
  @Filename: stack.c
  @Last modified by:   Arshad Shah
  @Last modified time: Tuesday, October 20, 2020 11:24 AM
*/



// Fig. 12.8: fig12_08.c
// A simple stack program

#include <stdio.h>
#include <stdlib.h>

// self-referential structure
struct stackNode {
   int data; // define data as an int
   struct stackNode *nextPtr; // stackNode pointer
};

typedef struct stackNode StackNode; // same as struct stackNode


// prototypes
void push(StackNode* *topPtr, int info);
int pop(StackNode* *topPtr);
void printStack(StackNode* currentPtr);
void instructions(void);

// function main begins program execution
int main(void)
{
   StackNode* stackPtr = NULL; // points to stack top
   int value; // int input by user

   instructions(); // display the menu
   printf("%s", "? ");
   unsigned int choice; // user's menu choice
   scanf("%u", &choice);

   // while user does not enter 3
   while (choice != 3) {

      switch (choice) {
         // push value onto stack
         case 1:
            printf("%s", "Enter an integer: ");
            scanf("%d", &value);
            push(&stackPtr, value);
            printStack(stackPtr);
            break;
         // pop value off stack
         case 2:
            // if stack is not empty
            if (stackPtr != NULL) {
               printf("The popped value is %d.\n", pop(&stackPtr));
            }

            printStack(stackPtr);
            break;
         default:
            puts("Invalid choice.\n");
            instructions();
            break;
      } // end switch

      printf("%s", "? ");
      scanf("%u", &choice);
   }

   puts("End of run.");
}

// display program instructions to user
void instructions(void)
{
   puts("Enter choice:\n"
      "1 to push a value on the stack\n"
      "2 to pop a value off the stack\n"
      "3 to end program");
}

// insert a node at the stack top
void push(StackNode* *topPtr, int info)
{
   StackNode* newPtr = malloc(sizeof(StackNode));//create a node and assign location to pointer

   // insert the node at stack top
   if (newPtr != NULL) {
      newPtr->data = info;
      newPtr->nextPtr = *topPtr;//point to next node
      *topPtr = newPtr;//assign address of new node to new ptr
   }
   else { // no space available
      printf("%d not inserted. No memory available.\n", info);
   }
}

// remove a node from the stack top
int pop(StackNode* *topPtr)
{
   StackNode* tempPtr = *topPtr;
   int popValue = (*topPtr)->data;
   *topPtr = (*topPtr)->nextPtr;
   free(tempPtr);
   return popValue;
}

// print the stack
void printStack(StackNode* currentPtr)
{
   // if stack is empty
   if (currentPtr == NULL) {
      puts("The stack is empty.\n");
   }
   else {
      puts("The stack is:");

      // while not the end of the stack
      while (currentPtr != NULL) {
         printf("%d --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      }

      puts("NULL\n");
   }
}

// return 1 if the stack is empty, 0 otherwise
int isEmpty(StackNode* topPtr)
{
   return topPtr == NULL;
}


/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
