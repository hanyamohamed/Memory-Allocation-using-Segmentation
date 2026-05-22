#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "memorymanager.h"
#include "models.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    MemoryManager* manager = nullptr;
    QList<Process> processes;
    void updateUI();

private slots:
    void on_initButton_clicked();
    void on_addHoleButton_clicked();
    void on_allocateButton_clicked();
    void on_deallocateButton_clicked();
    void on_numSegmentsEdit_textChanged(const QString &arg1);
};

#endif
