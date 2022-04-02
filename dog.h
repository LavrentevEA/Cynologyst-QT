#ifndef DOG_H
#define DOG_H
#include "QString"
#include <QObject>

class Dog: public QObject
{
    Q_OBJECT

public:
    Dog(QString ID, QString Name, QString Age, QString Value, QString Owner, QObject *parent = nullptr );
    virtual ~Dog();
    void SetID(QString ID);
    void SetName(QString Name);
    void SetAge(QString Age);
    void SetBreed(QString Value);
    void SetOwner(QString Owner);

    QString ID();
    QString Name();
    QString Age();
    QString Breed();
    QString Owner();
    static QStringList GetBreeds();
private:
    QString id;
    QString name;
    QString age;
    QString breed;
    QString owner;
};
#endif // DOG_H
