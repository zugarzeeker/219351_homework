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

References
----------
- [Message Passing](http://nartra.blogspot.com/2014/10/parallel-mpi-1-mpi.html)
- [Intro NoSQL](http://www.somkiat.cc/introduction-to-nosql-at-kmitl/)
- [Hadoop Ecosystem](https://thanachart.org/2014/10/18/hadoop-ecosystem-%E0%B8%AA%E0%B8%B3%E0%B8%AB%E0%B8%A3%E0%B8%B1%E0%B8%9A%E0%B8%81%E0%B8%B2%E0%B8%A3%E0%B8%9E%E0%B8%B1%E0%B8%92%E0%B8%99%E0%B8%B2-big-data/)
- [BigData + Hadoop](http://www.siamhtml.com/getting-started-with-big-data-and-hadoop-spark-on-cloud-dataproc/)
- [01219351 WebAppDev](https://www.cpe.ku.ac.th/~paruj/219351)



Member Group 7 
---
Fullname | StudentID
------------ | -------------
Supanut Apikulvanich | 5610501016
Aphichan Chaiyuttasart | 5610502888
Manatsawin Hanmongkolchai | 5610545757
Nut Kaewnak | 5610545676
Piyaphat Tulakoop | 5610545731

