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

**Result**

np | Elapsed time (sec)
------------ | -------------
2 | 8.947105
4 | 4.040553
8 | 2.019532

Homework 5
---------
Sequential vs MapReduce (Use [web-Google.txt](https://snap.stanford.edu/data/web-Google.html) as the input file)

**Problems**

 - **5. Sequential** - for every given node, how many nodes contains links to it
 - **6. MapReduce** - for every given node, how many nodes contains links to it
 - **7. Sequential** - for every given node, say X, a list of nodes that X can reach in two links
 - **8. MapReduce** - for every given node, say X, a list of nodes that X can reach in two links

**Note**
 - **Problem 7** - very slow execute because sequential programming **`O(n^3)`**
 - **MapReduce** - good programming practice for think and code with **faster** performance

Homework 6
---------
[PIG](https://en.wikipedia.org/wiki/Pig_(programming_tool)) - MapReduce (Use [web-Google.txt](https://snap.stanford.edu/data/web-Google.html) as the input file)
 - **4.** - for every given node, how many nodes contains links to it
 - **5.** - for every given node, say X, a list of nodes that X can reach in two links

**Syntax friendly**
```PIG
SET default_parallel 3;
items = LOAD '/user/input2/web-Google.txt' USING PigStorage('\t') AS (from:int, to:int);
groupTo = GROUP items BY to;
count = FOREACH groupTo GENERATE group as id, COUNT(items);
store count into 'problem4_out'
```

**Compare with Java (same problem)** PIG is shorter than Java.
```Java
import java.io.*;
import java.util.*;

public class Problem5{

	public static void main(String[] args) {
		int N = 5105039;
		String path = "../web-Google.txt";
		File file = new File(path);
		String[] data = new String[N];
		String[] id = new String[N];
		int[] num = new int[N];

		try {
			BufferedReader br = new BufferedReader(new FileReader(file));
			String line;
			int i = 0;
			while ((line = br.readLine()) != null) {
				String[] parts = line.split("\t");
				data[i] = parts[1];
				i++;
			}
			br.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Arrays.sort(data);
		int k = 0, count = 0;
		String temp = " ";
		for(int j = 0; j < data.length; j++) {
			if(data[j].equals(temp)) {
				num[k-1] = ++count;
			}
			else {
				count = 1;
				temp = data[j];
				id[k] = data[j];
				num[k] = count;
				k++;
			}
		}
		for(int j = 0; j < k; j++) {
			System.out.println(id[j] + "\t" + num[j]);
		}
	}
}
```

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

