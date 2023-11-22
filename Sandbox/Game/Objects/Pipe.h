#pragma once
#include <Cure.h>
class Pipe : public Cure::Object
{
public:
	Pipe(float lowerPipe);
	void SetLowerPos(float lp);
	float GetLowerPos();
private:
	float m_LowerPos;
};

