# Make file for HW3, CSCI2270
# WRITTEN BY: Elizabeth White
#
# This makefile is used as follows to regenerate files for the BigNum program:
#   make BigNum.o   --  Regenerates BigNum.o by compiling
#   make TaylorsTest.o   --  Regenerates TaylorsTest.o by compiling
#   make TaylorsTest --  Regenerates the executable TaylorsTest file by compiling
#   make              --  Same as "make TaylorsTest" (since TaylorsTest is 
#                     --  the 1st target)
#
# Two special targets may also be used with this makefile:
#   make all          --  Regenerates all files listed above
#   make clean        --  Erases all files listed above
#
# All compilations occur with -Wall and -g.
# The clean command uses rm to remove all expendable files.

# define the different outputs of all g++ commands
# on Ubuntu, the .exe suffix disappears
EXPENDABLES = BigNum.o TaylorsTest.o TaylorsTest

# make all is listed first, which lets you type "make" to recompile 
# anything that has changed in either your class, your test code, 
# or my test code.
all:
	@make $(EXPENDABLES)

# this compiles your test program and your BigNum class together
TaylorsTest:  TaylorsTest.o BigNum.o
	g++ -std=c++0x -Wall -g BigNum.o TaylorsTest.o -lm -o TaylorsTest

# this compiles your BigNum class, which isn't executable (no main)
BigNum.o: BigNum.h BigNum.cxx
	g++ -std=c++0x -Wall -g -c BigNum.cxx -o BigNum.o

TaylorsTest.o: BigNum.h TaylorsTest.cxx
	g++ -std=c++0x -Wall -g -c TaylorsTest.cxx -o TaylorsTest.o

# this deletes all the output files
clean:
	rm $(EXPENDABLES)
