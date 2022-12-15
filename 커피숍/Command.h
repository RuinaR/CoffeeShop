#pragma once
class Command
{
public:
	virtual void Execute(void) abstract;
	virtual ~Command() {}

protected:
	Command() {}
	Command(const Command& ref) {}
	Command& operator=(const Command& ref) { return *this; }
};

