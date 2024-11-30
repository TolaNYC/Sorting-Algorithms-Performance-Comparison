# Sorting-Algorithms-Performance-Comparison
Program that compares the performance of different sorting algorithms for different array lengths and data arrangments.
----------------------------------------------------------------------------
  The classic question “Which sorting algorithm is faster?” does not have an
   easy answerwer. The speed of a sorting algorithm can depend on many factors,
   such as the type of elements that are sorted, the environment where the
   sorting is done and how the elements are distributed.
  For example, sorting an array of 100 integers can be very different from
   sorting a large database; sorting a linked list can be different from
   sorting an array. Often, a particular algorithm is fast in some cases
   and slow in other cases.
  This project will provide an opportunity to implement and analyze various
   sorting algorithms.
  
  SPECIFICATIONS
  -------------------------------------------------------------------
  Write a program to compare the relative performance of different sorting
   algorithms on datasets containing  integers. Ultimately, the data should
   be sorted in ascending order. Your sorting algorithms should use arrays.
  Test your program on two different array sizes : 100 and 1000.
  Use the following random number distributions :
  a) Completely random
  b) Almost sorted in ascending order ( about 90% of items are in increasing
   order, 10% are random)
  c) Almost reversed -  same as b) but in reverse order
  d) Array is sorted except for the last 10%
  You should include the following sorting algorithms Feel free to place all
   of these in the same file. This is an analysis problem, not a structured
   software solution.
  •Selection Sort
  •Insertion Sort
  •Heap Sort
  •Merge Sort
  •QuickSort
  To measure the performance of the various sorting routines, count the
   number of comparisons and swaps required to achieve the desired ascending
   sorted order. You will be required to perform this analysis for all
   sorting routines for the datasets. Be sure to measure compares as
   occurrences in each algorithm where array elements themselves are compared.
  You should utilize global variables as counters. This is required for the
   recursive algorithms. Place all functions in one file, if necessary. For
   counting the comparisons, consider each place in each algorithm where an
   array element is compared to another. Swaps in the algorithms should utilize
   an included function swap(). Be sure to utilize two separate counters; one
   for total swaps and one for total comparisons.
   
  Deliverables
  •Source code.
  •A summary table that describes the results of the experiment, along with a
   summary statement highlighting your conclusions from the results.
   ----------------------------------------------------------------------
