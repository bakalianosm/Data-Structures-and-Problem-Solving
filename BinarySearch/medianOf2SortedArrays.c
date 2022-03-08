
#define MIN_INF -9999999
#define MAX_INF 9999999
#include <stdio.h>


double avg(int num1, int num2);
double max(int num1, int num2);
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size);


int main(void)
{
   
   int arr1[] = {1,3};
   int arr2[] = {2};

   printf("Median is %f\n", findMedianSortedArrays(arr1, sizeof(arr1)/sizeof(int), arr2, sizeof(arr2)/sizeof(int)));

}


double avg(int num1, int num2)
{
   double sum = num1 + num2;
   if (sum == 0)
      return 0;

   double average = (double)(sum / 2);
   return average;
}

double max(int num1, int num2)
{
   int ret = (num1 > num2) ? num1 : num2;
   return ret;
}
double min(int num1, int num2)
{
   int ret = (num1 < num2) ? num1 : num2;
   return ret;
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{

   // consider first the array with the least items
   // if(nums1Size ==0 && nums2Size ==0) { printf("empty\n"); return 0;  }
   // if( (nums1Size ==1) && (nums2Size ==1)) {
   //     printf("2 arrays that contain 1 item\n");
   //     return avg(nums1[0], nums2[0]);
   // }
   if (nums1Size > nums2Size)
      findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

   // going to apply binary search on the smallest array,let nums1

   // binary search bounds
   int start = 0;
   int end = nums1Size;
   printf("nums1size = %d\n", nums1Size);
   // do binary search
   while (start <= end)
   {

      // where to partition each array
      int partitionA = (end + start) / 2;
      int wholeItems = (nums1Size + nums2Size + 1) / 2;

      // partitionA + partitionB = (x+y+1)/2 => partitionB = (x+y+1)/2 - partitionA
      int partitionB = wholeItems - partitionA;

      int maxLeftA = (partitionA == 0) ? MIN_INF : nums1[partitionA - 1];
      int minRightA = (partitionA == nums1Size) ? MAX_INF : nums1[partitionA];

      int maxLeftB = (partitionB == 0) ? MIN_INF : nums2[partitionB - 1];
      int minRightB = (partitionB == nums2Size) ? MAX_INF : nums2[partitionB];

      if ((maxLeftA <= minRightB) && (maxLeftB <= minRightA))
      {
         return avg(max(maxLeftA, maxLeftB), min(minRightA, minRightB));
         // if ((nums1Size + nums2Size) % 2 == 0)
         // {
         //    return ((double)max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2;
         // }
         // else
         // {
         //    return (double)max(maxLeftA, maxLeftB);
         // }
      }
      else if (maxLeftA > minRightB)
      {
         end = partitionA - 1;
      }
      else
      {
         start = partitionA + 1;
      }
   }
   return 0;
}
