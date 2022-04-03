#include "dialogdelegate.h"
#include "QtWidgets"
#include "editdogdialog.h"

DialogDelegate::DialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent) {
    dparentWidget = parentWidget;

}


bool DialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &, const QModelIndex &index) {
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditDogDialog* editDialog = new EditDogDialog(dparentWidget);

        QString ID = model->data(model->index(index.row(),0,index)).toString();
        QString Name = model->data(model->index(index.row(),1,index)).toString();
        QString Age = model->data(model->index(index.row(),2,index)).toString();
        QString Breed = model->data(model->index(index.row(),2,index)).toString();
        QString Owner = model->data(model->index(index.row(),2,index)).toString();

        editDialog->SetUpDialog(ID, Name, Age, Breed, Owner);

        if (editDialog->exec() == QDialog::Accepted)
        {
            model->setData(model->index(index.row(),0,index),editDialog->id());
            model->setData(model->index(index.row(),1,index),editDialog->name());
            model->setData(model->index(index.row(),2,index),editDialog->age());
            model->setData(model->index(index.row(),3,index), editDialog->breed());
            model->setData(model->index(index.row(),4,index),editDialog->owner());
        }

         editDialog->close();

    }

    return false;

}

QWidget *DialogDelegate::createEditor(QWidget* /* parent */, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const {
    return nullptr;
}
