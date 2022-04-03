#include "dog.h"

Dog::Dog(QString ID, QString Name, QString Age, QString Breed, QString Owner, QObject *parent): QObject(parent) {
    id = ID;
    name = Name;
    age = Age;
    breed = Breed;
    owner = Owner;
}

void Dog::SetID(QString ID) {
    id = ID;
}

void Dog::SetName(QString Name) {
    name = Name;
}

void Dog::SetAge(QString Age) {
    age = Age;
}

void Dog::SetBreed(QString Breed) {
    breed = Breed;
}

void Dog::SetOwner(QString Owner) {
    owner = Owner;
}

QString Dog::ID() {
    return id;
}

QString Dog::Name() {
    return name;
}

QString Dog::Age() {
    return age;
}

QString Dog::Breed() {
    return breed;
}

QString Dog::Owner() {
    return owner;
}

QStringList Dog::GetBreeds() {
    QStringList value;

    value.append("Колли");
    value.append("Сенбернар");
    value.append("Немецкая овчарка");
    value.append("Корги");
    value.append("Мопс");

    return value;
}

 Dog::~Dog() {
}
