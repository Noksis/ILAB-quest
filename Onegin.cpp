#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <locale.h>
#pragma warning (disable: 4996)

const  char* mode_write = "w";
const  char* mode_append = "a";

struct STRING {
	unsigned char* index;
	int len;
};
int Comporator(const void* x1, const void* x2) {
	assert(x1);
	assert(x2);
	STRING* Line1 = (STRING*) x1;
	STRING* Line2 = (STRING*) x2;
	for (int i = 0; i < Line1->len && i < Line2->len; i++) {
		if (unsigned char(*(Line1->index + i)) < unsigned char (*(Line2->index + i)))
			return -1;
		if (*(Line1->index + i) > *(Line2->index + i))
			return 1;
	}
	return 0;
}
int Comporator_Reverse(const void* x1, const void* x2) {
	assert(x1);
	assert(x2);
	STRING* Line1 = (STRING*)x1;
	STRING* Line2 = (STRING*)x2;
	int CountLineAlpha1 = 0;
	int CountLineAlpha2 = 0;
	for (int i = 0; i < Line1->len && i < Line2->len ; i++) {
		while (isalpha(unsigned char(*(Line1->index - i + Line1->len - 1-CountLineAlpha1))) == 0)
			CountLineAlpha1++;
		while (isalpha(unsigned char(*(Line2->index - i + Line2->len - 1-CountLineAlpha2))) == 0)
			CountLineAlpha2++;
		if (unsigned char(*(Line1->index - i - CountLineAlpha1 + Line1->len - 1 )) < unsigned char(*(Line2->index + i - CountLineAlpha2 + Line2->len - 1)))
			return -1;
		if (*(Line1->index + i - CountLineAlpha1 + Line1->len - 1) > * (Line2->index + i - CountLineAlpha2  + Line2->len) - 1)
			return 1;
	}
	return 0;
}
unsigned char* OPENandWRITE(int *len) {
	assert(*len != NULL);
	int trylen = 0;
	FILE* f = fopen("wap.txt", "r");
	assert(("Wrong open file!", f));
	assert(("Wrong seek file", !fseek(f, 0, SEEK_END) != 0));
	*len = ftell(f);
	if (*len == -1) {
		printf("Wrong ftell");
		return NULL;
	}
	unsigned char* text = (unsigned char*)calloc(*len, sizeof(unsigned char));
	assert(text != NULL);
	fseek(f, 0, SEEK_SET);
	trylen = fread(text, sizeof(unsigned char), *len, f);
	*len = trylen + 1;
	fclose(f);
	return text;
}
 void CLOSEandWRITE(int len, struct STRING arrow_index[],const char* Type) {
	assert(Type);
	FILE* fp = fopen("SortedOnegin.txt", Type);
	assert(fp != NULL);
	if (fp == NULL)
		printf("Wrong open file");
	else
		printf("Successfully open file");
	for (int i = 0; i < len; i++)
		fprintf(fp, "%s\n", (arrow_index + i)->index);
	fprintf(fp, "\n \n");
	fclose(fp);
}
 int Index_Arrow_constr(unsigned char* text, int Textlen, STRING** index) {
	 struct STRING Line = {};
	 int Indexlen = 0, StringLen = 0, CountLine = 0;
	 for (int i = 0; i < Textlen; i++) {
		 if (*(text + i) == '\n')
			 Indexlen++;
		 while (*(text + i) == '\n') {
			 *(text + i) = '\0';
			 i++;
		 }
	 }
	 Indexlen++;
	 *index = (STRING*)calloc(Indexlen, sizeof(**index));
	 Line.index = text;
	 for (int i = 0; i < Textlen; i++) {
		 if (*(text + i) == '\0') {
			 while ((isalpha(*(text + i)) == 0) && (i < (Textlen - 1)))
				 i++;
			 Line.len = StringLen;
			 *(*index+CountLine) = Line;
			 Line.index = text + i;
			 CountLine++;
			 StringLen = 0;
		 }
		 StringLen++;
	 }
	 assert(*index != NULL);
	 return CountLine;
 }

int main() {
		 int Textlen = 1, CountLine = 0, StringLen = 0;
		 unsigned char* text;
		 STRING* index = NULL;
		 text = OPENandWRITE(&Textlen);
		 CountLine = Index_Arrow_constr(text, Textlen, &index);
		 CLOSEandWRITE(CountLine, index,mode_write);
		 qsort(index, CountLine,sizeof(STRING),Comporator);
		 CLOSEandWRITE(CountLine, index,mode_append);
		 qsort(index, CountLine, sizeof(STRING), Comporator_Reverse);
		 CLOSEandWRITE(CountLine, index,mode_append);
		 free(text);
		 free(index);
		 return 0;
	 }
 
