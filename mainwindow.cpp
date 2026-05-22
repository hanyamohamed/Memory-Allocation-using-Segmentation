#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->segmentsTable->setRowCount(3);
    ui->segmentsTable->setColumnCount(2);
    ui->segmentsTable->setHorizontalHeaderLabels({"Segment Name", "Size"});
    ui->segmentsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (manager) delete manager;
}

//determining total size of memory
void MainWindow::on_initButton_clicked() {
    int totalSize = ui->totalMemorySpinBox->value();
    if (manager) delete manager;
    manager = new MemoryManager(totalSize);
    QMessageBox::information(this, "Success", "Memory Initialized: " + QString::number(totalSize));
    updateUI();
}

//adding hole 1,2,3
void MainWindow::on_addHoleButton_clicked() {
    if (!manager) return;
    int start = ui->holeStartSpinBox->value();
    int size = ui->holeSizeSpinBox->value();

    manager->addInitialHole(start, size);
    updateUI();
}

//allocating processes
void MainWindow::on_allocateButton_clicked() {
    if (!manager) return;

    Process p;
    p.name = ui->processNameEdit->text();

    for (int i = 0; i < ui->segmentsTable->rowCount(); ++i) {
        if (ui->segmentsTable->item(i, 0) && ui->segmentsTable->item(i, 1)) {
            Segment seg;
            seg.name = ui->segmentsTable->item(i, 0)->text();
            seg.size = ui->segmentsTable->item(i, 1)->text().toInt();
            p.segments.append(seg);
        }
    }

    QString method = ui->methodComboBox->currentText(); //first fit or best fit

    if (manager->allocateProcess(p, method)) {
        updateUI();
    } else {
        QMessageBox::critical(this, "Error", "Process " + p.name + " does not fit!");
    }
}

//deallocating
void MainWindow::on_deallocateButton_clicked() {
    if (!manager) return;
    QString name = ui->deallocateEdit->text();
    manager->deallocateProcess(name);
    updateUI();
}

//drawing and visualizing output
void MainWindow::updateUI() {
    if (!manager) return;

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    double scale = 1.0;
    int width = 150;
    int xOffset = 60;

    scene->addRect(xOffset, 0, width, manager->getTotalSize() * scale, QPen(QColor("#AD1457"), 2), QBrush(Qt::white));

    for (const Segment &seg : manager->getAllocatedSegments()) {
        uint hash = qHash(seg.processName);
        QColor processColor = QColor::fromHsv(330 + (hash % 30), 100, 250);

        double yPos = seg.baseAddress * scale;
        double height = seg.size * scale;

        scene->addRect(xOffset, yPos, width, height, QPen(QColor("#AD1457")), QBrush(processColor));

        auto text = scene->addText(seg.processName + ":" + seg.name + " (" + QString::number(seg.size) + "K)");
        text->setDefaultTextColor(QColor("#880E4F"));
        text->setPos(xOffset + 5, yPos + (height/4));

        auto addrText = scene->addText(QString::number(seg.baseAddress) + "K");
        addrText->setDefaultTextColor(QColor("#AD1457"));
        addrText->setPos(xOffset - 50, yPos - 10);
    }

    for (const Hole &h : manager->getHoles()) {
        double yPos = h.startAddress * scale;
        double height = h.size * scale;

        scene->addRect(xOffset, yPos, width, height, QPen(QColor("#757575"), 1, Qt::DashLine), QBrush(QColor("#E0E0E0")));

        auto text = scene->addText("Hole (" + QString::number(h.size) + "K)");
        text->setDefaultTextColor(QColor("#616161"));
        text->setPos(xOffset + 15, yPos + (height/3));

        auto addrText = scene->addText(QString::number(h.startAddress) + "K");
        addrText->setDefaultTextColor(QColor("#757575"));
        addrText->setPos(xOffset - 50, yPos - 10);
    }

    auto lastAddr = scene->addText(QString::number(manager->getTotalSize()) + "K");
    lastAddr->setPos(xOffset - 50, (manager->getTotalSize() * scale) - 5);

    ui->graphicsView->setSceneRect(scene->itemsBoundingRect());

    ui->processSummaryTable->setRowCount(0);

    int row = 0;
    QString lastProcessName = "";

    for (const Segment &seg : manager->getAllocatedSegments()) {
        ui->processSummaryTable->insertRow(row);

        if (seg.processName != lastProcessName) {
            QTableWidgetItem *nameItem = new QTableWidgetItem(seg.processName);
            nameItem->setFont(QFont("Segoe UI", 9, QFont::Bold));
            nameItem->setForeground(QColor("#880E4F"));
            ui->processSummaryTable->setItem(row, 0, nameItem);

            lastProcessName = seg.processName;
        } else {
            ui->processSummaryTable->setItem(row, 0, new QTableWidgetItem(""));
        }

        ui->processSummaryTable->setItem(row, 1, new QTableWidgetItem(seg.name));
        ui->processSummaryTable->setItem(row, 2, new QTableWidgetItem(QString::number(seg.baseAddress)));
        ui->processSummaryTable->setItem(row, 3, new QTableWidgetItem(QString::number(seg.size) + "K"));

        row++;
    }
}

void MainWindow::on_numSegmentsEdit_textChanged(const QString &text)
{
    bool ok;
    int count = text.toInt(&ok);

    if (ok && count > 0) {
        ui->segmentsTable->setRowCount(count);

        for(int i = 0; i < count; ++i) {
            if(ui->segmentsTable->item(i, 0) == nullptr)
                ui->segmentsTable->setItem(i, 0, new QTableWidgetItem("Segment " + QString::number(i+1)));
            if(ui->segmentsTable->item(i, 1) == nullptr)
                ui->segmentsTable->setItem(i, 1, new QTableWidgetItem("0"));
        }
    } else if (text.isEmpty()) {
        ui->segmentsTable->setRowCount(0);
    }
}