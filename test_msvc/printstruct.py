#!/usr/bin/python

# Copyright (c) 2019 Andreas Jung
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

############################################################################################################################

import sys
import string

print ("struct", sys.argv[1])
print ("{")

countfields = int(sys.argv[2])

for i in range (0, countfields ):
    if (15 == (i % 16)):
        print("int field", i, ";", sep='') 
    else:
        print("int field", i, ";", sep='', end='') 
print()
print ("};")


