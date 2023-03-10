# Brent-Algorithm
Your task is to write a class which stores numbers using Brent’s Method. You are provided with a header file which has the class definition inside; a source file which you are supposed to complete; a main file and an input file in order to test your functions. Please test your code by using the main file and input file, and be sure that your functions work well with the given inputs. You can change the inputs and the table size in the main in order to test your work with different inputs.

You have four member functions to implement:

Constructor for the class: The parameter passed to the constructor represents the desired size of the hash table. Write necessary code to accommodate this.

insert: The parameter passed is the value to be inserted into the hashtable.Write necessary code to insert this value to the hash table using Brent logic.

Find_num_probes: This function’s job is to find out how many ‘hops’ are required to find a certain key inside the hash table. Note that the number of probes for a given key must be at least 1 (i.e. if you find the key directly without following any links, the result should be 1). The parameter passed is the key to be searched for in the hash table. You can assume that the searched key always exists in the table.

find_average_num_probes: Computes average number of probes required to find a key in this table. Find how many probes it takes to find all keys inside the hash table, and divide it by the number of valid entries.

Important: Use imin when selecting which entry to move if there are multiple minimum i+j<s.

<hr>

You can compile this project by typing below code in your terminal

<img width="164" alt="Ekran Resmi 2023-01-11 21 38 42" src="https://user-images.githubusercontent.com/79373487/211914791-4f6acaaa-e31e-4c76-8f8c-b4f215ebe992.png">

<b>OUTPUT: 

<img width="164" alt="Ekran Resmi 2023-01-11 21 38 14" src="https://user-images.githubusercontent.com/79373487/211915043-5c94cd3b-4334-4d3b-bea8-903ea73c1ab5.png">
