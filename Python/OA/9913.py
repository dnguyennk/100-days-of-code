# Import your libraries
import pandas as pd

# Start writing code
customers.head()
orders.head()

# Merge customer and order DF, filter J and E
df = pd.merge(customers, orders, left_on = "id", right_on = "cust_id")
df
df_filtered = df[["first_name", "order_date", "order_details", "total_order_cost"]]
df_filtered
result = df[["first_name", "order_date", "order_details", "total_order_cost"]].query("first_name=='Jill' or first_name=='Eva'")