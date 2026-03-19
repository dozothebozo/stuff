// Towers of Hanoi
// Write a program that prints the moves needed to solve the Towers of Hanoi
// puzzle for n disks.
//
// Rules and Specifications:
// 1) Ask the user for the number of disks at the beginning of the program.
// 2) Assume all disks start on peg 1.
// 3) The goal is to move all disks from peg 1 to peg 3.
// 4) Peg 2 may be used as temporary storage.
// 5) Only one disk may be moved at a time.
// 6) A larger disk may never be placed on top of a smaller disk.
// 7) Print each move in the form:
//    Move disk from peg 1 to peg 3
//
// Suggested Recursive Approach:
// 1) Write a helper function:
//    void hanoi(int from, int to, int n)
// 2) This function should move n disks from peg from to peg to.
// 3) To move n disks:
//    - first move the top n - 1 disks to the temporary peg,
//    - then move the largest remaining disk to the destination peg,
//    - then move the n - 1 disks from the temporary peg to the destination peg.
// 4) The temporary peg is the peg that is neither from nor to.
//
// Base Case Hint:
// 1) When n is 1, just print the single move from the starting peg to the
//    destination peg.
// 2) Otherwise, make the three recursive steps described above.
//
// Example Output:
// Move disk from peg 1 to peg 3
// Move disk from peg 1 to peg 2
// Move disk from peg 3 to peg 2
