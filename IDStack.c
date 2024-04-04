#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IDStack.h"

static int MAXSTACK = 128;
static sStack stack;
stack.size = 0;
stack.top = NULL;
