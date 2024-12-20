#ifndef TWORDLIST_H
#define TWORDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char word[40];
    int count;
} TPair;

typedef struct {
    TPair* data;
    int capacity;
    int size;
} TWordList;

void IncSize(TWordList* pL);
int Find(const TWordList L, const char word[]);
int FindPlace(const TWordList L, const char word[]);
void printList(const TWordList L);
void InsertWord(TWordList* pL, int k, const char word[]);

#endif