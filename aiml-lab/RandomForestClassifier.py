import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import LabelEncoder

path="C:/Users/angsh/OneDrive/coding/python/AIML/Iris_Dataset.csv"
data=pd.read_csv(path)
X=data.drop("species",axis=1)

data1=pd.read_csv(path)
data1.drop(data1.iloc[:,0:4],axis=1,inplace=True)
Y=data1

le=LabelEncoder()
labels=le.fit_transform(Y)
print(Y)
print("Labels=\n",labels)

X_train, X_test, Y_train,Y_test=train_test_split(X,labels,test_size=0.5,random_state=(15))

rand_for=RandomForestClassifier()
rand_for.fit(X_train,Y_train)
Y_pred=rand_for.predict(X_test)
result=0

confusion_matrix=confusion_matrix(Y_test, Y_pred)
acc=accuracy_score(Y_test, Y_pred)
print("Accuracy score: ",acc*100)
print(confusion_matrix)
