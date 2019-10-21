#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <locale.h>
#pragma warning (disable: 4996)
struct STRING {
	char* index;
	int len;
};
int Comporator(const void* x1, const void* x2) {
	STRING* Line1 = (STRING*) x1;
	STRING* Line2 = (STRING*) x2;
	for (int i = 0; i < Line1->len; i++) {
		if (char(*(Line1->index + i)) < char (*(Line2->index + i)))
			return -1;
		if (*(Line1->index + i) > *(Line2->index + i))
			return 1;
	}
	return 0;
}
int Comporator_Reverse(const void* x1, const void* x2) {
	STRING* Line1 = (STRING*)x1;
	STRING* Line2 = (STRING*)x2;
	int CountAlpha1 = 0;
	int CountAlpha2 = 0;
	for (int i = 0; i < Line1->len && i < Line2->len ; i++) {
		while (isalpha(char(*(Line1->index - i + Line1->len - 1-CountAlpha1))) == 0)
			CountAlpha1++;
		while (isalpha(char(*(Line2->index - i + Line2->len - 1-CountAlpha2))) == 0)
			CountAlpha2++;
		if (char(*(Line1->index - i - CountAlpha1 + Line1->len - 1 )) < char(*(Line2->index + i - CountAlpha2 + Line2->len - 1)))
			return -1;
		if (*(Line1->index + i - CountAlpha1 + Line1->len - 1) > * (Line2->index + i - CountAlpha2  + Line2->len) - 1)
			return 1;
	}
	return 0;
  
char* OPENandWRITE(int *len) {
	assert(*len != NULL);
	int trylen = 0;
	FILE* f = fopen("h.txt", "r");
	assert(("Wrong open file!", f));
	assert(("Wrong seek file", !fseek(f, 0, SEEK_END) != 0));
	*len = ftell(f);
	if (*len == -1) {
		printf("Wrong ftell");
		return NULL;
	}
	char* text = (char*)calloc(*len, sizeof(char));
	assert(text != NULL);
	fseek(f, 0, SEEK_SET);
	trylen = fread(text, sizeof(char), *len, f);
	*len = trylen + 1;
	fclose(f);
	return text;
}
 void CLOSEandWRITE(int len, struct STRING arrow_index[],const char* Type) {
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
/*void SORTpyzirek(int len, struct STRING arrow_index[]) {
	for (int i = 0; i < len; i++)
		for (int k = 0; k < len; k++)
			if (Comporator(*(arrow_index + i),*(arrow_index + k)) != 0) {
				char* temp = 0;
				temp = (arrow_index + k)->index;
				(arrow_index + k)->index = (arrow_index + i)->index;
				(arrow_index + i)->index = temp;
			}
}
*/

int main() {
		 int Textlen = 1, Indexlen = 0, count = 0, StringLen = 0;
		 const char* mode_write = "w";
		 const char* mode_append = "a";
		 struct STRING Line = {};
		 char* text;
		 text = OPENandWRITE(&Textlen);
		 assert(text != NULL);

		 for (int i = 0; i < Textlen; i++) {
			 if (*(text + i) == '\n')
				 Indexlen++;
			 while (*(text + i) == '\n') {
				 *(text + i) = '\0';
				 i++;
			 }

		 }
		 Indexlen++;
		 STRING* index = (STRING*)calloc(Indexlen, sizeof(index[0]));
		 Line.index = text;
		 for (int i = 0; i < Textlen; i++) {
			 if (*(text + i) == '\0') {
				 while ((isalpha(*(text + i)) == 0) && (i < (Textlen - 1)))
					 i++;
				 Line.len = StringLen;
				 index[count] = Line;
				 Line.index = text + i;
				 count++;
				 StringLen = 0;
			 }
			 StringLen++;
		 }
		 assert(index != NULL);
		 CLOSEandWRITE(count, index,mode_write);
		 qsort(index, count,sizeof(STRING),Comporator);
		 CLOSEandWRITE(count, index,mode_append);
		 qsort(index, count, sizeof(STRING), Comporator_Reverse);
		 CLOSEandWRITE(count, index,mode_append);
		 free(text);
		 free(index);
		 return 0;
	 }
 
