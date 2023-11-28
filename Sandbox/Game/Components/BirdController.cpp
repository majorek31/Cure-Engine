#include "BirdController.h"

void BirdController::Start()
{
	Restart();
}
void BirdController::Update()
{
	auto& app = Cure::Application::Get();
	auto transform = GetOwner()->GetComponent<Cure::TransformComponent>();
	auto& input = Cure::Input::Get();
	const double gravity = 2000.0 * app.GetDeltaTime();
	const double jumpForce = 800.0;

	transform->m_Velocity.y += gravity;

	if (input.GetKeyDown(Cure::ScanCode::KEY_SPACE)) {
		transform->m_Velocity.y = -jumpForce;
	}

	transform->m_Position.y += transform->m_Velocity.y * app.GetDeltaTime();
	if (transform->m_Velocity.y < 0)
		transform->m_Angle = -25;
	else 
		transform->m_Angle = 0;
	if (transform->m_Position.y < 0) {
		transform->m_Position.y = 0;
		transform->m_Velocity.y = 0;
	}
}


void BirdController::Render()
{
}

void BirdController::Kill()
{
	m_isAlive = false;
}

void BirdController::Restart()
{
	m_Points = 0;
	m_isAlive = true;
	auto transform = GetOwner()->GetComponent<Cure::TransformComponent>();
	transform->m_Velocity = { 0, 0 };
	transform->m_Position = { 100, 300 };
}

void BirdController::IncreasePoints()
{
	m_Points++;
}

int BirdController::GetPoints()
{
	return m_Points;
}
