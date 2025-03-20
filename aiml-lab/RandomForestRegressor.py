import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.metrics import mean_squared_error,r2_score
from sklearn.ensemble import RandomForestRegressor
from sklearn.preprocessing import LabelEncoder

path="C:/Users/angsh/OneDrive/coding/python/AIML/Iris_Dataset.csv"
data=pd.read_csv(path)
X=data.drop("species",axis=1) # removing species column
data1=pd.read_csv(path)
data1.drop(data1.iloc[:,0:4],axis=1,inplace=True) # axis=0 is row
Y=data1

le=LabelEncoder()
labels=le.fit_transform(Y)
print(Y)
print(labels)
X_train,X_test,Y_train,Y_test=train_test_split(X,labels,test_size=0.4,random_state=15)

# Random Forest Regressor Model
random_forest_regressor=RandomForestRegressor() 
random_forest_regressor.fit(X_train,Y_train)
print(random_forest_regressor.get_params())
Y_pred=random_forest_regressor.predict(X_test)
result=0
mean_sq_error=mean_squared_error(Y_test,Y_pred)
print("Value of mean squared error: ",mean_sq_error)

