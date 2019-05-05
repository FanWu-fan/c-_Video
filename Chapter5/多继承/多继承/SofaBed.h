#pragma once
#include "Sofa.h"
#include "Bed.h"
class SofaBed : public Sofa, public Bed
{
public:
	SofaBed();
	~SofaBed();
	void  sitandslepp()
	{
		sleep();
		sit();
	}
};

