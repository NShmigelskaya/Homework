#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <string>
#include <fstream> 
#include <iomanip> 
#include <cstring>
#include <vector>           
#include <sstream>          
#include <algorithm>    
#include <list>
#include <iterator>
#include "storage.h"
int main()
{
    Storage stor_1;
    std::list <std::string>::iterator i;
    stor_1.SetHash();
    stor_1.ReadFile();
    stor_1.FindBook();
    return 0;
}
