// An Array is a data structure which can contain any kind of data type but all the 
// elements of an array have to be of same data type.

// If we declare an array inside main():
// int arr[6]; This results in arr containing 6 elements which are garbage values. (initially)

// If we declare an array outside main() i.e. globally:
// int arr[6]; This results in arr containing 6 elements which are all 0. (initially)

// The max size of integer array is 10^6 inside main() and 10^7 globally.

// Where is array stored in the computer memory?
// It is unpredictable. Whenever we declare an array with some size, it basically
// goes into the computer memory, creates a block of that size and the first element
// is stored at some random address location. This address location is not predictable.
// One thing we are sure about is if the address of the first element is x, 
// then the second element will be at x+1, the third element will be at x+2 and so on.
// i.e. contiguous memory location 

// Hence accessing the array by address is not possible, so we access it by index.