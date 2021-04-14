rm a.out
gcc -g -Wall A1_PES1201800410.c
# echo -e "\n"
./a.out < menu.dat > codegen.c 
gcc -g -Wall codegen.c 
./a.out < inputsequence.txt

#rm  a.out
