#pragma once
#include <Cure.h>

class BirdController : public Cure::Component
{
public:
	void Start() override;
	void Update() override;
	void Render() override;
private:
	bool m_isAlive;
	bool m_isGoingUp = false;
};

