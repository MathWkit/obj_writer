#ifndef OBJWRITER_H
#define OBJWRITER_H

#include "Model.h"
#include <string>
#include <fstream>

class ObjWriter
{
public:
	ObjWriter() = default;

	static void write(const Model& model, const std::string& filename);

	~ObjWriter();
};

#endif