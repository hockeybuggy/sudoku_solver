# A C sudoku solver 
### by Douglas Anderson

This was something I started to write in the summer of 2012. The C program takes
in a string representing a sudoku puzzle. It should output a solved representation.

./bin/solver [puzzle string]
- Input  : a 81 character string x. where x[i]is an element of {0123456789}
    - Zero denotes a unfilled cell
- Output : a 81 character string y. where y[i] is an element of {123456789}

### Usage:
The program is simple enough to test.

        $ make
        $ ./bin/solver [puzzle_string]

Example puzzle

        $ ./bin/solver 200000060000075030048090100000300000300010009000008000001020570080730000090000004

To make html document from documentation markdown

        $ make doc

### Testing:
Currently test are very lacking. It only tests valid input. 
There are some test files such as:

once_3.py (solves 3 puzzles once):

    $ ./test/once_3.py
    $ cat test/log/once_3.txt

test.py (which solves 244 each problem 3 times each and takes the mean):

    $ ./test/test.py
    $ tail -f test/log/test.txt

test_3.py (3 games, 3 times and takes mean)

once.py (244 games once)

### Todo:
- Input checking
- Output checking
- Improve tests
- Test v2.0
- Improve documentation
- Improve algorithm
    - Count number of occupied cells in rows, cols, and boxes
    - Other?
- Use redis to track solves
- Find multithreading solution
- Improve Output

### Licanse:
The code is under the MIT license. This permissive license is included to
encourage sharing of any modifications.


Please comment or contribute. I would love and greatly appreciate feedback!

