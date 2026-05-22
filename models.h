#ifndef MODELS_H
#define MODELS_H

#include <QString>
#include <QList>

struct Segment {
    QString name;
    QString processName;
    int size;
    int baseAddress = -1; //not yet allocated
};

struct Hole {
    int startAddress;
    int size;
};

struct Process {
    QString name;
    QList<Segment> segments;
    bool isAllocated = false;
};

#endif