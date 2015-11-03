#ifndef __JIT_X64_OPT_H__
#define __JIT_X64_OPT_H__

typedef struct __Data_State {
    int offset; // offset by the current data pointer
    int diff; // differ to previos output value
    int totalDiff;
    int predict; // if this data maybe predict
} DataState;

DataState *create(int offset);
DataState *find(int offset, DataState *data[], int sizeOfData);
void inc(int offset, DataState *(*data)[], int *sizeOfData);
void dec(int offset, DataState *(*data)[], int *sizeOfData);
void movPtr(int from, int to);
void genLoops(int *ptr, DataState *(*data)[], int *sizeOfData, DataState *cond);
void genAll(int *ptr, DataState *(*data)[], int *sizeOfData);
void getPtr(int ptr, DataState *(*data)[], int *sizeOfData);
void putPtr(int ptr, DataState *(*data)[], int *sizeOfData);
void compile();

#endif
