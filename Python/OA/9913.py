#Order Details

# Import your libraries
import pandas as pd
import numpy as np

# Start writing code
customers.head()

# Merge customer and order DF, filter J and E
merge = pd.merge(customers, orders, left_on ="id", right_on = "cust_id")
cust = ["Jill", "Eva"]
# select the required columns and store the result 
result = merge[merge["first_name"].isin(cust)][
    ["first_name","order_date", "order_details", "total_order_cost"]
    ]