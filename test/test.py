#! /usr/bin/python
import os
import subprocess
import time

PROJECTDIR =  os.path.abspath( os.path.join(os.path.dirname( os.path.realpath(__file__)), os.path.pardir)) + "/"

SOLVER = PROJECTDIR + "bin/solver"
INPUT = PROJECTDIR + "test/input/lotsOfGames.txt"
LOG = PROJECTDIR + "test/log/test.txt"
AVGOF = 3

r = open(INPUT, 'r')
l = open(LOG, 'w')
n = open("/dev/null", 'w')

i = 0
line = r.readline()
while line:
    i += 1
    l.write("game:" + str(i))
    solved = subprocess.call([SOLVER, line])
    for j in range(AVGOF):
        before = time.time()
        subprocess.call([SOLVER, line], stdout=n)
        after = time.time()
        l.write("\tattempt " + str(j) + ": " + str(after - before) )
    l.write("\tsolved:" + str(solved) + "\n")
    l.flush()
    line = r.readline()

r.close()
l.close()
n.close()
