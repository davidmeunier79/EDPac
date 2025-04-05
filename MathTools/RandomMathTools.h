// RandomMathTools.h

#ifndef _RANDOM_MATH_TOOLS_H
#define _RANDOM_MATH_TOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "RandomNumberGenerator.h"

using namespace std;
using namespace KW_RNG;

/******************************************************************************************************************************************/
/****************************************************** Génération de nombres aléatoires **************************************************/
/******************************************************************************************************************************************/

void initRandom();
double randomProb();
double randomUniform();
double randomSign();
double randomBool();
int randomInt(int randMax);

#endif


