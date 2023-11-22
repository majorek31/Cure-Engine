#include "Pipe.h"
#include "../Components/PipeController.h"

Pipe::Pipe(float lowerPipe)
	: Cure::Object("Pipe"),
	  m_LowerPos(lowerPipe)
			
{
	auto transform = AddComponent<Cure::TransformComponent>();
	transform->m_Position = { 600, 0 };
	auto pipeController = AddComponent<PipeController>();
}

void Pipe::SetLowerPos(float lp)
{
	m_LowerPos = lp;
}

float Pipe::GetLowerPos()
{
	return m_LowerPos;
}
