# 219351_homework
219351 Web Application Development Homework

Code
---
- [Homework 3 - Message Passing Programming](hw3)
- [Homework 5 - MapReduce Hadoop](hw5)
- [Homework 6 - PIG](hw6)

Homework 3
---------
Message Passing Programming with C (bubblesort MPI)

**Complie**
```bash
mpicc bubble_sort_mpi.c -o bubble
```
**Execute with np = 2**
```bash
mpiexec -np 2 ./bubble 
```
**Execute with np = 4**
```bash
mpiexec -np 4 ./bubble 
```

Homework 5
---------
Sequential vs MapReduce (Use [web-Google.txt](https://snap.stanford.edu/data/web-Google.html) as the input file)

**Problems**

 - **5. Sequential** - for every given node, how many nodes contains links to it
 - **6. MapReduce** - for every given node, how many nodes contains links to it
 - **7. Sequential** - for every given node, say X, a list of nodes that X can reach in two links
 - **8. MapReduce** - for every given node, say X, a list of nodes that X can reach in two links

Homework 6
---------
[PIG](https://en.wikipedia.org/wiki/Pig_(programming_tool)) - MapReduce (Use [web-Google.txt](https://snap.stanford.edu/data/web-Google.html) as the input file)
 - **4.** - for every given node, how many nodes contains links to it
 - **5.** - for every given node, say X, a list of nodes that X can reach in two links

Member
---
Fullname | StudentID
------------ | -------------
Supanut Apikulvanich | 5610501016
Aphichan Chaiyuttasart | 5610502888
Manatsawin Hanmongkolchai | -
Nut Kaewnak | -
Piyaphat Tulakoop | -

