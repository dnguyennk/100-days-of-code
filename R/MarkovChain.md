Stochastic Processes
================
2024-06-20

1.  Consider a simple game. In a track like the following.

    1 2 3

You start on position 1, the goal is to reach position 3. You flip a
coin. If you get heads, stay where you are. If you get tails, move
forward in the next position. Each player counts the number of coin
flips. The winner is who reaches 3 in the lowest number of moves. Write
the transition probability matrix and the state transition diagram for
this game. Write an R code to simulate this game.

``` r
# Function to compute markov chain
set.seed(123)
markov = function(x0, n, x, P){
  s = numeric()
  s[1] = x0
  row = which(x==x0)
  for (i in 2:n){
    s[i] = sample(x, 1, P[row,], replace = T)
      row = which(x==s[i])
    }
    return(s)
}

# Max number of moves
n = 20

# Create Transition matrix
P = matrix(c(1/2,1/2,0,0,1/2,1/2,0,0,1), nrow = 3, ncol = 3, byrow = T)

# Let 2 players be x and y
x = c(1,2,3)
y = c(1,2,3)
# Starting state
x0 = 1
y0 = 1

#Calculate probability
sx <- markov(x0, n, x, P)
sy <- markov(y0, n, y, P)
tmp = which(sx==3)
x.result = tmp[1]
tmp = which(sy==3)
y.result = tmp[1]

#Compare result
if (x.result < y.result){
  print("X wins")
} else if (x.result > y.result){
  print("Y wins")
} else 
  print("Tie")
```

    ## [1] "X wins"

2.  Assume the following transition probability matrix for a Markov
    process describing weather, with possible states:

    1 = clear sky 2 = cloud covered sky 3 = rain

Let P be:

    P = (0.4, 0.3, 0.3,
         0.2, 0.4, 0.4,
         0.1, 0.6, 0.3)
         

A meteorologist predicts for tomorrow, Friday, 40 % rain probability and
60 % clear sky. What is the probability of rain on Saturday?

``` r
set.seed(123)
# Transition matrix
mat = matrix(c(0.4, 0.3, 0.3, 
             0.2, 0.4, 0.4, 
             0.1, 0.6, 0.3), byrow = TRUE, ncol = 3)

# Define states
states = c("Clear", "Cloudy", "Rain")
# Initial state: 60% clear sky, 0% cloud covered sky, 40% rain
initial_state = c(0.6, 0, 0.4) 

# State distribution for Saturday
satState = initial_state %*% mat

# Probability Rain on Sat
prob = satState[3]

# Result
prob
```

    ## [1] 0.3
