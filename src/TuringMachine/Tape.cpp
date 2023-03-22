#include "Tape.h"

Tape::Tape(const SymbolString& input, Symbol blankSymbol)
	: m_tape(input.begin(), input.end()),
	  m_blankSymbol(blankSymbol) {}

void Tape::moveHead(const Direction& directon) {
	if (directon == Direction::LEFT) {
		m_head--;
	}
	else {
		m_head++;
	}
	
	if (isOutOfBounds(m_head)) {
		growTape();
	}
	else {
		shrinkToFit();
	}
}

void Tape::writeSymbol(Symbol symbol) {
	m_tape[m_head] = symbol;
}

Symbol Tape::readSymbol() const {
	return m_tape[m_head];
}

Symbol Tape::getSymbolFromOffset(int offset) const {
	int index = m_head + offset;

	if (isOutOfBounds(index)) {
		return m_blankSymbol;
	}
	
	return m_tape[index];
}

bool Tape::isOutOfBounds(int index) const {
	return index >= m_tape.size() || index < 0;
}

void Tape::growTape() {
	if (m_head >= m_tape.size()) {
		m_tape.push_back(m_blankSymbol);
	}
	else if (m_head < 0) {
		m_tape.push_front(m_blankSymbol);
		m_head = 0;
	}
}

void Tape::shrinkToFit() {
	if (m_head > 0 && m_tape.front() == m_blankSymbol) {
		m_tape.pop_front();
		m_head--;
	}
	else if (m_head < m_tape.size() - 1 && m_tape.back() == m_blankSymbol) {
		m_tape.pop_back();
	}
}