#pragma once
#include <tinyfsm.hpp>
#include <iostream>
#include <AnimatedSprite.h>

//--------------------------------------------------------------FINITE STATE MACHINE SETUP------------------------------------------------------
struct Idling; // forward declaration
struct Running;
struct Jumping;

// Events
struct Idle : tinyfsm::Event { };
struct Run : tinyfsm::Event { };
struct Jump : tinyfsm::Event { };

//Class
class FSM : public tinyfsm::Fsm<FSM>
{

	friend class tinyfsm::Fsm<FSM>;

	virtual void react(Idle const &) { };
	virtual void react(Run const &) { };
	virtual void react(Jump const &) { };

	virtual void entry(void) { };
	void         exit(void) { };

public:

	static AnimatedSprite* currentAnim;
	static AnimatedSprite idleAnim;
	static AnimatedSprite runAnim;

	static AnimatedSprite* getAnim() { return currentAnim; }
	static AnimatedSprite& getIdleRef() { return idleAnim; }
	static AnimatedSprite& getRunRef() { return runAnim; }
	static void updateAnim() { currentAnim->update(); }
};

