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
==30310== Command: ./cachex 500
==30310== 
v1 average is: 50.41; time is 0.009622
v2 average is: 50.41; time is 0.010441
==30310== 
==30310== I refs:        28,137,225
```

2. Output for matrix size 1000

```
==30368== Command: ./cachex 1000
==30368== 
v1 average is: 50.46; time is 0.044459
v2 average is: 50.46; time is 0.038771
==30368== 
==30368== I refs:        111,585,971
```


