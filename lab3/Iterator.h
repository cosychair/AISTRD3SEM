#pragma once
class Iterator {
public:
	virtual int next() = 0;
	virtual bool hasNext() = 0;
};