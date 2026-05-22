#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "models.h"
#include <QList>

class MemoryManager {
public:
    MemoryManager(int totalSize);
    void addInitialHole(int start, int size);
    bool allocateProcess(Process &p, QString method);
    void deallocateProcess(QString processName);

    int getTotalSize() const { return totalMemorySize; }

    // for ui drawing
    QList<Hole> getHoles() const { return holesTable; }
    QList<Segment> getAllocatedSegments() const { return allocatedTable; }

private:
    int totalMemorySize;
    QList<Hole> holesTable;      //table b
    QList<Segment> allocatedTable; //table a

    void mergeHoles(); //for deallocation
};

#endif
