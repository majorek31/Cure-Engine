#pragma once
#include <Cure.h>
class BackgroundComponent : public Cure::Component
{
public:
	void Start() override;
	void Update() override;
	void Render() override;
};

