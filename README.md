/* 
My attempt of this project Idea I found on Reddit
*/



Here’s something that I’ve posted in the past. It’s intended as a gentle introduction in some of the wider issues when writing C code.

The requirements are simple so you focus on learning the language itself rather than trying to understand the actual requirements of the task.

Hope it helps.

- start by creating an array and store 1000 random double values in it
- write code to calculate the min, max and average value
- now write some code to sort the array
- now move those 4 functions (min, max, average, sort) into separate .c files. 
	This exposes you to thinking about data hiding (ie, not exposing the array publicly to other C files). 
	This will expose you to the fact that C doesn’t have scope keywords like private, public, protected. 
	It also expands the project and opens up the need to understand .h files and (if you’re not using an IDE) you need to understand how to compile and link multiple files to generate an executable - on Linux, 
	this would be by using makefiles.
- now change the array size to 500 million. This will compile but in all likelihood will crash (or segfault) when you run it. 
	This exposes you to heap and stack (c arrays are on the stack and the array is now too big to fit on the stack). You’ll need to move the array to the heap and deal with malloc/calloc. 
	This will also expose you to pointers.
- you can put timer code around each of the 4 operations and play with various compiler options to improve the performance.
- Also turn on various compiler warnings (if using gcc or clang, -Wall and -Werror). You’ll have hours of fun fixing up “problems” in your code.
- if you feel adventurous, move the 4 operations into separate threads. 
	This will expose you to multithreaded issues like sorting the array while trying to find the average (ie you need to protect the array using some form of mutex or semaphore). 
	The min, max and average can all run in parallel (they don’t modify the array) but the sort operation needs sole access to the array. 
	This is useful to understand because it forms the basis of the Rust language’s ownership model.
