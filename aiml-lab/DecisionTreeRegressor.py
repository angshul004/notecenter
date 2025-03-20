import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeRegressor
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

# Decision Tree Regressor Model
decision_tree_regressor=DecisionTreeRegressor(max_depth=20) 
decision_tree_regressor.fit(X_train,Y_train)
Y_pred=decision_tree_regressor.predict(X_test)
result=0
confusion_matrix=confusion_matrix(Y_test,Y_pred)
acc=accuracy_score(Y_test,Y_pred)
print("Accuracy using function is: ",acc*100)
print(confusion_matrix)

