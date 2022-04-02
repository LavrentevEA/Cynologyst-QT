#include "breeddelegate.h"
#include "QtWidgets"
#include "dog.h"
BreedDelegate::BreedDelegate(QObject *parent): QItemDelegate(parent)
{

}


QWidget *BreedDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QComboBox* cmb = new QComboBox(parent);
    QStringList breeds = Dog::GetBreeds();
    foreach  (QString fc, breeds)
    {
        cmb->addItem(fc);
    }
    return cmb;
}

void BreedDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    QComboBox *myeditor = static_cast<QComboBox*>(editor);

    QString value = myeditor->currentText();

    model->setData(index, value, Qt::EditRole);
}

void BreedDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QComboBox *myeditor = qobject_cast<QComboBox *>(editor);
    const QString currentText =  index.data(Qt::DisplayRole).toString();
    const int cbIndex = myeditor->findText(currentText);
    if (cbIndex >= 0)
       myeditor->setCurrentIndex(cbIndex);
}



