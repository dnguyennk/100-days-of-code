#Linear Programming

#Example 1:  A person wants to create a balance diet using 3 food 
#items A, B, C
# A -> Apple -> 10g Protein, 5g fat, 20 carbs, cost $2
# B -> Banana -> 15g Protein, 10g fat, 25 carbs, cost $3
# C -> Carrot -> 8g Protein, 12g fat, 30 carbs, cost $4
# The person needs at least 60g protein, 30g fat, 120 carbs
# Goal: Determine the optimal combination of the food to min cost, 
# but also meet min requirements:

#MIN COST = 2 x APPLES + 3 x BANANAS 4 x CARROTS

# MODEL:
# VARIABLES: A, B, C #DAILY UNITS
# COST: Z = F(A, B, C) = 2A + 3B +4C
# CONSTRAINTS : 
# C1 = 10A + 15B + 8C >= 60
# C2 = 5A + 10B + 12C >= 30
# C3 = 20A + 25B + 30C >= 60
# C4 = A, B, C >= 0

# EASY SOLUTION

install.packages("lpSolve")
library(lpSolve)

#Diet Example 1

#Define the objective function coefficient (cost of food items)
obj <- c(2, 3, 4) # cost for A, B, C

#Define the direction of the constraints and RHS values
mat <- matrix(c(10, 15, 8, 5, 10, 12, 20, 25, 30), nrow = 3, byrow = TRUE)
rhs <- c(60, 30, 120)

#Define the direction of the constraints
dir <- c(">=", ">=", ">=")
lp_solution <- lp("min", obj, mat, dir, rhs)

# Print the optimal solution and min cost
print(lp_solution$solution)
print(lp_solution$objval)

# Diet Example 2
# A company manufactures 2 products:
# A -> $10
# B -> $15
# Company has 100 hours of labours, product A requires 2 hours
# product B requires 3 hours. At least 30 units of A and 20 units 
# of B are needed
# Find Max profits

obj <- c(10, 15)
mat <- matrix(c(1, 0, 0, 1, 2, 3), ncol = 2, byrow = TRUE)
rhs <- c(30, 20, 100)
dir <- c(">=", ">=", "<=")
lp_solution_2 <-lp("max", obj, mat, dir, rhs)
print(lp_solution_2$solution)
print(lp_solution_2$objval)
#Note: no solution since hours = 120, while 2A + 3B <= 100

#Change B to 10
obj <- c(10, 15)
mat <- matrix(c(1, 0, 0, 1, 2, 3), ncol = 2, byrow = TRUE)
rhs <- c(30, 10, 100)
dir <- c(">=", ">=", "<=")
lp_solution_2 <-lp("max", obj, mat, dir, rhs)
print(lp_solution_2$solution)
print(lp_solution_2$objval)