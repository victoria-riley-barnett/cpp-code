# Data Structures and Algorithms - Victoria Barnett

## Data

| Sort Algorithm | Array Length | Pass 1 | Pass 2 | Pass 3 | Average array access |
| -------------- | ------------ | ------ | ------ | ------ | ------------------- |
| Bubble Sort    | 8          | 8     | 8     | 8     | 8.0                |
| Merge Sort | 8 | 6 | 6 | 6 | 6.0 |
| Combination Sort | 8 | 8 | 8 | 8 | 8.0 |
| Bubble Sort | 32 | 32 | 32 | 32 | 32.0 |
| Merge Sort | 32 | 18 | 18 | 18 | 18.0 |
| Combination Sort | 32 | 32 | 32 | 32 | 32.0 |
| Bubble Sort | 128 | 128 | 128 | 128 | 128.0 |
| Merge Sort | 128 | 66 | 66 | 66 | 67.0 (I think I have a bug here :( ) |
| Combination Sort | 128 | 128 | 128 | 128 | 128.0 |


## Question 3
The expected efficiency of the combining sort is O(n+k) - making it impractical as it scales poorly if there are lots of repeating values - requiring more and more memory to store the count, it's reproducing the data rather than working with it in place more efficiently.

## Observations: 
* The merge sort is the most efficient of the three algorithms, showing the lowest decrease in array accesses as the int load increased.
* Combination sort and bubble sort performed the same in this case, with the combination sort being the least efficient due to it's O(n) c
* My bubble sort has the same performance as Combination sort - I think I'm not counting it correctly as it uses a while loop.