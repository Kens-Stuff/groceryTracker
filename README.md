# groceryTracker
Brushing up on C++: file read/write, custom class, pointers, linked list.

The imagined scanario:
A grocer has a system which tracks what produce are purchased by adding them to a text file as they are checked out.
They want to know how many of each thing was purchased, leading to the following process:
1 Read the text file, counting the instances of each item
2 Write a list of items with their respective counts to a new file as a backup.
3 provide options to view the count for a specific item, all items, or a histogram of all items.

All requirements met
- Costructed a rudementary linked list to track the data.
- Data operations were contained within recursive linked list methods. keeping the code concise.
- a while loop implementation for the menu options with input validation.

Improvemnts
- One recommendation in the scenario was to use a Map container using item names and counts as the key value pairs. an alternate version would be a good exercise.

Challenges
- First versions of the data operation functions were not recursive and involved multiple helper functions.
  Reducing those to a single recursive function was a satisfying challenge.

Transferable skills
- linked list structure
- file read/write operations
- class definitions
- pointer practice

How did you make this program maintainable, readable, and adaptable?
Clear keeping of coding standards and conventions keeps the code readable.
Keeping functions small and clear makes debugging easier.
Use of a custom class makes it possible to reuse that class code in other similar applications.
