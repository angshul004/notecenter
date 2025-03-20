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


confusion_matrix = confusion_matrix(Y_test_l, Y_pred_l)
f1_value=f1_score(Y_test_l,Y_pred_l)
acc=accuracy_score(Y_test_l,Y_pred_l)
print("F1 score is: ",f1_value*100)
print("Accuracy using function is: ",acc*100)
print(confusion_matrix)





