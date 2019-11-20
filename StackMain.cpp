#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#pragma warning (disable: 4996)



int main() {
	stack <int> istk;
	StkConstruct(&istk);
	Start_work(&istk);
	return 0;
}
