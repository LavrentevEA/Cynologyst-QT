#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{

    Dog* dog1 = new Dog("101","Klem", "3", "Сенбернар", "Petrov I.V.", this);
    Dog* dog2 = new Dog("102","Ares", "2", "Немецкая овчарка", "Karandashova I.M.", this);
    Dog* dog3 = new Dog("103","Kate","8", "Корги", "Ivanon S.S", this);
    AddDog(dog1);
    AddDog(dog2);
    AddDog(dog3);
}

int MyModel::rowCount(const QModelIndex &) const
{
   return dogs.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 5;
}


QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Dog* dog = dogs.at(index.row());
        if (index.column() == 0){Value = dog->ID();}
        else if (index.column() == 1){Value = dog->Name();}
        else if (index.column() == 2){Value = dog->Age();}
        else if (index.column() == 3){Value = dog->Breed();}
        else if (index.column() == 4){Value = dog->Owner();}
        else {Value = "";};
       return Value;
    }
    return QVariant();
}


QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Name");
            case 2:
                return QString("Age");
            case 3:
                return QString("Breed");
            case 4:
                return QString("Owner");
            }
        }
    }
    return QVariant();
}


bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)
    {
        Dog* dog = dogs.at(index.row());
        if (index.column() == 0){dog->SetID(value.toString());}
        else if (index.column() == 1){dog->SetName(value.toString());}
        else if (index.column() == 2){dog->SetAge(value.toString());}
        else if (index.column() == 3){dog->SetBreed(value.toString());}
        else if (index.column() == 4){dog->SetOwner(value.toString());}
    }

    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}




void MyModel::AddDog(Dog * dog)
{
    beginInsertRows(QModelIndex(),dogs.size(),dogs.size());
    dogs.append(dog);
    endInsertRows();

}

void MyModel::DeleteDog(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    dogs.removeAt(row);
    endRemoveRows();

}

