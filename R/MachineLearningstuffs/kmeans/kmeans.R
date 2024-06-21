library(readr)
library(dplyr)
library(ggplot2)
library(tidyr)
install.packages("factoextra")
library(cluster)    # clustering algorithms
library(factoextra)
library(purrr)
library(plotly)
rank <- read.csv("rank.csv")

# The magnitude of difference between the average invoice and the recency/frequency is too high
# (not in the same scale) => need to scale the feature => segmentation


a <- kmeans(scale(rank[, 3:5]), #recency, frequency, avg invoice
                  centers = 3, 
                  iter.max = 18, # 18 iteration till conversion
                  nstart = 10)

a$cluster

# Visualize
fviz_cluster(a, rank[,3:5])

# Examine the total within this cluster
a$tot.withinss

# Create functions to test different clusters
wss <- function(k){
  kmeans(scale(rank[,3:5]), , centers = k, iter.max = 18, nstart =10)$tot.withinss
}
# Let try 10 k
k<- seq(1:10)
# Apply mapping function
wss_score<-map_dbl(k, wss)
# Plot to examine
plot(k,wss_score)
#Verify the cut-off point
fviz_nbclust(scale(rank[,3:5]), kmeans, method = "wss")
fviz_nbclust(scale(rank[,3:5]), kmeans, method = "silhouette")

# Optimum clusters
b <- kmeans(scale(rank[, 3:5]),
              centers = 3, 
              iter.max = 18,
              nstart = 10)

## 3 dimensional scatter plot
rank$kmeans<- b$cluster

fig <- plot_ly(rank, x = ~frequency, y = ~recency, z = ~average_invoice_value, 
               color = ~kmeans )
fig <- fig %>% add_markers()
fig <- fig %>% layout(scene = list(xaxis = list(title = 'frequency'),
                                   yaxis = list(title = 'recency'),
                                   zaxis = list(title = 'invoice_value')))
fig

## As we can see, we have some high invoice value, they have recency and low frequence
## We can conclude that they are 1 time buyer
## The difference about the rest 3 group are the recency.



