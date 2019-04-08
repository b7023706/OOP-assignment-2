#pragma once
#include "LibraryItem.h"

struct predNameDesc
{
	bool operator()(LibraryItem* a, LibraryItem* b) const {
		return a->GetGame()->GetName() < b->GetGame()->GetName();
	}
};

struct predNameAsc
{
	bool operator()(LibraryItem* a, LibraryItem* b) const {
		return a->GetGame()->GetName() > b->GetGame()->GetName();
	}
};

struct predDateDesc
{
	bool operator()(LibraryItem* a, LibraryItem* b) const {
		return a->GetDate() < b->GetDate();
	}
};

struct predDateAsc
{
	bool operator()(LibraryItem* a, LibraryItem* b) const {
		return a->GetDate() > b->GetDate();
	}
};