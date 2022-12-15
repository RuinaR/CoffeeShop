#pragma once
#include "Command.h"

template <typename RECEIVER>
class SimpleCommand : public Command
{
public:
	typedef void (RECEIVER::* ACTION)(void);
	void Execute(void) final
	{
		(this->m_receiver->*m_action)();
	}

	SimpleCommand() :m_receiver(nullptr), m_action(nullptr), Command() {}
	SimpleCommand(const SimpleCommand<RECEIVER>& ref) :m_receiver(ref.m_receiver), m_action(ref.m_action), Command(ref) {}
	SimpleCommand(RECEIVER* m) :m_receiver(m), m_action(nullptr), Command() {}
	SimpleCommand(RECEIVER* m, ACTION m1) :m_receiver(m), m_action(m1), Command() {}
	~SimpleCommand() {}

	SimpleCommand<RECEIVER>& operator=(const SimpleCommand<RECEIVER>& ref)
	{
		Command::operator=(ref);
		this->m_receiver = ref.m_receiver;
		this->m_action = ref.m_action;
		return *this;
	}

	inline RECEIVER* GetReceiver(void)const { return this->m_receiver; }
	inline void SetReceiver(RECEIVER* m) { this->m_receiver = m; }
	inline ACTION GetAction(void)const { return this->m_action; }
	inline void SetAction(ACTION m) { this->m_action = m; }

private:
	RECEIVER* m_receiver;
	ACTION m_action;
};

