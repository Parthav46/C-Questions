/**
1.Magnus Carlsen,has finally managed to write a program to solve the N queens problem.
However, his version of the N queens problem is not really all that similar to the classical one.

Recall that in the N queens problem, there is a square chessboard of size NxN.
The goal is to put N queens on the chessboard so that no two queens would be able to attack each other.

In Magnus's version of the problem (which he states to be "much harder" than the original one),
there are K "blocked" squares given on the chessboard. The goal is still the same:
to put N queens on the chessboard such that no two queens would be able to attack each other.
However, there are some differences due to the existence of blocked squares.
First, a queen cannot be put on a blocked square.
Secondly, two queens are considered to be able to attack each other only if there
is no blocked square between them. Finally, there must be exactly one queen on
every column of the board.

Magnus claims that his program solves the above problem very effectively.
He generates some test cases (which his program can solve within minutes) to challenge you.
You know the method Magnus used to generate the test case.
For a given N, Magnus randomly picks a number K between 1 and N2/2 with equal probability.
After that, Magnus picks K blocked squares on the chess board. Any combinations
of K squares can be picked with equal probability.

Write a program that can solve Magnus's test cases within seconds.
*/
