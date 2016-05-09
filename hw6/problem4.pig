SET default_parallel 3;
items = LOAD '/user/input2/web-Google.txt' USING PigStorage('\t') AS (from:int, to:int);
groupTo = GROUP items BY to;
count = FOREACH groupTo GENERATE group as id, COUNT(items);
store count into 'problem4_out';
