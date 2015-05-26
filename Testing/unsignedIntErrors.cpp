/* Find the errors in the following code:

	unsigned int i;
	for (i = 100; i >=0; --i)
	printf("% d\n", i);

   Answer:
   This code has a check for whether i is >= 0. For an 
   unsigned int, this will always be true. This means 
   that there will be an infinite loop. Once the value 
   gets to 0 it will have overflow and go to the greatest
   value. To fix this issue, and print out the numbers from
   100 to 0, one could either change the unsigned int to an
   int (as ints can handle that range without overflowing, 
   or making the check be i > 0 and then printing 0 out outside
   of the loop.
   Another problem is that #include <stdio.h> is necessary
   in order to use printf. 
   Finally, %d is for regular integers, while %u should 
   be used for unsigned ints

*/
