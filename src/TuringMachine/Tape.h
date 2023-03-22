#pragma once
#include <deque>
#include "Symbol.h"
#include "Direction.h"

class Tape {
public:
	Tape(const SymbolString& input, Symbol blankSymbol);
	~Tape() = default;
public:
	void moveHead(const Direction& directon);

	void writeSymbol(Symbol symbol);
	Symbol readSymbol() const;

	Symbol getSymbolFromOffset(int offset) const;
private:
	bool isOutOfBounds(int index) const;
	void growTape();
	void shrinkToFit();
private:
	std::deque<Symbol> m_tape;
	const Symbol m_blankSymbol;
	int m_head = 0;
};