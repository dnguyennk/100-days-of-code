# Import your libraries
import pandas as pd

# Start writing code
shopify_orders.head()
shopify_carriers.head()

df = pd.merge(shopify_carriers, shopify_orders, left_on ="id", right_on ="carrier_id")
df
# shape[0] -> get nrow
df_filtered = df[df['name'].str.lower() =='speedy express'].shape[0]
df_filtered