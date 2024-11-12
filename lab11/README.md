# Valgrind Lab Results

## Performance Timing

1. Results for matrix size 500

```
v1 average is: 50.47; time is 0.001313
v2 average is: 50.47; time is 0.001159
```

2. Results for matrix size 1000

```
v1 average is: 50.50; time is 0.004269
v2 average is: 50.50; time is 0.003811
```

## Valgrind Caching

1. Output for matrix size 500

```
==27147== Command: ./avg_matrix 500
==27147== 
--27147-- warning: L3 cache found, using its data for the LL simulation.
v1 average is: 50.59; time is 0.018306
v2 average is: 50.59; time is 0.021814
==27147== 
==27147== I refs:        28,137,756
==27147== I1  misses:         1,496
==27147== LLi misses:         1,472
==27147== I1  miss rate:       0.01%
==27147== LLi miss rate:       0.01%
==27147== 
==27147== D refs:        14,397,431  (11,603,896 rd   + 2,793,535 wr)
==27147== D1  misses:        49,801  (    33,535 rd   +    16,266 wr)
==27147== LLd misses:        17,263  (     1,084 rd   +    16,179 wr)
==27147== D1  miss rate:        0.3% (       0.3%     +       0.6%  )
==27147== LLd miss rate:        0.1% (       0.0%     +       0.6%  )
==27147== 
==27147== LL refs:           51,297  (    35,031 rd   +    16,266 wr)
==27147== LL misses:         18,735  (     2,556 rd   +    16,179 wr)
==27147== LL miss rate:         0.0% (       0.0%     +       0.6%  )
```

2. Output for matrix size 1000

```
==27050== Command: ./avg_matrix 1000
==27050== 
--27050-- warning: L3 cache found, using its data for the LL simulation.
v1 average is: 50.55; time is 0.0708
v2 average is: 50.55; time is 0.089054
==27050== 
==27050== I refs:        111,586,442
==27050== I1  misses:          1,482
==27050== LLi misses:          1,473
==27050== I1  miss rate:        0.00%
==27050== LLi miss rate:        0.00%
==27050== 
==27050== D refs:         57,239,320  (46,166,815 rd   + 11,072,505 wr)
==27050== D1  misses:      1,254,974  ( 1,191,615 rd   +     63,359 wr)
==27050== LLd misses:         64,326  (     1,084 rd   +     63,242 wr)
==27050== D1  miss rate:         2.2% (       2.6%     +        0.6%  )
==27050== LLd miss rate:         0.1% (       0.0%     +        0.6%  )
==27050== 
==27050== LL refs:         1,256,456  ( 1,193,097 rd   +     63,359 wr)
==27050== LL misses:          65,799  (     2,557 rd   +     63,242 wr)
==27050== LL miss rate:          0.0% (       0.0%     +        0.6%  )
```

## Detailed Analysis Results

1. V1 Analysis
- D1mr: 62,877

2. V2 Analysis
- D1mr: 1,125,997

The V1 traversal method works much better because of how it access the memory similarly to how the caching system expects it to: continguously.

## Reflection Questions

1. As the matrix size increases, the cache misses during the column-major access increases exponentially.
2. The data made the slow speeds and optimization failures of column-major data access obvious.
3. In that case, one should prioritize row-major data access
4. Knowledge of how the cache system works helps to focus code toward accessing data as contiguously and predictibly as possible.
