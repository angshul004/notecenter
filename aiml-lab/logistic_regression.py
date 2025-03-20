import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.metrics import precision_score
from sklearn.metrics import recall_score
from sklearn.metrics import f1_score
from sklearn.linear_model import LogisticRegression
from sklearn import preprocessing
from sklearn.preprocessing import LabelEncoder

path="C:/Users/user/OneDrive/coding/python/AIML/"
data=pd.read_csv(path+"Iris_Dataset.csv")

#Drops the species column to keep only the numerical features.
X=data.drop("species",axis=1)

data1=pd.read_csv(path+"Iris_Dataset.csv")
#drops the first 4 columns (features), leaving only the species column as Y
data1.drop(data1.iloc[:,0:4],axis=1, inplace=True)
Y=data1

#LabelEncoder converts species names (like 'Setosa', 'Versicolor', 'Virginica') 
#into numerical values.Eg. Setosa → 0, Versicolor → 1, Virginica → 2
le = LabelEncoder()
#labels now contains numerical class labels.
labels = le.fit_transform(Y)
print("Y:\n",Y)
print("Labels:\n",labels)

#test_size=0.4: 40% data used for testing, 60% for training.
#random_state=15: Ensures consistent splitting across runs.
X_train,X_test,Y_train,Y_test=train_test_split(X,labels,test_size=0.4,random_state=15)

#Prints the shape of training and testing sets.
print("Shapes of xtrain,ytrain,xtest,ytest:\n")
print(X_train.shape)
print(Y_train.shape)
print(X_test.shape)
print(Y_test.shape)

#log_reg=LogisticRegression(max_iter=10000)

#multi_class='multinomial': Uses softmax regression for multi-class classification.
#max_iter=10: Sets maximum iterations for model convergence.
log_reg=LogisticRegression(multi_class='multinomial',max_iter=10)
log_reg.fit(X_train, Y_train)

#Uses the trained model to predict species for test data (X_test).
Y_pred=log_reg.predict(X_test)
result=0

#The confusion matrix shows how well the model classified each species.
confusion_matrix = confusion_matrix(Y_test, Y_pred)
#f1_value=f1_score(Y_test,Y_pred)

#Computes accuracy:= (Correct Predictions/Total Predictions)*100
acc=accuracy_score(Y_test,Y_pred)
print("Accuracy using function is: ",acc*100)
#print("F1 score is: ",f1_value*100)

print("Confusion matrix:\n",confusion_matrix)
