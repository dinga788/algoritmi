#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
 {
	 char word[40];
	 int count;
 } TPair;
 
typedef struct 
 {
	 TPair *data;
	 int capacity;
	 int size;
 } TWordList;
 
void IncSize ( TWordList *pL )
{
	 pL->size ++;
	 if ( pL->size > pL->capacity )
	 {
		 pL->capacity += 10;
		 pL->data = (TPair*) realloc ( pL->data, sizeof(TPair)*pL->capacity );
	 }
}
int Find( TWordList L, char word[] )
{
	 int i;
	 for ( i=0; i<L.size; i++ )
	 if ( 0 == strcmp(L.data[i].word, word) )
	 return i;
	 return -1;
}
int FindPlace ( TWordList L, char word[] )
{
	 int i;
	 for ( i=0; i<L.size; i++ )
	 if ( strcmp(L.data[i].word, word) > 0 )
	 return i;
	 return L.size;
}
void printList ( TWordList L )
{
	 int i;
	 for ( i=0; i<L.size; i++ )
	 printf ( "%s: %d\n", L.data[i].word, L.data[i].count );
}
void InsertWord ( TWordList *pL, int k, char word[] )
{
	 int i;
	 IncSize ( pL );
	 for ( i=pL->size-1; i>=k+1; i-- )
	 pL->data[i] = pL->data[i-1];
	 strcpy ( pL->data[k].word, word );
	 pL->data[k].count = 1;
}
main ()
{
	 TWordList L;
	 int p;
	 char s[80];
	 FILE *F;
	 L.size = 0;
	 L.capacity = 10;
	 L.data = (TPair*) calloc ( L.capacity, sizeof(TPair) );
	 F = fopen ( "words.txt", "r" );
	
	 while ( 1 == fscanf(F, "%s", s) )
	 {
		 p = Find ( L, s );
		 if ( p >= 0 )
		 L.data[p].count ++;
		 else 
		 {
			 p = FindPlace ( L, s );
			 InsertWord ( &L, p, s );
		 }
	 }
	 fclose(F);
	 
	 F = fopen ( "ww.txt", "w" );
	 for ( p=0; p<L.size; p++ )
	 fprintf ( F, "%s: %d\n", L.data[p].word, L.data[p].count);
	 fclose(F);
	 printf ( "\nРезультат записан в файл ww.txt\n");
	 getchar();
}
