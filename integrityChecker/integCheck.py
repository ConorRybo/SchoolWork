'''
Conor Rybacki
02.12.2020
CSC3810-01
Information Security

File integrity checker
Python 3.7.3
'''
#importing necessary things
import hashlib
from os import path

if path.exists('integrity'):    #if an integrity file exitst...
    with open('integrity', 'r') as inFile, open('target.txt', 'r') as tFile: #opening files
        if inFile.read() == (hashlib.sha256(tFile.read().encode()).hexdigest()):    #checking if the hash in the integrity file is the same 
            print('\nIntegrity of file confirmed; Hashes match\n')                  #and printing necessary response
        else:
            print('\nWarning: Check failed!\n')
else: #if the integrity file doesn't exits
    with open('integrity', 'w+') as inFile, open('target.txt', 'r') as tFile: #creating integrity file
        print('\nIntegrity file not found; File being created...')            #hasing target file and writing to integrity file
        inFile.write(hashlib.sha256(tFile.read().encode()).hexdigest())
        print('Done!\n')