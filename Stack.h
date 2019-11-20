#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>
#pragma warning (disable: 4996)

#define Commands1 Commands2
#define Commands2 printf("	/|||||||||||||||||||||||||||||||||||||||||||\\\n"); Commands3
#define Commands3 printf("	/          View a list of commands:         \\\n"); Commands4
#define Commands4 printf("	/          -----> 0 = Exit                  \\\n"); Commands5
#define Commands5 printf("	/          -----> 1 = Push a value          \\\n"); Commands6
#define Commands6 printf("	/          -----> 2 = Pop a value           \\\n"); Commands7
#define Commands7 printf("	/          -----> 3 = Dumb                  \\\n"); Commands8
#define Commands8 printf("	/                                           \\\n"); Commands9
#define Commands9 printf("	/                                           \\\n"); Commands10
#define Commands10 printf("	/                                           \\\n"); Commands11
#define Commands11 printf("	/|||||||||||||||||||||||||||||||||||||||||||\\\n");

#define DUMB2									   printf("	/|||||||||||||||||||||||||||||||||||||||||||||||||||||||\\\n"); DUMB3
#define DUMB3									   printf("	/              View a list of DUMB:                     \\\n"); DUMB4
#define DUMB4									   printf("	/        -----> Canary 1 = %X <------                 \\\n",stk->canary1); DUMB5
#define DUMB5									   printf("	/        -----> Canary 2 = %X <------                 \\\n",stk->canary2); DUMB6
#define DUMB6									   printf("	/        -----> Number of elem stack [%d]  <------       \\\n",stk->size); DUMB7
#define DUMB7 for (int i = 0; i < stk->size;i++){  printf("	/        -----> Stack[%d]: <------                       \\\n",i); DUMB9
#define DUMB9				printf("	/        -----> ");std::cout << stk->data[i] ;  printf("         <------                      \\\n");} DUMB10
#define DUMB10									   printf("	/        -----> Parrot 1 = %X  <------                \\\n",*stk->parrot1); DUMB11
#define DUMB11									   printf("	/        -----> Parrot 2 = %X  <------                \\\n",*stk->parrot2); DUMB12
#define DUMB12									   printf("	/        -----> HASH = %X  <------                \\\n",stk->HASH); DUMB13
#define DUMB13									   printf("	/                                                       \\\n"); DUMB14
#define DUMB14									   printf("	/                                                       \\\n"); DUMB15
#define DUMB15									   printf("	/                                                       \\\n"); DUMB16
#define DUMB16									   printf("	/|||||||||||||||||||||||||||||||||||||||||||||||||||||||\\\n"); 

#define STACK_INFO1 printf("Canary 1 = %X\n",stk->canary1); printf("Canary 2 = %X\n",stk->canary2); printf("Number of elem stack [%d]\n",(stk->size));
#define STACK_INFO2 for (int i = 0; i < stk->size;i++){  printf("Stack[%d] = ",i); std::cout << stk->data[i] << std::endl ; }
#define STACK_INFO3 printf("Parrot 1 = %X\n",*stk->parrot1); printf("Parrot 2 = %X\n", *stk->parrot2);

typedef unsigned long long FatCanary;
typedef unsigned long long hash_t;


FatCanary bird_size = 0;
const char FAIL = -1;
const char SUCCESS = 0;
const char Inuput_error = -2;
const char capacity = 1;
const char Decrement_const = 5;
//const FatCanary bird_size = 0x1100DEAD;



template <typename T>
struct stack {
	FatCanary canary1;
	FatCanary* parrot1;
	T* data;
	int size;
	hash_t HASH;
	int cap;
	FatCanary* parrot2;
	FatCanary canary2;
};

void Bird_Size(void) {
	//Random bird const
	srand(time(NULL));
	bird_size = rand();
}
// Hash function
template <typename T>
hash_t FAQ6Hash(stack <T>* stk)
{
	hash_t hash = 0;

	for (size_t i = 0; i < stk->cap; i++)
	{
		hash += (unsigned char)(stk->data[i]);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);

	return hash;
} /* End of 'FAQ6Hash' function */

template <typename T>
void DUMB(stack <T>* stk) {
	DUMB2
}


template <typename T>
bool Hash_OK(stack <T>* stk, bool CHECK) {
		// If CHECK = 0, we only check HASH
		// If CHECK = 1, we change HASH
		if (CHECK != 0)
			stk->HASH = FAQ6Hash(stk);
		// Hash problem
		if (stk->HASH != FAQ6Hash(stk)) {
			printf("Your HASH is broke\n");
			DUMB(stk);
			StkDistruct(stk);
			return 1;
	}
	return 0;
}


template <typename T>
bool stack_OK(char STATUS,stack <T>* stk) {
	// Error code
	if (stk->canary1 != bird_size || stk->canary2 != bird_size)
		STATUS = 2;
	if (*stk->parrot1 != bird_size || *stk->parrot2 != bird_size)
		STATUS = 3;

	switch (STATUS) {
	case 0: {
		printf("[Action is success]\n");
		break;
		return 0;
	}
	case -1: {
		printf("[ERORR!]\n[Out of stack!]\n");
		DUMB(stk);
		StkDistruct(stk);
		return 1;
		break;
	}
	case 2: {
		printf("[ERORR!]\nYour cannarys is dead\n");
		DUMB(stk);
		StkDistruct(stk);
		return 1;
		break;
	}
	case 3: {
		printf("[ERORR!]\nYour parrot is dead\n");
		DUMB(stk);
		StkDistruct(stk);
		return 1;
		break;
	}
	case 4: {
		printf("[ERORR!]\nYour HASH is broke\n");
		DUMB(stk);
		StkDistruct(stk);
		return 1;
		break;
	}
	  return 1;
	}
}

template <typename T>
char push(stack <T>* stk, T value) {
	// Check pointer
	if (stk == NULL) {
		return FAIL;
	}
	if (stk->size >= stk->cap)
		Realloc_inc(stk);
	*(stk->data + stk->size++) = value;
	return SUCCESS;
}

template <typename T>
char pop(stack <T>* stk, T* var) {
	// Pointer check
	if (stk->size <= 0)
		return FAIL;

	if (stk == NULL)
		return FAIL;
	// Pop value
	stk->size--;
	*var = *(stk->data + stk->size);
	*(stk->data + stk->size) = 666;
	if (stk->size < stk->cap - Decrement_const)
		Realloc_dec(stk);
	return SUCCESS;
}

template <typename T>
char StkConstruct(stack <T>* stk) {
	Bird_Size();

	// Pointer check
	if (stk == NULL)
		return FAIL;

	// Initialization variable
	stk->cap = capacity;
	stk->canary1 = bird_size;
	stk->canary2 = bird_size;

	// memory allocation for array and parrot
	stk->parrot1 = (FatCanary*) calloc(sizeof(T)*stk->cap + 2*sizeof(FatCanary),1);
	stk->data = (T*) (stk->parrot1 + 1);
	stk->parrot2 = (FatCanary*) (stk->data + stk->cap);

	// Initialization variable
	for (int i = 0; i < stk->cap; i++)
		stk->data[i] = 666;
	stk->HASH = FAQ6Hash(stk);
	stk->parrot2[0] = bird_size;
	stk->parrot1[0] = bird_size;
	stk->size = 0;

	return SUCCESS;
}

template <typename T>
char StkDistruct(stack <T>* stk) {
	// Pointer check
	if (stk == NULL)
		return FAIL;

	// free memory
	free(stk->parrot1);
	stk->size = 0;
	stk->cap = 0;
	stk->canary1 = 0;
	stk->canary2 = 0;
	stk->parrot1 = NULL;
	stk->parrot2 = NULL;
	stk->HASH = 0;

	return SUCCESS;
}


// Next 2 func not work
 template <typename T>
char Realloc_inc(stack <T>* stk) {
	stk->cap = stk->cap * 2;

	stk->parrot1 = (FatCanary*) realloc(stk->parrot1, sizeof(T) * stk->cap + 2 * sizeof(FatCanary));
	stk->data = (T*)(stk->parrot1 + 1);
	stk->parrot2 = (FatCanary*)(stk->data + stk->cap);
	stk->parrot2 = stk->parrot1;

	if (stk == NULL)
		return FAIL;
	else
		return SUCCESS;
}

template <typename T>
char Realloc_dec(stack <T>* stk) {
	stk->cap = stk->cap / 2;

	stk->parrot1 = (FatCanary*)realloc(stk->parrot1, sizeof(T) * stk->cap + 2 * sizeof(FatCanary));
	stk->data = (T*)(stk->parrot1 + 1);
	stk->parrot2 = (FatCanary*)(stk->data + stk->cap);
	stk->parrot2 = stk->parrot1;

	if (stk->data != NULL)
		return SUCCESS;
	else
		return FAIL;
}


template <typename T>
char Start_work(stack <T>* stk) {
	T value = 0;
	int Case = 0;
	// Menu of commands
	Commands1;
	Hash_OK(stk,0);
	while (true) {
		// Enter commands
		scanf("%d", &Case);
		switch (Case) {
		case 0:
			// Exit
			printf("Thank for use my stack! Goodbuy! \n");

			stack_OK(SUCCESS, stk);
			StkDistruct(stk);
			return 0;
		case 1:
			// Push
			printf("[Push is accepted]\nPlease enter value\n");
			std::cin >> value;

			// Check problem
			if (stack_OK(push(stk, value), stk) == 1) 
				return 0;
			Hash_OK(stk,1);
			printf("Your value %d is accepted\n", value);
			break;
		case 2:
			//  Pop
			printf("[Pop is accepted]\n");
			
			// Check problem
			if (stack_OK(pop(stk, &value), stk) == 1) 
				return 0;
			Hash_OK(stk, 1);
			printf("Your value is %d \n", value);
			break;
		case 3:
			// DUMB
			DUMB(stk);
			break;
		}
	}

	return 0;
}
