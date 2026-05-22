#include "memorymanager.h"
#include <algorithm>

MemoryManager::MemoryManager(int totalSize) : totalMemorySize(totalSize) {
    //first, entire memory is one big hole
    holesTable.clear();
    allocatedTable.clear();
}

void MemoryManager::addInitialHole(int start, int size) {
    Hole h;
    h.startAddress = start;
    h.size = size;
    holesTable.append(h);
    //keeping holes sorted and merged
    mergeHoles();
}

bool MemoryManager::allocateProcess(Process &p, QString method) {
    QList<Hole> tempHoles = holesTable;
    QList<int> plannedAddresses;

    for (const Segment &seg : p.segments) {
        int chosenIdx = -1;

        if (method == "First Fit") {
            for (int i = 0; i < tempHoles.size(); ++i) {
                if (tempHoles[i].size >= seg.size) {
                    chosenIdx = i;
                    break;
                }
            }
        } else { // Best Fit
            int minSize = 2147483647;
            for (int i = 0; i < tempHoles.size(); ++i) {
                if (tempHoles[i].size >= seg.size && tempHoles[i].size < minSize) {
                    minSize = tempHoles[i].size;
                    chosenIdx = i;
                }
            }
        }

        if (chosenIdx == -1) return false;

        plannedAddresses.append(tempHoles[chosenIdx].startAddress);
        tempHoles[chosenIdx].startAddress += seg.size;
        tempHoles[chosenIdx].size -= seg.size;

        if (tempHoles[chosenIdx].size == 0) {
            tempHoles.removeAt(chosenIdx);
        }
    }

    for (int i = 0; i < p.segments.size(); ++i) {
        p.segments[i].baseAddress = plannedAddresses[i];
        p.segments[i].processName = p.name;
        allocatedTable.append(p.segments[i]);
    }

    holesTable = tempHoles;
    p.isAllocated = true;
    return true;
}

void MemoryManager::deallocateProcess(QString processName) {
    //searching for all segments belonging to this process
    for (int i = 0; i < allocatedTable.size(); ) {
        if (allocatedTable[i].processName == processName) {
            Hole newHole;
            newHole.startAddress = allocatedTable[i].baseAddress;
            newHole.size = allocatedTable[i].size;
            holesTable.append(newHole);

            allocatedTable.removeAt(i);
        }
        else {
            i++;
        }
    }

    //combinig neighboring holes
    mergeHoles();
}

void MemoryManager::mergeHoles() {
    if (holesTable.isEmpty()) return;
    std::sort(holesTable.begin(), holesTable.end(), [](const Hole &a, const Hole &b) {
        return a.startAddress < b.startAddress;
    });

    //merging adjacent holes
    for (int i = 0; i < holesTable.size() - 1; ) {
        if (holesTable[i].startAddress + holesTable[i].size == holesTable[i+1].startAddress) {
            holesTable[i].size += holesTable[i+1].size;
            holesTable.removeAt(i + 1);
        }
        else {
            i++;
        }
    }
}

