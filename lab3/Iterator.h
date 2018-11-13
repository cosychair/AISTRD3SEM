#pragma once
class Iterator {
public:
	virtual void next() = 0;
	virtual bool hasNext() = 0;
	virtual int current() = 0;
};