#include "FSM.h"

AnimatedSprite FSM::idleAnim;
AnimatedSprite FSM::runAnim;
AnimatedSprite* FSM::currentAnim;

//States
struct Idling : FSM
{
	void entry() override
	{
		currentAnim = &idleAnim;
		std::cout << "* Idling" << std::endl;
	};
	void react(Run const &) override { transit<Running>(); };
	void react(Jump const &) override { transit<Jumping>(); };
};

struct Running : FSM
{
	void entry() override
	{
		currentAnim = &runAnim;
		std::cout << "* Running" << std::endl;
	};
	void react(Idle const &) override { transit<Idling>(); };
	void react(Jump const &) override { transit<Jumping>(); };
};

struct Jumping : FSM
{
	void entry() override { std::cout << "* Jumping" << std::endl; };
	void react(Idle const &) override { transit<Idling>(); };
	void react(Run const &) override { transit<Running>(); };
};

FSM_INITIAL_STATE(FSM, Idling)