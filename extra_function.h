#ifndef EXTRAFUNCTION_H
#define EXTRAFUNCTION_H

#include "bajar.h"
#include "manager.h"
#include "payment.h"



#define dd "                                                                       "
#define uu "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
#define uuu "\n\n\n\n\n\n"


template<class type>
void update_file(type *t,string fileName)
{
    ofstream file;
    file.open(fileName,ios::binary | ios:: app);
    file.write(reinterpret_cast<char*>(t),sizeof(type));
    file.close();
}


#endif // EXTRA_FUNCTION_H



