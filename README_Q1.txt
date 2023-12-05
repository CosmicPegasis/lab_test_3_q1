LAB EXAM 3a Q1
----------------------------

Implementation Details 
------------------------
You have been given a file "q1_3a.cpp" in which you need to provide the implementation for 
the "telephone_line_cost" function. Write your implementation within this function. 
Only this function will be called for testing, although you can declare classes and helper functions 
which you can use within the implementation.

You have been given the adjacency list of the graph as a map<int,map<int,int>> graph. 

For any city with ID u, graph[u] gives the map representing all edges incident on v.
Suppose there is an edge from u -> v with weight w (> 0), then graph[u][v] == w.

Compilation and Running Details 
---------------------------------
To compile your program, use the following commands: 
$ (LINUX)   g++ q1_3a.cpp -o q1.out 
$ (WINDOWS) g++ q1_3a.cpp -o q1.exe

To execute:
$ (LINUX)   ./q1.out 
$ (WINDOWS) q1.exe

You must provide a single number (1-4) as an input to the program via the terminal, this corresponds
to the testcase to run. For example, to run the testcase #1 on Linux, you must write:

$ ./q1.out
>> Enter testcase number (1-3):
$ 1

The details of whether your testcase passed or failed will then be printed to stdout.

Submission Details 
--------------------
You need to submit a single file, q1_3a.cpp on Moodle. 

Testcases Details 
------------------
The testcases can be found in the folder "tests_q1". Here is the format of the cases for your
understanding:
The first line contains |V| |E|
All of the further lines are as follows:
u v w
which represents an undirected edge between u, v with weight w

STL Details
-----------------
A refresher on the syntax of std::map

1. To use a map, we need to include the header file:
    #include<map>

2. Here is how we create a map:
    std::map<int,int> my_map;

3. Insertion into map
    my_map[5] = 0;
    my_map[3] = 7;

4. Deletion from map
    my_map.erase(3);

5. Retrieve value corresponding to key 
    int x = my_map[5];

6. Check if key exists 
    bool exists = (my_map.find("bombay") != my_map.end()) 

7. Iterate over key-value pairs in a map
    for (auto &p : my_map) {
        int first = p.first;
        int second = p.second;
    }