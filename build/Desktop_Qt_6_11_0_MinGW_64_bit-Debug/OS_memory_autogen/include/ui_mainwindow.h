/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QSpinBox *totalMemorySpinBox;
    QPushButton *initButton;
    QLabel *label_2;
    QSpinBox *holeStartSpinBox;
    QSpinBox *holeSizeSpinBox;
    QPushButton *addHoleButton;
    QLabel *label_3;
    QLineEdit *processNameEdit;
    QTableWidget *segmentsTable;
    QComboBox *methodComboBox;
    QPushButton *allocateButton;
    QLabel *label_4;
    QLineEdit *deallocateEdit;
    QPushButton *deallocateButton;
    QLabel *label_5;
    QGraphicsView *graphicsView;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *numSegmentsEdit;
    QLabel *label_12;
    QTableWidget *processSummaryTable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1412, 670);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #FFF5F7; \n"
"}\n"
"QGroupBox {\n"
"    background-color: #FFFFFF; \n"
"    border: 2px solid #FCE4EC; \n"
"    border-radius: 15px;\n"
"    margin-top: 20px;\n"
"    font-weight: bold;\n"
"    color: #AD1457; \n"
"}\n"
"QPushButton {\n"
"    background-color: #F06292; \n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #EC407A;\n"
"}\n"
"QTableWidget, QLineEdit, QSpinBox, QComboBox {\n"
"    background-color: white;\n"
"    border: 1px solid #F8BBD0;\n"
"    border-radius: 5px;\n"
"    selection-background-color: #F48FB1;\n"
"}\n"
"QGraphicsView {\n"
"    background-color: #FFFFFF;\n"
"    border: 2px dashed #F8BBD0;\n"
"    border-radius: 10px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 50, 151, 21));
        totalMemorySpinBox = new QSpinBox(centralwidget);
        totalMemorySpinBox->setObjectName("totalMemorySpinBox");
        totalMemorySpinBox->setGeometry(QRect(180, 50, 100, 26));
        totalMemorySpinBox->setMinimumSize(QSize(100, 0));
        totalMemorySpinBox->setMaximum(10000);
        initButton = new QPushButton(centralwidget);
        initButton->setObjectName("initButton");
        initButton->setGeometry(QRect(290, 50, 131, 29));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 90, 151, 20));
        holeStartSpinBox = new QSpinBox(centralwidget);
        holeStartSpinBox->setObjectName("holeStartSpinBox");
        holeStartSpinBox->setGeometry(QRect(180, 90, 100, 26));
        holeStartSpinBox->setMinimumSize(QSize(100, 0));
        holeStartSpinBox->setMaximum(10000);
        holeSizeSpinBox = new QSpinBox(centralwidget);
        holeSizeSpinBox->setObjectName("holeSizeSpinBox");
        holeSizeSpinBox->setGeometry(QRect(180, 130, 100, 26));
        holeSizeSpinBox->setMinimumSize(QSize(100, 0));
        holeSizeSpinBox->setMaximum(10000);
        addHoleButton = new QPushButton(centralwidget);
        addHoleButton->setObjectName("addHoleButton");
        addHoleButton->setGeometry(QRect(40, 180, 381, 29));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 260, 101, 20));
        processNameEdit = new QLineEdit(centralwidget);
        processNameEdit->setObjectName("processNameEdit");
        processNameEdit->setGeometry(QRect(190, 260, 241, 26));
        segmentsTable = new QTableWidget(centralwidget);
        if (segmentsTable->columnCount() < 2)
            segmentsTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        segmentsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        segmentsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        segmentsTable->setObjectName("segmentsTable");
        segmentsTable->setGeometry(QRect(20, 330, 391, 192));
        methodComboBox = new QComboBox(centralwidget);
        methodComboBox->addItem(QString());
        methodComboBox->addItem(QString());
        methodComboBox->setObjectName("methodComboBox");
        methodComboBox->setGeometry(QRect(150, 530, 251, 26));
        allocateButton = new QPushButton(centralwidget);
        allocateButton->setObjectName("allocateButton");
        allocateButton->setGeometry(QRect(10, 570, 391, 29));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(650, 50, 181, 20));
        deallocateEdit = new QLineEdit(centralwidget);
        deallocateEdit->setObjectName("deallocateEdit");
        deallocateEdit->setGeometry(QRect(830, 50, 113, 26));
        deallocateButton = new QPushButton(centralwidget);
        deallocateButton->setObjectName("deallocateButton");
        deallocateButton->setGeometry(QRect(650, 90, 301, 29));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(450, 140, 301, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label_5->setFont(font);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(470, 180, 371, 421));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 130, 91, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 10, 261, 31));
        label_7->setFont(font);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 220, 311, 31));
        label_8->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 530, 141, 20));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(660, 20, 171, 20));
        label_10->setFont(font);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 300, 161, 20));
        numSegmentsEdit = new QLineEdit(centralwidget);
        numSegmentsEdit->setObjectName("numSegmentsEdit");
        numSegmentsEdit->setGeometry(QRect(190, 300, 241, 26));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(860, 200, 291, 31));
        label_12->setFont(font);
        processSummaryTable = new QTableWidget(centralwidget);
        if (processSummaryTable->columnCount() < 4)
            processSummaryTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        processSummaryTable->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        processSummaryTable->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        processSummaryTable->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        processSummaryTable->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        processSummaryTable->setObjectName("processSummaryTable");
        processSummaryTable->setGeometry(QRect(860, 270, 531, 192));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1412, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Total Memory Size", nullptr));
        initButton->setText(QCoreApplication::translate("MainWindow", "Set Memory", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Hole Starting Address:", nullptr));
        addHoleButton->setText(QCoreApplication::translate("MainWindow", "Add Hole", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Process Name:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = segmentsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Segment Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = segmentsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        methodComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "First Fit", nullptr));
        methodComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Best Fit", nullptr));

        allocateButton->setText(QCoreApplication::translate("MainWindow", "Allocate Process", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Deallocate Process Name:", nullptr));
        deallocateButton->setText(QCoreApplication::translate("MainWindow", "Deallocate", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "4. Memory Layout (Output)", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Hole Size:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "1. Initial Memory Setup", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "2. Process & Segment Input ", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Allocation Strategy: ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "3. Deallocation", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Number of Segments: ", nullptr));
        numSegmentsEdit->setPlaceholderText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "5. Process Segment Tables", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = processSummaryTable->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Process ", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = processSummaryTable->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Segment", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = processSummaryTable->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = processSummaryTable->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
