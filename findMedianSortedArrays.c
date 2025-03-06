double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int i;
  int two = 0;
  int one = 0;
  int lenght = (nums1Size + nums2Size);
  int *merged;

  merged = malloc(sizeof(int) * lenght);
  
  for (i = 0; (one < nums1Size && two < nums2Size) && (i <= lenght/2); i++)
      merged[i] = nums1[one] > nums2[two] ? nums2[two++] : nums1[one++];

  if (i <= lenght/2)
      if (one == nums1Size) // already caught all numbers of nums1
          while (two < nums2Size && i <= lenght)
              merged[i++] = nums2[two++];
       else 
          while (one < nums1Size && i <= lenght)
              merged[i++] = nums1[one++];
  
  if (lenght % 2 == 0) // it has a pair quantify of numbers 
      return (double)(merged[lenght/2] + merged[(lenght/2) - 1]) / 2;
  else 
      return merged[lenght/2];
}