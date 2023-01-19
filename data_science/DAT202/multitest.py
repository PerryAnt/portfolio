def worker(x,y):
    return x+y


def worker2(args):
    (x,y) = args
    return x*y


def split_train_score(model, data_label, X_train, y_train, X_test, y_test, beta):
    from numpy import arange
    from numpy import argmax
    from sklearn.metrics import confusion_matrix, accuracy_score, recall_score, precision_score, fbeta_score

    # apply threshold to positive probabilities to create labels
    def to_labels(pos_probs, threshold):
        return (pos_probs >= threshold).astype('int')


    def predict_and_score(x, y, label):
        model_output = fit_model.predict(x)
        cm = confusion_matrix(y, model_output)
        recall = recall_score(y, model_output)
        precision = precision_score(y, model_output)
        f = fbeta_score(y, model_output, beta=beta)
        return {'model': model[0],'data':data_label, 'test': label, 'recall': recall, 'precision': precision, 'f': f, "cm":cm}
    
    print("Fitting :", model)
    results = []
    fit_model = model[1].fit(X_train, y_train.to_numpy().ravel())

    results.append(predict_and_score(X_train, y_train, 'train'))
    results.append(predict_and_score(X_test, y_test, 'test'))

    # predict probabilities
    yhat = fit_model.predict_proba(X_train)
    # keep probabilities for the positive outcome only
    probs = yhat[:, 1]
    # define thresholds
    thresholds = arange(0, 1, 0.001)
    # evaluate each threshold
    scores = [fbeta_score(y_train, to_labels(probs, t), beta=beta) for t in thresholds]
    # get best threshold
    ix = argmax(scores)

    # predict probabilities
    yhat = fit_model.predict_proba(X_test)
    # keep probabilities for the positive outcome only
    probs = yhat[:, 1]
    model_output = to_labels(probs, thresholds[ix])

    cm = confusion_matrix(y_test, model_output)
    recall = recall_score(y_test, model_output)
    precision = precision_score(y_test, model_output)
    f = fbeta_score(y_test, model_output, beta=beta)

    results.append({'model': model[0],'data':data_label, 'test': 'threshold', 'recall': recall, 'precision': precision, 'f': f, "cm":cm})
    print("Finished with :", model)
    return results
