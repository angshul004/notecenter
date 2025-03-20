import numpy as np
import pandas as pd
from sklearn.linear_model import Ridge,LinearRegression
from sklearn.metrics import mean_squared_error
from sklearn.model_selection import train_test_split

data=pd.read_csv("C:\Users\User\OneDrive\coding\python\AIML\ridge regression.py")
z=pd.DataFrame(data.corr().round(2))
x=data['rm']
y=data['medv']
x=pd.DataFrame(x)
y=pd.DataFrame(y)
x=np.reshape(x,(len(x),1))

x_train,x_test, y_train,y_test=train_test_split(x,y,test_size=0.1)
y_test=np.reshape(y_test,(-1,1))

reg=LinearRegression()
reg=reg.fit(x_train,y_train)
y_pred=reg.predict(x_test)

mean_sq_er=np.sqrt(mean_squared_error(y_test,y_pred))
r2_square=reg.score(y_test,y_pred)

RidgeRegressionClassifier=Ridge()
RidgeRegressionClassifier.fit(x_train,y_train)
y_pred_ridge=RidgeRegressionClassifier.predict(x_test)
mean_sq_er_ridge=np.sqrt(mean_squared_error(y_test, y_pred_ridge))

print("For linear regression",mean_sq_er)
print("for ridge regression",mean_sq_er_ridge)
