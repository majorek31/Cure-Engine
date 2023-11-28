#pragma once
#include <Cure.h>
#include <random>

class PipeController : public Cure::Component
{
public:
	void Start() override;
	void Update() override;
	void Render() override;
private:
	std::random_device m_RandomDevice;
	std::mt19937 m_Generator;
	std::uniform_real_distribution<float> m_LowerPipeDist;
	bool m_CollidedThisFrame = false;
};

