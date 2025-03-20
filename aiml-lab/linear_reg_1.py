import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

path="C:/Users/user/OneDrive/coding/python/AIML/"
dataset=pd.read_csv(path+"headbrain.csv")
#print(dataset.head())

x=dataset['Head Size(cm^3)'].values
y=dataset['Brain Weight(grams)'].values
mean_x=np.mean(x)
mean_y=np.mean(y)

numer=0
denom=0
for i in range(len(x)):
    numer +=(x[i]-mean_x)*(y[i]-mean_y)
    denom +=(x[i]-mean_x)**2

m=numer/denom     # y' = c + mx'
c=mean_y-(m*mean_x)
max_x=np.max(x)+100
min_x=np.min(x)-100
x1=np.linspace(min_x,max_x,100)
y1=(m*x1)+c

value=int(input("Insert the head size in cm^3:"))
predict=(m*value)+c
print(predict)

plt.plot(x1, y1, color='#58b970', label='Regression Line')
plt.scatter(x,y, c='#ef5423', label='data points')
plt.show()

ss_t = 0  # Total sum of squares
ss_r = 0  # Residual sum of squares

for i in range(len(x)): 
  y_pred = c + m * x[i]  # Predicted value using the regression equation
  ss_t += (y[i] - mean_y) ** 2  # Total sum of squares
  ss_r += (y[i] - y_pred) ** 2  # Residual sum of squares

r2 = 1 - (ss_r/ss_t)  # R² score calculation
print(r2)
