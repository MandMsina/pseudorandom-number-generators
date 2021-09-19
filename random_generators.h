#pragma once
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "LKM.h"
#include "Mother_of_all.h"
#include "Middle_square.h"
#include "Xorshift.h"
#include "Mersenne_twister.h"


int generate(short int algorithm, unsigned long int quantity, unsigned long int* buffer);
// variable algorithm needs to choose algorithm, it can be:
// 1 - LKM
// 2 - Mother_of_all
// 3 - Middle square
// 4 - Xorshift
// 5 - Mersenne twister
