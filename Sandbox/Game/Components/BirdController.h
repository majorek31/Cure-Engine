#pragma once
#include <Cure.h>

class BirdController : public Cure::Component
{
public:
	void Start() override;
	void Update() override;
	void Render() override;
	void Kill();
	void Restart();
	void IncreasePoints();
	int GetPoints();
private:
	bool m_isAlive;
	bool m_isGoingUp = false;
	int m_Points;
};

