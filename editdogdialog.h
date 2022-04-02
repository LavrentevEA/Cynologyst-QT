#ifndef EDITDOGDIALOG_H
#define EDITDOGDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "dog.h"

class EditDogDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit* editID;
    QLineEdit* editName;
    QLineEdit* editAge;
    QComboBox* editBreed;
    QLineEdit* editOwner;


public:
    EditDogDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString name() const;
    QString age() const;
    QString breed() const;
    QString owner() const;
    void SetUpDialog(QString id, QString name,QString age, QString breed, QString owner);
};
#endif // EDITDOGDIALOG_H
