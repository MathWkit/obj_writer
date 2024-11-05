#ifndef OBJWRITER_H
#define OBJWRITER_H

#include "Model.h"
#include <string>
#include <fstream>

class ObjWriter
{
public:
	ObjWriter() = default;

	void write(const Model& model);

	~ObjWriter();
};

#endif