#! /usr/bin/python
import os
import subprocess
import time

PROJECTDIR =  os.path.abspath( os.path.join(os.path.dirname( os.path.realpath(__file__)), os.path.pardir)) + "/"

SOLVER = PROJECTDIR + "bin/solver"
INPUT = PROJECTDIR + "test/input/threeGames.txt"
LOG = PROJECTDIR + "test/log/once_3.txt"

r = open(INPUT, 'r')
l = open(LOG, 'w')
n = open("/dev/null", 'w')

i = 0
line = r.readline()
start = time.time()
while line:
    i += 1
    l.write("game:" + str(i))
    before = time.time()
    solved = subprocess.call([SOLVER, line])
    after = time.time()
    l.write("\tattempt: " + str(after - before))
    l.write("\tsolved:" + str(solved) + "\n")
    l.flush()
    line = r.readline()
end = time.time()
l.write("Total Duration:" + str(end - start) + "\n")

r.close()
l.close()
n.close()
