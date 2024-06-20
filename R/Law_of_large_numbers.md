Law of Large Number
================
2024-06-20

Test the Law of Large Numbers for N random normally distributed numbers
with mean = 0, stdev = 1.

Create an R script that will count how many of these numbers fall in
range \[-1, 1\] and divide by the total quantity of N. Given that E(X) =
68.2%

Check that mean(Xn) -\> E(X) as you rerun your script while increasing N

Sample = 100

``` r
n = 100
count = 0;
# Generate vector of 100 random numbers
for (i in rnorm(n)){ #i in this context is an actual number
  if (i> -1 & i <1){
    count = count +1
  }
}
count/n
```

    ## [1] 0.69

``` r
#compare: 0.682
```

Sample = 1000

``` r
n = 1000
count = 0;
# Generate vector of 100 random numbers
for (i in rnorm(n)){ 
  if (i> -1 & i <1){
    count = count +1
  }
}
count/n
```

    ## [1] 0.671

``` r
#compare: 0.682
```

Sample = 10000

``` r
n = 10000
count = 0;
# Generate vector of 100 random numbers
for (i in rnorm(n)){ 
  if (i> -1 & i <1){
    count = count +1
  }
}
count/n
```

    ## [1] 0.6881

``` r
#compare: 0.682
```

Sample = 1000000

``` r
n = 1000000
count = 0;
# Generate vector of 100 random numbers
for (i in rnorm(n)){ 
  if (i> -1 & i <1){
    count = count +1
  }
}
count/n
```

    ## [1] 0.683133

``` r
#compare: 0.682
```

Sample = 10000000

``` r
n = 10000000
count = 0;
# Generate vector of 100 random numbers
for (i in rnorm(n)){ 
  if (i> -1 & i <1){
    count = count +1
  }
}
count/n
```

    ## [1] 0.6828357

``` r
#compare: 0.682
```

As we can see, the more we increase our sample, the closer we get to our
expected value. Thus, our claim holds.
