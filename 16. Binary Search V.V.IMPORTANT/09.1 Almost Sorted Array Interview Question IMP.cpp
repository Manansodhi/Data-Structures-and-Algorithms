// An array of integers is almost sorted if at most one element can be deleted from it to make it perfectly
// sorted, ascending. For example, arrays [2, 1, 7], [13], [9, 2]; and [1, 5, 6] are almost sorted because
// they have 0 or 1 elements out of place. The arrays [4, 2, 1], [1, 2, 6, 4, 3] are not because they have
// more than one element out of place. Given an array of n unique integers, determine the minimum number of
// elements to remove so it becomes almost sorted.


// We could count no of inversions - a[i]> a[i+1] and if Count >=2, return no. of inversions -1
// edge case -0 and 1 inversions only-> return 0;