


#include <stdio.h>
#include <stdlib.h>


int recursiveBinarySearch(int numArray[], int whichNum, int leftBound, int rightBound);
int iterativeBinarySearch(int numArray[], int whichNum, int arraySize);

int main(int argc, char* argv[]){

   
   int searchNum = atoi(argv[1]);
   int array[] = { 1, 5, 14, 22, 26, 45, 69, 12} ;
   int arraySize = sizeof(array)/sizeof(int);


   if( recursiveBinarySearch(array, searchNum, 0, arraySize) == 1 && iterativeBinarySearch(array, searchNum, arraySize)){
      printf("%d found in the array\n", searchNum);
   }
   else{
      printf("%d not found in the array\n", searchNum);
   }
}



int recursiveBinarySearch(int numArray[], int whichNum, int leftBound, int rightBound){
   

   if(leftBound >= rightBound){
      return 0;
   }
   int mid = 1+ (rightBound - leftBound)/2 ;

   if(numArray[mid] == whichNum){
      return 1;
   }
   if(numArray[mid] > whichNum){
      return recursiveBinarySearch(numArray, whichNum, leftBound, mid-1 );
   }
   else  if(numArray[mid] < whichNum){ 
      return recursiveBinarySearch(numArray, whichNum, mid+1, rightBound );
   }

   return 0;

}

int iterativeBinarySearch(int numArray[], int whichNum, int arraySize){
   int leftBound = 0;
   int rightBound = arraySize;

   int mid ;
   while(leftBound <= rightBound){
      
      mid =1 + (rightBound - leftBound)/2;

      if(numArray[mid] == whichNum){
         return 1;
      }
      else if(numArray[mid] < whichNum){
         leftBound = mid+1;
      }
      else 
         rightBound = mid-1;
   }

   return 0;
}