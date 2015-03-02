#!/usr/bin/env python
from puzzle import Puzzle


#TODO include optparse


if __name__ == "__main__":
    puzzle_str = "200000060000075030048090100000300000300010009000008000001020570080730000090000004"
    p = Puzzle(puzzle_str)
    print "Before:"
    print p.pretty_str
    solved = p.solve()
    print "After:"
    print solved.pretty_str

