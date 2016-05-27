SET default_parallel 3;
items = LOAD '/user/input2/web-Google.txt' USING PigStorage('\t') AS (from:int, to:int);
groupTo = GROUP items BY to;
groupFrom = GROUP items BY from;
twonode = FOREACH groupTo {
	additional = CROSS groupTo, groupFrom;
	GENERATE UNION(groupTo.items, additional);
};
ILLUSTRATE twonode;
-- store wordcount into 'my_WC_pig_out';
