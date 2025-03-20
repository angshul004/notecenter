import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
from sklearn.model_selection import train_test_split

path="C:/Users/user/OneDrive/coding/python/AIML/"
dataset=pd.read_csv(path+"headbrain.csv")

x=dataset['Head Size(cm^3)'].values
y=dataset['Brain Weight(grams)'].values
x = x.reshape(len(x), 1)

#splits the dataset into 90% training and 10% testing
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.1)

reg = LinearRegression() #Creates a LinearRegression model
reg = reg.fit(x_train,y_train)

#Uses the trained model to predict brain weights for x_test values.
#y_pred contains the predicted brain weights for each corresponding head size in x_test
y_pred = reg.predict(x_test)

#Computes the Root Mean Squared Error (RMSE):
mean_sq_er=np.sqrt(mean_squared_error(y_test, y_pred))
print(mean_sq_er)

#Computes the R² score (coefficient of determination):
r2_square = reg.score(x_test,y_test)
print (r2_square)