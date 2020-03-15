The purpose of this program is to check the integrity of a file. The program will take a file, target.txt in this case,
and perform a sha256 hash on said file. It then will take this hash and store it in a file called integrity. If an 
integrity file already exists in the working directory, then the program will compare the hashed file against the hash 
located in the integrity file. The program will then print an appropriate respose according to the result. 
