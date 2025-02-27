(Codes given by sir)
## 1. linear regression (manual)
```python
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
```

## 2. linear regression (sklearn)
```python
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
```
## 3. Logistic regression (sklearn)
```python
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

#Computes accuracy, (Correct Predictions/Total Predictions)*100
acc=accuracy_score(Y_test,Y_pred)
print("Accuracy using function is: ",acc*100)

#f1_value=f1_score(Y_test,Y_pred)
#print("F1 score is: ",f1_value*100)

print("Confusion matrix:\n",confusion_matrix)
```

## 4. logistic regression (manual)
```python
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.metrics import precision_score
from sklearn.metrics import recall_score
from sklearn.metrics import f1_score
path="C:/Users/UEM/OneDrive - University Of Engineering & Management/subject/AI/lab/2025/dataset/logistic_regression/final_dataset/"


X=pd.read_excel(path+"X.xlsx")
Y=pd.read_excel(path+"Y.xlsx")


X_train,X_test,Y_train,Y_test=train_test_split(X,Y,test_size=0.1)

X_train = X_train.values
Y_train = Y_train.values
X_test = X_test.values
Y_test = Y_test.values

X_train = X_train.T
Y_train = Y_train.reshape(1, X_train.shape[1])

X_test = X_test.T
Y_test = Y_test.reshape(1, X_test.shape[1])



def sigmoid(x):
    return 1/(1 + np.exp(-x))

def model(X, Y, learning_rate, iterations):
    
    m = X_train.shape[1]
    n = X_train.shape[0]
    
    W = np.zeros((n,1))
    B = 0
    
    cost_list = []
    
    for i in range(iterations):
        
        Z = np.dot(W.T, X) + B
        A = sigmoid(Z)
        
        # cost function
        cost = -(1/m)*np.sum( Y*np.log(A) + (1-Y)*np.log(1-A))
        
        # Gradient Descent
        dW = (1/m)*np.dot(A-Y, X.T)
        dB = (1/m)*np.sum(A - Y)
        
        W = W - learning_rate*dW.T
        B = B - learning_rate*dB
        
        # Keeping track of our cost function value
        cost_list.append(cost)
        
        if(i%(iterations/10) == 0):
            print("cost after ", i, "iteration is : ", cost)
        
    return W, B, cost_list


iterations = 100000
learning_rate = 0.0015
W, B, cost_list = model(X_train, Y_train, learning_rate = learning_rate, iterations = iterations)

plt.plot(np.arange(iterations), cost_list)
plt.show()


def predict(X, Y, W, B):
    
    Z = np.dot(W.T, X) + B
    A = sigmoid(Z)
    
    A = A > 0.5
    
    A = np.array(A, dtype = 'int64')
    
     
    return A
    

Y_pred=predict(X_test, Y_test, W, B)
Y_pred_l=Y_pred.flatten()
Y_pred_l=Y_pred_l.tolist()


Y_test_l=Y_test.flatten()
Y_test_l=Y_test_l.tolist()
result=0
for i in range(len(Y_test_l)):
    if Y_test_l[i]==Y_pred_l[i]:
        result=result+1

manual_accuracy=result/len(Y_test_l)
print("Accuracy using loop is: ",manual_accuracy*100)
```

confusion_matrix = confusion_matrix(Y_test_l, Y_pred_l)
f1_value=f1_score(Y_test_l,Y_pred_l)
acc=accuracy_score(Y_test_l,Y_pred_l)
print("F1 score is: ",f1_value*100)
print("Accuracy using function is: ",acc*100)
print(confusion_matrix)
