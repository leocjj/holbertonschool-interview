# 0x12. Advanced Binary Search


You may have noticed that basic binary search does not necessarily return
the index of the first value in the array
(if this value appears more than once in the array).
In this exercise, you’ll have to solve this problem.
Write a function that searches for a value in a sorted array of integers.

* Prototype: int advanced_binary(int *array, size_t size, int value);
size is the number of elements in array
value is the value to search for
Your function must return the index where value is located
You can assume that array will be sorted in ascending order
If value is not present or if array is NULL, your function must return -1
Every time you split the array, you have to print the new array (or subarray)
you’re searching in (See example).

## Coding style tests

[Holberton Betty style test.](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl)



## Author

* **Leonardo Calderon J.** - *Initial work* - [LeoCJJ](https://github.com/leocjj)
2021
